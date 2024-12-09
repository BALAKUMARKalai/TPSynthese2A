#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define ENSEASH "enseash % "
int main() {
	const char *mess ="$ ./enseash Bienvenue dans le Shell ENSEA. Pour quitter, tapez 'exit'.enseash %\n";
	
    char commande[256];
    
    write(STDOUT_FILENO, mess, strlen(mess));//Pour écrire notre message 
	while(1){
<<<<<<< HEAD
		write(STDOUT_FILENO, ENSEASH, strlen(ENSEASH));//pour avoir notre prompt
        read(STDIN_FILENO, commande, 256);//pour attendre une commande 
=======
		write(STDOUT_FILENO, mess, strlen(ENSEASH));
        	ssize_t n = read(STDIN_FILENO, commande, 256);
>>>>>>> 32f5d9ded14440ad6951651b5a91b8826a2d2533
    
	}
    exit(EXIT_SUCCESS);
}
