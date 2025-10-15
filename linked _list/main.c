#include <stdio.h>
#include <stdlib.h> //malloc, free

//int arr[10]; //40 bytes

typedef struct Node{ 
    int data;
    struct Node* next;
    struct Node* prev;    
} Node;

Node* head = NULL;//16 bytes

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));//reservamos memoria para nuestro Node
    if (!new_node) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
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
        node->prev = current;
    }
}

void remove_node(int value) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next; // si es el primer nodo
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
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

void print_reverse() {
    Node* current = head;
    if (!current) return;
    while (current->next) {
        current = current->next;
    }
    printf("\nLista en reversa:");
    while (current) {
        printf("%d\n", current->data);
        current = current->prev;
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
        if (value == -999) {
            break;
        }
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
        print_reverse();
    }
    free_list();
    return 0;
}
