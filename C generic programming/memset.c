#include <stdio.h>
#include <string.h>

int main()
{
	char arr[ ] = "SAMEER SHARMA";

	printf("%s\n",arr);

	memset(arr,'A',5);

	printf("%s\n",arr);

	return 0;

}
