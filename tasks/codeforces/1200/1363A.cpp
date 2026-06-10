#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1363A (1200) - Выбор нечётных, O(n)
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

    // Пусть сумма x элементов - sum, odds - кол-во нечётных,
    // тогда получится сделать sum нечётным, если odds % 2 == 1,

    // Значит, нужно найти, можно ли вместить в массив из x элементов нечётное кол-во
    // нечётных чисел и заполнить оставшееся место чётными

    int odds = 0, evens = 0;

    for (int i = 0; i < n; i++)
    {
      if (a[i] % 2 == 0)
        evens++;
      else
        odds++;
    }

    // ((odds % 2 == 0) ? odds - 1 : odds) вычитает единицу из кол-ва нечётных, если оно чётно
    // Первое условие проверяет, хватит ли чётных
    // odds == 0 - тогда не сделать нечётную сумму
    // (x % 2 == 0 && evens <= 0) - если нужно хотя бы одно чётное, а их 0
    if (evens < x - ((odds % 2 == 0) ? odds - 1 : odds) || odds == 0 || (x % 2 == 0 && evens <= 0))
      printf("No\n");
    else
      printf("Yes\n");
  }

  return 0;
}