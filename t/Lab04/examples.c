/*wait(NULL);
        printf("\nI am parent process with pid = %d and finished waiting\n", getpid());
    }
    return 0;
}
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    pid_t childpid = fork();
    int status=0;
    if (childpid == 0) {
    
        printf("I am a child process with pid = %d\n", getpid());
        printf("The next statement is execv and ls will run\n");
	char *env[] = { "TERM=vt100", "PATH=/bin:/usr/bin", NULL };
	char *args[] = { "cat", "file1", NULL };
	execve("/bin/cat", args, env);


        printf("Exec failed\n");
    } else if (childpid > 0) {
        wait(&status);
        int temp=WEXITSTATUS(status);
        printf("\nI am parent process with pid = %d and finished waiting:%d\n", getpid(),temp);
    }
    return 0;
}
