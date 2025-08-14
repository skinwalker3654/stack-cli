#ifndef STACK_H
#define STACK_H

//you can change the 100 if you want a different size
#define MAX_STACK_SIZE 100
typedef struct {
    int elements[MAX_STACK_SIZE];
    int top_index;
} Stack;

//the file location of the command hisory
#define FILE_NAME "bin/history.txt"
extern int count; //from stack.c 

//functions
void count_elements(Stack *stack);
void initialize(Stack *stack);
void push(Stack *stack, int value);
void pop(Stack *stack);
void peek(Stack *stack);
void print(Stack *stack);
void swap_top(Stack *stack);
void reverse(Stack *stack);
void sort(Stack *stack, int start, int end);
void delete_(Stack *stack, int value);
void search(Stack *stack, int value);
void help_menu(void);
void save_history(char *input);
void print_history(void);
int IsValid_arg(int parsed, int args);

//colors
#define RESET        "\033[0m"
#define RED          "\033[31m"
#define GREEN        "\033[32m"
#define YELLOW       "\033[33m"
#define LIGHT_GREEN  "\033[35m"
#define CYAN         "\033[36m"

#endif
