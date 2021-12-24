#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *next;
};
typedef struct Node node;

void initlist(node **l){
    *l = NULL;
}

int isemptylist(node *l){
    return l == NULL;
}

void addlist(node **l, int x){
    node *p, *q, *back;
    q = *l;
    back = *l;
    p = (node*)malloc(sizeof(node));
    p->info = x;
    if (q == NULL || q->info > x){
        *l = p;
        p->next = q;
    }else{
        while(q != NULL && x > q->info){
            back = q;
            q = q->next;
        }
        back->next = p;
        p->next = q;
    }
}

void traverselist(node *l){
    while (l != NULL){
        printf("%d\t", l->info);
        l = l->next;
    }printf("\n");
}

void deletelist(node **l, int x){
    node *q, *back;
    q = *l;
    back = *l;
    if(q->info == x){
        *l = q->next;
        free(q);
    }else{
        while(q != NULL && q->info != x){
            back = q;
            q = q->next;
        }
        if(q != NULL){
            back->next = q->next;
            free(q);
        }
    }
}

int main(){
    int choice, val;
    node *list;
    initlist(&list);
    do{
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Print the List\n");
        printf("4. Check for Empty List\n");
        printf("5. Exit\n");

        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\nEnter the value:");
            scanf("%d", &val);
            addlist(&list, val);
            break;
        case 2:
            if (!isemptylist(list)){
                printf("\nDeleting Value:");
                scanf("%d", &val);
                deletelist(&list, val);
            }else{
                printf("\nList is Already Empty\n");
            }
            break;
        case 3:
            if(isemptylist(list)){
                printf("\nList is Empty\n");
            }else{
                printf("List -> ");
                traverselist(list);
            }
            break;
        case 4:
            if(isemptylist(list)){
                printf("\nList is Empty\n");
            }else{
                printf("\nList is NOT Empty\n");
            }
            break;
        case 5:
            printf("THANK YOU, <BYE>");
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }while(choice != 5);
    return 0;
}
