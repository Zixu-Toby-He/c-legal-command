#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pause() system("pause")
char cmd[32];

int getCommondFromInput()
{
	printf("Please input the commond: ");
	scanf("%s",&cmd);
	return EXIT_SUCCESS;
}

int isCommondIllegal()
{
	int toReturn,useless;
	toReturn = system(cmd);
	useless = system("cls");
	return toReturn;
}

int main(int argc, char* argv[])
{
	int counting;
	int* returnsForCommonds;
	if (argc == 1)
	{
		returnsForCommonds = (int*)malloc(1 * sizeof(int));
		if (!returnsForCommonds)
		{
			puts("Memory Error\n");
			return EXIT_FAILURE;
		}
		getCommondFromInput();
		*returnsForCommonds = isCommondIllegal();
		printf("Commond \"%s\" is %s.\n",cmd,(*returnsForCommonds)?"illegal":"legal");
	}
	else if (argc == 2)
	{
		strcpy(cmd,argv[1]);
		returnsForCommonds = (int*)malloc(1 * sizeof(int));
		if (!returnsForCommonds)
		{
			puts("Memory Error\n");
			return EXIT_FAILURE;
		}
		*returnsForCommonds = isCommondIllegal();
		printf("Commond \"%s\" is %s.\n", cmd, (*returnsForCommonds)?"illegal":"legal");
	}
	else
	{
		returnsForCommonds = (int*)malloc((argc - 1) * sizeof(int));
		if (!returnsForCommonds)
		{
			puts("Memory Error\n");
			return EXIT_FAILURE;
		}
		for (counting = 1; counting < argc; counting++)
		{
			strcpy(cmd, argv[counting]);
			returnsForCommonds[counting-1] = isCommondIllegal();
		}
		for (counting = 1; counting < argc; counting++)
		{
			printf("Commond \"%s\" is %s.\n", argv[counting], (returnsForCommonds[counting-1]) ? "illegal" : "legal");
		}
	}
	free(returnsForCommonds);
	pause();
	return EXIT_SUCCESS;
}