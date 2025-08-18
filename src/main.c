#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "stack.h"

void handler(int sig) {
    printf(YELLOW "\nClosing the program...\n" RESET);
    usleep(500000);
    exit(1);
}

int main() {
    Stack my_stack;
    initialize(&my_stack);
    
    char user_input[50];
    char command[10];
    int value;

    while(1) {
        signal(SIGINT, handler);
        printf(CYAN "Prompt@~> " RESET); //getting input
        if(fgets(user_input, sizeof(user_input), stdin) == NULL) {
                printf("Input error\n");
                continue;
        }

        user_input[strcspn(user_input, "\n")] = '\0'; 
        if(strlen(user_input) == 0) continue;
        int args_parsed = sscanf(user_input, "%s %d", command, &value); //parsing commands

        if(strcmp(command, "push") == 0) { //push
            if(IsValid_Arg(args_parsed, 2)) {
                    push(&my_stack, value);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "pop") == 0) { //pop
            if(IsValid_Arg(args_parsed, 1)) {
                    pop(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "peek") == 0) { //peek
            if(IsValid_Arg(args_parsed, 1)) {
                    peek(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "print") == 0) { //print
            if(IsValid_Arg(args_parsed, 1)) {
                    print(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "count") == 0) { //count
            if(IsValid_Arg(args_parsed, 1)) {
                    count_elements(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "swap") == 0) { //swap
            if(IsValid_Arg(args_parsed, 1)) {
                    swap_top(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "sort") == 0) { //sort
            if(IsValid_Arg(args_parsed, 1)) {
                    sort(&my_stack, 0, my_stack.top_index);
                    printf(GREEN "Stack is now sorted\n" RESET);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "reverse") == 0) { //reverse
            if(IsValid_Arg(args_parsed, 1)) {
                    reverse(&my_stack);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "del") == 0) { //del
            if(IsValid_Arg(args_parsed, 2)) { 
                    delete_(&my_stack, value);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "find") == 0) { //find
            if(IsValid_Arg(args_parsed, 2)) {
                    search(&my_stack,value);
            }
            save_history(user_input);
        }
        else if(strcmp(command, "help") == 0) { //help
            if(IsValid_Arg(args_parsed, 1)) {
                    help_menu();
            }
            save_history(user_input);
        }
        else if(strcmp(command,"history") == 0) { //history
            if(IsValid_Arg(args_parsed, 1)) {
                    print_history();
            }
        }
        else if(strcmp(command, "cls") == 0) { //cls
            if(IsValid_Arg(args_parsed, 1)) {
                    system("clear"); 
            }
            save_history(user_input);
        }
        else if(strcmp(command, "exit") == 0) { //exit
            if(IsValid_Arg(args_parsed, 1)) {
                    printf(YELLOW "Exiting...\n" RESET); 
                    usleep(500000);
                    break;
            }
            save_history(user_input);
        }
        else {
            printf(RED "Unknown command: '%s'\n" RESET, command);
            printf(RED "Type 'help' for available commands\n" RESET);
            save_history(user_input);
        }
    }

    return 0;
}
