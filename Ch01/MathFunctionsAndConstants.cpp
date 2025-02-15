#include "Declarations.h"

// Use #include <cmath> and scope math functions with std::.

#include <cmath>
#include <format>
#include <iostream>
#include <numbers>

void
math_functions_and_constants ()
{
  using std::cout, std::format, std::endl;

  cout << "\n=== math_functions_and_constants() === (top calling function)" << endl;

  cout << "\n=== trig_fcn(.) ===" << endl;
  cout << format ("sin({}) + cos({}) = {}", std::numbers::pi, std::numbers::pi,
                  trig_fcn (std::numbers::pi, std::numbers::pi))
       << endl;

  cout << "\n=== zero_coupon_bond(.) ===" << endl;
  cout << format ("zero_coupon_bond({}, {}, {}) = {}", 1000.0, 0.06, 0.05, zero_coupon_bond (1000.0, 0.06, 0.05))
       << endl;

  cout << "\n=== polynomial using Horner's Method f(.) ===" << endl;
  cout << format ("f({}) = {}", 1.0, f (1.0)) << endl;

  cout << "\n=== polynomial using brute force f_pow(.) (version of f(.) using std::pow(.)) ===" << endl;
  cout << format ("f_pow({}) = {}", 1.0, f_pow (1.0)) << endl;

  cout << "\n=== real exponent g(.) ===" << endl;
  cout << format ("g({}, {}) = {}", 1.0, 1.0, g (1.0, 1.0)) << endl;

  cout << "\n=== C++ mathematical constants math_constant_fcn(.) ===" << endl;
  cout << format ("\nmath_constant_fcn({}, {}) = {}", 1.0, 1.0, math_constant_fcn (1.0, 1.0)) << endl;
}

double
trig_fcn (double theta, double phi)
{
  return std::sin (theta) + std::cos (phi);
}

double
zero_coupon_bond (double face_value, double int_rate, double year_fraction)
{
  return face_value * std::exp (-int_rate * year_fraction);
}

// Polynomial using Horner's Method:
double
f (double x)
{
  return x * (x * (x * (8.0 * x + 7.0) + 4.0 * x) - 10.0) - 6.0;
}

// Same polynomial, but using brute force method:
double
f_pow (double x) // f(.) in text
{
  return 8.0 * std::pow (x, 4) + 7.0 * std::pow (x, 3) + 4.0 * std::pow (x, 2) + 10.0 * x - 6.0;
}

double
g (double x, double y)
{
  return std::pow (x, -1.368 * x) + 4.19 * y;
}

// C++20 mathematical constants
double
math_constant_fcn (double x, double y)
{
  using namespace std::numbers;

  double math_inv_sqrt_two_pi = inv_sqrtpi / sqrt2;

  return math_inv_sqrt_two_pi * (std::sin (pi * x) + std::cos (inv_pi * y));
}
