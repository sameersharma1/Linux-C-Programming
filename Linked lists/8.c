/*Palindrome linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *);
void palindrome(struct node **, int);

int main()
{
	struct node *p=NULL;
	int i, data, howmany;

	printf("Howmany nodes you want in linked list : ");
	scanf("%d",&howmany);

	for(i=0; i<howmany; i++)
	{
		printf("Enter data for %dth node : ",i);
		scanf("%d",&data);
		append(&p,data);
	}

	display(p);
	palindrome(&p,howmany);
	printf("Total %d nodes are available in linked list.\n",count(p));

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

void palindrome(struct node **q, int n)
{
	struct node *temp1, *temp2;
	int flag=0, i, j, k;

	for(i=0; i< n/2; i++)
	{
		if(flag)
			break;
		temp1 = *q;
		temp2 = *q;
	
	
		for(j=0; j< i; j++)
			temp1 = temp1->link;
		for(k=n; k>i+1; k--)
			temp2 = temp2->link;

		if(temp1->data != temp2->data)
			flag = 1;
	}

	if(!flag)
		printf("Linked list is palindrome\n");
	else
		printf("Linked list is not palindrome\n");
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
