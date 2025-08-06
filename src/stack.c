#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void count(Stack *s) { printf("Elements count: %d\n", s->top + 1); }
void init(Stack *s) { s->top = -1; }

void push(Stack *s, int value) {
    if(s->top >= max_nums - 1) {
        printf("Stack overflow\n");
        return;
    } else {
        s->data[++s->top] = value;
    }
}

int pop(Stack *s) {
    if(s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return s->data[s->top--];
    }
}

int peek(Stack *s) {
    if(s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return s->data[s->top];
    }
}

void print(Stack *s) {
    if(s->top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        for (int i = 0; i <= s->top; i++)
            printf("%d ", s->data[i]);
        printf("\n");
    }
}

void swap(Stack *s) {
    if(s->top == -1) {
        printf("Stack underflow\n");
        return;
    } else {
        int tmp = s->data[s->top];
        s->data[s->top] = s->data[s->top - 1];
        s->data[s->top - 1] = tmp;
    }

    printf("Top: %d swapped with %d\n", s->data[s->top - 1], s->data[s->top]);
}

void sort(Stack *s, int start, int end) {
    if(start >= end) return;
    int pivot = s->data[end];
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if (s->data[j] < pivot) {
            i++;
            int tmp = s->data[i];
            s->data[i] = s->data[j];
            s->data[j] = tmp;
        }
    }

    int tmp = s->data[i + 1];
    s->data[i + 1] = s->data[end];
    s->data[end] = tmp;

    int pi = i + 1;
    sort(s, start, pi - 1);
    sort(s, pi + 1, end);
}

void delete_(Stack *s, int value) {
    if(s->top == -1) {
        printf("Stack is empty\n");
        return;
    }

    int index = -1;
    for(int i = 0; i <= s->top; i++) {
        if (s->data[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Value %d not found\n", value);
        return;
    }

    for (int i = index; i < s->top; i++)
        s->data[i] = s->data[i + 1];
    s->top--;
}

void find(Stack *s, int value) {
    if(s->top == -1) {
        printf("Stack is empty\n");
        return;
    }

    int index = -1;
    for(int i = 0; i <= s->top; i++)
        if (s->data[i] == value)
            index = i;

    if(index == -1) {
        printf("Value %d not found!\n", value);
    } else {
        printf("Value %d found at index: %d\n", value, index);
    }
}

void reverse(Stack *s) {
    if(s->top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for(int i=0; i<=(s->top/2); i++) {
        int temp = s->data[i];
        s->data[i] = s->data[s->top-i];
        s->data[s->top-i] = temp;
    }
}

int parser(int persed,int n) {
    if(persed == n) {return 1;}
    printf("Error: Invalid arguments passed\n");
    return 0;
}

void print_commands() {
    printf("\nAvailable commands:\n");
    printf("  push <value>  - Push a value onto the stack\n");
    printf("  pop           - Pop a value from the stack\n");
    printf("  peek          - View the top value without popping\n");
    printf("  del  <value>  - Delete a value from the stack\n");
    printf("  count         - Show number of elements in stack\n");
    printf("  swap          - Swap the top elements\n");
    printf("  reverse       - Reverse the stack elements\n");
    printf("  print         - Display stack contents\n");
    printf("  sort          - Sort the stack in ascending order\n");
    printf("  find <value>  - Search for a value in the stack\n");
    printf("  help          - Show this help message\n");
    printf("  cls           - Clear the terminal\n");
    printf("  exit          - Exit the program\n\n");
}
