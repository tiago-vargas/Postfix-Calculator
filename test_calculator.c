#include <stdio.h>
#include <stdbool.h>
#include "calculator.c"

bool test_single_addition()
{
	char input[] = "2 5 +";

	float result = evaluate(input);

	return result == 7;
}

bool test_single_subtraction()
{
	char input[] = "2 5 -";

	float result = evaluate(input);

	return result == -3;
}

bool test_single_multiplication()
{
	char input[] = "2 5 *";

	float result = evaluate(input);

	return result == 10;
}

bool test_single_integer_division()
{
	char input[] = "10 2 /";

	float result = evaluate(input);

	return result == 5;
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

	run_test(test_single_addition, "`2 5 +` should evaluate to 7");
	run_test(test_single_subtraction, "`2 5 -` should evaluate to -3");
	run_test(test_single_multiplication, "`2 5 *` should evaluate to 10");
	run_test(test_single_integer_division, "`10 2 /` should evaluate to 5");
}

void main()
{
	run_all_tests();
}
