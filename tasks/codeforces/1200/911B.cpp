#include <bits/stdc++.h>
using namespace std;

// Codeforces 911B - Два торта, O()
int main()
{
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  int lo = 1, hi = min(a, b);
  while (lo < hi)
  {
    int x = lo + (hi - lo + 1) / 2;
    bool can = a / x + b / x >= n && b >= x && a >= x;
    if (can)
      lo = x;
    else
      hi = x - 1;
  }

  printf("%d", lo);

  return 0;
}