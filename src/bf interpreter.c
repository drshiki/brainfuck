#include <stdio.h>

char* subInterpreter(char **pstring, char *curp);

void noExecLoop(char **pstring){
	while(**pstring != ']')
		*pstring++;
}

char* execLoop(char **pstring, char *curp){
	
	char *leftBraceStart = *pstring;
	//char *curpp;
	for((*pstring)++; **pstring != '\0';(*pstring)++){
		//printf("%c ,%d, %d\n",**pstring, curp,*curp);
		//getch();
		switch(**pstring){
			case '+' : (*curp)++; break;
			case '-' : (*curp)--; break;
			case '>' : curp++;break;
			case '<' : curp--;break;
			case '[' : curp = subInterpreter(pstring, curp);break;
			case ']' : 
				//puts("-------------");
				//getch();
				if (*curp == 0){
					return curp;
				}
				else
					*pstring = leftBraceStart; 
				break;
			case '.' : printf("%c", *curp);/*getch()*/; break;
			case ',' : *curp = getchar();
		}
	}
}

char* subInterpreter(char **pstring, char *curp){
	//printf("this is %c, curp = %d\n", *subString, *curp);
	if(*curp == 0){
		noExecLoop(pstring);
	}else{
		curp = execLoop(pstring,curp);
	}
	return curp;
}

int intepreter(char *string, char *curp){
	
	char **pstring = &string;
	
	for(int i = 1;**pstring != '\0';(*pstring)++){
		//printf("this is %c curp = %d\n",**pstring,*curp);
		switch(**pstring){
			case '+' : (*curp)++; break;
			case '-' : (*curp)--; break;
			case '>' : curp++;break;
			case '<' : curp--;break;
			case '[' : curp = subInterpreter(pstring, curp);break;
			case ']' : puts("illegal input"); break;
			case '.' : printf("%c", *curp);/*getch()*/; break;
			case ',' : *curp = getchar();
		}
		//printf("%d", i);
		//getch();
	}
}

int main()
{
	char arr[3000] = {0};
	char str[10000] ={'\0'};
	scanf("%s", str);
	intepreter(str, arr);
	return;
}