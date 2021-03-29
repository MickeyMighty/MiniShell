#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int 	main()
{
	int 	i;

	i = 0;
	printf("before while i = %d\n", i);
	while(i++ < 5)
	{
		printf("in the while before if  i = %d\n", i);
		if (i == 2)
			printf("in the while in the if i = %d\n", i);
		printf("in the while after if i = %d\n", i);
	}
	printf("after while i = %d\n", i);
	return (0);
}
