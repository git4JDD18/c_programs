#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

struct node* insertAtTheBeg(struct node *head, int data);
struct node{
	struct node* nextNode;
	int data;
};

int main()
{
	
	struct node *head = NULL;
	head->data = 10;
	head = insertAtTheBeg(head, 10);
	printf("%d \n" , head->data);
	head = insertAtTheBeg(head, 30);
	printf("%d \n" , head->data);
	//getch();
	return 0;
	
}

struct node* insertAtTheBeg(struct node *head, int data){
	
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	
	if(NULL == head)
	{
		head = new_node;
		head->nextNode = NULL;
	}
	else
	{
		new_node->nextNode = head;
		head = new_node;
	}
	
	return head;
	
}
