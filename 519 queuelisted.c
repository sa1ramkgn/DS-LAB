#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front,*rear;
};
void create_queue(struct queue *q)
{
  q->front = q->rear = NULL;
}
void insert(struct queue *q,int val)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	if(q->rear == NULL)
	q->front = q->rear = ptr;
	else
	q->rear = q->rear->next=ptr;
}
void delete_elements(struct queue *q)
{
	if(q->front == NULL)
	{
		printf("\nUNDERFLOW");
		return;
	}
	struct node *temp=q->front;
	printf("\nDeleted: %d\n",temp->data);
	q->front = q->front->next;
	if(q->front == NULL)
	q->rear = NULL;
	
	free(temp);
}
int peek(struct queue *q)
{
	return (q->front)?q->front->data:-1;
}
void display(struct queue *q)
{
	if(q->front == NULL)
{
    printf("\nQUEUE IS EMPTY");
    return;
	}
	struct node *temp = q->front;
	printf("\nQueue: ");
	while(temp)
	{
	printf("%d",temp->data);
	temp=temp->next;
	}
}
int main() {
	int choice, value;
	struct queue q;
	create_queue(&q);
	printf("\n---Queue Menu---");
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Peek");
	printf("\n4. Display");
	printf("\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
        printf("Enter the value to insert: ");
        scanf("%d",&value);
	    insert(&q, value);
	break;
	case 2:
		delete_elements(&q);
		break;
	case 3:
	    value = peek(&q);
		if (value == -1)
		printf("\nQueue is empty\n");
		else
		printf("\nFront element is: %d\n",value);
		break;
	case 4:
	    display(&q);
	    break;
	case 5:
	     printf("\nExisting...\n");
		 exit(0);
		 default:
		 printf("\nInvalid choice. Try again.\n");	
	}
}

