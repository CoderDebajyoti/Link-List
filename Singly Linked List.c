#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Global head pointer
struct node *head = NULL;

// Function to create and initialize a new node
struct node* create_node(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) // Check if memory allocation was successful
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = item;
    ptr->link = NULL;
    return ptr;
}

void insert_at_beg()
{
    int item;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    struct node *ptr = create_node(item); // Create and initialize new node

    if (head == NULL)
    {
        head = ptr; // Empty list
    }
    else
    {
        ptr->link = head; // New node points to old head
        head = ptr; // Head now points to the new node
    }
}

void insert_at_end()
{
    int item;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    struct node *ptr = create_node(item); // Create and initialize new node
    struct node *ptr1 = head; // Pointer to traverse the list
    
    if (head == NULL)
    {
        head = ptr; // Empty list
    }
    else
    {
        while (ptr1->link != NULL) // Traverse to the end of the list
        {
            ptr1 = ptr1->link;
        }
        ptr1->link = ptr; // Last node points to new node
    }
}

void insert_at_any()
{
    int item, pos;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    printf("Enter the position of new Node: ");
    scanf("%d", &pos);
    
    struct node *ptr = create_node(item); // Create and initialize new node
    struct node *ptr1 = head; // Pointer for traversal

    if (pos == 1)
    {
        insert_at_beg(); // Insert at beginning if position is 1
    }
    else
    {
        int count = 1;
        while (ptr1 != NULL && count < pos - 1)
        {
            ptr1 = ptr1->link;
            count++;
        }
        
        if (ptr1 == NULL)
        {
            printf("Position does not exist.\n");
        }
        else
        {
            ptr->link = ptr1->link;
            ptr1->link = ptr;
        }
    }
}

void delete_from_beg()
{
    if (head == NULL)
    {
        printf("List does not exist.\n");
    }
    else
    {
        struct node *ptr = head; // Pointer to the node to be deleted
        head = ptr->link;
        printf("Deleted Node data: %d\n", ptr->data);
        free(ptr);
    }
}

void delete_from_end()
{
    if (head == NULL)
    {
        printf("List does not exist.\n");
    }
    else if (head->link == NULL) // Single node case
    {
        struct node *ptr = head;
        head = NULL; // Set head to NULL since this is the only node
        printf("Deleted Node data: %d\n", ptr->data);
        free(ptr);
    }
    else
    {
        struct node *ptr1 = head;
        while (ptr1->link->link != NULL) // Traverse to the second last node
        {
            ptr1 = ptr1->link;
        }
        struct node *ptr = ptr1->link; // Last node to be deleted
        ptr1->link = NULL; // Second last node becomes the last node
        printf("Deleted Node data: %d\n", ptr->data);
        free(ptr); // Free the last node
    }
}

void delete_from_any()
{
    if (head == NULL)
    {
        printf("List does not exist.\n");
        return;
    }
    
    // Take position
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_from_beg(); // Use the delete_from_beg function for the first position
        return;
    }

    struct node *ptr1 = head; // Pointer for traversal
    struct node *ptr = NULL;  // Pointer to the node to be deleted
    int count = 1;

    // Traverse to the node just before the position
    while (ptr1 != NULL && count < pos - 1)
    {
        ptr1 = ptr1->link;
        count++;
    }

    // Check if the position is valid
    if (ptr1 == NULL || ptr1->link == NULL)
    {
        printf("Position does not exist.\n");
    }
    else
    {
        ptr = ptr1->link; // Node to be deleted
        ptr1->link = ptr->link; // Bypass the node
        printf("Deleted Node data: %d\n", ptr->data);
        free(ptr); // Free the deleted node
    }
}


void display()
{
    struct node *ptr1 = head;
    while (ptr1 != NULL)
    {
        printf("%d -> ", ptr1->data);
        ptr1 = ptr1->link;
    }
    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at any position\n4. Delete from Beginning\n5. Delete at End\n6. Delete at any position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_end();
            break;    
        case 3:
            insert_at_any();
            break;  
        case 4:
            delete_from_beg();
            break; 
        case 5:
            delete_from_end();
            break;
        case 6:
            delete_at_any();
            break; 
        case 7:
            display();
            break;
        case 8:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8); // Exit the loop when choice is 8

    return 0;
}
