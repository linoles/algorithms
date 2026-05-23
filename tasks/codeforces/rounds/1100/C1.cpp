#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces Round 1100 C1 - Время переворотов (простая версия), O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    ll a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    int k = 0;
    vector<int> opers;
    while (k < n)
    {
      // Проходимся по каждому элементу с конца,
      // так как после операции на i, все a[k], k > i, не поменяются
      for (int i = n - 1; i >= 0; i--)
        // Если число положительное, его надо перевернуть, чтобы минимизировать общую сумму
        if (a[i] > 0LL)
        {
          k++;
          opers.push_back(i + 1);
          // Выполняем операцию - все a[j], j <= i меняем на противоположное
          for (int j = i; j >= 0; j--)
            a[j] = -a[j];
        }
      break;
    }

    printf("%d\n", k);
    for (int oper : opers)
      printf("%d ", oper);
    printf("\n\n");
  }

  return 0;
}

// Пример с 1 теста:
// -1 -2  3 -5  4
//  1  2 -3  5 -4, i = 5
// -1 -2  3 -5 -4, i = 4
//  1  2 -3 -5 -4, i = 3
// -1 -2 -3 -5 -4, i = 2

// Я не знаю, правильно ли это, т.к. я не зарегистрировался,
// но по сути условие минимизирования суммы выполняется
// К сожалению, тут есть шанс получения TLE