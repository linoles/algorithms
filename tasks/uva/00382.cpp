

#include <bits/stdc++.h>
using namespace std;

// UVa 00382 - Perfection, O(n * m)
int main()
{
  int n;
  vector<int> nums;
  while (scanf("%d", &n) == 1 && n != 0)
    nums.push_back(n);

  printf("PERFECTION OUTPUT\n");
  for (int num : nums)
  {
    printf("%5d  ", num);

    // Поиск и суммирование делителей
    int d = 0;
    for (int x = 1; x < num; x++)
      if (num % x == 0)
        d += x;

    if (d < num)
      printf("DEFICIENT\n");
    else if (d == num)
      printf("PERFECT\n");
    else
      printf("ABUNDANT\n");
  }
  printf("END OF OUTPUT\n");

  return 0;
}