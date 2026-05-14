#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

// UVa 00441 - Lotto
int main()
{
  int n;
  vi nums;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  // a, b, c, d, e - индексы
  // Начальное значение у второго -   a + 1, то есть след. индекс после первого
  // Начальное значение у третьего -  b + 1, то есть след. индекс после второго
  // ...
  // a - первый, для него n - 5 граница, чтобы на остальные 5 тоже хватило
  // b - второй, для него n - 4 граница, чтобы на остальные 4 тоже хватило (c, d, e, f)
  // ...
  for (int a = 0; a < n-5; ++a)
  {
    for (int b = a+1; b < n-4; ++b)
    {
      for (int c = b+1; c < n-3; ++c)
      {
        for (int d = c+1; d < n-2; ++d)
        {
          for (int e = d+1; e < n-1; ++e)
          {
            for (int f = e+1; f < n; ++f)
            {
              printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c], nums[d], nums[e], nums[f]);
            }
          }
        }
      }
    }
  }

  return 0;
}