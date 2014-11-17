#include <stdio.h>

#define MAXLEN 100

int fibonacci(int number)
{
	if (number == 0 || number == 1)
		return number;
	else
		return fibonacci(number - 1) + fibonacci(number - 2);
}

void _static_test(void)
{
	static int i = 10;
	printf("static i = %d\n", i++);
}

void static_test(void)
{
	char c = '\0';
	char array[MAXLEN];
	int i = 0, j = 0;

	//while ((c = getchar()) != '\n' && c != EOF && i < MAXLEN - 1)
	//	array[i++] = c;

	array[i] = '\0';
	_static_test();
	_static_test();
	_static_test();
	_static_test();

}

int main(int argc, char *argv[])
{
	int number = 0;

	static_test();
	printf("fibonacci(5)=%d\n", fibonacci(5));
	return 0;
}
