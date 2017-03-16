/*Program to evaluate number of set bits*/
#include <stdio.h>

void show(int);
int count(int);

int main()
{
	int num;

	printf("Enter any number : ");
	scanf("%d",&num);

	show(num);	
	printf("Total %d bits are set...!!\n",count(num));
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
	if (s == 1)
		printf("Number of a power of 2\n");
	return s;
}
