#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *next;
	int data;
};

void insertAtEnd(struct node **head, int data);

int main()
{
	struct node *head = NULL;
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 30);
	
	while(head->next != NULL)
	{
		printf("%d",head->data);
		printf("\t");
		head = head->next;
	}
	
	return 0;

}

void insertAtEnd(struct node **head, int data)
{
	struct node *new_node, *temp;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	temp = *head;
	
	if(NULL == *head)
	{
		*head = new_node;
		(*head)->next = NULL;
	}
	else
	{
		while(NULL != temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
