
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// UVa 00616 - Coconuts, Revisted, O(n)
int main()
{
  // Коротко говоря, вот то, что случилось в задаче с 5 людьми и обезьяной:
  // monkey += t % 5 (было всегда 1); t -= (t // 5 + 1); для каждого i (от 0 до 4)
  // В итоге получилось, что t % 5 = 0
  ll n; // Не сказано, какие ограничения, поэтому везде использую ll на всякий случай
  while (scanf("%lld", &n) && n != -1)
  {
    // Максимальное кол-во людей - √n: при большем значении кокосы уйдут в минус
    ll p = ceill(sqrtl(n));
    for (; p >= 1; p--)
    {
      ll t = n;
      bool ok = 1;
      for (int i = 0; i < p && ok; i++)
      {
        // Проверяем, остался ли ровно один кокос
        if (t % p != 1)
          ok = 0;
        ll minus = t / p + 1;
        t -= minus;
      }

      if (!ok)
        continue;
      // Важно ещё проверить, что кол-во кокосов не стало отрицательным
      if (t % p == 0 && t >= 0)
        break;
    }

    if (p == 0)
      printf("%lld coconuts, no solution\n", n);
    else
      printf("%lld coconuts, %d people and 1 monkey\n", n, p);
  }

  return 0;
}
