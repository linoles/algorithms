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

    // gcd(lcm(a, b), lcm(b, c)) = gcd(a,c)  <=> a % b == 0 && c % b == 0
    // Для каждого b ∈ [1, n]:
    //   - кол-во a ∈ [1, n] таких, что a % b == 0, равно n / b
    //   - кол-во c ∈ [1, n] таких, что c % b == 0, равно n / b

    ll ans = 0;
    for (int b = 1; b <= n; b++)
      ans += ll(n / b) * ll(n / b); // Для каждого такого a по столько же существующих c
    
    printf("%lld\n\n", ans);
  }
}