/*
 * =====================================================================================
 *
 *       Filename:  daemon.c
 *
 *    Description:  a daemon for libevent
 *
 *        Version:  1.0
 *        Created:  02/01/2012 10:46:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (feinno), yueyang@feinno.com
 *        Company:  feinno
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include "http-server.h"
#include "log.h"

extern FILE *log_fp;

int task_http_proxy(void);

int
main ( int argc, char *argv[] )
{
    int flag;
    char *log_path = "/tmp";

    flag = log_open(log_path);
    if (flag) {
        return -1;
    }

    /* Call daemon function */
    daemon(0, 0);
    log_write(INFO, "daemon: Daemon has started.\n");

    log_write(INFO, "daemon: http proxy will be start.\n");
    task_http_proxy();

    log_close();
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

