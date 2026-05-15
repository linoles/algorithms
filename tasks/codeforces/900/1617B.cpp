#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Codeforces 1617B (900) - Задача про НОД, O(1) на каждый тест
int main()
{
  int t, n, a, b, c; // 1 ≤ t ≤ 10^5, 10 ≤ n ≤ 10^9
                     // Важно заметить, что числа реально огромные
                     // Поэтому тут подходит только O(1) или O(log n) решение
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);

    // Это не моё решение. К сожалению, я не смог придумать такую формулу
    // https://codeforces.com/blog/entry/97920
    if (n % 2 == 0)
    {
      a = n - 3;
      b = 2;
      c = 1;
    } else if (n % 4 == 1) {
      a = floor(n / 2) - 1;
      b = floor(n / 2) + 1;
      c = 1;
    } else if (n % 4 == 3) {
      a = floor(n / 2) - 2;
      b = floor(n / 2) + 2;
      c = 1;
    }

    printf("%d %d %d\n", a, b, c);
  }

  return 0;
}