#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  vector<ll> f(max(n + 1, 3), 1);
  for (int i = 3; i <= n; i++)
    f[i] = f[i-2] + f[i-1];
  
  printf("%lld\n", f[n]);
}