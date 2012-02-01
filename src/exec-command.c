/*
 * =====================================================================================
 *
 *       Filename:  exec-command.c
 *
 *    Description:  parser and exec command form http post
 *
 *        Version:  1.0
 *        Created:  02/01/2012 04:19:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (feinno), yueyang@feinno.com
 *        Company:  feinno
 *
 * =====================================================================================
 */


#include "exec-command.h"

int
shell_cmd (char *buf)
{
    int rc;

    char *cmd[] = {"python", "/tmp/echo.py", (char *)0};
    char *env[] = {};

    free(buf);
    buf = NULL;
    rc = execve("/usr/bin/python", cmd , env);

    return rc;
}		/* -----  end of function shell_cmd  ----- */

