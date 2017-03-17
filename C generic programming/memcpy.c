#include <stdio.h>
#include <string.h>

int main()
{
	char src[ ] = "SAMEER SHARMA";
	char dest[20];

	printf("Src  is : %s\n",src);
	printf("Dest is : %s\n",src);

	memcpy(dest,src,5);

	printf("Now dest is : %s\n",dest);

	return 0;

}
