// Insert element between any specific position of the singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *createnodeList(struct node *head, int totalnodes)
{
	int i, values;
	struct node *temp;

	for (i = 0; i < totalnodes; i++)
	{
		if (i == 0)
		{
			printf("Enter The Value: ");
			scanf("%d", &values);

			head->data = values;
			if (totalnodes == 1)
				head->next = NULL;
			temp = head;
		}
		else
		{
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			temp->next = newNode;
			printf("Enter The Value: ");
			scanf("%d", &values);

			newNode->data = values;
			newNode->next = NULL;
			temp = newNode;
		}
	}
	return head;
}

void insMid(struct node *head, int values, int pos)
{
	struct node *ptr = head;
	struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
	ptr2->data = values;
	ptr2->next = NULL;

	pos--;
	while(pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}
	ptr2->next = ptr->next;
	ptr->next = ptr2;
}

void ListPrint(struct node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	int ListSize, value, pos;
	printf("Enter the List Size: ");
	scanf("%d", &ListSize);

	struct node *head = (struct node *)malloc(sizeof(struct node *));

	createnodeList(head, ListSize);
	ListPrint(head);

	printf("Enter the Position: ");
	scanf("%d", &pos);
	printf("Enter the New Value: ");
	scanf("%d", &value);

	insMid(head, value, pos);
	ListPrint(head);
}
