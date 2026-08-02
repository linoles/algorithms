
#include <bits/stdc++.h>
using namespace std;

// UVa 00151 - Power Crisis, O(n³)
int main()
{
  int n;
  while (scanf("%d", &n) && n != 0)
  {
    int m = 1;
    // Перебираем m
    for (; m < n; m++)
    {
      bool ok = 1;
      int it = 1;
      vector<bool> used(n, 0);
      used[0] = 1; // Уже считаем отключенным
      for (int i = 0; i < n - 1 && ok; i++)
      {
        // Симулируем процесс перехода к следующему району
        int t = 0;
        while (t < m)
        {
          it++;
          if (it > n)
            it = it % n;
          if (!used[it - 1])
            t++;
        }

        // Отмечаем, чтоб пропустить в следующие разы
        used[it - 1] = 1;

        if (it == 13 && i != n - 2)
          ok = 0;
      }

      if (ok)
      {
        printf("%d\n", m);
        break;
      }
    }
  }

  return 0;
}