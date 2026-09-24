#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig) {
    signal_count++;

    printf("\nCtrl+C pressed %d time(s)\n", signal_count);

    if (signal_count == 3) {
        printf("Ctrl+C pressed 3 times. Exiting...\n");
        exit(0);
    }

    printf("Program is still running...\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}