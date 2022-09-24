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

	float error_code;
	float result = evaluate(input, &error_code);

	printf("Result: %f\n", result);

	if (error_code == 1)
		printf("ERROR: Too few operands.\n");

	return 0;
}
