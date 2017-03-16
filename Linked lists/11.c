/*Identical linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *);
void identical(struct node **, struct node **);

int main()
{
	struct node *p1=NULL, *p2=NULL;
	int i, data, howmany;

	printf("Howmany nodes you want in linked list : ");
	scanf("%d",&howmany);

	for(i=0; i<howmany; i++)
	{
		printf("Enter data for %dth node : ",i);
		scanf("%d",&data);
		append(&p1,data);
	}
	for(i=0; i<howmany; i++)
	{
		printf("Enter data for %dth node : ",i);
		scanf("%d",&data);
		append(&p2,data);
	}

	display(p1);
	display(p2);
	identical(&p1, &p2);
	printf("Total %d nodes are available in linked list.\n",count(p1));

	return 0;
}

void append(struct node **q, int data)
{
	struct node *temp, *r;	
	temp = *q;

	if(temp == NULL)
	{
		temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->link = NULL;

		*q = temp;
	}
	else
	{
		while(temp->link != NULL)
			temp = temp->link;

		r = malloc(sizeof(struct node));
		r->data = data;
		r->link = NULL;
		
		temp->link =r;
	}
}

void identical(struct node **q1, struct node **q2)
{
	struct node *temp1, *temp2;
	temp1 = *q1;
	temp2 = *q2;

	int flag=0;

	while(temp1)
	{
		if (flag)
			break;

		if(temp1->data != temp2->data)
			flag = 1;
		
		temp1 = temp1->link;
		temp2 = temp2->link;
	}

	if(!flag)
		printf("Both linked lists are identical\n");
	else
		printf("Both linked lists are different\n");
}

void display(struct node *q)
{
	printf("========display fun()========\n");

	while(q != NULL)
	{
		printf("%d",q->data);
		if(q->link != NULL)
			printf(" -> ");
		q = q->link;
	}
	printf("\n");
}

int count(struct node *q)
{
	printf("========count fun()=========\n");
	int c = 0;

	while(q != NULL)
	{
		c++;
		q = q->link;
	}

	return c;
}
