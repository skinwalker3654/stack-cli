#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

//counts the elements
void count_elements(Stack *stack) {
        printf(GREEN "Elements count: %d\n" RESET, stack->top_index + 1);
}

//stack initializer
void initialize(Stack *stack) {
        stack->top_index = -1;
}

//push values into the stack
void push(Stack *stack, int value) {
    int found = 0;
    for(int i=0; i<stack->top_index+1; i++) {
        if(value == stack->elements[i]) {
                found = 1;
                break;
        }
    }

    if(!found) {
        if(stack->top_index >= MAX_STACK_SIZE - 1) {
                printf(RED "Stack overflow\n" RESET);
                return;
        }
        stack->elements[++stack->top_index] = value; 
        printf(GREEN "Pushed: %d\n" RESET, value);
    } else {
            printf(RED "Error: The value %d already exists\n" RESET,value);
            return;
    }
}

//pops values from the stack
void pop(Stack *stack) {
    if(stack->top_index == -1) {
            printf(RED "Stack underflow\n" RESET);
            return;
    } else {
            printf(GREEN "Popped: %d\n" RESET,stack->elements[stack->top_index--]);
            return;
    }
}

//peek value
void peek(Stack *stack) {
    if(stack->top_index == -1) {
            printf(RED "Stack underflow\n" RESET);
            return;
    } else {
            printf(GREEN "Top element: %d\n" RESET,stack->elements[stack->top_index]);
            return;
    }
}

//prints the stack
void print(Stack *stack) {
    if(stack->top_index == -1) {
            printf(YELLOW "Stack is empty\n" RESET);
            return;
    }
    
    printf(GREEN "Bottom->Top: " RESET);
    for(int i = 0; i <= stack->top_index; i++) 
            printf(CYAN "%d " RESET, stack->elements[i]);

    printf("\n");
}

//swaps the top elements
void swap_top(Stack *stack) {
    if(stack->top_index < 1) {
            printf(YELLOW "Not enough elements to swap\n" RESET); 
            return;
    }
    
    int temp = stack->elements[stack->top_index];
    stack->elements[stack->top_index] = stack->elements[stack->top_index - 1];
    stack->elements[stack->top_index - 1] = temp;
    
    printf(GREEN "Swapped: %d and %d\n" RESET, 
           stack->elements[stack->top_index], 
           stack->elements[stack->top_index - 1]);
}

//sorts the stack by quicksort
void sort(Stack *stack, int start, int end) {
    if(start >= end) return;
    int pivot = stack->elements[end];
    int partition_index = start - 1;

    for(int j = start; j < end; j++) {
        if(stack->elements[j] < pivot) {
                partition_index++;
                int temp = stack->elements[partition_index];
                stack->elements[partition_index] = stack->elements[j];
                stack->elements[j] = temp;
        }
    }

    int temp = stack->elements[partition_index + 1];
    stack->elements[partition_index + 1] = stack->elements[end];
    stack->elements[end] = temp;

    int pivot_index = partition_index + 1;
    sort(stack, start, pivot_index - 1);
    sort(stack, pivot_index + 1, end);
}

//deletes values
void delete_(Stack *stack, int value) {
    if(stack->top_index == -1) {
            printf(YELLOW "Stack is empty\n" RESET);
            return;
    }

    int found_index = -1;
    for(int i = 0; i <= stack->top_index; i++) {
        if(stack->elements[i] == value) {
                found_index = i;
                break;
        }
    }

    if(found_index == -1) {
            printf(YELLOW "Value %d not found\n" RESET, value);
            return;
    }

    for(int i = found_index; i < stack->top_index; i++) 
            stack->elements[i] = stack->elements[i + 1];
    stack->top_index--;

    printf(GREEN "Deleted: %d\n" RESET,value);
}

//find the index of a value 0 based index
void search(Stack *stack, int value) {
    if(stack->top_index == -1) {
            printf(YELLOW "Stack is empty\n" RESET);
            return;
    }

    int found_index = -1;
    for(int i = 0; i <= stack->top_index; i++) {
        if(stack->elements[i] == value) {
                found_index = i;
        }
    }

    if(found_index == -1) {
            printf(YELLOW "Value %d not found\n" RESET, value);
    } else {
            printf(GREEN "Value %d found at index: %d\n" RESET, value, found_index);
    }
}

//reverse the stack
void reverse(Stack *stack) {
    if(stack->top_index == -1) {
            printf(YELLOW "Stack is empty\n" RESET);
            return;
    }

    for(int i = 0; i <= stack->top_index / 2; i++) {
            int temp = stack->elements[i];
            stack->elements[i] = stack->elements[stack->top_index - i];
            stack->elements[stack->top_index - i] = temp;
    }

    printf(GREEN "Stack is now reversed\n" RESET);
}

//checks if you added the amount of arguments required
int IsValid_arg(int parsed, int args) {
        if(parsed == args) {return 1;}
        printf(RED "Error: Invalid arguments\n" RESET);
        return 0;
}

//prints the commands
void help_menu() {
        printf(LIGHT_GREEN "\nAvailable commands:\n" RESET);
        printf(LIGHT_GREEN "  push  <value> - Add value to stack\n" RESET);
        printf(LIGHT_GREEN "  find  <value> - Search for value\n" RESET);
        printf(LIGHT_GREEN "  del   <value> - Delete specific value\n" RESET);
        printf(LIGHT_GREEN "  pop           - Remove top value\n" RESET);
        printf(LIGHT_GREEN "  peek          - View top value\n" RESET);
        printf(LIGHT_GREEN "  count         - Show element count\n" RESET);
        printf(LIGHT_GREEN "  swap          - Swap top two elements\n" RESET);
        printf(LIGHT_GREEN "  reverse       - Reverse stack order\n" RESET);
        printf(LIGHT_GREEN "  print         - Display stack contents\n" RESET);
        printf(LIGHT_GREEN "  sort          - Sort stack\n" RESET);
        printf(LIGHT_GREEN "  help          - Show this menu\n" RESET);
        printf(LIGHT_GREEN "  cls           - Clear screen\n" RESET);
        printf(LIGHT_GREEN "  exit          - Quit program\n\n" RESET);
}
