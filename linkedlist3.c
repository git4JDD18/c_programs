#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *next;
	int data;
};

struct node* insertAtEnd(struct node *head, int data);

int main()
{
	struct node *head = NULL;
	head = insertAtEnd(head, 10);
	head = insertAtEnd(head, 20);
	//head = insertAtEnd(head, 30);
	//printf("%d",head->data);
	
	/*while(head->next->next != NULL)
	{
		printf("%d",head->data);
		printf("\t");
		head = head->next;
	}*/
	
	return 0;
	
}

struct node* insertAtEnd(struct node *head, int data)
{
	struct node *new_node, *temp;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	
	temp = head;
	
	if(NULL == head)
	{
		head = new_node;
		head->next = NULL;
	}
	else
	{
		printf("**test1** \n");
		printf("%d \n", temp->data);
		while(NULL != temp->next)
		{
			printf("**test2** \n");
			printf("%d \n", temp->data);
			temp = temp->next;
			printf("**test3** \n");
			printf("%d \n", temp->data);
		}
		
		printf("**test4** \n");
		printf("%d \n", temp->data);
		temp->next = new_node;
		printf("**test5 \n**");
		printf("%d \n", temp->data);
	}
	
	return head;
	
}
