
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1272A (900) - Три друга, O(1)
int main()
{
  int q, a, b, c; // 1 ≤ q ≤ 1000, 1 ≤ a, b, c ≤ 10^9
  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d %d", &a, &b, &c);

    // Сортируем
    if (b > c)
      swap(b, c);
    if (a > b)
      swap(a, b);
    if (b > c)
      swap(b, c);

    // Проверяем сначала, что нужно сделать с b
    if (abs(c - b) > abs(b - a)) // Если b ближе к c, прибавляем
      b++;
    else if (abs(c - b) < abs(b - a)) // Если ближе к a, убавляем
      b--;

    // Дальше сокращаем дистанцию a и b
    if (a < b)
      a++;
    // Теперь дистанцию между c и b или c и a
    if (c > b || c > a)
      c--;

    // Важен именно такой порядок. Например, в случае 49 49 52 у меня возникал неправильный ответ

    // Тут вроде расстояние не выйдет за INT_MAX, но я всё-таки подстраховался, т.к. 2 * 10^9 уже почти лимит
    printf("%lld\n", (long long)(abs(a - b) + abs(a - c) + abs(b - c)));
  }

  return 0;
}