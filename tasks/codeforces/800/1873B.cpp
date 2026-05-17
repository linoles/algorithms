#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1873B (800) - Хороший ребёнок, O(n)
int main()
{
  int t, n; // 1 ≤ t ≤ 10^4, 1 ≤ n ≤ 9
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }

    // Находим минимальный элемент и его индекс,
    // Чтобы итоговое произведение было наибольшим
    int min_el = a[0];
    int min_ind = 0;
    for (int i = 0; i < n; i++)
    {
      if (min_el > a[i])
      {
        min_el = a[i];
        min_ind = i;
      }
    }
    a[min_ind] = min_el + 1; // Меняем

    // Находим результат
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
      res *= a[i];
    }

    printf("%lld\n", res);
  }

  return 0;
}