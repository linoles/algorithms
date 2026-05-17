#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1791D - Непересекающееся разделение, O(n)
int main()
{
  int t, n; // 1 ≤ t ≤ 10^4, 2 ≤ n ≤ 2*10^5
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    int pref[n];  // Это кол-во уникальных символов в s[0...i]
    int seen = 0; // Битмаска для полной скорости
                  // Ограничения задачи не заставляют её использовать
                  // Но для практики полезно, тут также подошёл бы bool[26], неважно
    for (int i = 0; i < n; i++)
    {
      seen |= (1 << (s[i] - 'a'));        // Ставим единицу в нужном бите
                                          // s[i] - 'a' превращает char в индекс в алфавите (0...25), т.к. 'a' = индексу первой буквы
                                          // 1 << (s[i] - 'a') превращает это в двоичное представление, а |= включает нужный бит или оставляет, как есть
      pref[i] = __builtin_popcount(seen); // Подсчёт единичных бит в числе
    }

    int suff[n]; // Это кол-во уникальных символов в s[i...n-1]
    seen = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      seen |= (1 << (s[i] - 'a'));
      suff[i] = __builtin_popcount(seen);
    }

    // Подбираем лучшие субстроки
    int max_res = 0;
    for (int i = 0; i < n - 1; i++)
    {
      int cur_sum = pref[i] + suff[i + 1]; // Кол-во уникальных в первой подстроке (0...i)
                                           // + кол-во уникальных во второй (i+1...n-1)
      if (cur_sum > max_res)
        max_res = cur_sum;
    }

    printf("%d\n", max_res);
  }

  return 0;
}