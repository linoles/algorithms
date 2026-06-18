#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis prinova, O(n)
int main()
{
  int n, a, b;
  scanf("%d", &n);
  int boys[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &boys[i]);
  scanf("%d %d", &a, &b);

  sort(boys, boys + n);

  // Находим самый большой промежуток [boys[i]; boys[i + 1]] и располагаем новое имя по середине
  int res = -1, res_pos = -1;
  for (int i = 1; i < n; i++)
  {
    if (boys[i] < a || boys[i - 1] > b)
      continue;
    int dist = (boys[i] - boys[i - 1]) / 2;
    if (dist % 2 != 1)
      dist++;
    int pos = min(b, max(a, dist + boys[i - 1]));
    if (pos % 2 != 1)
    {
      if (min(pos - 1 - boys[i - 1], boys[i] - pos + 1) >= min(pos + 1 - boys[i - 1], boys[i] - pos - 1))
        pos--;
      else
        pos++;
    }
    if (res < min(pos - boys[i - 1], boys[i] - pos))
    {
      res = min(pos - boys[i - 1], boys[i] - pos);
      res_pos = pos;
    }
  }

  if (a <= boys[0] && res < boys[0] - ((a % 2 == 1) ? a : a + 1))
  {
    res = boys[0] - ((a % 2 == 1) ? a : a + 1);
    res_pos = (a % 2 == 1) ? a : a + 1;
  }

  if (b >= boys[n - 1] && res < ((b % 2 == 1) ? b : b - 1) - boys[n - 1])
  {
    res = ((b % 2 == 1) ? b : b - 1) - boys[n - 1];
    res_pos = (b % 2 == 1) ? b : b - 1;
  }

  printf("%d", res_pos);

  return 0;
}