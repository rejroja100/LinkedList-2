#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *creat_node(int item, Node *next){
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL){
        printf("Exception, memory is not allocated !!\n");
        exit(1);
    }

    new_node -> data = item;
    new_node -> next = next;

    return new_node;

}


int main(){
    Node *n;
    n = creat_node(10, NULL);

    printf("data = %d", n -> data);
}

