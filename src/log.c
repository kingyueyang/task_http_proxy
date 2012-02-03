/*
 * =====================================================================================
 *
 *       Filename:  log.c
 *
 *    Description:  simple log
 *
 *        Version:  1.0
 *        Created:  02/01/2012 05:29:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (feinno), yueyang@feinno.com
 *        Company:  feinno
 *
 * =====================================================================================
 */

#include "log.h"

int log_open(const char *path) {
    char log_filename[FILENAME_LEN];

    /*
     *Get date YYYYMM
     *Generate file name
     */
    time(&log_time);
    log_tm = localtime(&log_time);
    snprintf(log_filename, FILENAME_LEN,
            "%s/task-http-proxy-%.4d%.2d.log",
            path, log_tm->tm_year + 1900, log_tm->tm_mon + 1);

    /* Appending the log file */
    log_fp = fopen(log_filename, "a");
    if (log_fp) {
        return 0;
    } else {
        return -1;
    }
}

int log_write(int level, const char *fmt, ...){
    int count = 0;
    char log_level[LEVEL_LEN];
    va_list args;

    switch(level) {
        case DEBUG:
            snprintf(log_level, LEVEL_LEN,  "DEBUG");
            break;
        case INFO:
            snprintf(log_level, LEVEL_LEN, "INFO");
            break;
        case WARN:
            snprintf(log_level, LEVEL_LEN, "WARN");
            break;
        case ERROR:
            snprintf(log_level, LEVEL_LEN, "ERROR");
            break;
        default:
            snprintf(log_level, LEVEL_LEN, "UNKN");
            break;
    }

    time(&log_time);
    log_tm = localtime(&log_time);

    /* Time format YYYY-MM-DD HH:MM:SS */
    count = fprintf(log_fp, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d | %s |",
            log_tm->tm_year + 1900, log_tm->tm_mon + 1, log_tm->tm_mday, 
            log_tm->tm_hour, log_tm->tm_min, log_tm->tm_sec, log_level);

    va_start(args, fmt);
    count += vfprintf(log_fp, fmt, args);
    va_end(args);
    fflush(log_fp);

    return count;
}

void log_close(void){
    if(log_fp) {
        fclose(log_fp);
    }

    return ;
}

