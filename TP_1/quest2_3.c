#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_CHAT_EXIT 4
#define HELLO "Bienvenue dans le shell ENSEA .\n"
#define STR_EXIT "exit"
#define ENSEASH "enseash % "
#define EXIT_MSG "Au revoir!\n"

int main(){
    const char *mess = HELLO;
    char commande[256];
    char outputBuffer[256];
    int outputSize;
    write(STDOUT_FILENO, mess, strlen(mess));

    while (1)
    {
        write(STDOUT_FILENO, ENSEASH, sizeof(ENSEASH));
        ssize_t n = read(STDIN_FILENO, commande, 256);
        commande[n - 1] = '\0';
 	if (n < 0)
        {
            perror("Erreur");
            exit(EXIT_FAILURE);
        }
        else if (strcmp(commande, "fortune") == 0)
        {
            if(0 == fork()){ // Son
              execlp("/usr/games/fortune","fortune",NULL);//executer le prog fortune
            }
            else { // Father
                int status;
                wait(&status);
            }
        }
         else if (strcmp(commande, "ls") == 0)
        {
            if(0 == fork()){ // Son
              execlp("/bin/ls","ls",NULL);
            }
            else { // Father
                int status;
                wait(&status);
            }
        }

        
        else if (strcmp(commande, "exit") == 0)//QUESTION 3
	    {
            write(STDOUT_FILENO, EXIT_MSG, strlen(EXIT_MSG));
            exit(EXIT_SUCCESS);
        }
        else
        {
            write(STDOUT_FILENO, "Commande non reconnue\n", 22);
        }
    }

    exit(EXIT_SUCCESS);
}