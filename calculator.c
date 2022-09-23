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

	push_float(atof(tokens[0]), &stack);
	push_float(atof(tokens[1]), &stack);

	float last_number = pop_float(&stack);
	float penultimate_number = pop_float(&stack);

	if (tokens[2][0] == '+')
		result = penultimate_number + last_number;

	if (tokens[2][0] == '-')
		result = penultimate_number - last_number;

	if (tokens[2][0] == '*')
		result = penultimate_number * last_number;

	if (tokens[2][0] == '/')
		result = penultimate_number / last_number;

	return result;
}
