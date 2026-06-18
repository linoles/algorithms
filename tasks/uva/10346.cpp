#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// UVa 10346 - Peter's Smoke, O(-)
int main()
{
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF)
  {
    // res - итоговое число выкуренных сигарет, r - остаток окурков
    int res = 0, r = 0;
    while (n > 0)
    {
      res += n;   // Прибавляем к итогу
      r += n % k; // Оставшиеся окурки
      n /= k;     // Выкуривает сигареты и из окурков делает n / k новых сигарет

      // Когда остатки могут собраться в сигарету
      if (r >= k)
      {
        int plus = floor(r / k);
        r -= plus * k;
        n += plus;
      }
    }

    printf("%d\n", res);
  }

  return 0;
}