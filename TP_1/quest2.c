#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const char *mess ="$ ./enseash Bienvenue dans le Shell ENSEA. Pour quitter, tapez 'exit'.enseash %\n";
	write(STDOUT_FILENO, mess, strlen(mess));
	
    exit(EXIT_SUCCESS);
}