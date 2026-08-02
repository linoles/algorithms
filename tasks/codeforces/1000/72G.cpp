#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  vector<ll> f(n + 1, 0);
  f[0] = 1, f[1] = 1;
  for (int i = 2; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];
  
  printf("%lld\n", f[n]);
}