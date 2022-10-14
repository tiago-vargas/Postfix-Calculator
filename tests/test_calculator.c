#include <stdio.h>
#include <stdbool.h>
#include "../calculator.c"
#include "../tests.c"

#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

bool test_single_addition(out float *actual_result)
{
	float error_code;
	char input[] = "2 5 +";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 7;
}

bool test_single_subtraction(out float *actual_result)
{
	float error_code;
	char input[] = "2 5 -";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == -3;
}

bool test_single_multiplication(out float *actual_result)
{
	float error_code;
	char input[] = "2 5 *";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 10;
}

bool test_single_integer_division(out float *actual_result)
{
	float error_code;
	char input[] = "10 2 /";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 5;
}

bool test_float_operands(out float *actual_result)
{
	float error_code;
	char input[] = "5.6 1.9 +";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 7.5f;
}

bool test_float_division_result(out float *actual_result)
{
	float error_code;
	char input[] = "5 2 /";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 2.5f;
}

bool test_multiple_operations(out float *actual_result)
{
	float error_code;
	char input[] = "2 5 + 3 * 1 - 2 / 3 *";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == 30;
}

bool test_five_operands_before_operators(out float *actual_result)
{
	float error_code;
	char input[] = "2 5 6 10 4 * + - *";

	float result = evaluate(input, out &error_code);

	*actual_result = result;
	return result == -82;
}

bool test_too_few_operators_error(out float *error_code)
{
	char input[] = "2 5 6 10 4 * +";

	float result = evaluate(input, out error_code);

	return *error_code == TOO_FEW_OPERATORS_ERROR;
}

void run_all_tests()
{
	printf("-- CALCULATOR TEST RESULTS --\n");

	run_test(test_single_addition,
	         "`2 5 +` should evaluate to 7");
	run_test(test_single_subtraction,
	         "`2 5 -` should evaluate to -3");
	run_test(test_single_multiplication,
	         "`2 5 *` should evaluate to 10");
	run_test(test_single_integer_division,
	         "`10 2 /` should evaluate to 5");

	run_test(test_float_operands,
	         "`5.6 1.9 +` should evaluate to 7.5f");
	run_test(test_float_division_result,
	         "`5 2 /` should evaluate to 2.5f");

	run_test(test_multiple_operations,
	         "`2 5 + 3 * 1 - 2 / 3 *` should evaluate to 30");
	run_test(test_five_operands_before_operators,
	         "`2 5 6 10 4 * + - *` should evaluate to -82");

	run_test(test_too_few_operators_error,
	         "`2 5 6 10 4 * +` should have error code of TOO_FEW_OPERATORS");
}

void main()
{
	run_all_tests();
}
