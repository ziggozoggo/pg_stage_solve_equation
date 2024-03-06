#include "../quadratic_equation.h"

#define X1 true
#define X2 false

static bool is_input_data_ok(const double *a, const double *b, const double *c,
                             const double *x1, const double *x2);
static double get_root(const double *a, const double *b,
                       const double *discriminant, const bool is_x1);
static double get_discriminant(const double *a, const double *b,
                               const double *c);

/**
 * @brief Quadratic equation ax^2+bx+c=0
 * @param a Coeff a
 * @param b Coeff b
 * @param c Coeff c
 * @param x1 Pointer to first root x1
 * @param x2 Pointer to second root x2
 * @return Calculation result code: 0 OK; 1 one root (x1 = x2); 2 no roots; -1 Error
 */
int solve_equation(const double a, const double b, const double c, double *x1,
                   double *x2) {
  if (!is_input_data_ok(&a, &b, &c, x1, x2)) return QUAD_EQ_ERROR;

  int return_code = QUAD_EQ_OK;

  if (a == 0) {
    // Linear equation bx + c = 0
    *x1 = -c / b;
    *x2 = *x1;
    return_code = QUAD_EQ_ONE_ROOT;
  } else {
    double discriminant = get_discriminant(&a, &b, &c);
    if (discriminant < 0) {
      return_code = QUAD_EQ_NO_ROOTS;
    } else if (discriminant == 0) {
      *x1 = -b / (2 * a);
      return_code = QUAD_EQ_ONE_ROOT;
    } else {
      *x1 = get_root(&a, &b, &discriminant, X1);
      *x2 = get_root(&a, &b, &discriminant, X2);
    }
  }

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

double get_discriminant(const double *a, const double *b, const double *c) {
  return (*b) * (*b) - 4 * ((*a) * (*c));
}

double get_root(const double *a, const double *b, const double *discriminant,
                const bool is_x1) {
  double sign = (is_x1) ? 1 : -1;
  double result = (-(*b) + sign * sqrt(*discriminant)) / (2 * (*a));
  return result;
}