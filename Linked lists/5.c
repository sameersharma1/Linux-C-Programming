/*Delete a node*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *);
void delete(struct node **, int);

int main()
{
	struct node *p=NULL;
	int i, data, howmany, which;

	printf("Howmany nodes you want in linked list : ");
	scanf("%d",&howmany);

	for(i=0; i<howmany; i++)
	{
		printf("Enter data for %dth node : ",i);
		scanf("%d",&data);
		append(&p,data);
	}

	printf("Which data node you want to delete : ");
	scanf("%d",&which);

	printf("Total %d nodes are available in linked list.\n",count(p));

	display(p);
	delete(&p,which);
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

void delete(struct node **q, int data)
{
	struct node *temp, *old;
	temp=*q;

	while(1)
	{
		if(temp->data == data)
		{
			if(temp == *q)
			{
				*q = temp->link;
				free(temp);
				return ;
			}
			else
			{
				old->link = temp->link;
				free(temp);
				return ;	
			}
		}
		else
		{
			old = temp;
			temp = temp->link;
		}
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
