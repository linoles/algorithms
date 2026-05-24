#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 66B (1100) - Петя и деревня, O(n²)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int max_len = 0;
  // Проверяем все случаи расстановки дождя
  for (int i = 0; i < n; i++)
  {
    int cur_field = a[i];
    int len = 1;

    // Проверяем то, что слева
    for (int l = i - 1; l >= 0; l--)
    {
      if (a[l] > a[l + 1])
        break;
      else
        len++;
    }
    // Проверяем то, что справа
    for (int r = i + 1; r < n; r++)
    {
      if (a[r - 1] < a[r])
        break;
      else
        len++;
    }

    // И выявляем лучший
    max_len = max(max_len, len);
  }

  printf("%d", max_len);

  return 0;
}