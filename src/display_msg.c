#include "brainfuck.h"

void show_welcome(){
	printf("Welcome to brainfuck REPL %s <https://github.com/touchEngine/brainfuck>\n", VERSION);
	printf("This is free software, distributed under the GPLv2 License\n");
	printf("Type 'exit()' to exit.\n");
}

void show_arg_error(char *error_arg){
	
	fprintf(stderr, "Unrecognized option: %s\n", error_arg);
	fprintf(stderr, "See usage : -h");
	
}

void print_usage(){
	
	fprintf(stderr, "Usage: brainfuck [option] [arg]\n");
	fprintf(stderr, "Options: \n");
	fprintf(stderr, "\t-f <file>\t\tinput the file and run it\n");
	fprintf(stderr, "\t-h \t\t\tshow the help information\n");
	fprintf(stderr, "\t-r <code>\t\trun the brainfuck code directly\n");
	fprintf(stderr, "\t-v \t\t\tshow version information of this interpreter\n");
	
}

void show_version(){
	
	fprintf(stderr, "brainfuck %s\n", VERSION);
	fprintf(stderr, "see https://github.com/touchEngine/brainfuck for details\n");
	
}

void no_match_error(){
	
		fprintf(stderr, "no any ] match to the [");
		exit(-1);
		
}