#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_PROCESSES 4
#define EXECUTE_PROCESS "ps"

void printPId(int process_number) 
{
   while (1) 
   {
       printf("Subprocess %d, pid: %d\n", process_number, getpid());
       sleep(1);
   }
}

pid_t *pids_ctr(int num_processes) {
    pid_t *pid = malloc(num_processes * sizeof(pid_t));
    if (pid == NULL) 
    {
        perror("Not enough memory for pids");
        exit(1);
    }

    return pid;
}

void pids_dtr(pid_t *pid) 
{
    free(pid);
}

void run_subprocesses(pid_t *pid, int num_processes)
{
   for (int i = 0; i < num_processes; i++) 
   {
       pid[i] = fork();

       if (pid[i] < 0) 
       {
           perror("Fork failed");
           exit(1);
       }

       if (pid[i] == 0) 
       {
           if (i == 2) 
           {
               execvp(EXECUTE_PROCESS, NULL);
               perror("Exec failed");
               exit(1);
           } 
           else 
           {
               printPId(i + 1);
           }
       }
   }
}

void wait_pids(pid_t *pid, int num_processes)
{
   for (int i = 0; i < num_processes; i++) 
   {
       waitpid(pid[i], NULL, 0);
   }
}

void parent_waiting(void)
{
   printf("Parent pid: %d\n", getpid());
   sleep(5);
}

void kill_pids(pid_t *pid, int num_processes)
{
   printf("Killing pids\n");
   for (int i = 0; i < 4; i++) 
   {
       kill(pid[i], SIGKILL);
       printf("Killed pid: %d\n", pid[i]);
   }
}

int main(int argc, char *argv[]) {
   pid_t *pid = pids_ctr(MAX_PROCESSES);

   run_subprocesses(pid, MAX_PROCESSES);

   parent_waiting();

   kill_pids(pid, MAX_PROCESSES);
   wait_pids(pid, MAX_PROCESSES);

   printf("All pids terminated, stop program\n");

   pids_dtr(pid);
   return 0;
}