#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev; 
    struct node *next; 
};

// Global head pointer
struct node *head = NULL;

struct node* create_node(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = item;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

void insert_at_beg()
{
    int item;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    struct node *ptr = create_node(item); 

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head; // New node points to the old head
        head->prev = ptr; // Old head points back to new node
        head = ptr; // Head now points to the new node
    }
}

void insert_at_end()
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
        struct node *ptr1 = head; // Pointer to traverse the list

        while (ptr1->next != NULL) // Traverse to the end of the list
        {
            ptr1 = ptr1->next;
        }

        ptr1->next = ptr; // Last node points to the new node
        ptr->prev = ptr1; // New node points back to the last node
    }
}

void insert_at_any()
{
    int item, pos;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    printf("Enter the position of new Node: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position. Position should be greater than 0.\n");
        return;
    }

    struct node *ptr = create_node(item); // Create and initialize new node
    
    if (pos == 1)
    {
        insert_at_beg(); // Insert at the beginning if position is 1
    }
    else
    {
        struct node *ptr1 = head;
        int count = 1;

        // Traverse to the node before the desired position
        while (ptr1 != NULL && count < pos - 1)
        {
            ptr1 = ptr1->next;
            count++;
        }

        if (ptr1 == NULL)
        {
            printf("Position does not exist.\n");
            free(ptr); // Free the newly created node if position is invalid
        }
        else
        {
            ptr->next = ptr1->next; // Set the new node's next to the next of the current node
            ptr->prev = ptr1; // Set the new node's prev to the current node

            if (ptr1->next != NULL) // Update the next node's prev to the new node, if not inserting at the end
            {
                ptr1->next->prev = ptr;
            }

            ptr1->next = ptr; // Update the current node's next to the new node
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
        head = ptr->next;

        if (head != NULL) // Update head's previous pointer if list is not empty after deletion
        {
            head->prev = NULL;
        }

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
    else if (head->next == NULL) // Single node case
    {
        struct node *ptr = head;
        head = NULL; // Set head to NULL since this is the only node
        printf("Deleted Node data: %d\n", ptr->data);
        free(ptr);
    }
    else
    {
        struct node *ptr1 = head;

        while (ptr1->next != NULL) // Traverse to the last node
        {
            ptr1 = ptr1->next;
        }

        ptr1->prev->next = NULL; // Update the second last node's next to NULL
        printf("Deleted Node data: %d\n", ptr1->data);
        free(ptr1); // Free the last node
    }
}

void delete_from_any()
{
    if (head == NULL)
    {
        printf("List does not exist.\n");
        return;
    }

    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position. Position should be greater than 0.\n");
        return;
    }

    if (pos == 1)
    {
        delete_from_beg(); // Use delete_from_beg for the first position
        return;
    }

    struct node *ptr1 = head;
    int count = 1;
    while (ptr1 != NULL && count < pos)
    {
        ptr1 = ptr1->next;
        count++;
    }

    if (ptr1 == NULL)
    {
        printf("Position does not exist.\n");
    }
    else
    {
        if (ptr1->prev != NULL)
        {
            ptr1->prev->next = ptr1->next; // Bypass the node
        }

        if (ptr1->next != NULL)
        {
            ptr1->next->prev = ptr1->prev; // Update the next node's prev if necessary
        }

        printf("Deleted Node data: %d\n", ptr1->data);
        free(ptr1); // Free the deleted node
    }
}

void display()
{
    struct node *ptr1 = head;

    if (ptr1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (ptr1 != NULL)
    {
        printf("%d <-> ", ptr1->data);
        ptr1 = ptr1->next;
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
            delete_from_any();
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
