
#include <bits/stdc++.h>
using namespace std;

// Codeforces 363B (1100) - Забор, O(n)
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int h[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &h[i]);

  // Изначально считаем, что первые k - лучший вариант
  int cur_sum = 0, first_item = 0;
  for (int i = 0; i < k; i++)
    cur_sum += h[i];

  // Плавающее окно: смотрим, какие доски лучше вылымать
  int min_sum = cur_sum;
  int best_first = 0;
  for (int i = k; i < n; i++)
  {
    cur_sum -= h[first_item];
    cur_sum += h[i];
    first_item++;

    if (cur_sum < min_sum)
    {
      min_sum = cur_sum;
      best_first = first_item;
    }
  }

  // 1-indexed ответ
  printf("%d", best_first + 1);

  return 0;
}