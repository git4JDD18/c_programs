#include<stdlib.h>
#include<stdio.h>


struct node{
	struct node *next;
	int data;
};

struct node* sortedInsert(struct node *head, int data);
struct node* nodeRemove(struct node *head, int data);

int main()
{
	
	struct node *head = NULL, *myPtr;
	
	
	head = sortedInsert(head, 10);
	head = sortedInsert(head, 20);
	head = sortedInsert(head, 30);
	head = sortedInsert(head, 40);
	head = sortedInsert(head, 50);
	head = sortedInsert(head, 35);
	head = sortedInsert(head, 65);
	//printf("%d",head->data);
	myPtr = head;
	while(myPtr->next!= NULL)
	{
		printf("%d",myPtr->data);
		printf("\t");
		myPtr = myPtr->next;
	}
	printf("%d \n",myPtr->data);
	
	
	//head = nodeRemove(head, 10);
	//head = nodeRemove(head, 35);
	head = nodeRemove(head, 65);
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

struct node* sortedInsert(struct node *head, int data)
{
	struct node *currentNode, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	currentNode = head;
	
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
		
		while(currentNode->next != NULL)
		{
			
			if((currentNode->data) < (newNode->data) && (currentNode->next->data) > (newNode->data))
			{
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				break;
			}
			
			currentNode = currentNode->next;
		}
		
		if(NULL == (currentNode->next))
		{
			currentNode->next = newNode;
		}
	}
	
	return head;
	
}


struct node* nodeRemove(struct node *head, int data)
{
	struct node *prevNode, *currentNode;
	prevNode = head;
	currentNode = head;
	
	if(NULL == head)
	{
		printf("No data to remove please check");
		return NULL;
	}
	else if(currentNode->data == data)
	{
		printf("test1 \n");
		head = currentNode->next;
		free(currentNode);
	}	
	else
	{
		printf("test2 \n");
		while(NULL != currentNode->next)
		{
			printf("test3 \n");
			if(currentNode->data == data)
			{
				printf("test4 \n");
				printf("***previousdata : %d, currentdata : %d**** \n ", prevNode->data, currentNode->data);
				prevNode->next = currentNode->next;
				printf("previousdata : %d, currentdata : %d \n ", prevNode->data, currentNode->data);
				free(currentNode);
				break;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
			
			
		}
		
		if(currentNode->data == data && currentNode->next == NULL)
			{
				printf("test5 \n");
				printf("***previousdata : %d, currentdata : %d**** \n ", prevNode->data, currentNode->data);
				prevNode->next = currentNode->next;
				printf("previousdata : %d, currentdata : %d \n ", prevNode->data, currentNode->data);
				free(currentNode);
			}
		
	}
	
	return head;
	
}
