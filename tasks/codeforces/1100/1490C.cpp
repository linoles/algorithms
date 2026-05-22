#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1490C (1100) - Сумма кубов, O(∛n)
int main()
{
  int t;
  ll x;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld", &x);

    // Чтобы не подбирать также b, смотрим a и находим по нему b,
    // затем проверяем, целое ли b число
    bool found = 0;
    for (ll a = 1; a * a * a < x; a++)
    {
      long double b = cbrt((double)(x - a * a * a));
      if (ceil(b) == floor(b))
      {
        found = 1;
        break;
      }
    }

    printf(found ? "YES\n" : "NO\n");
  }

  return 0;
}