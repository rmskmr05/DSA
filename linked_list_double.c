#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *prev, *next;
} node;

void init_dll(node **dl){
    *dl = NULL;
}

void add_dll(node **dll, int x){
    node *p, *q;
    q = *dll;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    if(q == NULL){                  // List is empty
        p->next = NULL;
        p->prev = NULL;
    }else{                          // List is not empty
        if(x > q->info){            // Right side of the current list pointer
            while(q->next != NULL && x > q->info)
                q = q->next;
            if(x > q->info){        // To add at last position of list
                p->next = NULL;
                p->prev = q;
                q->next = p;
            }else{                 // to add between two nodes
                p->prev = q->prev;
                p->next = q;
                q->prev->next = p;
                q->prev = p;
            }

        }else {                    // Left side of the current list pointer
            while(q->prev != NULL && x < q->info)
                q = q->prev;
            if(x < q->info){        // To insert at left most postion
                p->prev = NULL;
                p->next = q;
                q->prev = p;
            }else{                  // to insert between two node
                p->next = q->next;
                p->prev = q;
                q->next->prev = p;
                q->next = p;
            }
        }
    }
    *dll = p;
}

void traverse_dll(node *dll){
    node *p;
    p = dll;
    while(dll != NULL && p->prev != NULL)
        p = p->prev;

    while(p != NULL){
        printf("%d\t", p->info);
        p = p->next;
    }printf("\n");
}

int empty_dll(node *dl){
    return dl == NULL;
}

void clear_dll(node **dl){
    *dl = NULL;
}

void delete_dll(node **dl, int x){
    node *q;
    q = *dl;
    // Locate the deleting pointer
    if(q->info > x){                // value is left side current pointer
        while(q->prev != NULL && q->info != x)
            q = q->prev;
    }else{                          // value is Right side of current pointer or current pointer itself
        while(q->next != NULL && q->info != x)
            q = q->next;
    }
    if (q->info == x){
        if (q->next != NULL && q->prev != NULL){
            q->prev->next = q->next;
            q->next->prev = q->prev;
            *dl = q->next;
        }else if (q->next == NULL && q->prev == NULL){
            *dl = NULL;
        }else if(q->next == NULL){
            q->prev->next = NULL;
            *dl = q->prev;
        }else if(q->prev == NULL){
            q->next->prev = NULL;
            *dl = q->next;
        }
        free(q);
    }
}

int main()
{
    int choice, val;
    node *dll;
    init_dll(&dll);
    do{
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Print the List\n");
        printf("4. Check for Empty List\n");
        printf("5. Clear the List\n");
        printf("6. Exit\n");

        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\nEnter the value:");
            scanf("%d", &val);
            add_dll(&dll, val);
            break;
        case 2:
            if (!empty_dll(dll)){
                printf("\nDeleting Value:");
                scanf("%d", &val);
                delete_dll(&dll, val);
            }else{
                printf("\nList is Already Empty\n\n");
            }
            break;
        case 3:
            if(empty_dll(dll)){
                printf("\nList is Empty\n\n");
            }else{
                printf("List -> ");
                traverse_dll(dll);
            }
            break;
        case 4:
            if(empty_dll(dll)){
                printf("\nList is Empty\n\n");
            }else{
                printf("\nList is NOT Empty\n\n");
            }
            break;
        case 5:
            clear_dll(&dll);
            printf("\nList is Cleared\n");
            break;
        case 6:
            printf("THANK YOU, <BYE>");
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }while(choice != 6);

    return 0;
}
