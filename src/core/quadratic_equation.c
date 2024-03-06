#include "../quadratic_equation.h"


/**
 * @brief Quadratic equation ax^2+bx+c=0 
 * @param a Coeff a
 * @param b Coeff b
 * @param c Coeff c
 * @param x1 Pointer to first root x1
 * @param x2 Pointer to second root x2
 * @return Calculation result code: 0 - OK; 1 - one root (x1 = x2); 2 - no roots
 */
int solve_equation (const double a, const double b, 
                    const double c, double *x1, double *x2) {
  int return_code = QUAD_EQ_OK;
  // TODO Some logic
  (void)a;
  (void)b;
  (void)c;
  *x1 = *x2 = 0;
  return return_code;
}

