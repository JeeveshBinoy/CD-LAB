%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char val[10];
  struct node *l, *r;
};
typedef struct node Node;

Node *make(char *v, Node *l, Node *r);
void print(Node *t, int sp);
Node *root;
int yylex(void);
int yyerror(char *s);
%}

%union {
    struct node *n;
    char sval[10];
}

%token <sval> NUM
%type  <n> expr term factor

%left '+' '-'
%left '*' '/'

%%
input: expr { root = $1; }
     ;

expr: expr '+' term { $$ = make("+", $1, $3); }
    | expr '-' term { $$ = make("-", $1, $3); }
    | term          { $$ = $1; }
    ;

term: term '*' factor { $$ = make("*", $1, $3); }
    | term '/' factor { $$ = make("/", $1, $3); }
    | factor          { $$ = $1; }
    ;

factor: '(' expr ')' { $$ = $2; }
      | NUM          { $$ = make($1, NULL, NULL); }
      ;
%%

int yyerror(char *s) { printf("Error: %s\n", s); return 0; }

Node* make(char *v, Node *l, Node *r) {
  Node *t = (Node*)malloc(sizeof(Node));
  strcpy(t->val, v);
  t->l = l;
  t->r = r;
  return t;
}

void print(Node *t, int sp) {
  if (!t) return;
  sp += 5;
  print(t->r, sp);
  printf("\n%*s%s", sp, "", t->val);
  print(t->l, sp);
}

int main() {
  printf("Enter expression: ");
  yyparse();
  printf("\n\nAbstract Syntax Tree:\n");
  print(root, 0);
  printf("\n");
  return 0;
}

