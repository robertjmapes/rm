/*
————————————–––––––––—————————
rm/main.c — Becausse, why not?

Author, Robert, 2025.
——————————————————————————————
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>


int help() {
	printf("usage: rm [directory | file] | [-R]\n");
	return 0;
}

void _remove(char* file, int dir_flag) {
	if (dir_flag)
		rmdir(file);
    else remove(file);
}

int main(int argc, char* argv[]) {
	if (argc != 2) 
		goto help;		
	else
		goto run;
	
	run:
		if (argv[2] == NULL)
			_remove(argv[1], 0);
		else if (strcmp(argv[2], "-D") == 0)
			_remove(argv[1], 1);
		goto exit;

	help:
		help();
		goto exit;
		
	exit: return 0;
}
