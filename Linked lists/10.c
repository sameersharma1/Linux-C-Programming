/*Sort a linked list containing 0's 1's 2's*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *, int);
void sort(struct node **, int, int, int);

int main()
{
	struct node *p=NULL;
	int i, data, howmany, z, o, t;

	printf("Howmany nodes you want in linked list : ");
	scanf("%d",&howmany);

	for(i=0; i<howmany; i++)
	{
		printf("Enter data for %dth node : ",i);
		scanf("%d",&data);
		append(&p,data);
	}

	display(p);

	z = count(p,0);
	o = count(p,1);
	t = count(p,2);
	sort(&p,z,o,t);

	display(p);
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

void sort(struct node **q, int z, int o, int t)
{
	struct node * temp;
	int i;
	temp = *q;

	for (i=0 ; i< z + o + t; i++)
	{
		if(i < z)
			temp->data = 0;
		else if(i < z + o)
			temp->data = 1;
		else
			temp->data = 2;
			
		temp = temp->link;
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

int count(struct node *q, int data)
{
	int c = 0;

	while(q != NULL)
	{
		if(q->data == data)
			c++;
		q = q->link;
	}

	return c;
}
