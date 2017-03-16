#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node **, int);
void display(struct node *);
int count(struct node *);
void detectloop(struct node *);
void removeloop(struct node *, struct node *);
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
	printf("Total %d nodes are available in linked list.\n",count(p));
	p->link->link->link->link->link = p->link->link;
//	display(p);
	detectloop(p);
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

void detectloop(struct node * list)
{
	struct node *slow, *fast;
	slow = list;
	fast = list;

	while(slow && fast && fast->link)
	{
		slow = slow->link;
		fast = fast->link->link;

		if(slow == fast)
			removeloop(slow,list);
	}
}

void removeloop(struct node *loop, struct node *list)
{
	struct node *ptr1, *ptr2;
	ptr1 = list;

	while(1)
	{
		ptr2=loop;

		while(ptr2->link != ptr1 && ptr2->link != loop)
		{
			ptr2 = ptr2->link;
		}
		
		if(ptr2->link == ptr1)
			break;
		else
			ptr1 = ptr1->link;
	}
	
	ptr2->link = NULL;
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
