#include <bits/stdc++.h>
#include <vector>
#include <algorithm> // next_permutation
using namespace std;
typedef vector<tuple<int, int, int>> vti;

// UVa 11742 - Social Constraints
int main()
{
  // 0 <= n <= 20,  0 <= m <= 20
  int n, m;

  // Чтение пока ввод не будет 0 0
  while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0))
  {
    vti consts;

    // Чтение m элементов a, b, c
    for (int i = 0; i < m; i++)
    {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      consts.push_back({a, b, c});
    }

    int p[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // При наибольшем n
    int res = 0;

    do
    {
      bool valid = 1;                       // Изначально предполагаем, что выражение истинно, далее если не оппровергли, так и остаётся
      for (tuple<int, int, int> x : consts) // Прохождение по всей рассадке
      {
        int a = get<0>(x), b = get<1>(x), c = get<2>(x); // Получение элементов из tuple

        int pos_a, pos_b; // Нахождение позиций
        for (int i = 0; i < n; i++)
        {
          if (p[i] == a)
            pos_a = i;
          if (p[i] == b)
            pos_b = i;
        }

        int dist = abs(pos_a - pos_b); // Расстояние между подростками

        if (c > 0 && dist > c)
          valid = false; // c > 0  =>  |a - b| должны быть <= c
        else if (c < 0 && dist < -c)
          valid = false; // c < 0  =>  |a - b| должны быть >= |c|
      }
      if (valid)
        res++; // Тест подходит
    } while (next_permutation(p, p + n)); // p - начальная граница, p + n - обрезание до n элементов

    printf("%d\n", res); // Результат
  }
}