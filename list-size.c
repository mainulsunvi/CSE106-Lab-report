// Call a function that will generate the size of the singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct N
{
	int Data;
	struct N *Next;
};
typedef struct N node;

void creatList(struct N *head)
{
	node *temp;
	char C[100];
	temp = head;

	printf("Enter numbers to create and store in Linked List, to stop storing enter 'x'\n");
	while (1)
	{
		printf("Enter The Values: ");
		scanf("%s", C);
		if (C[0] != ' ')
		{
			if (C[0] != 'x')
			{
				temp->Data = atoi(C);
				temp->Next = (node *)malloc(sizeof(node));
				temp = temp->Next;
				temp->Next = NULL;
			}
			else
				break;
		}
	}
	temp = head;
}

void getLength(struct N *head)
{
	int count = 0;
	node *temp;

	temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->Next;
	}
	printf("The List Size is: %d", count - 1);
}

void ListPrint(struct N *head)
{
	printf("The elements in the Linked List are:");
	while (head->Next != NULL)
	{
		printf(" %d", head->Data);
		head = head->Next;
	}
	printf(".\n");
}

void main()
{
	node *head;
	head = (node *)malloc(sizeof(node));

	creatList(head);
	ListPrint(head);
	getLength(head);
}