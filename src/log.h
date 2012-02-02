/*
 * =====================================================================================
 *
 *       Filename:  log.h
 *
 *    Description:  simple log
 *
 *        Version:  1.0
 *        Created:  02/01/2012 05:30:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (feinno), yueyang@feinno.com
 *        Company:  feinno
 *
 * =====================================================================================
 */

#ifndef _LOG_H_
#define _LOG_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#include <sys/stat.h>

#define	LEVEL_LEN 8			/* level buffer length  */
#define	FILENAME_LEN 128			/* filename buffer length  */

time_t log_time;
struct tm *log_tm;

enum LEVEL {DEBUG, INFO, WARN, ERROR};
FILE *log_fp;

int log_open(const char *path);
int log_write(int level, const char *fmt, ...);
void log_close(void);

#endif

