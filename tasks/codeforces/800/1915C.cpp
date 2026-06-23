#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1915C - Можно ли построить квадрат?, O(n)
int main()
{
  int t, n;
  ll temp;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%lld", &temp);
      sum += temp;
    }

    // Проверяем, является ли квадрат суммы целым числом
    printf((floor(sqrtl(sum)) == ceill(sqrtl(sum))) ? "YES\n" : "NO\n");
  }

  return 0;
}