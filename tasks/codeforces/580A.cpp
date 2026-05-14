#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Codeforces 580A (900) - Кефа и первые шаги, O(n)
int main()
{
  int n, cur_len = 0, max_len = 1; // 1 ≤ n ≤ 10^5, 1 ≤ a[i] ≤ 10^9
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (cur_len == 0)
      cur_len++; // Если текущая последовательность закончилась, считаем этот элемент началом
                 // Допустим, a = 2 3 5 4 6 7. При i = 3 (a[i] = 4), cur_len станет 0
                 // Затем на след. итерации (i = 4, a[i] = 6) cur_len увеличится - посчитает предыдущее число 4 началом последовательности
    if (i > 0 && a[i] >= a[i - 1])
      cur_len++; // Если i > 0 (исключаем первую итерацию, в первом if уже посчитали ++ к cur_len)
                 // и текущий элемент больше прошлого, прибавляем cur_len
    else
      cur_len = 0; // иначе считаем, что последовательность закончена
    if (cur_len > max_len)
      max_len = cur_len; // Устанавливаем max_len
  }

  cout << max_len;

  return 0;
}