#include <iostream>
#include "../cserver/log.h"
int main()
{
    cserver::Logger::ptr logger(new cserver::Logger);
    logger->addAppender(cserver::LogAppender::ptr(new cserver::StdoutLogAppender));
    return 0;
}

