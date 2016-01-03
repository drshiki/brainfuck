#include "brainfuck.h"

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
	return EXIT_NORMAL;
}

