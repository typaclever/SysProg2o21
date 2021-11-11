#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char charArray[100];
	printf("Enter some chars: ");

	fgets(charArray, 100, stdin);

	FILE *inputFile = fopen("myTxtFile.txt", "w");

	int c, charIndex = 0;

	char *charArrPoint = (char*) malloc (strlen(charArray)-1);	

	for (int i = 0; i < strlen(charArray); i++)
	{
		c = charArray[i];
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			charArrPoint[charIndex] = charArray[i];
			charIndex++;

		}
	}

	puts(charArrPoint);

	for (int j = 0; j < strlen(charArrPoint) - 1; j++)
	{

		for (int k = 0; k < strlen(charArrPoint)- j -1; k++)
		{

			if (charArrPoint[k] > charArrPoint[k+1])
			{
				char tmp = charArrPoint[k];
				charArrPoint[k] = charArrPoint[k+1];
				charArrPoint[k+1] = tmp;
			}

		}

	}
	puts(charArrPoint);
	inputFileuts(charArrPoint, inputFile);
	fclose(inputFile);
	free(charArrPoint);

	return 0;
}