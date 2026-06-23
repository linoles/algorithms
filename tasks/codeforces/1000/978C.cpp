#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 978C - Письма, O(n + m)
int main()
{
  int n, m, cur_host = 0; // Номер текущего общежития
  scanf("%d %d", &n, &m);
  ll a[n + 1], b, last_b = 0; // last_b - общая сумма b, которые ушли на полные a
  for (int i = 0; i < n; i++)
    scanf("%lld", &a[i]);
  for (int i = 0; i < m; i++)
  {
    scanf("%lld", &b);
    b -= last_b;
    // Двигаемся по общежитиям и уменьшаем b, пока b не будет в пределах номеров текущего общежития
    while (b > a[cur_host])
    {
      last_b += a[cur_host];
      b -= a[cur_host];
      cur_host++;
    }
    printf("%d %lld\n", cur_host + 1, b);
  }

  return 0;
}

// Кстати, тут даётся целых 4 секунды на тест. И у меня может не самое быстрое решение, но оно O(n + m) вот почему:
// Хоть и цикл while вложен в цикл с границами 1...m, но максимально этот while в общем выполнится n раз
// всего за всё время выполнения кода, а не за каждый из b