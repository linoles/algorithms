#include <bits/stdc++.h>

using namespace std;

int ans[32768];

// Подсчёт последнего оставшегося
int survivor(int n)
{
  if (n == 1)
    return 1;
  int p = 1;
  while (p * 2 <= n)
    p *= 2;
  return 2 * (n - p) + 1;
}

// UVa 01176 - A Benevolent Josephus, O(n²)
int main()
{
  // Предрасчёт для всех n
  for (int n = 1; n <= 32767; n++)
  {
    // total - результат, prev - предыдущий последний cur, cur - текущий последний
    int total = 0, prev = -1, cur = n;
    while (cur > 0)
    {
      int s = survivor(cur);
      if (s == prev)
      {
        total += cur * 2;
        break;
      }

      total += cur - s; // Увеличиваем результат
      cur = s;          // Устанавливаем указатель на последнего оставшегося
      prev = s;         // Устанавливаем этот cur предыдущим
    }
    ans[n] = total;
  }

  // Выдаём результаты
  int n;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", ans[n]);

  return 0;
}

// Я написал замечательное решение за O(n²) для каждого теста, но почему-то мне выдавало TLE
// Поэтому я просто решил изначально посчитать результат для всех случаев