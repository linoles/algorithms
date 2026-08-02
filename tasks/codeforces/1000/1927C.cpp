

#include <bits/stdc++.h>
using namespace std;

// Codeforces 1927C (1000) - Выбери различные!, O(max(n, m, k))
int main()
{
  int t, n, m, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &n, &m, &k);
    int a[n + 1], b[m + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
      scanf("%d", &b[i]);

    // Заполняем массивы, которые говорят, существует ли нужное число в них
    vector<bool> nums_a(k + 1, 0), nums_b(k + 1, 0);
    for (int i = 0; i < n; i++)
      if (a[i] <= k)
        nums_a[a[i]] = 1;
    for (int i = 0; i < m; i++)
      if (b[i] <= k)
        nums_b[b[i]] = 1;

    // from_a - сколько взято из a, from_b - из b, from_both - если есть в обоих
    int from_a = 0, from_b = 0, from_both = 0;
    bool res = 1;
    for (int i = 1; i <= k; i++)
    {
      int cur_found = 0; // 0 - не найдено, 1 - найдено в a, 2 - найдено в b, 3 - есть в обоих
      if (nums_a[i])
        cur_found = 1;
      if (nums_b[i])
        cur_found = cur_found ? 3 : 2;

      if (cur_found == 0)
      {
        res = 0;
        break;
      }
      else if (cur_found == 1)
        from_a++;
      else if (cur_found == 2)
        from_b++;
      else
        from_both++;
    }

    // Переменные для понимания
    bool are_similar = from_a == from_b && from_a == k / 2; // Взято ли из двух массивов одинаково
    int diff = abs(from_a - from_b);                        // Требуется добавить к наименьшему из from_both
    int remain = from_both - diff;                          // Осталось после добавления
    bool correct_add = remain % 2 == 0 && remain >= 0;      // Можно ли оставшееся разделить по полам

    printf(!res ? "NO\n\n" : ((are_similar || correct_add) ? "YES\n\n" : "NO\n\n"));
  }

  return 0;
}

// Кстати, изначально моё решение дало TLE, т.к. я не додумался сначала создать
// массив с проверкой вхождений и сложность была O(k(n + m))