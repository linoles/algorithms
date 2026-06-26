#include <bits/stdc++.h>
using namespace std;

// Codeforces 911B - Два торта, O(log min(a, b))
int main()
{
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  // Бинарным поиском подбираем x
  int lo = 1, hi = min(a, b);
  while (lo < hi)
  {
    int x = lo + (hi - lo + 1) / 2;
    if (a / x + b / x >= n)
      lo = x;
    else
      hi = x - 1;
  }

  printf("%d", lo);

  return 0;
}