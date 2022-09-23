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
	float result;

	FloatStack stack = { .quantity = 0 };

	char *tokens[200];
	tokenize(input, tokens);

	stack.elements[0] = atof(tokens[0]);
	stack.elements[1] = atof(tokens[1]);

	float last_number = stack.elements[0];
	float penultimate_number = stack.elements[1];

	if (tokens[2][0] == '+')
		result = last_number + penultimate_number;

	if (tokens[2][0] == '-')
		result = last_number - penultimate_number;

	if (tokens[2][0] == '*')
		result = last_number * penultimate_number;

	if (tokens[2][0] == '/')
		result = last_number / penultimate_number;

	return result;
}
