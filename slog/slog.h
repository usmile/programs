#ifndef __SLOG_H__
#define __SLOG_H__

// default config
#define LOG_FILE             "./temp.log"
#define DEFAULT_LOG_LEVEL    debug
#define DEFAULT_LOG_SWITCH   slog_open

// log switch
#define slog_open 1
#define slog_close 0

// log level
typedef enum
{
    debug = 0,
    error = 1,
    fatal = 2,
    log_butt
} LOG_LEVEL;

// api
void setLogLevel(LOG_LEVEL level);
LOG_LEVEL getLogLevel();

void setLogSwitch(int sw);
int  getLogSwitch();

void print2file(LOG_LEVEL level, char *fmt, ...);
void print2screen(LOG_LEVEL level, char *fmt, ...);

// helpers
#define slog(level, fmt, log_arg...) \
    do \
    { \
        print2screen(level, "[%s:%d %s] " fmt "\n", __FILE__, __LINE__, __func__, ##log_arg); \
        print2file(level, "[%s:%d %s] " fmt "\n", __FILE__, __LINE__, __func__, ##log_arg); \
    } while (0)

#define slog_debug(fmt, log_arg...) slog(debug, fmt, ##log_arg)
#define slog_error(fmt, log_arg...) slog(error, fmt, ##log_arg)
#define slog_fatal(fmt, log_arg...) slog(fatal, fmt, ##log_arg)

#endif
