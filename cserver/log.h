#ifndef __CSERVER_LOG_H__
#define __CSERVER_LOG_H__
#include <cstdint>
#include  <string>
#include <memory>
namespace cserver {

// event of log
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
private:
    const char* m_file = nullptr; // file name
    int32_t m_line = 0; // line num
    uint32_t m_elapse = 0; // msec from program start
    int32_t m_threadId = 0; // thread id
    uint32_t m_fiberId = 0; // fiber id
    uint64_t m_time = 0; // time stamp
    std::string m_content;
};

// Level of Log
class LogLevel {
public:
    enum Level {
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };
};

// log format
class LogFormatter {
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    std::string format(LogEvent::ptr event);
private:
};

//log output dest
class LogAppender {
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender();
    void log(LogLevel::Level level, LogEvent::ptr event);
private:
    LogLevel::Level m_level;
};



class Logger {
public:
    Logger();
    void log(LogLevel::Level level, LogEvent::ptr event);
    typedef std::shared_ptr<Logger> ptr;
private:

    std::string m_name;
    LogLevel::Level m_level;
    LogAppender::ptr logAppender;

};

//output to console
class StdoutLogAppender: public LogAppender {

};


// output to file
class FileLogAppender: public LogAppender {

};


}
#endif
