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
    int drc = daemon(0, 1);
    /*sleep(5);*/
    task_http_proxy();

    printf("%d\n", drc);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

