/*
 * Title: Double Linked Lists
 * Author: Haider Ali Punjabi
 * Email: haideralipunjabi@hackesta.org
 * Date: 15-12-2018
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* HEAD = NULL;
int main()
{
    int ch,temp,temp2;
    while(1){
        system("cls");
        printf("1.Display\n2.Add Data\n3.Add Data at Position\n4.Delete By Data\n5.Delete By Pos\n6.Search by Data\n7.Search By Pos\n8.Exit\n");
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
            printf("Enter Value to Insert: ");
            scanf("%d",&temp);
            printf("Enter Position at which to Insert: ");
            scanf("%d", &temp2);
            addnodeatpos(temp,temp2);
            break;
        case 4:
            printf("Enter Data to Delete: ");
            scanf("%d", &temp);
            deletebydata(temp);
            break;
        case 5:
            printf("Enter Position to Delete: ");
            scanf("%d", &temp);
            deletebypos(temp);
            break;
        case 6:
            printf("Enter Data to Search: ");
            scanf("%d", &temp);
            temp = searchbydata(temp);
            if(temp == -1)
                printf("Data Not Found");
            else
                printf("Data Found at Position %d",temp);
            getch();
            break;
        case 7:
            printf("Enter Position to Search: ");
            scanf("%d", &temp);
            temp = searchbypos(temp);
            if(temp == NULL)
                printf("Position Not Found");
            else
                printf("Position Found with Data= %d",temp);
            getch();
            break;
        case 8:
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
    temp->prev = NULL;
    if(HEAD == NULL){
        HEAD = temp;
        return;
    }
    iter = HEAD;
    while(iter->next != NULL){
        iter=iter->next;
    }
    temp->prev = iter;
    iter->next = temp;
}
void addnodeatpos(int d,int p){
    if(p>size()){
        printf("Position Not Available. Adding at last position.\n");
        getch();
    }
    node *iter = HEAD, *iter2=NULL, *temp;
    int pos = 0;
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    temp->prev = NULL;
    while(pos != p && iter!=NULL){
        pos++;
        iter2 = iter;
        iter = iter->next;
    }
    if(p == 0 && HEAD==NULL){
        HEAD=temp;
        return;
    }
   // if(iter == NULL){
    //    printf("Invalid Position/n");
    //    getch();
    //   return;
    //}
    temp->next = iter;
    temp->prev = iter2;
    iter2->next = temp;
    if(iter!=NULL)
    {
        iter->prev = temp;
    }
}
void deletebydata(int d){
    node* iter = HEAD;
    while(iter != NULL){
        if(iter->data == d){
            if(iter == HEAD){
                iter->prev = NULL;
                HEAD = iter->next;
            }
            else{
                ((node *)(iter->prev))->next = iter->next;
                ((node *)iter->next)->prev = iter->prev;
            }
            printf("Data Deleted");
            getch();
            return;
        }
        iter = iter->next;
    }
    printf("Node not found with data %d", d);
    getch();
}
void deletebypos(int p){
    node* iter = HEAD;
    int pos = 0;
    while(iter != NULL){
        if(pos == p){
            if(iter == HEAD){
                iter->prev = NULL;
                HEAD = iter->next;
            }
            else{
                ((node *)iter->prev)->next = iter->next;
                ((node *)iter->next)->prev = iter->prev;
            }
            printf("Data Deleted");
            getch();
            return;
        }
        pos++;
        iter = iter->next;
    }
    printf("Node not found at position %d", p);
    getch();
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
    node *iter = HEAD;
    node *iter2 = NULL;
    printf("Head->Tail:\n");
    while(iter != NULL){
        printf("%d-->", iter->data);
        iter2 = iter;
        iter = iter->next;
    }
    printf("\nTail<-Head:\n");
    while(iter2 != NULL){
        printf("%<--%d", iter2->data);
        iter2 = iter2->prev;
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
