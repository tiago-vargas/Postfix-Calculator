#include <stdio.h>
#include "calculator.c"

int main()
{
	printf("Type an expression in RPN:\n");

	char input[400];
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
		input[i++] = c;

	float result = evaluate(input);

	printf("Result: %f\n", result);

	return 0;
}
