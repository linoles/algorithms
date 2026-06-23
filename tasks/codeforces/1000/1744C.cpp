#include <bits/stdc++.h>
using namespace std;

// Codeforces 1744C - Светофор, O(n)
int main()
{
  int t, n;
  char c;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %c", &n, &c);
    char buffer[n + 1];
    scanf(" %s", &buffer);
    string s = buffer;

    if (c == 'g')
    {
      printf("0\n");
      continue;
    }

    // Максимальное ожидание и индекс встретившегося c
    int max_res = 0, searching_start = -1;
    for (int i = 0; i < n; i++)
    {
      // Обновляем индекс
      if (s[i] == c && searching_start == -1)
        searching_start = i;
      // Когда встретился зелёный свет
      else if (s[i] == 'g' && searching_start != -1)
      {
        max_res = max(i - searching_start, max_res);
        searching_start = -1;
      }
    }

    // Случай, когда строка закончилась, а зелёный цвет не найден
    // Тогда ищем первый зелёный цвет, и гарантированно больше нет символов c
    if (searching_start != -1)
      for (int i = 0; i < n; i++)
        if (s[i] == 'g')
        {
          max_res = max(max_res, i + (n - searching_start));
          break;
        }

    printf("%d\n", max_res);
  }

  return 0;
}