#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1594C (1200) - Сделай их равными, O(n * log n)
int main()
{
  int t, n;
  char c;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %c\n", &n, &c);
    char s[n + 2];
    for (int i = 1; i <= n; i++)
      scanf("%c", &s[i]);

    // Случай, когда уже все символы равны c
    bool already = 1;
    for (int i = 1; i <= n; i++)
      if (s[i] != c)
      {
        already = 0;
        break;
      }

    if (already)
    {
      printf("0\n\n");
      continue;
    }

    // Подбираем x
    int x = 2;
    bool found = 0;
    for (; x <= n; x++)
    {
      bool all_c = 1;
      for (int i = x; i <= n; i += x)
        if (s[i] != c)
        {
          all_c = 0;
          break;
        }

      // Если все индексы, кратные x, равны c, то ответ 1 - этот x
      if (all_c)
      {
        found = 1;
        break;
      }
    }

    if (found)
      printf("1\n%d\n\n", x);
    else
      printf("2\n%d %d\n\n", n, n - 1); // Иначе выводим n, n - 1
  }

  return 0;
}