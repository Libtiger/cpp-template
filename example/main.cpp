#include "log/log.h"

int main(int argc, char *argv[]) {
    Logger::GetInstance()->setLevel(LOG_LEVEL::INFO);
    LOGI("Hello world");
    return 0;
}
