#include "../cserver/log.h"
#include <iostream>
int main() {
    cserver::Logger::ptr logger(new cserver::Logger);
    logger->addAppender(
        cserver::LogAppender::ptr(new cserver::StdoutLogAppender));
    cserver::LogEvent::ptr event(
        new cserver::LogEvent(__FILE__, __LINE__, 0, 1, 2, time(0)));
    logger->log(cserver::LogLevel::DEBUG, event);
    return 0;
}
