#include <stdlib.h>
#include "../FloatStack/float_stack.c"

float evaluate(char *input)
{
	FloatStack stack;
	char *element;

	int index = 0;
	element = get_next_element(input, index);

	if (is_operator(element))
	{
	}
	else if (is_number(element))
	{
		float number = atof(element);
		push_float(number, &stack);
	}
	else
	{
		fprintf(stderr, "invalid syntax: %s", element);
	}

}
