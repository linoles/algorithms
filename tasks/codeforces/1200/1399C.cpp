#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1399C (1200) - Лодочное соревнование, O(m * n²), m = max(w) * 2 - min(w) * 2
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int w[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &w[i]);

    // Минимальное и максимальное s, чтоб не проходиться по лишним весам
    int max_s = *max_element(w, w + n) * 2, min_s = *min_element(w, w + n) * 2;
    int max_found = 0; // Макс. k
    // Для каждого веса s считаем, сколько можно составить пар с таким общим весом
    for (int s = min_s; s <= max_s; s++)
    {
      int cur_found = 0;
      vector<bool> used(n, 0); // Какие спортсмены использовались

      for (int i = 0; i < n; i++)
      {
        if (used[i])
          continue;
        for (int j = i + 1; j < n; j++)
          if (!used[j] && w[i] + w[j] == s)
          {
            cur_found++;
            used[i] = 1;
            used[j] = 1;
            break;
          }
      }

      max_found = max(max_found, cur_found);
    }

    printf("%d\n\n", max_found);
  }

  return 0;
}