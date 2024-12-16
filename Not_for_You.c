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

Node *remove_element(Node *head, int data) {
    if (head == NULL) {
        return head;
    }

    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *current_node = head;
    while (current_node->next != NULL && current_node->next->data != data) {
        current_node = current_node->next;
    }

    if (current_node->next == NULL) {
        return head;
    }

    Node *temp = current_node->next;
    current_node->next = current_node->next->next;
    free(temp);
    return head;
}

int main() {
    Node *head = NULL;

    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 23);
    head = append(head, 24);
    head = append(head, 50);

    // Remove the node with data 23
    head = remove_element(head, 50);

    print_linked_list(head);

    // Free the remaining nodes
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
