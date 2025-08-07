#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

typedef struct {
    int elements[MAX_STACK_SIZE];
    int top_index;
} Stack;

void count_elements(Stack *stack);
void initialize(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void print(Stack *stack);
void swap_top(Stack *stack);
void reverse(Stack *stack);
void sort(Stack *stack, int start, int end);
void delete(Stack *stack, int value);
void search(Stack *stack, int value);
void help_menu(void);
int validate_arguments(int parsed_args, int expected_args);

#endif
