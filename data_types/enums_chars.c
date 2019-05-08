#include <stdio.h>



int main()
{
  enum gender {male, female};
  enum gender myGender;
  myGender = male;
  enum gender herGender = female;
  _Bool isMale = (myGender == herGender);
  printf("%d %d %d \n", isMale, myGender, herGender);

  char newLine = '\n';
  printf("hello %c world", newLine);




}


/*
  data type to define a variable and specifiy valid values.
  Define enum type and give it a name:
  initated by the keyword enum;
  then the name of the enumerated data type;
  then list of identifiers(enclosed in a set of curly braces) that define the
  permissible values that can be assigned to the type.

  enum primayColor {red, yellow, blue}; variables declared to be of this data
  type can only be red, yellow, or blue
  f.e enum primaryColor mColor, gregsColor
  myColour = red;

  enum month {jan, feb, mar};
  compiler treats enum identifiers as integer constants. feb is assigned 1;
  integer can be assigned to the identifier fe:
  enum direction {up, down, left = 10, right} (0,1,10,11);


  char represents a single character ('a', '6', ';') using single quotes.
  can be unsigned.
  char broiled; broiled = 'T'; can't be "T", because that's a string.

  escape characters/sequences: char x = '\n', represents a new line
  \a Alert, \b backspace, \f formfeed, \n newline, \r carriage return
  \t horizontal tab, \v vertical tab, \\ backslash, \' single quote
  \" double quote,\? question mark, /0aa octal values, /xaa hex value

*/
