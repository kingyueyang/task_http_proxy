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

int
main ( int argc, char *argv[] )
{
    int flag;
    char tt[] = "daemon starting...";
    char *log_path = "/tmp";

    flag = log_open(log_path);
    if (flag) {
        return -1;
    }

    flag = log_write(2, "debug, %s\n", tt);
    printf("%d\n", flag);

    log_close();

    int drc = daemon(0, 1);

    task_http_proxy();

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

