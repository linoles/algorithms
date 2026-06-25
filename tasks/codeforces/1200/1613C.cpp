#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1613C - Отравленный кинжал, O(n * log h)
int main()
{
  int t, n;
  ll h;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %lld", &n, &h);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a, a + n); // На всякий случай, т.к. в условии не написано, что a - отсортированный

    // 100^500 = 10^1000. Не знаю, зачем это, но оно явно больше 10^18, поэтому нет разницы
    // Бинарным поиском находим наименьшее k, при котором результат >= h
    ll lo = 0, hi = h;
    while (lo < hi)
    {
      // d = k, т.к. заранее считаем последнюю атаку, в которой гарантированно нанесётся k урона
      ll k = lo + (hi - lo) / 2, d = k;
      // Считаем кол-во урона
      for (int i = 1; i < n; i++)
        d += min((ll)a[i] - a[i - 1], k); // Если получится, наносим k урона, иначе разницу
      if (d < h)
        lo = k + 1;
      else
        hi = k;
    }

    printf("%lld\n\n", lo);
  }

  return 0;
}