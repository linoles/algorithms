#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int k, res = -201;

void gen(int num, int r)
{
  if (abs(num - k) <= abs(res - k))
    res = num;
  if (r >= 2 || abs(res - k) == 0)
    return;

  for (int i = 0; i < 10; i++)
  {
    int from = num % 10, to = i;
    int from_col, from_row, to_col, to_row;

    // Определение позиции последней цифры числа
    if (from == 0)
    {
      from_row = 3;
      from_col = 1;
    }
    else
    {
      from_row = (from - 1) / 3;
      from_col = (from - 1) % 3;
    }

    // Определение позиции этой цифры
    if (to == 0)
    {
      to_row = 3;
      to_col = 1;
    }
    else
    {
      to_row = (to - 1) / 3;
      to_col = (to - 1) % 3;
    }

    // Если цифры равны или цифра ниже и правее
    if (from == to || (to_row >= from_row && to_col >= from_col))
      gen(num * 10 + to, r + 1);
  }
}

// Kattis goodmorning
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &k);

    // Перебираем первую цифру
    for (int i = 0; i < 10; i++)
      gen(i, 0);

    printf("%d\n", res);
  }

  return 0;
}