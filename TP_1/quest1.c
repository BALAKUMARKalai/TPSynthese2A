#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define ENSEASH "enseash % "
int main() {
	const char *mess ="$ ./enseash Bienvenue dans le Shell ENSEA. Pour quitter, tapez 'exit'.enseash %\n";
	
    char commande[256];
    
    write(STDOUT_FILENO, mess, strlen(mess));
	while(1){
		write(STDOUT_FILENO, mess, strlen(ENSEASH));
        ssize_t n = read(STDIN_FILENO, commande, 256);
    
	}
	write(STDOUT_FILENO, mess, sizeof(mess));
    exit(EXIT_SUCCESS);
}
