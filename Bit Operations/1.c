/*Simple program*/
#include <stdio.h>

void show(int);
int main()
{
	int num;

	printf("Enter any number : ");
	scanf("%d",&num);

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
