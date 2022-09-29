#include <stdio.h>
#include <stdbool.h>
#include "../float_stack.c"

bool test_pushing_one_item_to_stack(float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, error_code);

	return stack.elements[0] == 2.5f;
}

bool test_pushing_multiple_items(float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, error_code);
	push_float(3.7f, &stack, error_code);

	return stack.elements[0] == 2.5f
	       && stack.elements[1] == 3.7f;
}

bool test_incrementing_stack_on_push(float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	push_float(2.5f, &stack, error_code);

	return stack.quantity == 1;
}

bool test_popping_from_stack(float *error_code)
{
	FloatStack stack = { .quantity = 0 };
	stack.elements[0] = 2.5f;
	stack.elements[1] = 3.7f;
	stack.quantity = 2;

	float last_number = pop_float(&stack, error_code);

	return last_number == 3.7f;
}

bool test_decrementing_stack_on_pop(float *error_code)
{
	FloatStack stack = { .quantity = 0 };
	stack.elements[0] = 2.5f;
	stack.elements[1] = 3.7f;
	stack.quantity = 2;

	float last_number = pop_float(&stack, error_code);

	return stack.quantity == 1;
}

bool test_popping_from_empty_stack_to_have_no_effect(float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	pop_float(&stack, error_code);

	return stack.quantity == 0;
}

bool test_popping_from_empty_stack_error(float *error_code)
{
	FloatStack stack = { .quantity = 0 };

	pop_float(&stack, error_code);

	return *error_code == 1;
}

void run_test(bool (*testing_function)(), char *message)
{
	if (testing_function())
		printf("PASSED: %s\n", message);
	else
		printf("----- FAILED: %s\n", message);
}

void run_all_tests()
{
	printf("-- FLOAT STACK TEST RESULTS --\n");

	run_test(test_pushing_one_item_to_stack, "pushing 2.5f to empty stack should make its elements be [ 2.5f, ... ]");
	run_test(test_incrementing_stack_on_push, "pushing to empty stack should make its quantity be 1");
	run_test(test_pushing_multiple_items, "pushing 2.5f, 3.7f to empty stack should make its elements be [ 2.5f, 3.7f, ... ]");
	run_test(test_popping_from_stack, "popping from [ 2.5f, 3.7f, ... ] should return 3.7f");
	run_test(test_decrementing_stack_on_pop, "popping from stack of 2 elements should make its quantity be 1");
	run_test(test_popping_from_empty_stack_to_have_no_effect, "popping from empty stack should make its quantity still be 0");
	run_test(test_popping_from_empty_stack_error, "popping from empty stack should return error code of 1");
}

void main()
{
	run_all_tests();
}
