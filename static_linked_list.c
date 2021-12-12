#include<stdio.h>
#define N   5

typedef struct{
    int info;
    int next;
}node ;

void initlist(node *a, int *list, int *avail){
    int i;
    *list = -1;
    *avail = 0;
    for (i = 0; i < N-1; i++){
        a[i].next = i+1;
    }a[N-1].next = -1;
}

void traverselist(node *a, int list){
    while(list != -1){
        printf("%d\t", a[list].info);
        list = a[list].next;
    }printf("\n");
}

int fulllist(int avail){
    return avail == -1;
}

int emptylist(int list){
    return list == -1;
}

void addlist(node *a, int *list, int *avail, int x){
    int p, q, back;
    p = *avail;
    q = *list;
    back = *list;
    // A node from avail & update the avail pointer
    a[*avail].info = x;
    *avail = a[*avail].next;
    // if list is empty or new value is the smallest
    if(q == -1 || a[q].info >= x){
        *list = p;
        a[p].next = q;
    }else{
        // Search for the Element Postion
        while (q != -1 && x > a[q].info){
            back = q;
            q = a[q].next;
        }
        // Transfer the links
        a[back].next = p;
        a[p].next = q;
    }
}

int deletelist(node *a, int *list, int *avail, int x){
    int p, q, back;
    p = *avail;
    q = *list;
    back = *list;
    // first Element to delete
    if (a[q].info == x){
        *list = a[q].next;
        *avail = q;
        a[*avail].next = p;
        printf("\nElement Deleted.\n");
    }else{
        // find the location of deleting element
        while(1 != -1 && a[q].info != x){
            back = q;
            q = a[q].next;
        }
        if (q != -1){       // element found
            *avail = a[back].next;
            a[back].next = a[q].next; // delete the node from the list
            *avail = q;
            a[*avail].next = p;
            
            printf("\nElement Deleted.\n");
        }else{
            printf("\nElement NOT Found.\n");
        }
    }
}

int main(){

    printf("\nLinked List using Array\n");
    node a[N];
    int list, avail;
    initlist(a, &list, &avail);
    
    int choice, x;
    do
    {
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Print the List\n");
        printf("4. Check for Empty\n");
        printf("5. Check for Full\n");
        printf("6. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (!fulllist(avail)){
                printf("\nElement to Enter:");
                scanf("%d", &x);
                addlist(a, &list, &avail, x);
            }else{
                printf("\nList is already Full.\n");
            }
            break;
        case 2:
            if (!emptylist(list)){
                printf("\nElement to Delete:");
                scanf("%d", &x);
                deletelist(a, &list, &avail, x);
            }else{
                printf("\nList is already Empty.\n");
            }
            break;
        case 3:
            printf("\n Avail(%d)->", avail);
            traverselist(a, avail);
            printf("  List(%d)->", list);
            traverselist(a, list);
            break;
        case 4:
            printf("\nIs list Empty:%d\n", emptylist(list));
            break;
        case 5:
            printf("\nIs list Full:%d\n", fulllist(avail));
            break;
        case 6:
            printf("\n\nTHANK YOU, BYE.\n\n");
            break;
        default:
            printf("\nInvalid Choice.Choose again.\n");
            break;
        }

    } while (choice != 6);
    
    
    return 0;
}