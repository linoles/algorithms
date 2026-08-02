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
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    ll mx = 0, mn = 0;
    for (int i = 0; i < n; i++)
    {
      ll new_mx = max(mx - a[i], b[i] - mn);
      ll new_mn = min(mn - a[i], b[i] - mx);
      mx = new_mx, mn = new_mn;
    }
    printf("%lld\n", mx);
  }
}