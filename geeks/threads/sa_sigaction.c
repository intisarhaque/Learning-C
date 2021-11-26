#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

//handler takes 3 params because using sa_sigaction
static void hdl (int sig, siginfo_t *siginfo, void *context){
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);//can get process id and user id
}

int main(int argc, char *argv[]){
    struct sigaction act;
    memset(&act, '\0', sizeof(act));

    //use the sa_sigaction field bc the handler has 2 additional parameters handler contains a siginfo_t and a void pointer
    act.sa_sigaction = &hdl;

    //SA_SIGINFO flag tells sigaction() to use sa_sigaction and not sa_handler
    act.sa_flags=SA_SIGINFO;

    if (sigaction(SIGTERM, &act, NULL) < 0){
        perror("sigaction");
        return 1;
    }
    while(1){
        sleep(3);
    }
    return 0;
}