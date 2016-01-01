#ifndef __BF_H__
#define __BF_H__

#include <stdio.h>
#include <string.h>
#include <stdio.h>

int intepreter(char *string, char *curp);
char *subInterpreter(char **pstring, char *curp);

char *noExecLoop(char **pstring, char *curp);
char *execLoop(char **pstring, char *curp);

void get_arg(char *arg);
void show_arg_error();


#endif