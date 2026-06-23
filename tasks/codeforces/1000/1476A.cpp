#include <bits/stdc++.h>
using namespace std;

// Codeforces 1476A - Сумма, кратная K, O(1)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    // Нужно найти минимальное S такое, что n <= S <= n * m и S % k == 0
    // Минимальна сумма: S = ceil(n / k) * k, значит m = ceil(ceil(n / k) * k / n)
    printf("%lld\n", (long long)ceil(ceill((long double)n / k) * k / n));
  }

  return 0;
}