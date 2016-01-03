#include "brainfuck.h" 

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