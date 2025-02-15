#include "Declarations.h"

#include <cmath>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::format, std::string, std::endl, std::vector;

void
lambda_expressions ()
{
  cout << "\n=== lambda_expressions() === (top calling function)" << endl;
  hello_world ();
  more_lambda_examples ();
}

void
hello_world ()
{
  cout << "\n=== hello_world() ===" << endl;
  cout << endl;
  auto f = [] { cout << "Hello World!" << endl; };

  f ();
}

void
more_lambda_examples ()
{
  cout << "\n=== more_lambda_examples() ===" << endl;
  cout << endl;

  // return type is optional:
  // auto g = [] (double x, double y) -> double
  // { return x + y; };

  auto g = [] (double x, double y) { return x + y; };

  double z = g (9.2, 2.6); // 11.8
  cout << format ("z = {}", z) << endl;

  // To demonstrate lambda capture:
  vector u{ 1.0, 1.5, 2.0, 2.5, 3.0, 3.5 };
  double shift = 0.25;

  for (auto x : u)
    {
      cout << x << " ";
    }
  cout << endl;

  // auto shift_scalar_mult = [u, shift] (double alpha) { // u won't be changed
  // Using the wildcard [=] or [&] as a lambda capture will allow any preceding external variable or object to be
  // captured by value or reference, respectively -> not recommended!
  auto shift_scalar_mult = [&u, shift] (double alpha) {
    for (double &x : u)
      {
        x = alpha * (x + shift);
      }
  };

  shift_scalar_mult (-1.0);
  cout << "shift_scalar_mult(-1.0):" << endl;
  for (auto x : u)
    {
      cout << x << " ";
    }
  cout << endl;
}
