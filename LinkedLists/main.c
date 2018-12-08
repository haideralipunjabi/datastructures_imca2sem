/*
 * Title: Linked Lists
 * Author: Haider Ali Punjabi
 * Email: haideralipunjabi@hackesta.org
 * Date: 08-12-2018
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data;
    struct node* next;
}node;

node* HEAD = NULL;
int main()
{
    int ch,temp;
    while(1){
        system("cls");
        printf("1.Display\n2.Add Data\n3.Delete\n4.Exit\n");
        printf("Enter Option: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            display();
            break;
        case 2:
            printf("Enter Value to Insert: ");
            scanf("%d", &temp);
            addnode(temp);
            break;
        case 3:
            deletenode();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Error: Wrong Input, Try Again!");
            getch();
            break;
        }
    }
}


void addnode(int d,int pos){
    printf("%d",pos);
    node *iter, *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    if(HEAD == NULL){
        HEAD = temp;
        return;
    }
    iter = HEAD;
    while(iter->next != NULL){
        iter=iter->next;
    }
    iter->next = temp;
}

void deletenode(){
    node* iter = HEAD;
    node *temp;
    while(iter->next != NULL){
        temp=iter->next;
        if(temp->next == NULL){
            iter->next = NULL;
            return;
        }
        iter = temp;
    }
    HEAD = NULL;
}

void display(){
    printf("Size:%d\n", size());
    node *temp = HEAD;
    while(temp != NULL){
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    getch();
}

int size(){
    int s = 0;
    node *temp = HEAD;
    while(temp != NULL){
        s++;
        temp = temp->next;
    }
    return s;
}
