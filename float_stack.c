#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

#define MAX_SIZE 200

typedef struct
{
	float elements[MAX_SIZE];
	int quantity;
} FloatStack;

enum stack_error_codes
{
	NO_STACK_ERRORS = 0,
	POP_FROM_EMPTY_STACK_ERROR_CODE,
	PUSH_TO_FULL_STACK_ERROR_CODE
};

void push_float(float number, FloatStack *stack, out float *error_code)
{
	int index_to_put = stack->quantity;

	stack->elements[index_to_put] = number;
	stack->quantity++;
}

float pop_float(FloatStack *stack, out float *error_code)
{
	int current_index = stack->quantity - 1;
	float last_item = stack->elements[current_index];

	if (stack->quantity > 0)
	{
		// *error_code = NO_STACK_ERRORS;
		stack->quantity--;
	}
	else
	{
		// *error_code = POP_FROM_EMPTY_STACK_ERROR_CODE;
		fprintf(stderr, "ERROR: Attemped to pop from empty stack.\n");
	}

	return last_item;
}
