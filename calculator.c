#include <stdlib.h>
#include <string.h>
#include "../../FloatStack/float_stack.c"

void tokenize(char string[], char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 1; i < 200; i++)
		tokens[i] = strtok(NULL, " ");
}

float evaluate(char input[])
{
	float operand_1, operand_2;

	char *tokens[200];
	tokenize(input, tokens);

	operand_1 = atof(tokens[0]);
	operand_2 = atof(tokens[1]);

	if (tokens[2][0] == '+')
		return operand_1 + operand_2;

	if (tokens[2][0] == '-')
		return operand_1 - operand_2;

	if (tokens[2][0] == '*')
		return operand_1 * operand_2;

	if (tokens[2][0] == '/')
		return operand_1 / operand_2;
}
