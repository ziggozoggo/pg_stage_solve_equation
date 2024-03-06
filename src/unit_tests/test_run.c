#include "test_quadratic_equation.h"
#include "suites_runner.h"

test_results_t run_core_tests() {
  test_results_t core_res_tests = {0};

  Suite *suites_basics[] = {suite_quadratic_equation(), NULL};
  run_test_module("Basics unit-tests:", suites_basics, &core_res_tests);

  printf(DIVIDER_TEXT);
  return core_res_tests;
}

int main() {
  test_results_t total_res_tests = {0};

  printf(MARINE_TEXT "\t---Core tests---" RESET_TEXT);
  test_results_t core_res_tests = run_core_tests();

  print_tests_results(core_res_tests, "Core");

  total_res_tests.all += core_res_tests.all;
  total_res_tests.failed += core_res_tests.failed;

  printf(MARINE_TEXT
         "\n===================Total===================\n" RESET_TEXT);
  print_tests_results(total_res_tests, "All");

  return 0;
}
