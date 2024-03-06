#include "test_quadratic_equation.h"

/* NORMAL */

START_TEST(normal_manual_a_is_zero) {
  double a = 0;
  double b = -5;
  double c = 3;
  double x1, x2;
  x1 = x2 = 0;

  double expected_x1 = -c / b;

  ck_assert_int_eq(solve_equation(a, b, c, &x1, &x2), QUAD_EQ_ONE_ROOT);
  ck_assert_double_eq_tol(x1, expected_x1, QUAD_EQ_DBL_EPS);
  ck_assert_double_eq_tol(x2, expected_x1, QUAD_EQ_DBL_EPS);
}
END_TEST

START_TEST(normal_manual_one_root) {
  double a = 2;
  double b = 0;
  double c = 0;
  double x1, x2;
  x1 = x2 = 0;

  double expected_x1 = -b / (2 * a);

  ck_assert_int_eq(solve_equation(a, b, c, &x1, &x2), QUAD_EQ_ONE_ROOT);
  ck_assert_double_eq_tol(x1, expected_x1, QUAD_EQ_DBL_EPS);
  ck_assert_double_eq_tol(x2, expected_x1, QUAD_EQ_DBL_EPS);
}
END_TEST

START_TEST(normal_manual_two_roots) {
  double a = 2;
  double b = -5;
  double c = 3;
  double x1, x2;
  x1 = x2 = 0;

  double expected_x1 = 1.5;
  double expexted_x2 = 1;

  ck_assert_int_eq(solve_equation(a, b, c, &x1, &x2), QUAD_EQ_OK);
  ck_assert_double_eq_tol(x1, expected_x1, QUAD_EQ_DBL_EPS);
  ck_assert_double_eq_tol(x2, expexted_x2, QUAD_EQ_DBL_EPS);
}
END_TEST

/* FAIL */

START_TEST(d_below_zero) {
  double a = 2;
  double b = -5;
  double c = 30;
  double x1, x2;

  ck_assert_int_eq(solve_equation(a, b, c, &x1, &x2), QUAD_EQ_NO_ROOTS);
}
END_TEST

START_TEST(check_data_nan) {
  double x1, x2;
  ck_assert_int_eq(solve_equation(NAN, -5, 2, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(NAN, NAN, 2, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(NAN, NAN, NAN, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(2, -5, NAN, &x1, &x2), QUAD_EQ_ERROR);
}
END_TEST

START_TEST(check_data_inf) {
  double x1, x2;
  ck_assert_int_eq(solve_equation(INFINITY, -5, 2, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(INFINITY, INFINITY, 2, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(INFINITY, INFINITY, INFINITY, &x1, &x2), QUAD_EQ_ERROR);
  ck_assert_int_eq(solve_equation(2, -5, INFINITY, &x1, &x2), QUAD_EQ_ERROR);
}
END_TEST

Suite *suite_quadratic_equation() {
  Suite *suite = suite_create("suite_quadratic_equation");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_manual_a_is_zero);
  tcase_add_test(normal_cases, normal_manual_one_root);
  tcase_add_test(normal_cases, normal_manual_two_roots);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, d_below_zero);
  tcase_add_test(anomaly_cases, check_data_nan);
  tcase_add_test(anomaly_cases, check_data_inf);
  tcase_add_test(anomaly_cases, check_data_inf);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}