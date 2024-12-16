#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>  

#define HELLO "Bienvenue dans le shell ENSEA .\n"
#define ENSEASH "enseash % "
#define EXIT_MSG "Au revoir!\n"

int main() {
    const char *mess = HELLO;
    char commande[256];
    char *args[256];

    //Write the welcoming message
    write(STDOUT_FILENO, mess, strlen(mess));

    while (1) {
        //Write our prompt
        write(STDOUT_FILENO, ENSEASH, strlen(ENSEASH));

        //Read the buf 
        ssize_t n = read(STDIN_FILENO, commande, sizeof(commande));
        if (n < 0) {
            perror("Erreur de lecture");
            exit(EXIT_FAILURE);
        }

        // Remove the newline from the command 
        commande[n - 1] = '\0';

        // Exit command (question 3)
        if (strcmp(commande, "exit") == 0) {
            write(STDOUT_FILENO, EXIT_MSG, strlen(EXIT_MSG));
            exit(EXIT_SUCCESS);
        }

        // Split the command into arguments(question 6)
        int i = 0;
        args[i] = strtok(commande, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Get the time before execution
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Son to execute the command
        pid_t pid = fork();
        if (pid == 0) {
            // son
            if (execvp(args[0], args) == -1) {
                perror("Erreur Commande non trouvée");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            //  father
            int status;
            wait(&status);  

            // Get the time after the execution
            clock_gettime(CLOCK_MONOTONIC, &end);

            
            // Calculation of execution time in milliseconds
            long seconds = end.tv_sec - start.tv_sec;
            long milliseconds = (end.tv_nsec - start.tv_nsec) / 1000000; // Change nanoseconds in miliseconds

            // To get the return  (question 4)
            char prompt[256];
            if (WIFEXITED(status)) {
                // If the process went with an exit
                int exit_code = WEXITSTATUS(status);
                snprintf(prompt, sizeof(prompt), "[time: %ld.%09ld ms][exit:%d] %% ", seconds, milliseconds, exit_code);
            } else if (WIFSIGNALED(status)) {
                // If the process went with a signal
                int signal = WTERMSIG(status);
                snprintf(prompt, sizeof(prompt), "[time: %ld.%09ld ms][sig:%d] %% ", seconds, milliseconds, signal);
            } 

            //write our new prompt 
            write(STDOUT_FILENO, prompt, strlen(prompt));
        } 
    }

    return 0;
}