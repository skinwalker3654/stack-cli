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
        printf("prompt@~> ");
        if(fgets(input,sizeof(input),stdin)==NULL) {
            printf("Error: Input failure\n");
            continue;
        }

        input[strcspn(input,"\n")] = 0;
        if(strlen(input)==0) {continue;}
        int persed = sscanf(input,"%s %d",command,&value);

        if(strcmp(command,"push")==0) { //push
            if(parser(persed,2)==1) {
                push(&s,value);
                printf("Value %d pushed into the stack\n",value);
            }
        } else if(strcmp(command,"del")==0) { //del
            if(parser(persed,2)==1) {
                delete_(&s,value);
                printf("Value %d deleted from the stack\n",value);
            }
        } else if(strcmp(command,"find")==0) { //find
            if(parser(persed,2)==1) {find(&s,value);}
        } else if(strcmp(command,"pop")==0) { //pop
            if(parser(persed,1)==1) {printf("Top element deleted: %d\n",pop(&s));}
        } else if(strcmp(command,"peek")==0) { //peek
            if(parser(persed,1)==1) {printf("Top element: %d\n",peek(&s));}
        } else if(strcmp(command,"print")==0) { //print
            if(parser(persed,1)==1) {print(&s);}
        } else if(strcmp(command,"count")==0) { //count
            if(parser(persed,1)==1) {count(&s);}
        } else if(strcmp(command,"swap")==0) { //swap
            if(parser(persed,1)==1) {swap(&s);}
        } else if(strcmp(command,"sort")==0) { //sort
            if(parser(persed,1)==1) {
                sort(&s,0,s.top);
                printf("Stack is sorted\n");
            }
        } else if(strcmp(command,"cls")==0) { //cls
            if(parser(persed,1)==1) {system("clear");}
        } else if(strcmp(command,"reverse")==0) { //reverse
            if(parser(persed,1)==1) {
                reverse(&s);
                printf("Stack is reversed\n");
            }
        } else if(strcmp(command,"exit")==0) { //exit
            if(parser(persed,1)==1) {
                printf("Exiting The Program...\n");
                return 0;
            }
        } else if(strcmp(command,"help")==0) { //help
            if(parser(persed,1)==1) {print_commands();}
        } else {
            printf("Error invalid command: '%s'\n",command);
            printf("Type: 'help'to see the invalid commands\n");
            continue;
        }
    }
    return 0;
}
