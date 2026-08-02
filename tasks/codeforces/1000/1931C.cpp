
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1931C (1000) - Снова сделай равными, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // Часть элементов массива уже должна быть x, тогда из что-то вроде x y y y x x мы
    // должны получить x x x x x x

    // Поэтому сначала ищем самую длинную последовательность в начале
    int longest = 0;
    for (int i = 0; a[i] == a[0] && i < n; i++)
      longest++;

    // Теперь, если в конце последовательность др. чисел, сравниваем длины, присваиваем наибольшую
    if (a[n - 1] != a[0])
    {
      int end = 0;
      for (int i = n - 1; a[i] == a[n - 1] && i > 0; i--)
        end++;
      longest = max(end, longest);
    }
    // Иначе и если весь массив не с одинаковыми числами, просто прибавляем в длине первой последовательности
    // длину второй последовательности
    else if (longest != n)
      for (int i = n - 1; a[i] == a[n - 1] && i > 0; i--)
        longest++;

    printf("%d\n\n", n - longest);
  }

  return 0;
}