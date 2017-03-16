/*Position of first set bit in any number*/
#include <stdio.h>
#include <math.h>
void show(int);
int main()
{
	int num, pos;

	printf("Enter any number : ");
	scanf("%d",&num);

	show(num);
	num = num & (~num + 1);
	pos = log2(num) + 1;
	printf("Position of set bit is %d\n",pos);	
	return 0;
}

void show(int n)
{
	int i;

	for (i=1<<15; i>0; i=i/2)
		(n & i) ? printf("1") : printf("0");

	printf("\n");
}
