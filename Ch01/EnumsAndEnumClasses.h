/*
 * This file is licensed under the Mozilla Public License, v. 2.0.
 * You can obtain a copy of the license at http://mozilla.org/MPL/2.0/.
 */

#pragma once

enum OptionType
{
  European,
  American,
  Bermudan,
  Asian
};

enum Baseball
{
  Pitcher,
  Catcher,
  First_Baseman,
  Second_Baseman,
  Third_Baseman,
  Shortstop,
  Left_Field,
  Center_Field,
  Right_Field
};

enum Football
{
  Defensive_Tackle,
  Edge_Rusher,
  Defensive_End,
  Linebacker,
  Cornerback,
  Strong_Safety,
  Weak_Safety
};

enum class Bond_Type
{
  Government,
  Corporate,
  Municipal,
  Convertible
};

enum class Futures_Contract
{
  Gold,
  Silver,
  Oil,
  Natural_Gas,
  Wheat,
  Corn
};
