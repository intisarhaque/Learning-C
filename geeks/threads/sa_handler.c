#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//handler only takes one int because it is sa_handler
void termination_handler (int signum){
    struct temp_file *p;
    // for (p = temp_file_list; p; p=p->next){
    //     unlink (p->name);
    // }
}

int main(void){
    struct sigaction new_action, old_action;
    new_action.sa_handler = termination_handler;//set handler to hadnler fucntion
    sigemptyset(&new_action.sa_mask);//dont need to block signals
    new_action.sa_flags=0;

    //checking if any signals in past are set to ignore, if so give it new action
    //but if ignored keep the way it is
    sigaction(SIGINT, NULL, &old_action);//oldaction to query information
    if (old_action.sa_handler != SIG_IGN){
        sigaction(SIGINT, &new_action, NULL);
    }

    sigaction(SIGHUP, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN){
        sigaction(SIGHUP, &new_action, NULL);
    }

    sigaction(SIGHUP, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN){
        sigaction(SIGHUP, &new_action, NULL);
    }

    sigaction(SIGTERM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN){
        sigaction(SIGTERM, &new_action, NULL);
    }




}