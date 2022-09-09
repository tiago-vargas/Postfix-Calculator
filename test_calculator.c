#include <stdio.h>
#include <stdbool.h>
#include "calculator.c"

bool test_single_operation()
{
	char *input = "2 5 +";

	float result = evaluate(input);

	return result == 7.0f;
}

void run_test(bool (*testing_function)(), char *message)
{
	if (testing_function())
		printf("\x1b[32mPASSED\x1b[0m: %s\n", message);
	else
		printf("\x1b[31mFAILED\x1b[0m: %s\n", message);
}

void run_all_tests()
{
	printf("-- TEST RESULTS --\n");

	run_test(test_single_operation, "`2 5 +` should return 7");
}

void main()
{
	run_all_tests();
}