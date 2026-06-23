#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

// 1474B - Различные делители, O(n^1.5)
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int d;
    cin >> d;

    // Находим первое простое p >= d + 1
    int p = d + 1;
    while (!is_prime(p))
      p++;

    // Находим первое простое q >= p + d
    int q = p + d;
    while (!is_prime(q))
      q++;

    printf("%lld\n", 1LL * p * q);
  }

  return 0;
}