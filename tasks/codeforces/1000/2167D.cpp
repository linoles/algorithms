
#include <bits/stdc++.h>
using namespace std;

// Codeforces 2167D (1000) - Ещё одна задача с массивами, O(n), но на самом деле 30n итераций макс.
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    long long a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    // Ответом будет именно простое число, т.к. иначе ответ делится на простое число, на которое делится и этот найденный предварительный ответ
    int prime_nums[31] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
    int min_res = 113;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 31; j++)
        if (a[i] % prime_nums[j] != 0)
        {
          min_res = min(min_res, prime_nums[j]);
          break; // Дальше числа только больше
        }

    printf("%d\n\n", min_res);
  }

  return 0;
}