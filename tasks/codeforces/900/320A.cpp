#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 320A (900) - Волшебные числа, O(ceil(log10n))
int main()
{
  char n[10]; // 1 ≤ n ≤ 10^9
  scanf("%s", n);

  // Жадный алгоритм: считаем, что число волшебное, затем оппровергаем
  // Ищем все случаи, проверяя последующие разряды, если есть
  // Когда находим 14, пропускаем след. цифру
  // Когда находим 144, пропускаем две след. цифры
  bool found = 1;
  int skip = 0;
  for (int i = 0; i < strlen(n); i++)
  {
    if (skip)
    {
      skip--;
      continue;
    }
    if (n[i] != '1')
    {
      found = 0;
      break;
    }
    else if (i == strlen(n) - 1 || n[i + 1] == '1')
    {
      // Число 1
      continue;
    }
    else if (n[i + 1] == '4' && (i == strlen(n) - 2 || n[i + 2] == '1'))
    {
      // Число 14
      skip = 1;
      continue;
    }
    else if (n[i + 1] == '4' && n[i + 2] == '4')
    {
      // Число 144
      skip = 2;
      continue;
    }
    else
    {
      // Нераспознаваемая последовательность
      found = 0;
      break;
    }
  }

  printf(found ? "YES" : "NO");

  return 0;
}