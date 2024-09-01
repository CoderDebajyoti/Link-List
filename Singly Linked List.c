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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));//ptr==new node
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
    free(ptr);
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
	free(ptr);
	free(ptr1);
}

void insert_at_any()
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));//new node
	struct node *ptr1 = (struct node *)malloc(sizeof(struct node));//pointer for traverse
    int item,pos;
    printf("Enter the data of new Node: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->link = NULL;
    printf("Enter the position of new Node: ");
    scanf("%d", &pos);
    if(ptr==NULL)
    {
    	printf("Not possible.");
    	break;
	}
	if(pos==1)
	{
		insert_at_beg();
	}
	else
	{
		int count=1;
		*ptr1 = head;
		while (ptr1 != NULL && count < pos-1)
    {
        ptr1 = ptr1->link;
        count = count +1;
    }
    
    if (ptr->link == && count != pos-1)
    {
    	printf("position not exist");
    	break;
	}
	ptr->link = ptr1->link;
	ptr1->link = ptr;
	printf("%d",ptr->data);
	free(ptr);
	free(ptr1);
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
