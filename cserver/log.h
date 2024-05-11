#ifndef __CSERVER_LOG_H__
#define __CSERVER_LOG_H__
#include <cstdint>
#include  <string>
#include <memory>
#include <list>
#include <fstream>
#include <iostream>
#include <vector>
namespace cserver {
class Logger;
// event of log
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
    const char* getFile() const {return m_file;}
    int32_t getLine() const {return m_line;}
    uint32_t getThreadId() const {return m_threadId;}
    uint32_t getElapse() const {return m_elapse;}
    uint32_t getFiberId() const {return m_fiberId;}
    uint64_t getTime() const {return m_time;}
    std::string getContent() const {return m_content;}

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
    static const char* ToString(LogLevel::Level level) ;
};

// log format
class LogFormatter {
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    LogFormatter(const std::string& pattern);
    std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public:
    class FormatItem {
    public:
        typedef std::shared_ptr<FormatItem> ptr;
        FormatItem(const std::string& fmt = "");
        virtual ~FormatItem() {}
        virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
    };
private:
    std::string m_pattern;
    std::vector<FormatItem::ptr> m_items;
    void init();
};

//log output dest
class LogAppender {
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender();
    virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
    void setFormatter(LogFormatter::ptr val) {m_formatter = val;}
    LogFormatter::ptr getFormater() const {return m_formatter;}
protected:
    LogLevel::Level m_level;
    LogFormatter::ptr m_formatter;
};



class Logger: public std::enable_shared_from_this <Logger>{
public:
    Logger(const std::string& name = "root");
    void log(LogLevel::Level level, LogEvent::ptr event);
    typedef std::shared_ptr<Logger> ptr;
    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);
    void addAppender(LogAppender::ptr appender);
    void delAppender(LogAppender::ptr appender);
    LogLevel::Level getLevel() const {return m_level;}
    void setLevel(LogLevel::Level val) {m_level = val;} 
    const std::string& getName() const {return m_name;}
private:
    std::string m_name;
    LogLevel::Level m_level;
    std::list<LogAppender::ptr> m_appenders; 
    LogFormatter::ptr m_formatter;
};

//output to console
class StdoutLogAppender: public LogAppender {
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
};


// output to file
class FileLogAppender: public LogAppender {
public:
    typedef std::shared_ptr<FileLogAppender> ptr;
    FileLogAppender(const std::string& filename);
    void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};


}
#endif
