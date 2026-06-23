#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1873E - Построение аквариума, O(n)
int main()
{
  int t, n, x;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &x);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a, a + n);
    
    // Нужно выбрать наибольшее h, чтобы выполнялось w <= x
    int lo = 0, hi = 2e9, mid;
    while (lo < hi) // O(1), т.к. известны границы и макс. будет log 2e9 итераций
    {
      // Считаем рассматриваемый h
      mid = lo + (hi - lo + 1) / 2;

      // Считаем требуемое w
      ll w = 0;
      for (int i = 0; i < n; i++)
        w += max(0, mid - a[i]);
      
      // Обновляем границы
      if (w > x)
        hi = mid - 1;
      else
        lo = mid;
    }

    printf("%d\n", lo);
  }
  
  return 0;
}