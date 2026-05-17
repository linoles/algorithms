#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1850D (900) - Сбалансированный раунд, O()
int main()
{
  int t, n, k; // 1 ≤ t ≤ 1000, 1 ≤ n ≤ 2 * 10^5, 1 ≤ k ≤ 10^9
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }

    sort(a, a + n);
    int res = 0, deleted = 0; // кол-во уже удалённых элементов
    vector<int> mb_res = {};  // Возможные ответы, когда удаляем подотрезок, хотя др. подотрезок несбалансированный
    for (int i = 1; i < n; i++)
    {
      // Если на i нарушается сбалансировка
      if (a[i] - a[i - 1] > k)
      {
        mb_res.push_back(max(i - deleted, n - i) + deleted); // Возможный ответ
        res += min(i - deleted, n - i);                      // Сам ответ: удаляем либо диапазон до, либо после
        if (n - i <= i - deleted)                            // Если удалили то, что после, дальше нечего смотреть
          break;
        deleted += min(i - deleted, n - i);
      }
    }

    // Если есть возможные ответы, то ищем минимальное среди всех ответов
    printf("%d\n\n", (mb_res.size() == 0) ? res : min(res, *min_element(mb_res.begin(), mb_res.end())));
  }

  return 0;
}