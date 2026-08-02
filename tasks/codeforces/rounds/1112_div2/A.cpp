#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int w[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &w[i]);

    if (n % 2 != 0)
    {
      printf("NO\n\n");
      continue;
    }

    int lo = 0, hi = 1e9;
    for (int i = 0; i < n && lo <= hi; i += 2)
    {
      lo = max(lo, w[i + 1] + 1);
      hi = min(hi, w[i] - 1);
    }

    printf((lo <= hi) ? "YES\n\n" : "NO\n\n");
  }
}