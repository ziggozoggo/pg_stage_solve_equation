#include "../quadratic_equation.h"

static bool is_input_data_ok(const double *a, const double *b, const double *c, 
                      const double *x1, const double *x2);

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
  if (!is_input_data_ok(&a, &b, &c, x1, x2)) return QUAD_EQ_ERROR;

  int return_code = QUAD_EQ_OK;
  // TODO Some logic
  (void)a;
  (void)b;
  (void)c;
  *x1 = *x2 = 0;
  return return_code;
}

bool is_input_data_ok(const double *a, const double *b, const double *c, 
                      const double *x1, const double *x2) {
  // Check for NULL
  if (x1 == NULL || x2 == NULL) return false;
  
  bool return_code = true;
  // Check for NaN
  if (isnan(*a) || isnan(*b) || isnan(*c)) return_code = false;
  // Check for INF
  if (return_code && (isinf(*a) || isinf(*b) || isinf(*c))) return_code = false;
  
  return return_code;                   
}