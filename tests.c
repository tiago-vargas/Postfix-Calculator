#include <stdbool.h>

#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

void run_test(bool (*testing_function)(), char *message)
{
	float actual_result;

	if (testing_function(out &actual_result))
		printf("\x1b[32mPASSED\x1b[0m: %s\n", message);
	else
		printf("\x1b[31mFAILED\x1b[0m: %s. Got: %f\n", message, actual_result);
}
