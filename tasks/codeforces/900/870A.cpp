#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 870A (900) - Поиск красивых чисел, O(n²)
int main()
{
  int n, m, min_res = 10;
  bool found = false; // 1 ≤ n, m ≤ 9
  scanf("%d %d", &n, &m);
  int a[n], b[m]; // 1 ≤ a[i], b[i] ≤ 9
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }

  // Проверка, есть ли схожие элементы в массивах
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i] == b[j] && a[i] < min_res)
      {
        min_res = a[i];
      }
    }
  }

  if (!found) // Если нет схожих чисел
  {
    int min_num = min(*min_element(a, a + n), *min_element(b, b + m)); // Десятки - минимальное число
    int max_num = max(*min_element(a, a + n), *min_element(b, b + m)); // Единицы - минимальное число в другом массива
    cout << min_num * 10 + max_num;
  }
  else
  {
    cout << min_res; // Если есть схожие числа в массивах, выводим наименьшее
  }

  return 0;
}