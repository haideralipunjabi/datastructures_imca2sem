/*
    Title: Queue Implementation using Arrays
    Author: Haider Ali Punjabi
    EMail: haideralipunjabi@hackesta.org
    Date: 14/11/2018
*/

#include <stdio.h>
#include <stdlib.h>

int Q[4];
int max = 3;
int front = -1;
int rear = -1;
int main()
{
    int ch, val;
    while(1){
        system("cls");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter Value to Push: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
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

void enqueue(int item){
    if(rear == max || rear == front - 1){
        // Stack Overflow
        printf("Stack Overflow!");
        return;
    }
    else if(rear == -1 && front == -1){
        // Empty Queue
        rear++;
        front++;
    }
    else if(front != 0 && rear == max){
        rear = 0;
    }
    else {
        rear++;
    }

    Q[rear] = item;

}

void dequeue(){

}

void display(){
    int i = front;
    while(i != rear){
        printf("%d | ", Q[i]);

        if(i == max){
            i =0;
        }
        else{
            i++;
        }
        if(i==rear){
            printf("%d | ", Q[i]);
        }
    }
}
