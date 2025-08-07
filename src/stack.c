#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void count_elements(Stack *stack) {
    printf("Elements count: %d\n", stack->top_index + 1);
}

void initialize(Stack *stack) {
    stack->top_index = -1;
}

void push(Stack *stack, int value) {
    if(stack->top_index >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->elements[++stack->top_index] = value;
}

int pop(Stack *stack) {
    if(stack->top_index == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top_index--];
}

int peek(Stack *stack) {
    if(stack->top_index == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top_index];
}

void print(Stack *stack) {
    if(stack->top_index == -1) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("bottom->top: ");
    for(int i = 0; i <= stack->top_index; i++) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

void swap_top(Stack *stack) {
    if(stack->top_index < 1) {
        printf("Not enough elements to swap\n");
        return;
    }
    
    int temp = stack->elements[stack->top_index];
    stack->elements[stack->top_index] = stack->elements[stack->top_index - 1];
    stack->elements[stack->top_index - 1] = temp;
    
    printf("Swapped: %d and %d\n", 
           stack->elements[stack->top_index], 
           stack->elements[stack->top_index - 1]);
}

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
    stack_sort(stack, start, pivot_index - 1);
    stack_sort(stack, pivot_index + 1, end);
}

void delete(Stack *stack, int value) {
    if(stack->top_index == -1) {
        printf("Stack is empty\n");
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
        printf("Value %d not found\n", value);
        return;
    }

    for(int i = found_index; i < stack->top_index; i++) {
        stack->elements[i] = stack->elements[i + 1];
    }
    stack->top_index--;
}

void search(Stack *stack, int value) {
    if(stack->top_index == -1) {
        printf("Stack is empty\n");
        return;
    }

    int found_index = -1;
    for(int i = 0; i <= stack->top_index; i++) {
        if(stack->elements[i] == value) {
            found_index = i;
        }
    }

    if(found_index == -1) {
        printf("Value %d not found\n", value);
    } else {
        printf("Value %d found at index: %d\n", value, found_index);
    }
}

void reverse(Stack *stack) {
    if(stack->top_index == -1) {
        printf("Stack is empty\n");
        return;
    }

    for(int i = 0; i <= stack->top_index / 2; i++) {
        int temp = stack->elements[i];
        stack->elements[i] = stack->elements[stack->top_index - i];
        stack->elements[stack->top_index - i] = temp;
    }
}

int validate_arguments(int parsed_args, int expected_args) {
    if(parsed_args == expected_args) {
        return 1;
    }
    printf("Error: Invalid arguments\n");
    return 0;
}

void help_menu() {
    printf("\nAvailable commands:\n");
    printf("  push <value>  - Add value to stack\n");
    printf("  pop           - Remove top value\n");
    printf("  peek          - View top value\n");
    printf("  del <value>   - Delete specific value\n");
    printf("  count         - Show element count\n");
    printf("  swap          - Swap top two elements\n");
    printf("  reverse       - Reverse stack order\n");
    printf("  print         - Display stack contents\n");
    printf("  sort          - Sort stack\n");
    printf("  find <value>  - Search for value\n");
    printf("  help          - Show this menu\n");
    printf("  cls           - Clear screen\n");
    printf("  exit          - Quit program\n\n");
}
