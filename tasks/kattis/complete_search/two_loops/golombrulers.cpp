#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis golombrulers, O()
int main()
{
  // Читаем построчно
  char line[1024];

  while (fgets(line, sizeof(line), stdin))
  {
    int a[26], n = 0;
    char *p = line, *end; // Итератор, читающий числа

    while (*p)
    {
      long val = strtol(p, &end, 10); // Получает число по итератору

      if (p == end)
      {
        p++;
        continue;
      }

      if (n < 26)
        a[n++] = (int)val;
      p = end;
    }

    // 2 - perfect, 1 - missing, 0 - not a ruler
    int status = 2;

    sort(a, a + n); // Сортируем для удобства получения максимума и т.п.

    // Проверяем, является ли линейкой (дубликаты)
    for (int i = 1; i < n; i++)
      if (a[i] == a[i - 1])
      {
        status = 0;
        break;
      }

    // Проверяем линейку на совершенность
    vector<int> missing;
    for (int dist = 1; dist <= a[n - 1] && status != 0; dist++)
    {
      bool found = 0;
      for (int i = 0; i < n - 1; i++)
      {
        if (status == 0)
          break;

        for (int j = i + 1; j < n; j++)
        {
          // Найдено в первый раз
          if (!found && a[j] - a[i] == dist)
            found = 1;
          // Если такая разница встречается не первый раз, это не линейка
          else if (found && a[j] - a[i] == dist)
          {
            status = 0;
            break;
          }
        }
      }

      if (!found)
        missing.push_back(dist); // Если не нашли эту разницу, добавляем в отсутствующие
    }

    // Если что-то отсутствует, то линейка не совершенная
    if (missing.size() != 0 && status != 0)
      status = 1;

    // Вывод
    switch (status)
    {
    case 0:
      printf("not a ruler");
      break;
    case 1:
      printf("missing ");
      for (int num : missing)
        printf("%d ", num);
      break;
    case 2:
      printf("perfect");
      break;
    }

    printf("\n");
  }

  return 0;
}