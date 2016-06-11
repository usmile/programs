#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include "slog.h"

// log switch
static int g_log_switch = DEFAULT_LOG_SWITCH;

// log level
static LOG_LEVEL g_log_level = DEFAULT_LOG_LEVEL;

// current time string
static char g_time_string[128] = {0};

void setLogLevel(LOG_LEVEL level)
{
    if (level >= log_butt) {
        g_log_level = DEFAULT_LOG_LEVEL;
    }
    else {
        g_log_level = level;
    }
}

LOG_LEVEL getLogLevel()
{
    return g_log_level;
}

void setLogSwitch(int sw)
{
    if (sw == slog_close) {
        g_log_switch = slog_close;
    }
    else {
        g_log_switch = slog_open;
    }
}

int getLogSwitch()
{
    return g_log_switch;
}

static void getCurtime(char *time_str)
{
    if (time_str == NULL) { return ; }

    time_str[0] = '\0';

    time_t timep;
    struct tm *p;

    time(&timep);
    p = gmtime(&timep);

    // get date
    sprintf(time_str, "%d-%02d-%02d ", 
            1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    // get time
    sprintf(time_str + strlen(time_str), "%02d:%02d:%02d", 
            p->tm_hour + 8, p->tm_min, p->tm_sec);
}

#define CASE_RETURN(level) case level: return #level

static char * getLogLevelStr(LOG_LEVEL level)
{
    switch (level) {
        CASE_RETURN(debug);
        CASE_RETURN(error);
        CASE_RETURN(fatal);
        default:
            return "invalid";
    }
}

void print2file(LOG_LEVEL level, char *fmt, ...)
{
    if (g_log_switch == slog_close || g_log_level > level) { return ; }

    char buf[1024] = {0};

    FILE *fp = NULL;

    strcat(buf, getLogLevelStr(level));
    strcat(buf, " ");

    getCurtime(g_time_string);
    strcat(buf, g_time_string);

    va_list args;
    va_start(args, fmt);
    vsprintf(buf + strlen(buf), fmt, args);
    va_end(args);

    fp = fopen(LOG_FILE, "a"); if (fp == NULL) { return ; }
    
    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);
    fp = NULL;
}

void print2screen(LOG_LEVEL level, char *fmt, ...)
{
    if (g_log_switch == slog_close || g_log_level > level) { return ; }

    char buf[1024] = {0};

    strcat(buf, getLogLevelStr(level));
    strcat(buf, " ");

    getCurtime(g_time_string);
    strcat(buf, g_time_string);

    va_list args;
    va_start(args, fmt);
    vsprintf(buf + strlen(buf), fmt, args);
    va_end(args);

    printf("%s", buf);
}
