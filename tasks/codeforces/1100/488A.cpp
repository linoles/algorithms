
#include <bits/stdc++.h>
using namespace std;

// Проверка счастливого часла
bool is_lucky(int a)
{
  while (abs(floor(a)) > 0)
  {
    // Проверяем разряд
    if (abs(a % 10) == 8)
      return 1;
    // Сдвигаем разряды
    a /= 10;
  }

  return 0;
}

// Codeforces 488A (1100) - Гигабашня, O(n * log10m)
int main()
{
  int a;
  scanf("%d", &a);
  bool first = 1;
  int b = 0;

  // Проходимся по числам, пока не встретим счастливое
  for (; !is_lucky(a) || first; a++)
  {
    first = 0;
    b++;
  }

  printf("%d", b);

  return 0;
}
