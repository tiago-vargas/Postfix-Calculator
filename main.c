#include <stdio.h>
#include "calculator.c"

#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

int main()
{
	printf("Type an expression in RPN:\n");

	char input[400];
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
		input[i++] = c;

	int error_code;
	float result = evaluate(input, out &error_code);

	printf("Result: %f\n", result);

	if (error_code == TOO_MANY_OPERATORS_ERROR)
		fprintf(stderr, "ERROR: Too many operators.\n");

	return 0;
}
