#include "Declarations.h"

#include <complex>
#include <format>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void
new_features ()
{
  cout << "\n=== new_features() === (top calling function)\n\n";

  uniform_initialization_size_t_and_auto ();
  range_based_for_loop ();
  typedef_and_using ();
  more_uniform_initialization ();
  vector_unif_init_exception ();
  std_format_example ();
  ctad_example ();
}

void
uniform_initialization_size_t_and_auto ()
{
  cout << "=== uniform_initialization() ===\n\n";

  vector<int> v{ 1, 2, 3 };
  string      s{ "This is a vector: " };

  cout << s << v[0] << ", " << v[1] << ", " << v[2] << "\n";

  size_t v_size = v.size ();
  cout << "size of v = " << v_size << "\n";

  auto k = 1;
  auto x = 419.53;

  cout << "k = " << k << endl;
  cout << "x = " << x << endl;
  cout << endl;
}

void
range_based_for_loop ()
{
  using std::string;

  cout << "=== range_based_for_loop() ===\n\n";

  vector<double> v{ 1.0, 2.0, 3.0, 4.0, 5.0 };

  for (unsigned i = 0; i < v.size (); ++i)
    {
      cout << v[i] << " ";
    }

  cout << "\nVerify type of v is a std::vector: " << typeid (v.begin ()).name () << "\n\n";

  for (double x : v)
    {
      cout << x << " ";
    }

  cout << endl;

  // Iterator based for loop (available pre-C++11):
  // std::iterator it = v.begin(); -- this was required prior to the availability of auto.
  for (auto iter = v.begin (); iter != v.end (); ++iter)
    {
      cout << *iter << " ";
    }

  cout << endl;

  double sum = 0.0;
  for (double x : v)
    {
      sum += x;
    }

  cout << "Sum = " << sum << "\n\n";

  // Can also use the & reference operator in both non-const and const cases:
  for (double &x : v)
    {
      x *= x;
    }

  for (double x : v)
    {
      cout << x << " ";
    }

  cout << endl;

  vector<string> sorry_dave{ "Open", "the", "pod", "bay", "doors", "HAL" };
  for (const string &s : sorry_dave)
    {
      cout << s << " ";
    }
  cout << endl;
}

void
typedef_and_using ()
{
  cout << "\n=== typedef_and_using (no output) () ===\n";
  // No output -- Just to verify the code in the text compiles:
  // typedef std::map<std::string, std::complex<double> > complex_map;
  typedef map<string, complex<double> > complex_map;

  // using complex_map = std::map<std::string, std::complex<double> >;
  using complex_map = map<string, complex<double> >;
}

void
more_uniform_initialization ()
{
  cout << "\n=== more_uniform_initialization() (no output) ===\n\n";
  // No output -- demonstrates what happens at compile time.
  int i{ 100 };

  double x = 92.09;
  int    k = x; // Compiles, possibly with a warning
  // int    n{ x }; // Compiler ERROR: narrowing conversion

  // An alternate equivalent form of uniform initialization:
  int         i_alt = { 100 }; //
  vector<int> v     = { 1, 2, 3 };
}

void
vector_unif_init_exception ()
{
  cout << "=== vector_unif_init_exception() (no output) ===\n\n";
  // No output -- for demonstration
  vector<int> u (2);  // A vector<int> containing 2 elements
  vector<int> v{ 2 }; // A vector<int> with a single element with a value of 2
}

void
std_format_example ()
{
  cout << "=== std_format_example() ===\n\n";
  using std::string;

  double u = 1.5;
  double v = 4.2;

  // If we wanted to output these values with the variable name labels, we could write:
  cout << "Output with cout : " << "\n";
  cout << "u = " << u << ", v = " << v << "\n";

  // Chaining the chevrons together, however, can become tiresome.
  // Alternatively, we could use format to concatenate the output into a single string:
  // Instead, we can now use the following.
  // Need #include <format>:
  cout << "Output with std::format:\n";
  // string output = std::format ("u = {0}, v = {1}\n", u, v);
  string output = std::format ("u = {}, v = {}\n", u, v);
  cout << output;

  // Alternatively, the format(.) function, as it returns a string, can just be used in cout without the intermediate
  // string object being constructed:
  using std::format;
  cout << "Output with std::format inside cout:\n";
  cout << format ("u = {0}, v = {1}", u, v) << endl;

  // When the order is from left to right, however, the index values can be dropped:
  cout << "Output with std::format inside cout with index values dropped:\n";
  cout << format ("u = {}, v = {}\n", u, v);

  // In some cases, however, the index values are needed; eg:
  // double w = std::sin(u) + v;
  // #include <cmath>		// (see top of file)
  cout << "With necessary index values:\n";
  cout << std::format ("u = {0}, v = {1}, sin({0}) + {1} = {2}", u, v, std::sin (u) + v) << endl;

  cout << endl;
}

void
ctad_example ()
{
  cout << "=== ctad_example() ===\n\n";
  // Usual initialization, with template parameter:
  std::vector<int> v_1{ 1, 2, 3 };

  for (int k : v_1)
    {
      cout << k << " ";
    }

  cout << endl;

  // CTAD = Class template argument deduction
  std::vector v_2{ 1, 2, 3 };
  for (int k : v_2)
    {
      cout << k << " ";
    }

  cout << "\n\n";
}
