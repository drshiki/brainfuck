/* $BrainFuck Interpreter : v 1.0.1, Oct 10, 2014,00:11:03 by Dam$ */

/*
* This is a lightweight interpreter in c for the program language which is called 
* BrainFuck, although its name is so absurd and is so little, it is Turing-complete.
*
* If you have any advice or you want to make some improvement for it, please contact
* me by xiaoguaivshaijian@163.com, if you are willing to throw yourself into this 
* project£¬it is my pleasuer. Please contact me, I will get you a copy if you need.
*
* As you see, this program has many bugs, I believe it could be better in one day, 
* welcome you join my project.
*/
#include <stdio.h>
#include <stdlib.h>

// the array max size
#define MAXNUM 3000

// the function for "+"
int Add(char *);

// the function for "-"
int Diff(char *);

// the function for "<"
int LeftMove(char **);

// the function for ">"
int RightMove(char **);

// the function for ","
int Comma(char *);

// the function for "."
int Period(char *);

// the function for "["
int LeftBracket(char *);

// the function for "]"
int RightBracket(char *);

// the function to call  all other functions
int Call(FILE *fp, char *operatePointer, const char *ub, const char *lb);

int main(int argc, char **argv)
{
	FILE *fp = fopen(*(argv+1), "rb");
	char UnitArray[MAXNUM] = {0}, *opc;
	/*
	 * opc is a pointer point to a operating seat of the array
	 * it init by the array headaddress 
	 */
	opc = UnitArray;
	
	const char *upperBound = &UnitArray[MAXNUM - 1], *LowerBound = &UnitArray[0]; 
	if ( fp == NULL) {
		puts("No file input");
		exit(1);
	}
	Call(fp, opc, upperBound, LowerBound);
	return 0;
}
int Call(FILE *fp, char *operatePointer, const char *ub, const char *lb)
{
	/*
	* op is a pointer point to a operating seat of the array
	* dealChar is the processing intrusion
	*/
	char dealChar, *op = operatePointer;
	int flag = 0;
	
	for (; (dealChar = fgetc(fp)) != EOF; ) {
		switch (dealChar) {
			case '+' : Add(op); break;
			case '-' : Diff(op); break;
			case '>' : if (op == ub) {
						puts("erro");
						exit(1);
						}
					   RightMove(&op); break;
			case '<' : if (op == lb) {
						puts("erro");
						exit(1);
						}
					   LeftMove(&op); break;
			case ',' : Comma(op); break;
			case '.' : Period(op); break;
			case '[' : flag = LeftBracket(op);
						if ( flag == 0) {
							while((dealChar = fgetc(fp)) != ']') {
								if (dealChar == EOF) {
									printf("error");
									exit(1);
								}
							}
							fseek(fp, -1, SEEK_CUR);
						}
						break;
			case ']' : flag = RightBracket(op);
								if (flag == 1) {
									while (!(fseek(fp, -2, SEEK_CUR))) {
										
										if(fgetc(fp) == '[')
											break;
									}
								}
								break;
		}
	}
	return 0;
}
int Add(char *p)
{
	(*p)++;
	
	return 0;
}
int Diff(char *p)
{
	(*p)--;
	
	return 0;
}
int RightMove(char **p)
{
	(*p)++;
	
	return 0;
}
int LeftMove(char **p)
{
	(*p)--;
	
	return 0;
}
int Comma(char *p)
{
	*p = getchar();
	
	return 0;
}
int Period(char *p)
{
	putchar(*p);

	return 0;
}
int LeftBracket(char *p)
{
	if (*p == 0)
		return 0;
	
	return 1;
}
int RightBracket(char *p)
{
	if (*p != 0)
		return 1;
	
	return 0;
}
