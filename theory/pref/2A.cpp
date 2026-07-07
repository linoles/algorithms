#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, temp, q, l, r;
  scanf("%d", &n);
  // Не храним массив a, а сразу заполняем преф. суммы, т.к. a не нужен будет
  vector<ll> a(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &temp);
    a[i + 1] = a[i] + temp;
  }

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d", &l, &r);
    printf("%lld\n", a[r] - a[l - 1]);
  }

  return 0;
}