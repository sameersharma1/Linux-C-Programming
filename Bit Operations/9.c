/*Simple program to set a bit*/
#include <stdio.h>

#define SET_BIT(n,d) (n | (1 << (d-1)))

void show(int);
int main()
{
	int num, pos;

	printf("Enter any number : ");
	scanf("%d",&num);
	printf("Which bit you want to set : ");
	scanf("%d",&pos);

	show(num);	
	num = SET_BIT(num,pos);
	show(num);

	return 0;
}

void show(int n)
{
	int i;

	for (i=1<<15; i>0; i=i/2)
		(n & i) ? printf("1") : printf("0");

	printf("\n");
}
