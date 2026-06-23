#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2232B - Выравнивание тортика, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    ll sum = 0;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
      sum += a[i];
      ans = min(ans, sum / (i + 1));
      printf("%lld ", ans);
    }

    printf("\n");
  }

  return 0;
}