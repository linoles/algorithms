
#include <bits/stdc++.h>
using namespace std;

// UVa 00639 - Don't Get Rooked, O(2^(n^2) * n^2)
int main()
{
  int n;
  while (true)
  {
    scanf("%d", &n);
    if (n == 0)
      break;

    vector<string> s(n, "\0\0\0\0");
    for (int i = 0; i < n; i++)
    {
      char buffer[n + 1];
      scanf(" %s", &buffer);
      s[i] = buffer;
    }

    // Битовая маска, описывающая, находится ли в конкретной позиции стена
    int walls = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (s[i][j] == 'X')
          walls |= (1 << (i * n + j));

    // Перебираем все возможные варианты расстановки ладей
    int max_t = 0;
    for (int mask = 0; mask < (1 << (n * n)); mask++)
    {
      // i-ный ряд: [n * i; n * i + 3] клетки
      // Проверяем, не стоит ли ладья на стене
      if (mask & walls)
        continue;

      // Расставляем ладьи по маске mask
      int t = 0;
      vector<string> cpy(s.begin(), s.end());
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (mask & (1 << (i * n + j)))
          {
            t++;
            cpy[i][j] = 'R';
          }

      // Проверяем горизонтали
      bool met_r = 0, ok = 1;
      for (int i = 0; i < n && ok; i++) // Ряд
      {
        for (int j = 0; j < n && ok; j++) // Колонка
        {
          if (cpy[i][j] == 'R' && !met_r)
            met_r = 1;
          else if (cpy[i][j] == 'X')
            met_r = 0;
          else if (cpy[i][j] == 'R' && met_r)
            ok = 0;
        }
        met_r = 0;
      }

      if (!ok)
        continue;

      // Проверяем вертикали
      for (int i = 0; i < n && ok; i++) // Колонка
      {
        met_r = 0;
        for (int j = 0; j < n && ok; j++) // Ряд
        {
          if (cpy[j][i] == 'R' && !met_r)
            met_r = 1;
          else if (cpy[j][i] == 'X')
            met_r = 0;
          else if (cpy[j][i] == 'R' && met_r)
            ok = 0;
        }
      }

      if (!ok)
        continue;

      max_t = max(t, max_t);
    }

    printf("%d\n", max_t);
  }

  return 0;
}