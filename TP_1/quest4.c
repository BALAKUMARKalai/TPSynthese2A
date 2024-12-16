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

    // Afficher le message de bienvenue
    write(STDOUT_FILENO, mess, strlen(mess));

    while (1) {
        // Afficher le prompt
        write(STDOUT_FILENO, ENSEASH, strlen(ENSEASH));

        // Lire la commande
        ssize_t n = read(STDIN_FILENO, commande, sizeof(commande));
        if (n < 0) {
            perror("Erreur de lecture");
            exit(EXIT_FAILURE);
        }

        // Supprimer le saut de ligne de la commande
        commande[n - 1] = '\0';

        // Gestion de la commande exit
        if (strcmp(commande, "exit") == 0) {
            write(STDOUT_FILENO, EXIT_MSG, strlen(EXIT_MSG));
            exit(EXIT_SUCCESS);
        }

        // Découper la commande en arguments
        int i = 0;
        args[i] = strtok(commande, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // fils pour exécuter la commande
        pid_t pid = fork();
       
        if (pid == 0) {
            //  fils
            if (execvp(args[0], args) == -1) {
                perror("Erreur Commande non trouvée");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            //  père
            int status;
            wait(&status);  

            // Déterminer le code de retour 
            char prompt[256];
            if (WIFEXITED(status)) {
                // Le processus s'est terminé normalement
                int exit_code = WEXITSTATUS(status);
                snprintf(prompt, sizeof(prompt), "[exit:%d] %% ", exit_code);
            } else if (WIFSIGNALED(status)) {
                // Le processus a été terminé par un signal
                int signal = WTERMSIG(status);
                snprintf(prompt, sizeof(prompt), "[sig:%d] %% ", signal);
            } 

            
            write(STDOUT_FILENO, prompt, strlen(prompt));
        } 
    }

    return 0;
}