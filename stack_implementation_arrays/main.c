/*
    Title: Stack Implementation using Arrays
    Author: Haider Ali Punjabi
    EMail: haideralipunjabi@hackesta.org
    Date: 14/11/2018
*/

#include <stdio.h>
#include <stdlib.h>

int stk[20];
int top = -1;
int main()
{
    int ch, val;
    while(1){
        system("cls");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter Value to Push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice. Try Again.");
            break;
        }
        getch();
    }
}

void push(int item){
    if(top == 19){
        printf("Stack Overflow!!!");
        return;
    }
    top++;
    stk[top] = item;
    printf("Pushed to Stack");
}

int pop(){
    int item;
    if(top == -1){
        printf("Stack Underflow!!!");
        return;
    }
    item = stk[top];
    top--;
    printf("Item |%d| popped from Stack", item);
    return item;
}

void display(){
    int count;
    if(top == -1){
        printf("Stack Empty!!!");
        return;
    }
    for(count=top;count>=0;count--){
        printf("%d | ", stk[count]);
    }
}
