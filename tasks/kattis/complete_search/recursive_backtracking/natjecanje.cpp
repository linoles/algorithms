#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, s, r, res = 1000;

void gen(int k, int reserve)
{
  bool found = 0;
  // Проходимся по каждому участнику
  for (int i = 0; i < n; i++)
    // Если у участника есть запасная байдарка
    if (reserve & (1 << i))
    {
      // Проверяем, есть ли у соседа справа байдарка
      if (i >= 0 && i < n - 1 && (k & (1 << (i + 1))) == 0)
      {
        // Если нет, то отдаём ему запасную
        found = 1;
        k |= 1 << (i + 1);
        reserve ^= 1 << i;
        gen(k, reserve);
        k ^= 1 << (i + 1);
        reserve |= 1 << i;
      }

      // Проверяем, есть ли у соседа слева байдарка
      if (i > 0 && i <= n - 1 && (k & (1 << (i - 1))) == 0)
      {
        // Если нет, то отдаём ему запасную
        found = 1;
        k |= 1 << (i - 1);
        reserve ^= 1 << i;
        gen(k, reserve);
        k ^= 1 << (i - 1);
        reserve |= 1 << i;
      }
    }

  if (!found)
    res = min(res, n - (int)__builtin_popcount(k)); // Быстрый счёт кол-ва оставшихся без байдарок
}

// Kattis natjecanje
int main()
{
  scanf("%d %d %d", &n, &s, &r);
  int k = (1 << n) - 1, reserve = 0; // Используем маски для скорости (n <= 10)
  for (int i = 0; i < s; i++)
  {
    int temp;
    scanf("%d", &temp);
    temp--;
    k ^= 1 << temp;
  }
  for (int i = 0; i < r; i++)
  {
    int temp;
    scanf("%d", &temp);
    temp--;
    reserve |= 1 << temp;
  }

  gen(k, reserve);
  printf("%d", res);

  return 0;
}