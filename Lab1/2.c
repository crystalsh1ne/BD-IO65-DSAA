#include <stdio.h>

int
main ()
{
  float x;

  scanf ("%f", &x);
  if (x > 0 && x <= 5)
    {
      printf ("x > 0 && x <= 5: (x^3-5x^2) %f\n", x * x * x - 5 * x * x);
    }
  else if ((x >= -32 && x < -20) || x > 10)
    {
      printf ("x ∈ [–32,–20) ∪ (10, +∞): (x^2-3) %f\n", x * x - 3);
    }
  else
    {
      printf ("функції не існує для заданого ікс\n");
    }
  return 0;
}

