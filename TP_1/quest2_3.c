#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

        // Split the command into arguments
        int i = 0;
        args[i] = strtok(commande, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Son to execute the command
        pid_t pid = fork();
       
        if (pid == 0) {
            //  son
            if (execvp(args[0], args) == -1) {//Execute the command
                perror("Erreur Commande non trouvée");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            //  father
            int status;
            wait(&status);  

        }
    }
    return 0;

}