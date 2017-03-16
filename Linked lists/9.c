/*Sort a linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *);
void sort(struct node **);

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
	sort(&p);
	display(p);

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

void sort(struct node **q)
{
	struct node *temp1, *temp2;
	int temp;
	temp1 = *q;

	while(temp1)
	{
		temp2 = temp1->link;
		while(temp2)
		{
			if(temp1->data > temp2->data)
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}

			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
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
