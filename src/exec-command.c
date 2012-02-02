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
shell_cmd (char *buf, int size) {
    int rc;
    char *path = NULL;

    path = strsep(&buf, ",");

    char *cmd[3] = {"", "", (char *)0};
    cmd[0] = strsep(&buf, ",");
    cmd[1] = strsep(&buf, ",");
    /*strcpy(NULL, "a");*/

    char *env[] = {};

    rc = execve(path, cmd , env);
    printf("%d\n", rc);

    return rc;
}		/* -----  end of function shell_cmd  ----- */

