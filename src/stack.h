#ifndef STACK_H
#define STACK_H

//you can change the 100 if you want a different size
#define MAX_STACK_SIZE 100
typedef struct {
    int elements[MAX_STACK_SIZE];
    int top_index;
} Stack;

//functions
void count_elements(Stack *stack);
void initialize(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void print(Stack *stack);
void swap_top(Stack *stack);
void reverse(Stack *stack);
void sort(Stack *stack, int start, int end);
void delete_(Stack *stack, int value);
void search(Stack *stack, int value);
void help_menu(void);
int IsValid_arg(int parsed, int args);

//colors
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define LIGHT_GREEN "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#endif
