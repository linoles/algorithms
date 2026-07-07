#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, q, l, r, d;
  scanf("%d", &n);
  ll a[n + 1], temp;
  scanf("%lld", &a[0]);
  int prev = a[0];
  for (int i = 1; i < n; i++)
  {
    scanf("%lld", &temp);
    a[i] = temp - prev;
    prev = temp;
  }

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d %d", &l, &r, &d);
    l--;
    a[l] += d;
    if (r < n)
      a[r] -= d;
  }

  vector<ll> res(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    res[i + 1] = res[i] + a[i];
    printf("%lld ", res[i + 1]);
  }

  return 0;
}