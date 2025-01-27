#include "src/file_writer/file_writer.h"
#include <sys/types.h>
#include <stdio.h>
#include <time.h>

#define FILENAME "output.txt"
#define NUM_PROCESSES 5

static const char * GREETINGS[NUM_PROCESSES] = {"Hello", "Hi", "Hi there", "Hi everyone", "Hello everyone"};

int main(void)
{
    pid_t pids[NUM_PROCESSES];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error forking");
            exit(1);
        } else if (pid == 0) {
            int count = file_writer_count_lines(FILENAME);

            printf("PID: %d, Count in file: %d\n", getpid(), count);

            char time_str[64];
            time_t now = time(NULL);
            struct tm *tm_info = localtime(&now);
            strftime(time_str, sizeof(time_str), "%Y-%m-%dT%H:%M:%S%z", tm_info);

            char buffer[256];
            snprintf(buffer, sizeof(buffer), "PID: %d, Greeting: '%s', Time: %s\n", getpid(), GREETINGS[i], time_str);

            file_writer_write(FILENAME, buffer, strlen(buffer));

            exit(0);
        } else {
            pids[i] = pid;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}