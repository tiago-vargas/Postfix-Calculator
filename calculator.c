#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../FloatStack/float_stack.c"

void tokenize(char string[], char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 1; i < 200; i++)
		tokens[i] = strtok(NULL, " ");
}

bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

bool is_number(char *string)
{
	if (!is_operator(string[0]) && string != NULL)
		return true;
	else
		return false;
}

float evaluate(char input[])
{
	float result;

	FloatStack stack = { .quantity = 0 };

	char *tokens[200];
	tokenize(input, tokens);

	if (is_number(tokens[0]) && is_number(tokens[1]))
	{
		push_float(atof(tokens[0]), &stack);
		push_float(atof(tokens[1]), &stack);
	}

	if (is_operator(tokens[2][0]))
	{
		char operator = tokens[2][0];

		float last_number = pop_float(&stack);
		float penultimate_number = pop_float(&stack);

		if (operator == '+')
			result = penultimate_number + last_number;

		if (operator == '-')
			result = penultimate_number - last_number;

		if (operator == '*')
			result = penultimate_number * last_number;

		if (operator == '/')
			result = penultimate_number / last_number;
	}

	return result;
}
