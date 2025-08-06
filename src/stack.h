#ifndef STACK_H
#define STACK_H

#define max_nums 100

typedef struct {
    int data[max_nums];
    int top;
} Stack;

void count(Stack *s);
void init(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void print(Stack *s);
void swap(Stack *s);
void reverse(Stack *s);
void sort(Stack *s, int start, int end);
void delete_(Stack *s, int value);
void find(Stack *s, int value);
void print_commands();
int parser(int persed,int n);

#endif
