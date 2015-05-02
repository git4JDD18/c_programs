#include<stdlib.h>
#include<stdio.h>

struct node{
	struct node *next;
	int data;
};

struct node* insertInCLL(struct node *head, int data);
struct node* removeNode(struct node *head, int data);

int main()
{
	struct node *head = NULL, *myCurr;
	head = insertInCLL(head, 10);
	head = insertInCLL(head, 20);
	head = insertInCLL(head, 30);
	head = insertInCLL(head, 40);
	head = insertInCLL(head, 50);
	head = insertInCLL(head, 35);
	head = insertInCLL(head, 65);
	//printf("%d",head->data);
	myCurr = head;
	
	while(myCurr->next != head)
	{
		printf("%d",myCurr->data);
		printf("\t");
		myCurr = myCurr->next;
	}
	printf("%d \n",myCurr->data);
	printf("head is : %d \n",head->data); 
	
	head = removeNode(head, 10);
	head = removeNode(head, 35);
	head = removeNode(head, 65);
	//printf("%d",head->data);
	myCurr = head;
	
	while(myCurr->next != head)
	{
		printf("%d",myCurr->data);
		printf("\t");
		myCurr = myCurr->next;
	}
	printf("%d \n",myCurr->data);
	printf("head is : %d \n",head->data);
	return 0;
}

struct node* insertInCLL(struct node *head, int data)
{
	struct node *newNode, *currentNode, *prevNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	prevNode = currentNode = head;
	
	if(NULL == head)
	{
		head = newNode;
		newNode->next = head;
	}
	else if(newNode->data < head->data && head->next == head)
	{
		newNode->next = head;
		head->next = newNode;
		head = newNode;
	}
	else
	{
		while(prevNode->next != head)
		{
			if(newNode->data > currentNode->data && newNode->data < currentNode->next->data )
			{
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				break;
				
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		
		if(prevNode->next== head && prevNode->data < newNode->data )
		{
			newNode->next = head;
			prevNode->next = newNode;
		}
	}
	return head;
}

struct node* removeNode(struct node *head, int data)
{
	//printf("test1 %d \n ", head);
	struct node *currentNode,*prevNode;
	prevNode = currentNode = head;

	//printf("test2 %p \n ", head);
	if(NULL == head)
	{
		//printf("test3 %p \n ", head);
		printf("No node to remove");
		return NULL ;
	}
	else if(head->next == head && head->data == data)
	{
		free(head);
		head = NULL;
	}
	else if(head->data == data && head->next != head)
	{
		while(prevNode->next != head)
		{
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		prevNode->next = currentNode->next;
		head = currentNode->next;
		free(currentNode);
		
	}
	else
	{
		while(prevNode->next != head)
		{
			if(currentNode->data == data)
			{
				prevNode->next = currentNode->next;
				free(currentNode);
				break;
			}
			
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
	}
	return head;
}
