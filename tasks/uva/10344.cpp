
#include <bits/stdc++.h>
using namespace std;

vector<int> a(5);

bool gen(vector<bool> used, int count, int res)
{
  // Если условие выполнено
  if (count == 5 && res == 23)
    return true;
  // Если результат в 23 не достигнут, но уже 5 чисел использовано
  else if (count == 5)
    return false;

  // Пробуем все оставшиеся числа
  for (int i = 0; i < 5; i++)
    if (!used[i])
    {
      used[i] = 1;

      // Пробуем по очереди все операции: +, -, *
      if (gen(used, count + 1, res + a[i]))
        return true;
      if (gen(used, count + 1, res - a[i]))
        return true;
      if (gen(used, count + 1, res * a[i]))
        return true;

      used[i] = 0;
    }

  return false;
}

// UVa 10344 - 23 Out of 5
int main()
{
  while (scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]) && a[0] != 0)
  {
    bool exists = 0;
    // Пробуем первым число каждое
    for (int i = 0; i < 5; i++)
    {
      vector<bool> used(5, 0);
      used[i] = 1;
      if (gen(used, 1, a[i]))
      {
        exists = 1;
        break;
      }
      used[i] = 0;
    }

    printf(exists ? "Possible\n" : "Impossible\n");
  }

  return 0;
}