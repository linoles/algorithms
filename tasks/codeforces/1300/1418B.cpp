#include <bits/stdc++.h>
using namespace std;

// Codeforces 1418B - Отрицательные префиксы, O(n * log n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1], l[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &l[i]);

    // Получаем все разблокированные числа
    vector<int> nums;
    for (int i = 0; i < n; i++)
      if (l[i] == 0)
        nums.push_back(a[i]);

    // Лучшее решение будет - отсортировать массив в убывающем порядке,
    // тогда преф. суммы будут наибольшими
    sort(nums.begin(), nums.end(), greater<int>());

    // Собираем массив обратно
    int c = 0;
    for (int i = 0; i < n; i++)
      if (l[i] == 0)
        a[i] = nums[c++];

    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n\n");
  }

  return 0;
}