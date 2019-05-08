#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double height = 12.4;
  double width = 10.3;
  double area = 0.0;
  double perimeter = 0.0;
  area = width*height;
  perimeter = 2*(width+height);

  printf("\nRectangle of height: %g\twidth: %g\nhas perimeter of: %g\t and area of: %g\n", height, width, area, perimeter);
}
