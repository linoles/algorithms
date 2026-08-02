
#include <bits/stdc++.h>
using namespace std;

// Kattis blackfriday, O(n) - erase может быть O(n), но там максимум 6 значений, поэтому коллизий не будет
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // unique_a: ключ - результат, значение - индекс встречи
  unordered_map<int, int> unique_a;
  int mask = 000000; // 1 - использовано, 0 - нет
  for (int i = 0; i < n; i++)
  {
    if (unique_a.erase(a[i])) // Если встречался, удаляем и отмечаем, что такие больше не принимаются
      mask |= (1 << a[i]);
    if (mask & (1 << a[i])) // Если не принимаются, возвращаемся
      continue;
    unique_a[a[i]] = i + 1; // 1-indexed
  }

  // Проходимся, ищем максимальный результат
  int max_ind = -1, max_num = -1;
  for (const auto &[res, ind] : unique_a)
    if (max_num < res)
    {
      max_ind = ind;
      max_num = res;
    }

  if (max_ind == -1)
    printf("none");
  else
    printf("%d", max_ind);

  return 0;
}