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

	float error_code;
	float result = evaluate(input, out &error_code);

	if (error_code == TOO_MANY_OPERATORS_ERROR)
		fprintf(stderr, "ERROR: Too many operators, not enough operands.\n");

	if (error_code == TOO_FEW_OPERATORS_ERROR)
		fprintf(stderr, "ERROR: Not enough operators, too many operands.\n");

	if (error_code == NO_EVALUATION_ERRORS)
		printf("Result: %f\n", result);

	return 0;
}
