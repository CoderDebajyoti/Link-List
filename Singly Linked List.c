#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Global head pointer
struct node *head = NULL;

void insert_at_beg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->link = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->link = head;
        head = ptr;
    }
}

void insert_at_end()
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->link = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else if(head->link == NULL)
    {
    	head->link=ptr;
	}
	else
	{
		ptr1 = head;
		while(ptr1->link != NULL)
		{
			ptr1=ptr1->link;
		}
		ptr1->link=ptr;
	}
}

void insert_at_any()
{
	
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
        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at any position\n7. Display\n8. Exit\n");
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
            //delete_at_beg();
            break; 
		    case 5:
            //delete_at_end();
            break;
		    case 6:
            //delete_at_any();
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
    } while (1);

    return 0;
}
