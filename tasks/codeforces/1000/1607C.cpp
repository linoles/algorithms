#include <iostream>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1607C (1000) - Устранение минимума, O(n * log n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    deque<int> a(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a.begin(), a.end()); // См. примечание ниже

    int cur_min = a[0];
    int res = cur_min;
    int minus = 0;
    while (a.size() > 1)
    {
      a.pop_front(); // Удаляем минимальный

      minus += cur_min;
      cur_min = a[0] - minus;

      res = max(res, cur_min);
    }

    printf("%d\n\n", res);
  }

  return 0;
}

// Достаточно сложная задача в плане нехватки времени. Все оптимизации:
// 1. Сортируем, чтобы каждую итерацию не искать минимум за O(n)
// 2. Используем deque, чтоб грамотно удалять первый элемент за O(1)
// 3. Заместо простого изменения каждого элемента, как вроде и требуется в задаче,
//    мы храним сумму, на которую должно было уменьшиться каждое число массива
// В итоге заместо n(n + n + n) = 3n² (не считая ввода), мы получаем O(n * log n) для сортировки