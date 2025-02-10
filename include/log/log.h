#ifndef LOG_LOG_H
#define LOG_LOG_H

#include <memory>
#include <spdlog/spdlog.h>

enum class LOG_LEVEL { DEBUG, INFO, WARN, ERROR };

class Logger {
public:
    static Logger *GetInstance() {
        static Logger instance{};
        return &instance;
    }

    void setLevel(LOG_LEVEL level) {
        switch (level) {
        case LOG_LEVEL::DEBUG:
            logger_->set_level(spdlog::level::debug);
            break;
        case LOG_LEVEL::WARN:
            logger_->set_level(spdlog::level::warn);
            break;
        case LOG_LEVEL::ERROR:
            logger_->set_level(spdlog::level::err);
            break;
        default:
            logger_->set_level(spdlog::level::info);
            break;
        }
    }

    template <typename... Args>
    void log(spdlog::level::level_enum level, const char *fmt, const Args &...args) {
        logger_->log(level, fmt, args...);
    }

    template <typename... Args>
    void debug(const char *fmt, const Args &...args) {
        log(spdlog::level::debug, fmt, args...);
    }

    template <typename... Args>
    void info(const char *fmt, const Args &...args) {
        log(spdlog::level::info, fmt, args...);
    }

    template <typename... Args>
    void warn(const char *fmt, const Args &...args) {
        log(spdlog::level::warn, fmt, args...);
    }

    template <typename... Args>
    void error(const char *fmt, const Args &...args) {
        log(spdlog::level::err, fmt, args...);
    }

private:
    Logger() {
#if defined(__ANDROID__) && defined(NDEBUG)
        auto android_sink = std::make_shared<spdlog::sinks::android_sink_mt>("MotionDetector");
        android_sink->set_pattern("%v");
        logger_ = std::make_shared<spdlog::logger>("MotionDetector", android_sink);
#else
        auto console_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
        console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] %v");
        logger_ = std::make_shared<spdlog::logger>("MotionDetector", console_sink);
#endif
        this->setLevel(LOG_LEVEL::INFO);
    }
    ~Logger() = default;
    Logger(const Logger &logger) = delete;
    Logger &operator=(const Logger &logger) = delete;

private:
    std::shared_ptr<spdlog::logger> logger_;
};

#define LOGD(...) Logger::GetInstance()->debug(__VA_ARGS__)
#define LOGI(...) Logger::GetInstance()->info(__VA_ARGS__)
#define LOGW(...) Logger::GetInstance()->warn(__VA_ARGS__)
#define LOGE(...) Logger::GetInstance()->error(__VA_ARGS__)

#endif // !LOG_LOG_H
