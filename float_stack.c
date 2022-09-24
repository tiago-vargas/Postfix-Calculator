#define MAX_SIZE 200

typedef struct
{
	float elements[MAX_SIZE];
	int quantity;
} FloatStack;

void push_float(float number, FloatStack *stack)
{
	int index_to_put = stack->quantity;

	stack->elements[index_to_put] = number;
	stack->quantity++;
}

float pop_float(FloatStack *stack)
{
	int current_index = stack->quantity - 1;
	float last_item = stack->elements[current_index];

	if (stack->quantity > 0)
		stack->quantity--;

	return last_item;
}
