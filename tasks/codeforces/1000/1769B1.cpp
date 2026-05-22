#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Поиск текущего показателя I прогресс-бара
int get_file_progress(int ai, int x)
{
  return floor(100 * x / ai);
}

// Поиск текущего показателя II прогресс-бара
int get_full_progress(vector<int> &a, int x, int sum_all, int i)
{
  int sum_x = 0;
  for (int j = 0; j < i; j++)
    sum_x += a[j];
  sum_x += x;
  return floor(100 * sum_x / sum_all);
}

// Codeforces 1769B1 (*1000) - Копирование файлов I, O(n³), хотя на самом деле n² * макс. a[i]
int main()
{
  int n, sum_all = 0;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    a[i] = temp;
    sum_all += temp; // Сразу находим сумму всех размеров файлов
  }

  printf("\n0\n");
  int last_out = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < a[i]; j++)
    {
      // Тут всего лишь находим прогресс-бар файла и прогресс-бар копирования
      int file_progress = get_file_progress(a[i], j + 1);
      int full_progress = get_full_progress(a, j + 1, sum_all, i);

      // Затем сравниваем и выводим, если такой процент ещё не выводили
      if (file_progress == full_progress && file_progress != last_out)
      {
        printf("%d\n", file_progress);
        last_out = file_progress;
      }
    }
  }

  return 0;
}

// Почему-то они поставили тут тег *особая задача,
// хотя на самом деле решение в лоб работает и не получает TLE