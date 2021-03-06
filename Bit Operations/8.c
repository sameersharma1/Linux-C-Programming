/*A->B*/
#include <stdio.h>

void show(int);
int count(int);

int main()
{
	int a, b;

	printf("Enter any number : ");
	scanf("%d",&a);

	printf("Enter any number : ");
	scanf("%d",&b);

	show(a);
	show(b);	

	printf("Total %d bits are required for A->B...!!\n",count(a^b));
	return 0;
}

void show(int n)
{
	int i;

	for (i=1<<15; i>0; i=i/2)
		(n & i) ? printf("1") : printf("0");

	printf("\n");
}

int count(int n)
{
	int s=0;
	
	while(n)
	{
		if(n & 1)
			s++;
		n = n>>1;
	}

	return s;
}
