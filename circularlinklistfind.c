#include<stdlib.h>
#include<stdio.h>

struct node{
	struct node *next;
	int data;
};

struct node* insertInCLL(struct node *head, int data);
struct node* find(struct node *head, int data);

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
	
	head = find(head, 10);
	head = find(head, 35);
	head = find(head, 65);
	head = find(head, 85);

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

struct node* find(struct node *head, int data)
{
	struct node *currentNode, *prevNode;
	currentNode = prevNode = head;
	int flag = 0;
	
	if(NULL == head)
	{
		printf("list is empty \n");
		flag = 0;
		return 0;
	}
	else
	{
		while(currentNode->next != head)
		{
			if(currentNode->data == data)
			{
				printf("%d : value found a the location %p \n ",data, currentNode);
				flag = 1;
				break;
			}
			currentNode = currentNode->next;
		}
		if(currentNode->data == data)
		{
			printf("%d : value found a the location %p \n ",data, currentNode);
			flag = 1;
		}
		
	}
	if(flag == 0)
	{
		printf("No match found \n");
	}
	
	return head;
}
