#include <bits/stdc++.h>
using namespace std;

// Codeforces 166A - Ранклист, O(n * log n)
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  pair<int, int> pt[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d %d", &pt[i].first, &pt[i].second);

  // Сортируем по правилу из описания задачи
  sort(pt, pt + n,
       [&](pair<int, int> &a, pair<int, int> &b)
       {
         return a.first > b.first || (a.first == b.first && b.second > a.second);
       });

  // Теперь в отсортированной таблице результатов ищем ответ
  int cur_start = 1;
  bool found = 0;
  for (int i = 1; i < n; i++)
  {
    pair<int, int> res = pt[i], prev_res = pt[i - 1];
    // Если текущий результат не совпадает с предыдущим
    if (res.first != prev_res.first || res.second != prev_res.second)
    {
      // Если нужное место в текущем диапазоне
      if (k >= cur_start && k <= i)
      {
        printf("%d\n", i - cur_start + 1);
        found = 1;
        break;
      }
      cur_start = i + 1;
    }
  }

  if (!found)
    printf("%d\n", n - cur_start + 1);

  return 0;
}