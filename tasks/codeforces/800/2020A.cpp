#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Codeforces 2020A (800) - Минимальное число операций, O(log n  по осн. k)
int main()
{
  int t;          // 1 ≤ t ≤ 10^4
  long long n, k; // 1 ≤ n, k ≤ 10^9
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld %lld", &n, &k); // k^x = n, x = logkn
    if (k == 1)
    {
      printf("%d\n", n);
      continue;
    }

    // Решение: переводим n в k-ую с.с., складываем цифры результата
    int res = 0;
    while (n != 0)
    {
      res += n % k;
      n /= k;
    }

    printf("%d\n", res);
  }

  return 0;
}