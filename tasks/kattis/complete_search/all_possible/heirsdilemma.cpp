#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis heirsdilemma, O(1)
int main()
{
  int l, h;
  scanf("%d %d", &l, &h);

  int t = 0;
  // Здесь бит i с конца указывает, используется ли цифра i + 1
  for (int mask = 63; mask <= 504; mask++)
  {
    // Пропускаем те, в которых не 6 цифр
    if (__builtin_popcount(mask) != 6)
      continue;

    // Собираем все цифры
    vector<int> nums;
    for (int i = __builtin_ctz(mask); i < 9; i++)
      if (mask & (1 << i))
        nums.push_back(i + 1);

    // Проходимся по всем возможным числам из этих цифр
    do
    {
      // Собираем число
      int n = 0, r = 5;
      for (int i : nums)
        n += i * pow(10, r--);

      if (n > h || n < l)
        continue;

      // Проверяем кратность
      bool ok = 1;
      for (int i : nums)
        if (n % i != 0)
          ok = 0;

      if (ok)
        t++;
    } while (next_permutation(nums.begin(), nums.end()));
  }

  printf("%d", t);

  return 0;
}

// Это O(1), потому что:
// 1. Цикл с масками с константным числом итераций
// 2. Все циклы, которые зависят от nums (int i : nums) O(1), т.к. nums.size() всегда 6,
// поэтому и перебор всех permutations - это O(1) (6! итераций)