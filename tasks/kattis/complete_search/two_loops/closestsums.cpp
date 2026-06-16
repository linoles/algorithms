#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis closestsums, O(m * n²)
int main()
{
  int n, m, case_ind = 0; // case_ind - для вывода номера теста
  while (scanf("%d", &n) != EOF)
  {
    case_ind++;
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    scanf("%d", &m);
    int b[m + 1];
    for (int i = 0; i < m; i++)
      scanf("%d", &b[i]);

    printf("Case %d:\n", case_ind);
    for (int mx = 0; mx < m; mx++)
    {
      int closest_sum;
      // Флаг для изменения closest_sum в первый раз (нельзя поставить, например, -1, т.к. числа могут быть отрицательными)
      bool first = 1;
      for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
          // Сравниваем по модулям разниц
          if (first || abs(closest_sum - b[mx]) > abs(a[i] + a[j] - b[mx]))
          {
            first = 0;
            closest_sum = a[i] + a[j];
          }

      printf("Closest sum to %d is %d.\n", b[mx], closest_sum);
    }
  }

  return 0;
}