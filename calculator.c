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
	float last_number, penultimate_number;
	FloatStack stack = { .quantity = 0 };

	char *tokens[200];
	tokenize(input, tokens);

	stack.elements[0] = atof(tokens[0]);
	stack.elements[1] = atof(tokens[1]);

	last_number = stack.elements[0];
	penultimate_number = stack.elements[1];

	if (tokens[2][0] == '+')
		return last_number + penultimate_number;

	if (tokens[2][0] == '-')
		return last_number - penultimate_number;

	if (tokens[2][0] == '*')
		return last_number * penultimate_number;

	if (tokens[2][0] == '/')
		return last_number / penultimate_number;
}
