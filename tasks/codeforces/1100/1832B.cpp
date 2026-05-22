#include <iostream>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1832B (1100) - Максимальная сумма, O(n * log n)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    deque<ll> a(n);
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    // Сортируем, чтоб не искать минимум / максимум
    sort(a.begin(), a.end());

    // Заполняем префиксный массив, чтоб быстрее считать сумму чисел в диапазоне
    vector<ll> pref(n + 1, 0);
    for (int w = 1; w < n + 1; w++)
    {
      pref[w] = pref[w - 1] + a[w - 1];
    }

    ll max_sum = 0;
    for (int i = 0; i < n - k; i++)
    {                // i - сколько раз удалили два минимальных
      int j = k - i; // j - сколько раз удалили максимальный элемент
      if (j < 0 || i < 0)
        continue;
      max_sum = max(max_sum, pref[n - j] - pref[2 * i]); // sum(l...r) = pref[r+1] - pref[l]
    }

    printf("%lld\n\n", max_sum);
  }

  return 0;
}