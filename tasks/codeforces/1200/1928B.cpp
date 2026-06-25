#include <bits/stdc++.h>
using namespace std;

// Codeforces 1928B - Уравняй, O(n * log n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    // Сделать числа равными получится в любом массиве, где max - min <= n - 1 (разброс перстановки)
    // Удаляем дубликаты - они не станут равными
    a.erase(unique(a.begin(), a.end()), a.end());

    // Двумя указателями ищем наибольший такой подмассив
    int l = 0, r = 0, max_len = 0;
    while (r < a.size())
    {
      if (a[r] - a[l] > n - 1)
        l++;
      else
      {
        max_len = max(max_len, r - l + 1);
        r++;
      }
    }

    printf("%d\n\n", max_len);
  }

  return 0;
}