#include <stdio.h>
#include <math.h>

int
main ()
{
  int n;
  double x;
  int counter = 0;
  double prod = 1.0;
  counter++; // =
  printf("n: ");
  scanf ("%d", &n);
  printf ("x: ");
  scanf ("%lf", &x);
  double pi = -n * M_PI;
  counter+=3; // =, -n, *
  counter+=2; // =, -n знизу для цикла
  for (int i = -n; i <= n; i++)
    {
      prod = prod * (2 * x - pi) / (x + pi);
      pi += M_PI;
      counter+=9;
    }
  double result = 0.5 * prod;
  counter+=2;
  printf ("Результат для n = %d, x = %lf; пройдено %d кроків: %lf\n", n, x, counter, result);
  return 0;
}
