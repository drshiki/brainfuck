#include "brainfuck.h"

void no_match_error(){
	
		fprintf(stderr, "no any ] match to the [");
		exit(EXIT_WITH_EXCEPTION);
		
}

char* jump_to_rbracket(char **pstring, char *curp){
	
	for((*pstring)++; **pstring != ']' && **pstring != '\0'; (*pstring)++){

		if (**pstring == '['){
			
			sub_interpreter(pstring, curp);
			
		}else{
			
			continue;
			
		}
	}
	if (**pstring == '\0'){
		
		no_match_error();
		
	}else{
		
	}
	return curp;
	
}

char* go_loop(char **pstring, char *curp){
	
	char *lbrace_start = *pstring;

	for((*pstring)++; **pstring != '\0';(*pstring)++){

		switch(**pstring){
			
			case '+' 	: 		(*curp)++; break;
			case '-' 	: 		(*curp)--; break;
			case '>' 	: 		curp++;break;
			case '<' 	: 		curp--;break;
			case '[' 	:		curp = sub_interpreter(pstring, curp);break;
			case ']' : 
				
				if (*curp == 0){
					
					return curp;
					
				}
				else{
					
					*pstring = lbrace_start;
					
				}
				break;
				
			case '.' 	: 		printf("%c", *curp); break;
			case ',' 	: 		*curp = getchar() ;break;
			default 	: 		break;
		}
	}
	
	no_match_error();
	return ;
}

char* sub_interpreter(char **pstring, char *curp){
	
	if(*curp == 0){
		
		curp = jump_to_rbracket(pstring,curp);

	}else{
		
		curp = go_loop(pstring,curp);
		
	}
	
	return curp;
}

int intepreter(char *string, char *curp){
	
	char **pstring = &string;

	for(int i = 0; **pstring != '\0'; (*pstring)++,i++){
		
		switch(**pstring){
			case '+' 	: 		(*curp)++; break;
			case '-' 	: 		(*curp)--; break;
			case '>' 	: 		curp++; break;
			case '<' 	: 		curp--; break;
			case '[' 	: 		curp = sub_interpreter(pstring, curp); break;
			case ']' 	:		exit(EXIT_WITH_EXCEPTION);
			case '.' 	: 		printf("%c", *curp); break;
			case ',' 	: 		*curp = getchar(); break;
			default		: 		break;
		}
		
	}
}

void run_code_of_file(char *file){
	
	if (file){
		
		FILE *source = fopen(file,"r");

		if(!source){
			
			fprintf(stderr, "can't open file %s", file);
			exit(EXIT_WITH_EXCEPTION);
			
		}else{
			
			char arr[BRAINFUCK_TAPE_SIZE] = {0};
			char str[MAX_INPUT_SIZE]={'\0'};
			
			for(int i = 0; (str[i] = fgetc(source)) != EOF; i++){
				
			}
			
			intepreter(str, arr);
		}
	}
	else{
		
	}

}

void run_code_of_arg(char *code){
	
	if(code){
			char arr[BRAINFUCK_TAPE_SIZE] = {0};
			char str[MAX_INPUT_SIZE]={'\0'};
			strcpy(str, code);
			intepreter(str, arr);		
	}
	else{
		
	}
}

char get_arg(char *arg){
	
	return arg[1];
	
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

void show_welcome(){
	printf("Welcome to brainfuck REPL %s <https://github.com/touchEngine/brainfuck>\n", VERSION);
	printf("This is free software, distributed under the GPLv2 License\n");
	printf("Type 'exit()' to exit.\n");
}

int main(int argc, char **argv)
{
	if (argc > 1){
		switch(get_arg(argv[1])){
			case	'h'		: 		print_usage(); break;
			case 	'v'		:		show_version(); break;
			case 	'f'		:		run_code_of_file(argv[2]); break;
			case	'r'		:		run_code_of_arg(argv[2]); break;
			default			:		show_arg_error(argv[1]);
		}
	}
	else{
		
		show_welcome();
		while(true){
			char arr[BRAINFUCK_TAPE_SIZE] = {0};
			char str[MAX_INPUT_SIZE]={'\0'};
			
			printf("=>:");
			scanf("%s",str);
			
			if(!strcmp(str,"exit()")){
				break;
			}else{
				intepreter(str, arr);
				puts("");
			}
		}
	}
	return EXIT_NORMAL;
}