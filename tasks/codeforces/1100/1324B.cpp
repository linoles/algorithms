#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1324B (1100) - Ещё одна задача про палиндромы, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // Если число x через какое-то y (y >= 1) встречается ещё раз, значит можно
    // составить подпоследовательность-палиндром x z x, где z - любое в интервале (x; y)

    // Составляем массив, где индекс - число из a, значение - первая встреча
    vector<int> seen(5001, -1);
    bool found = 0;
    for (int i = 0; i < n; i++)
    {
      if (seen[a[i]] == -1)
        seen[a[i]] = i;
      else if (i - seen[a[i]] >= 2)
      { // Если встретился не первый раз и между ними есть числа
        found = 1;
        break;
      }
    }
    printf(found ? "YES\n" : "NO\n");
  }

  return 0;
}