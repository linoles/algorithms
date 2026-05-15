#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1732B (900) - Угу, O(n)
int main()
{
  int t, n; // 1 ≤ t ≤ 10^4, 1 ≤ n ≤ 10^5
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char s[n];
    scanf("%s", &s);

    // Ищем индекс первой единицы
    int start = 0;
    while (start < n && s[start] == '0')
      start++;

    // Если строка из нулей
    if (start == n)
    {
      printf("0\n");
      continue;
    }

    // Просматриваем кол-во переходов:
    // Например, s = "00100010"
    // 00100010   001->000->1->0 (3)
    int res = 0;
    for (int i = start + 1; i < n; i++)
      if (s[i] != s[i - 1])
        res++;

    printf("%d\n\n", res);
  }

  return 0;
}