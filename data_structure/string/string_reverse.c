#include <stdio.h>
//#include <string.h>

#define MAXLEN 100

char carray[MAXLEN];

void getliner(char ca[])
{
	char c;
	int i = 0;
	for (i = 0; i < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n'; i++)
		ca[i] = c;

	printf("%s\n", ca);
}

int strlength(char arr[])
{
	char c;
	int i = 0;
	while (c = arr[i++]);
	return i - 1;
}

void reverse(char ca[])
{
	int length = 0;
	int i = 0, j = 0;

	length = strlength(ca);
	printf("length=%d\n", length);

	for (j = length - 1; i < j; i++, j--) {
		ca[i] ^= ca[j];
		ca[j] ^= ca[i];
		ca[i] ^= ca[j];
	}
	
}

int main(int argc, char *argv[])
{
	getliner(carray);
	reverse(carray);
	printf("%s\n", carray);
}
