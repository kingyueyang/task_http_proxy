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
shell_cmd (char *buf) {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        log_write(ERROR, "exec-command: fork process error.\n");
        return -1;
    } else if (0 == pid) {
        char *path = NULL;
        log_write(INFO, "exec-command: child process (%d) parser command: %s\n", getpid(), buf);

        path = strsep(&buf, ",");
        char *cmd[3] = {"", "", (char *)0};
        cmd[0] = strsep(&buf, ",");
        cmd[1] = strsep(&buf, ",");
        char *env[] = {};

        execve(path, cmd , env);
    } else {
#if 0
        /* Block recover child process. */
        pid = waitpid(-1, &child_st, 0);
        if (0 == child_st) {
            log_write(INFO, "exec-command: child process (%d) exit code %d.\n", pid, child_st);
        } else {
            log_write(ERROR, "exec-command: child process (%d) exit code %d.\n", pid, child_st);
        }
#endif
    }

    return 0;
}		/* -----  end of function shell_cmd  ----- */

