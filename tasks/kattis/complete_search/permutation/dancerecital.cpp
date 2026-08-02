

#include <bits/stdc++.h>
using namespace std;

// Kattis dancerecital, O(n! * n * m)
int main()
{
  int R;
  scanf("%d", &R);
  string a[R + 1];
  for (int i = 0; i < R; i++)
  {
    char buffer[27];
    scanf(" %s", &buffer);
    a[i] = buffer;
  }

  // Если не отсортировать массив, то выполнится неправильное число перестановок
  sort(a, a + R);

  int best_res = INT_MAX;
  do
  {
    int res = 0;
    // Ищем всех, кто выступает два раза подряд
    for (int i = 1; i < R; i++)
      for (char c1 : a[i - 1])
        for (char c2 : a[i])
          if (c1 == c2)
            res++;

    best_res = min(best_res, res);
  } while (next_permutation(a, a + R));

  printf("%d", best_res);

  return 0;
}