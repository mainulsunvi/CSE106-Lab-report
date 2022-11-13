// Find the specific node of an element that is present or not in the singly linked list.

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

void listSearch(struct node *head, int num)
{
	int count = 0;
	struct node *ptr = NULL;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == num)
		{
			printf("Item Found");
			count = 1;
		}
		ptr = ptr->next;
	}
	if (count != 1)
		printf("Search again, Item not Found!");

	return;
}

void ListPrint(struct node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int main()
{
	int ListSize, S_key;
	printf("Enter the List Size: ");
	scanf("%d", &ListSize);

	struct node *head = (struct node *)malloc(sizeof(struct node *));

	createnodeList(head, ListSize);
	ListPrint(head);

	printf("Enter the Search value: ");
	scanf("%d", &S_key);
	listSearch(head, S_key);
}
