#include <stdio.h>
#include <stdlib.h> //malloc, free

int arr[10]; //40 bytes

typedef struct Node{ 
    int data;
    struct Node* next;
} Node;

Node* head;//16 bytes

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));//reservamos memoria para nuestro Node
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}


void add_node(Node* node) {
    if (head == NULL) { //lista vacia
        head = node;
        return;
    } 
    if (head != NULL) //recorrer la lista
    {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void remove_node(int value) {
    Node* current = head;
    while (current)
    {
        printf("%d\n", current->data);

        if(current->next->data == value) {

            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;

        }
        current = current->next;
    }
}

void free_list() {
    Node* current = head;
    while (current)
    {
        Node* temp = current;
        current = current->next; //0x0
        free(temp);
    }
    
}


int main() {

    //head = create_node(10);
    while (1)
    {
        /* code */
        
        printf("Agrega un valor int\n");
        int value;
        scanf("%d", &value);
        if(value == -1) {
            printf("Elimina un nodo con valor:\n");
            scanf("%d", &value);
            remove_node(value);
            continue;
        }
        add_node(create_node(value));
        
        printf("Lista enlazada:\n");
        Node* current = head;
        while (current)
        {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
    free_list();
    return 0;
}