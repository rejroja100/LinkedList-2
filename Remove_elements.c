#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

Node *creat_node(int item, Node *next) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Exception, memory is not allocated !!\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *Prepend(Node *head, int item) {
    Node *new_node = creat_node(item, head);
    return new_node;
}

Node *remove_element(Node *head, Node *node) {
    if (node == head) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *current_node = head;
    while (current_node != NULL && current_node->next != node) {
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return head;
    }

    Node *temp = current_node->next;
    current_node->next = current_node->next->next;
    free(temp);
    return head;
}



int main() {
    Node *head = NULL;

    head = Prepend(head, 10);
    head = Prepend(head, 20);
    head = Prepend(head, 30);

    Node *current = head;
    while (current != NULL) {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

