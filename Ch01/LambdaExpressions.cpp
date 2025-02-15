/*
 * This file is licensed under the Mozilla Public License, v. 2.0.
 * You can obtain a copy of the license at http://mozilla.org/MPL/2.0/.
 */

#include "Declarations.h"
#include <cmath>
#include <complex>
#include <format>
#include <iostream>
#include <string>
#include <vector>

// This is a simple test script, so OK to put
// `using` statements at the top of the file.
using std::cout;
using std::format;
using std::string;
using std::vector;

void
lambda_expressions ()
{
  cout << "\n***** lambda_expressions() ***** (top calling function)\n";
  hello_world ();
  more_lambda_examples ();
}

void
hello_world ()
{
  cout << "\n*** hello_world() ***\n\n";
  auto f = [] { cout << "Hello World!" << "\n"; };

  f ();

  cout << "\n\n";
}

void
more_lambda_examples ()
{
  cout << "\n*** more_lambda_examples() ***\n\n";
  auto g = [] (double x, double y) -> double // return type is optional
  { return x + y; };

  double z = g (9.2, 2.6);                   // z = 11.8
  cout << format ("z = {}\n", z);

  // To demonstrate lambda capture:
  vector u{ 1.0, 1.5, 2.0, 2.5, 3.0, 3.5 };
  double shift = 0.25;

  auto shift_scalar_mult = [&u, shift] (double alpha) {
    for (double &x : u)
      {
        x = alpha * (x + shift);
      }
  };

  shift_scalar_mult (-1.0);
  cout << "shift_scalar_mult(-1.0):\n";
  for (auto x : u)
    {
      cout << x << " ";
    }

  cout << "\n\n";
}