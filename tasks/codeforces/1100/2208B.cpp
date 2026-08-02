

#include <bits/stdc++.h>
using namespace std;

// Codeforces 2208B (1100) - Цикл, O(m * k)
int main()
{
  int t, n, k, p, m;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d %d", &n, &k, &p, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // n карт, разыгрывать только k первых карт, затем положить эту карту в конец,
    // перемещаем самые дешёвые карты среди первых k карт, пока не находим карту p
    // считаем общую стоимость: sum <= m
    int sum = 0, p_ind = p - 1, ans = 0;
    bool last_p = false;
    while (sum < m)
    {
      // Если p в первых k картах, перемещаем её в конец
      if (p_ind <= k - 1)
      {
        ans++;
        rotate(a.begin() + p_ind, a.begin() + p_ind + 1, a.end());
        p_ind = n - 1;
        sum += a[p_ind];
        last_p = true;
        continue;
      }

      // Иначе находим минимальный по энергии элемент и перемещаем в конец
      last_p = false;

      int min_ind = 0;
      for (int i = 1; i < k; i++)
        if (a[min_ind] > a[i])
          min_ind = i;

      sum += a[min_ind];
      rotate(a.begin() + min_ind, a.begin() + min_ind + 1, a.end());
      p_ind--; // Все числа после k точно сместились назад, а если бы p не сместился, то он был бы в k первых
    }

    if (sum > m && last_p)
      ans--;

    printf("%d\n\n", ans);
  }

  return 0;
}
