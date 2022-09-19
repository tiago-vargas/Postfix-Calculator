#include <stdlib.h>
#include <string.h>
#include "../../FloatStack/float_stack.c"

float evaluate(char input[])
{
	float operand_1, operand_2;

	char *tokens[200];
	tokens[0] = strtok(input, " ");
	tokens[1] = strtok(NULL, " ");
	tokens[2] = strtok(NULL, " ");

	operand_1 = atof(tokens[0]);
	operand_2 = atof(tokens[1]);

	return operand_1 + operand_2;
}
