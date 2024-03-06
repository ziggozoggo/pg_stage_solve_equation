#ifndef SRC_UNIT_TESTS_TEST_QUADRATIC_EQUATION_H_
#define SRC_UNIT_TESTS_TEST_QUADRATIC_EQUATION_H_

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../quadratic_equation.h"

#define QUAD_EQ_DBL_EPS 1E-7

Suite *suite_quadratic_equation();

#endif  // !SRC_UNIT_TESTS_TEST_QUADRATIC_EQUATION_H_