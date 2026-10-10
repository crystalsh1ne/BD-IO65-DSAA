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
	  printf ("x > 0 and x <= 5:(x^3-5x^2) %f", x * x * x - 5 * x * x);
	}
      else if (x > 10)
	{
	  printf ("x > 10: (x^2-3) %f", x * x - 3);
	}
      else
	{
	  printf ("функції не існує для заданого ікс");
	}
    }
  else if (x >= -32)
    {
      if (x < -20)
	{
	  printf ("x >= -32 and x < -20: (x^2-3) %f", x * x * x - 5 * x * x);
	}
      else
	{
	  printf ("функції не існує для заданого ікс");
	}
    }
  else
    {
      printf ("функції не існує для заданого ікс");
    }
  return 0;
}
