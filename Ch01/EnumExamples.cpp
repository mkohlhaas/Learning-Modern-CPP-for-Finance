#include "Declarations.h"
#include "EnumsAndEnumClasses.h"

#include <format>
#include <iostream>

using std::cout, std::format, std::endl;

void
enum_examples ()
{
  cout << "\n=== enum_examples() === (top calling function)\n";

  enum_const_examples ();
  enum_class_examples ();
  switch_statement_scoped_enum (Bond_Type::Corporate);
}

void
enum_const_examples ()
{
  cout << "\n=== enum_const_examples() ===" << endl;
  cout << endl;
  cout << " European = " << European << endl;
  cout << " American = " << American << endl;
  cout << " Bermudan = " << Bermudan << endl;
  cout << " Asian = " << Asian << endl;
  cout << " American + Asian = " << American + Asian << endl;
  cout << endl;

  if (Defensive_End == First_Baseman)
    {
      cout << " Defensive_End == First_Baseman" << endl;
    }
  else
    {
      cout << " Defensive_End != First_Baseman" << endl;
    }

  cout << endl;
}

void
enum_class_examples ()
{
  cout << "\n=== enum_class_examples() (scoped enums) ===" << endl;

  // This will be caught by the compiler (a good thing!)
  // if (Bond_Type::Corporate == Futures_Contract::Silver)
  //   {
  //     // . . .
  //   }

  cout << format ("Corporate Bond index: {}", static_cast<int> (Bond_Type::Corporate)) << endl;               // 1
  cout << format ("Natural Gas Futures index: {}", static_cast<int> (Futures_Contract::Natural_Gas)) << endl; // 3
}

void
switch_statement_scoped_enum (Bond_Type bnd)
{
  std::cout << "\n=== switch_statement_scoped_enum ===" << endl;

  switch (bnd)
    {
    case Bond_Type::Government:
      std::cout << "Government Bond..." << endl;
      break;
    case Bond_Type::Corporate:
      cout << "Corporate Bond..." << endl;
      break;
    case Bond_Type::Municipal:
      cout << "Municipal Bond..." << endl;
      break;
    case Bond_Type::Convertible:
      cout << "Convertible Bond..." << endl;
      break;
    }
}
