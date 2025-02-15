#include <array>

using std::array;

enum class PayoffType
{
};

// std::array (introduced in C++11, see the NOTE that follows)

class BlackScholes
{
public:
  // default dividend = 0
  BlackScholes (double strike, double spot, double time_to_exp, PayoffType payoff_type, double rate, double div = 0.0);
  double operator() (double vol);

private:
  array<double, 2> compute_norm_args_ (double vol);
  double           strike_, spot_, time_to_exp_;
  PayoffType       payoff_type_;
  double           rate_, div_;
};
