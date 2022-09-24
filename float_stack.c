#define MAX_SIZE 200
#define out /**/

typedef struct
{
	float elements[MAX_SIZE];
	int quantity;
} FloatStack;

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
		stack->quantity--;
	}
	else
	{
		*error_code = 1;
		printf("ERROR: Attemped to pop from empty stack\n");
	}

	return last_item;
}
