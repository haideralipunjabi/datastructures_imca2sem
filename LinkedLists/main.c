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
        printf("1.Display\n2.Add Data\n3.Delete By Data\n4.Delete By Pos\n5.Search by Data\n6.Search By Pos\n7.Exit\n");
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
            printf("Enter Data to Delete: ");
            scanf("%d", &temp);
            deletebydata(temp);
            break;
        case 4:
            printf("Enter Position to Delete: ");
            scanf("%d", &temp);
            deletebypos(temp);
            break;
        case 5:
            printf("Enter Data to Search: ");
            scanf("%d", &temp);
            temp = searchbydata(temp);
            if(temp == -1)
                printf("Data Not Found");
            else
                printf("Data Found at Position %d",temp);
            getch();
            break;
        case 6:
            printf("Enter Position to Search: ");
            scanf("%d", &temp);
            temp = searchbypos(temp);
            if(temp == NULL)
                printf("Position Not Found");
            else
                printf("Position Found with Data= %d",temp);
            getch();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Error: Wrong Input, Try Again!");
            getch();
            break;
        }
    }
}


void addnode(int d){
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

void deletebydata(int d){
    node* iter = HEAD;
    node* prev;
    while(iter != NULL){
        if(iter->data == d){
            if(iter == HEAD){
                HEAD = iter->next;

            }
            else{
                prev->next = iter->next;
            }
            printf("Data Deleted");
            getch();
            return;
        }
        prev = iter;
        iter = iter->next;
    }

}
void deletebypos(int p){
    node* iter = HEAD;
    node* prev;
    int pos = 0;
    while(iter != NULL){
        if(pos == p){
            if(iter == HEAD){
                HEAD = iter->next;

            }
            else{
                prev->next = iter->next;
            }
            printf("Data Deleted");
            getch();
            return;
        }
        pos++;
        prev = iter;
        iter = iter->next;
    }
}

int searchbydata(int d){
    node* iter = HEAD;
    int pos = 0;
    while(iter != NULL){
        if(iter->data == d){
            return pos;
        }
        pos++;
        iter = iter->next;
    }
    return -1;
}

int searchbypos(int p){
    node* iter = HEAD;
    int pos = 0;
    while(iter != NULL){
        if(pos == p){
            return iter->data;
        }
        pos++;
        iter = iter->next;
    }
    return NULL;
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
