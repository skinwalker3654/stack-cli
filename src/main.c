#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack my_stack;
    initialize(&my_stack);
    
    char user_input[50];
    char command[10];
    int value;

    while(1) {
        printf("Prompt@~> ");
        if(fgets(user_input, sizeof(user_input), stdin) == NULL) {
            printf("Input error\n");
            continue;
        }

        user_input[strcspn(user_input, "\n")] = '\0';
        if(strlen(user_input) == 0) continue;
        
        int args_parsed = sscanf(user_input, "%s %d", command, &value);

        if(strcmp(command, "push") == 0) {
            if(validate_arguments(args_parsed, 2)) {
                push(&my_stack, value);
                printf("Pushed: %d\n", value);
            }
        }
        else if(strcmp(command, "pop") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                printf("Popped: %d\n",pop(&my_stack));
            }
        }
        else if(strcmp(command, "peek") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                printf("Top element: %d\n",peek(&my_stack));
            }
        }
        else if(strcmp(command, "print") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                print(&my_stack);
            }
        }
        else if(strcmp(command, "count") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                count_elements(&my_stack);
            }
        }
        else if(strcmp(command, "swap") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                swap_top(&my_stack);
            }
        }
        else if(strcmp(command, "sort") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                sort(&my_stack, 0, my_stack.top_index);
                printf("Stack is now sorted\n");
            }
        }
        else if(strcmp(command, "reverse") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                reverse(&my_stack);
                printf("Stack is now reversed\n");
            }
        }
        else if(strcmp(command, "del") == 0) {
            if(validate_arguments(args_parsed, 2)) {
                delete_(&my_stack, value);
                printf("Deleted: %d\n",value);
            }
        }
        else if(strcmp(command, "find") == 0) {
            if(validate_arguments(args_parsed, 2)) {
                search(&my_stack,value);
            }
        }
        else if(strcmp(command, "help") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                help_menu();
            }
        }
        else if(strcmp(command, "cls") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                system("clear"); 
            }
        }
        else if(strcmp(command, "exit") == 0) {
            if(validate_arguments(args_parsed, 1)) {
                printf("Exiting...\n"); 
                break;
            }
        }
        else {
            printf("Unknown command: '%s'\n", command);
            printf("Type 'help' for available commands\n");
        }
    }

    return 0;
}
