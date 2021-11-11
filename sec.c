#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *inputFile = fopen("myTxtFile.txt", "r");
  char charArray[100];

  fgets(charArray, 100, inputFile);
  puts(charArray);
  int n = strlen(charArray);
  printf("Chars count:\n");
  for (int i = 0; i < n; i++) {
    int c = 0;

    for (int j = 0; j < n; j++) {

      if (charArray[j] == charArray[i]) {
        c++;
      }

    }
    printf("\t%c: %d\n", charArray[i], c);

    while (charArray[i + 1] == charArray[i]) {
      i++;
    }
  }
  fclose(inputFile);
  return 0;
}