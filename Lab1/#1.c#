#include <stdio.h>

int
main ()
{
  float x;
  scanf ("%f", &x);
  if (x > 0)
    {
      if (x <= 5)
	{
	  printf ("x > 0 and x <= 5:(x^3-5x^2) %f\n", x * x * x - 5 * x * x);
	}
      else if (x > 10)
	{
	  printf ("x > 10: (x^2-3) %f\n", x * x - 3);
	}
      else
	{
	  printf ("функції не існує для заданого ікс\n");
	}
    }
  else if (x >= -32)
    {
      if (x < -20)
	{
	  printf ("x >= -32 and x < -20: (x^2-3) %f\n", x * x - 3);
	}
      else
	{
	  printf ("функції не існує для заданого ікс\n");
	}
    }
  else
    {
      printf ("функції не існує для заданого ікс\n");
    }
  return 0;
}
