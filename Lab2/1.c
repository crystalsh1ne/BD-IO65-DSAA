#include <stdio.h>
#include <math.h>

int
main ()
{
  int n;
  int counter = 0;
  printf("n: ");
  scanf ("%d", &n);
  double x;
  printf("x: ");
  scanf("%lf", &x);
  double P = 0.5;
  counter+=1; // "="
  counter+=2; // -n знизу, i = -n
  for (int i = -n; i <= n; i++)
    {
      counter+=3; // ітерації зовн. циклу, i++, i <= n
      double sum = 0.0;
      counter+=2; // i > 0, =
      if (i > 0)
        {
          counter+=1; // j = 1
          for (int j = 1; j <= i; j++)
            {
              sum += M_PI;
              counter+=4; // ітерація, j <= i; j++; +=
            }
        }
      else
        {
          counter+=1; // i < 0
          if (i < 0)
            {
              counter+=2; // -i, j = 1
              for (int j = 1; j <= -i; j++)
                {
                  sum -= M_PI;
                  counter+=4; // так само
                }
            }
        }
      double a = 2 * x - sum;
      counter+=2;
      double b = x + sum;
      counter++;
      P *= (a / b);
      counter+=2;
    }
  printf("Результат для n = %d, x = %lf; пройдено %d кроків: %.7lf\n", n, x, counter, P);
  return 0;
}
