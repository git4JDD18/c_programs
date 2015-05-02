#include<stdlib.h>
#include<stdio.h>

struct node{
	struct node *prev;
	struct node *next;
	int data;
};

void Print(struct node *head);
struct node* InsertAtHead(struct node *head, int data);
struct node* InsertAtTail(struct node *head, int data);
struct node* sortedInsert(struct node *head, int data);

int main()
{
	struct node *head = NULL;
	head = InsertAtHead(head, 4);
	Print(head); 
	head = InsertAtHead(head, 2);
	Print(head); 
	head = InsertAtHead(head, 1);
	Print(head); 
	head = InsertAtTail(head, 5); 
	Print(head); 
	head = InsertAtTail(head, 6); 
	Print(head); 
	head = InsertAtTail(head, 8); 
	Print(head); 
	head = InsertAtTail(head, 9); 
	Print(head);
	head = sortedInsert(head, 3);
	Print(head);
	head = sortedInsert(head, 7);
	Print(head);
	head = sortedInsert(head, 10);
	Print(head);
	return 0;
}

void Print(struct node *head) 
{
	struct node *temp = head;
	printf("Forward: ");
	while(temp != NULL) 
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
} 

struct node* InsertAtHead(struct node *head, int data)
{
	struct node *newNode,*currentNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;
	currentNode = head;
	
	if(NULL == head)
	{
		head = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	return head;
}

struct node* InsertAtTail(struct node *head, int data)
{
	struct node *newNode,*currentNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;
	
	currentNode = head;
	
	if(NULL == head)
	{
		head = newNode;
	}
	else
	{
		while(NULL != currentNode->next)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		newNode->prev = currentNode;
		
	}
	return head;
}

struct node* sortedInsert(struct node *head, int data)
{
	struct node *newNode, *currentNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;
	currentNode = head;
	
	if(NULL == head)
	{
		head = newNode;
	}
	if(currentNode-> data > data)
	{
		newNode->next = currentNode;
		currentNode->prev = newNode;
		head = newNode;
	}
	else 
	{
		while(currentNode->next != NULL)
		{
			if(currentNode->data < data && currentNode->next->data > data)
			{
				newNode->next = currentNode->next;
				currentNode->next->prev = newNode;
				currentNode->next = newNode;
				newNode->prev = currentNode;
				break;
				
			}
			currentNode = currentNode->next;
		}
		if(currentNode->next == NULL)
		{
			currentNode->next = newNode;
			newNode->prev = currentNode;
		}
	}
	return head;
	
}
