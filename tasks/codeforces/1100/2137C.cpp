#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2137C (1100) - Максимальная чётная сумма, O(1)
int main()
{
  int t;
  ll a, b;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld %lld", &a, &b);

    if (a % 2 == 1 && b % 2 == 1)
    {
      printf("%lld\n", 1 + a * b);
      continue;
    }

    if (a == b || (a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 4 == 0))
    {
      printf("%lld\n", 2 + a * (b / 2));
      continue;
    }

    if ((a % 2 == 0 && b % 2 == 1) || (b % 4 != 0 && a % 2 == 1))
    {
      printf("-1\n");
      continue;
    }
  }

  return 0;
}