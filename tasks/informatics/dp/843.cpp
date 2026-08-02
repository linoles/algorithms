#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  vector<ll> a(n + 1, 1);
  for (int i = 2; i <= n; i++)
  {
    if (i % 2 == 0)
      a[i] = a[i/2] + a[i/2-1];
    else
      a[i] = a[i/2] - a[i/2-1];
  }

  printf("%lld\n", a[n]);
}