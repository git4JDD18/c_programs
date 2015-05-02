#include<stdlib.h>
#include<stdio.h>

struct node{
	struct node *next;
	int data;
};

struct node* sortedInsert(struct node *head, int data);

int main()
{
	
	struct node *head = NULL;
	head = sortedInsert(head, 10);
	head = sortedInsert(head, 20);
	head = sortedInsert(head, 30);
	head = sortedInsert(head, 40);
	head = sortedInsert(head, 50);
	head = sortedInsert(head, 35);
	head = sortedInsert(head, 65);
	//printf("%d",head->data);
	
	while(head->next!= NULL)
	{
		printf("%d",head->data);
		printf("\t");
		head = head->next;
	}
	printf("%d",head->data);
	return 0;
	
}


/* Assumption: List is sorted */
struct node* sortedInsert(struct node *head, int data)
{
	struct node *currentNode, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	currentNode = head;
	printf("%d \n", data);
	if(head == NULL)
	{
		head = newNode;
	}
	else if((newNode->data)<(currentNode->data ))
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		printf("test0 \n");
		while(currentNode->next != NULL)
		{
			printf("test1 \n");
			if((currentNode->data) < (newNode->data) && (currentNode->next->data) > (newNode->data))
			{
				printf("test2===== \n");
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				printf("************ \n");
				printf("%d \n", currentNode->next->data);
				break;
			}
			printf("test3=====\n");
			currentNode = currentNode->next;
		}
		
		if(NULL == (currentNode->next))
		{
			currentNode->next = newNode;
		}
	}
	
	return head;
	
}
