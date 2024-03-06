#ifndef SRC_QUADRATIC_EQUATION_H_
#define SRC_QUADRATIC_EQUATION_H_

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define QUAD_EQ_OK 0
#define QUAD_EQ_ONE_ROOT 1  // D equal zero
#define QUAD_EQ_NO_ROOTS 2  // D less than zero
#define QUAD_EQ_ERROR -1 // Coeff is nan or inf

int solve_equation (const double a, const double b, 
                    const double c, double *x1, double *x2);

#endif  // SRC_QUADRATIC_EQUATION_H_