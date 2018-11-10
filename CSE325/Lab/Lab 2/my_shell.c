#include <unistd.h>
#include <sys/wait.h>

#define CMD_LEN 120

int main(int argc, char **argv) {
    char cmd[CMD_LEN];
    char *cmd_args[2];
    int n;
    int child_pid;

    while (1) {
        /* read command from user */
        write(1, "Shaykh__$ ", 10);
        n = read(0, cmd, CMD_LEN);
        if (n == 0) break; /* EOF reached; exit program */
        cmd[n - 1] = '\0'; /* replace '\n' with '\0' */

        /* fork off child to execute command */
        child_pid = fork();
        if (child_pid == 0) {
            cmd_args[0] = cmd;
            cmd_args[1] = NULL;
            execvp(cmd, cmd_args);
            /* If execvp returns, the command is bad. */
            write(1, "Command not found\n", 19);
            exit(-1); //@ child1
        }

        /* wait for child to exit before continuing */
        waitpid(child_pid, &n, 0);
    }
    return 0;
}
