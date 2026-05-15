#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Самый быстрый способ нахождения числа Фибоначчи (формула Бине)
int fibo_num(int i)
{
  return (pow((1 + sqrt(5)) / 2, i) - pow((1 - sqrt(5)) / 2, i)) / sqrt(5);
}

// Codeforces 199A (900) - Теорема Хексадесимал, O(k­² * log k), где k - кол-во чисел Фибоначчи до максимального n
int main()
{
  int n; // 0 ≤ n < 10^9
  bool found = false;
  scanf("%d", &n);

  int fibo[45];                // Размер 45 и затем также используется число 45, т.к. это макс. число Фибоначчи меньше 10^9
  for (int i = 0; i < 45; i++) // Заполняем массив чисел Фибоначчи
  {
    fibo[i] = fibo_num(i);
  }

  // Тут есть решения быстрее, но они сложнее и не намного быстрее
  // Поэтому можно просто перебрать a, b (45 * 45 = 2025)
  // Затем подобрать c и проверить, есть ли такой c в fibo (log 45 ~ 6)
  // 45 * 45 * 6 = 12150  - моментально
  for (int a = 0; a < 45; a++)
  {
    for (int b = 0; b < 45; b++)
    {
      int c = n - fibo[a] - fibo[b];
      if (binary_search(fibo, fibo + 45, c) && !found) // Массив отсортирован, можно применить бинарный поиск
      {
        printf("%d %d %d", fibo[a], fibo[b], c);
        found = 1;
        break;
        break;
      }
    }
  }

  if (!found)
    cout << "I'm too stupid to solve this problem";

  return 0;
}