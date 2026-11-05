/* write a menu driven program in c to perform following 
operations an doubly link list
a) create list
b) traverse list in forward and reverse order
c) insert a node at pth position
d) delete node from pth position of the list 
e) search a specific item in list
*/



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}
void forward()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void reverse()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
void insert()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(pos == 1)
    {
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;

        head = newnode;
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}
void delete()
{
    struct node *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = head;

    if(pos == 1)
    {
        head = head->next;

        if(head != NULL)
            head->prev = NULL;

        free(temp);
        return;
    }

    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position");
        return;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
void search()
{
    struct node *temp = head;
    int item, pos = 1;

    printf("Enter item to search: ");
    scanf("%d", &item);

    while(temp != NULL)
    {
        if(temp->data == item)
        {
            printf("Item found at position %d", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Item not found");
}
int main()
{
    int choice;

    while(1)
    {
        printf("\n\n--- DOUBLY LINKED LIST ---");
        printf("\n1. Create List");
        printf("\n2. Forward Traversal");
        printf("\n3. Reverse Traversal");
        printf("\n4. Insert at Pth Position");
        printf("\n5. Delete from Pth Position");
        printf("\n6. Search an Item");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                forward();
                break;

            case 3:
                reverse();
                break;

            case 4:
                insert();
                break;

            case 5:
                delete();
                break;

            case 6:
                search();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
