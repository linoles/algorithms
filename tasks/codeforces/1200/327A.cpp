#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 327A (1200) - Игра с переворачиванием, O(n³)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // Находим индексы всех нулей и смотрим, насколько увеличится кол-во единиц
  vector<int> zeros;
  for (int i = 0; i < n; i++)
    if (a[i] == 0)
      zeros.push_back(i);

  // Изначально просчитываем случай, когда меняем значения всех чисел на противоположные
  int max_sum = 0;
  for (int i = 0; i < n; i++)
    max_sum += 1 - a[i];

  int cur_sum = 0;

  // Случай, когда надо поменять только одну единицу
  for (int i = 0; i < n; i++)
    cur_sum += a[i];

  max_sum = max(max_sum, cur_sum - 1);
  cur_sum = 0;

  // Тут уже проверяем все случаи, когда меняем 0 ... 0
  for (int i = 0; i < (int)zeros.size() - 1; i++)
    for (int j = i + 1; j < zeros.size(); j++)
    {
      for (int z = 0; z < n; z++)
      {
        int value = a[z];
        if (z >= zeros[i] && z <= zeros[j])
          value = 1 - value;
        cur_sum += value;
      }
      max_sum = max(max_sum, cur_sum);
      cur_sum = 0;
    }

  printf("%d\n\n", max_sum);

  return 0;
}