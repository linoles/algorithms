#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2193D - Игра с монстрами, O()
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1], b[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + b[i - 1];

    // Нужно найти лучший x, при котором x * результат будет максимальным
    // При этом x лучше всего выбрать из a, а для получения результата можно использовать D&C

    sort(a, a + n);

    ll max_res = 0;
    // На монстра i тратится b[i] мечей
    for (int i = 0; i < n; i++)
    {
      int x = a[i];                // С таким x можно использовать ровно n - i мечей (исключая дубликаты)
      if (i != 0 && x == a[i - 1]) // Если уже встречался, пропускаем
        continue;

      // Находим кол-во мечей и результат за O(log n)
      // Для нахождения результата находим первое попадание, где pref[i] > swords и вычитаем 1, получая наибольший pref[i] <= swords
      ll swords = n - i, res = upper_bound(pref.begin(), pref.end(), swords) - pref.begin() - 1;
      max_res = max(max_res, (ll)res * x);
    }

    printf("%lld\n", max_res);
  }

  return 0;
}