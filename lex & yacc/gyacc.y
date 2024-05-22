%{

void yyerror (char *s);

#include <stdio.h>
#include <stdlib.h>

int symbols[53];
int symbol_value (char symbol);
void update_symbol_value (char symbol, int val);

%}

%union {int num; char id;}
%start line
%token print
%token exit_command
%token <num> number
%token <id> identifier
%type <num> line exp term
%type <id> assignment

%%