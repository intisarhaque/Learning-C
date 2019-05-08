#include <stdio.h>

int main()
{
  unsigned int a =60; //00111100
  unsigned int b =13; //00001101
  int and = a&b; //00001100
  int or = a|b; //00111101
  int complement = ~a; //11000011
  int shift = a<<2; //11110000
  printf("%d, %d, %d, %d\n", and, or, complement, shift);

}

/*
  Statement ends with semi colon, instruction for processor

  C offers bitwise and shift operators, operates on bits in integer values.
  To check if a byte is flagged, AND it
  To toggle a flag bit, OR it
  BRILLIANT

  If same precedence then left to right.

  Postfix: () [] ->. ++ --
  Unary: sizeof & (type)* -- ++ ~ ! - + 
  Multiplicative: * / %
  Additive: + -
  Shift: << >>
  Relational: < <= > >=
  Equality == !=


*/
