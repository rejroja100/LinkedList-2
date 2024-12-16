
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

void print_linked_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("data : %d\n", current_node->data);
        current_node = current_node->next;
    }
}

Node *append(Node *head, int item) {
    Node *new_node = creat_node(item, NULL);
    if (head == NULL) {
        return new_node;
    }

    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

void insert(Node *node, int item){
    Node *New_node = creat_node(item, node -> next);

    node -> next = New_node;
}

int main() {

    Node *n1, *n2, *n3, *head;

    n1 = creat_node(34, NULL);
    head = n1;
    n2 = append(head, 20);
    n3 = append(head, 23);
    insert(n2, 100);

    print_linked_list(head);

    // Free the remaining nodes
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
