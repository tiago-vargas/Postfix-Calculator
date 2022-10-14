#include <stdio.h>
#include <stdbool.h>
#include "../float_stack.c"
#include "../tests.c"

#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

bool test_pushing_one_item_to_stack(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, out error_code);

	return stack.elements[0] == 2.5f;
}

bool test_pushing_multiple_items(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, out error_code);
	push_float(3.7f, &stack, out error_code);

	return stack.elements[0] == 2.5f
	       && stack.elements[1] == 3.7f;
}

bool test_incrementing_stack_on_push(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, out error_code);

	return stack.quantity == 1;
}

bool test_popping_from_stack(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };
	stack.elements[0] = 2.5f;
	stack.elements[1] = 3.7f;
	stack.quantity = 2;

	float last_number = pop_float(&stack, out error_code);

	return last_number == 3.7f;
}

bool test_decrementing_stack_on_pop(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };
	stack.elements[0] = 2.5f;
	stack.elements[1] = 3.7f;
	stack.quantity = 2;

	float last_number = pop_float(&stack, out error_code);

	return stack.quantity == 1;
}

bool test_popping_from_empty_stack_to_have_no_effect(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	pop_float(&stack, out error_code);

	return stack.quantity == 0;
}

bool test_popping_from_empty_stack_error(out float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	pop_float(&stack, out error_code);

	return *error_code == POP_FROM_EMPTY_STACK_ERROR_CODE;
}

bool test_pushing_to_full_stack_to_have_no_effect()
{
	FloatStack stack = { .quantity = STACK_CAPACITY };

	float error_code;

	push_float(2.7f, &stack, &error_code);

	return stack.quantity == STACK_CAPACITY;
}

void run_all_tests()
{
	printf("-- FLOAT STACK TEST RESULTS --\n");

	run_test(test_pushing_one_item_to_stack,
	         "pushing 2.5f to empty stack should make its elements be [ 2.5f, ... ]");
	run_test(test_incrementing_stack_on_push,
	         "pushing to empty stack should make its quantity be 1");
	run_test(test_pushing_multiple_items,
	         "pushing 2.5f, 3.7f to empty stack should make its elements be [ 2.5f, 3.7f, ... ]");

	run_test(test_popping_from_stack,
	         "popping from [ 2.5f, 3.7f, ... ] should return 3.7f");
	run_test(test_decrementing_stack_on_pop,
	         "popping from stack of 2 elements should make its quantity be 1");
	run_test(test_popping_from_empty_stack_to_have_no_effect,
	         "popping from empty stack should make its quantity still be 0");
	run_test(test_popping_from_empty_stack_error,
	         "popping from empty stack should return error code of POP_FROM_EMPTY_STACK_ERROR_CODE");

	run_test(test_pushing_to_full_stack_to_have_no_effect,
	         "pushing to full stack should make its quantity still be STACK_CAPACITY");
}

void main()
{
	run_all_tests();
}
