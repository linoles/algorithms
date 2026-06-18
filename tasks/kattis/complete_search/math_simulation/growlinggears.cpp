#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis growlinggears, O()
int main()
{
  int p, n, a, b, c;
  scanf("%d", &p);
  while (p--)
  {
    scanf("%d", &n);
    double max_t = INT_MIN;
    int max_ind = -1;
    for (int i = 0; i < n; i++)
    {
      scanf("%d %d %d", &a, &b, &c);

      // T = -aR² + bR + c
      // T'(R) = -2aR + b
      // В т. максимума T' = 0: -2aR + b = 0, 2aR = b, R = b/2a
      // Подставляем: T = (-a * b²) / 4a² + b²/2a + c = -b²/4a + b²/2a + c = (-b² + 2b²)/4a + c = b²/4a + c
      double t = double(b * b) / double(4.0 * a) + c;
      if (t > max_t)
      {
        max_t = t;
        max_ind = i;
      }
    }

    printf("%d\n\n", max_ind + 1);
  }

  return 0;
}