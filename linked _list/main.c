#include <stdio.h>

int arr[10]; //40 bytes

typedef struct Node{ 
    int data;
    struct Node* next;
} Node;

int main() {
    Node n1; 
    Node n2; 
    Node n3;

    n1.data = 10;
    n2.data = 20;
    n3.data = 30;


    Node* head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL; // 0x0

    // printf("Head Node: %d\n", head->data);
    // printf("Second Node: %d\n", head->next->data);
    // printf("Third Node: %d\n", head->next->next->data);


    Node n4;
    n4.data = 40;
    n4.next = NULL;

    n3.next = &n4;

    // printf("Fourth Node: %d\n", head->next->next->next->data);

    Node* current = head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    

    return 0;
}