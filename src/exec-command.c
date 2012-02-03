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

    int flag;
    char *log_path = "/tmp";

    flag = log_open(log_path);
    if (flag) {
        return -1;
    }

    log_write(INFO, "exec request command.\n");

    path = strsep(&buf, ",");

    char *cmd[3] = {"", "", (char *)0};
    cmd[0] = strsep(&buf, ",");
    cmd[1] = strsep(&buf, ",");

    char *env[] = {};

    rc = execve(path, cmd , env);
    log_write(DEBUG, "command return %d.\n", rc);

    return rc;
}		/* -----  end of function shell_cmd  ----- */

