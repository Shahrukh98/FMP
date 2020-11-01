#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t child;
    pid_t grandchild;
    int outpipe[2];
    pipe(outpipe);
    child = fork();
    if (child == -1) {
        perror("child:");
        return 1;
    }

    if (child == 0) {
        close(outpipe[0]);
        // child
        grandchild = fork();
        if (grandchild == -1) {
            perror("grandchild:");
            exit(2);
        }
        if (grandchild == 0) {
            // grandchild - send our pid back
            pid_t self = getpid();
            printf("grandchild has pid %d\n", self);
            write(outpipe[1], &self, sizeof(self));
            close(outpipe[1]);
            sleep(5);
            printf("grandchild exiting\n");
            exit(15);
        }
        exit(42);
    }
    // (grand)parent
    close(outpipe[1]);
    read(outpipe[0], &grandchild, sizeof(grandchild));
    printf("grandchild pid is %d\n", grandchild);
    int status;
    if (waitpid(grandchild, &status, 0) == -1) {
        perror("waitpid on grandchild:");
        exit(1);
    }
    printf("grandchild exited %d\n", status);

    return 0;
}