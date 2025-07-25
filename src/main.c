#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack s;
    init(&s);
    
    char input[50];
    char command[10];
    int value;

    while(1) {
        printf("prompt@> ");
        if(fgets(input,sizeof(input),stdin)==NULL) {
            printf("Error: Input failure\n");
            continue;
        }

        input[strcspn(input,"\n")] = 0;
        if(strlen(input)==0) {continue;}
        int persed = sscanf(input,"%s %d",command,&value);

        if(strcmp(command,"push")==0) {
            if(persed != 2) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                push(&s,value);
                printf("Value %d pushed into the stack\n",value);
            }
        } else if(strcmp(command,"del")==0) {
            if(persed != 2) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                delete_(&s,value);
                printf("Value %d deleted from the stack\n",value);
            }
        } else if(strcmp(command,"find")==0) {
            if(persed != 2) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                find(&s,value);
            }
        } else if(strcmp(command,"pop")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                printf("Top element deleted: %d\n",pop(&s));
            }
        } else if(strcmp(command,"peek")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                printf("Top element: %d\n",peek(&s));
            }
        } else if(strcmp(command,"print")==0) {
            if(persed != 1) {
                printf("Invalid arguments passed\n");
                continue;
            } else {
                print(&s);
            }
        } else if(strcmp(command,"count")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                count(&s);
            }
        } else if(strcmp(command,"swap")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                swap(&s);
            }
        } else if(strcmp(command,"sort")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                sort(&s,0,s.top);
                printf("Stack is sorted\n");
            }
        } else if(strcmp(command,"cls")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                system("clear");
            }
        } else if(strcmp(command,"exit")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                printf("Exiting The Program...\n");
                return 0;
            }
        } else if(strcmp(command,"help")==0) {
            if(persed != 1) {
                printf("Error: Invalid arguments passed\n");
                continue;
            } else {
                print_commands();
            }
        } else {
            printf("Error invalid command: '%s'\n",command);
            printf("Type: 'help'to see the invalid commands\n");
            continue;
        }
    }
    return 0;
}
