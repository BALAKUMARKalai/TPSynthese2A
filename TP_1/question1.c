#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	const char mess="$ ./enseash Bienvenue dans le Shell ENSEA. Pour quitter, tapez 'exit'.enseash %";
	write(STDOUT_FILEN0, mess, strlen(mess));
	EXIT_SUCCESS;
}
