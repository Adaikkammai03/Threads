#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head, *current, *newnode;  
void insertion(int data){
    newnode=(struct node *)malloc(sizeof(struct node *));  
    newnode->data=data;
    if (head==NULL)
        head=newnode;
    else if (data<head->data){
        newnode->next=head;
        head=newnode;}
    else{
        current=head;
        while(current->next!=NULL && current->next->data<data){
            current=current->next;}
        newnode->next=current->next;
        current->next=newnode;}}
void deletion(int data){
    if (head->data==data){
        newnode=head;
        head=head->next;
        free(newnode);}
    else{
        current=head;
        while(current->next!=NULL && current->next->data!=data)
            current=current->next;
        if (current->next){
            newnode=current->next;
            current->next=current->next->next;
            free(newnode);}}}
void reverse(){
    struct node *prev=NULL,*next;
    current=head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;}
    head=prev;}
void display(){
    current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;}}
int main(){
    printf("1.Insertion\n2.Deletion\n3.Reverse\n4.Display\n5.Exit");
    while(1){
        int n;
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:{
                int x;
                printf("\nEnter data to insert: ");
                scanf("%d",&x);
                insertion(x);
                break;}
            case 2:{
                int x;
                printf("\nEnter data to delete: ");
                scanf("%d",&x);
                deletion(x);
                break;}
            case 3:{
                reverse();
                break;}
            case 4:{
                display();
                break;}
            case 5:{
                exit(0);
                break;}
            default:{
                printf("\nInvalid choice!!!");}}}
    return 0;}
