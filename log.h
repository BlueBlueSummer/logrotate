#ifndef H_LOG
#define H_LOG

#include <stdio.h>

#define MESS_REALDEBUG  1
#define MESS_DEBUG      2
#define MESS_VERBOSE    3
#define MESS_NORMAL     4
#define MESS_ERROR      5
#define MESS_FATAL      6

void message(int level, const char *format, ...)
#ifdef __GNUC__
    __attribute__ ((format(printf, 2, 3)));
#else
;
#endif

#define message_OOM() \
    do { \
        message(MESS_ERROR, "cannot allocate memory [%s():%d]\n", __func__, __LINE__); \
    } while(0)

void logSetMessageFile(FILE * f);
void logToSyslog(int enable);
void logSetLevel(int level);

#endif

