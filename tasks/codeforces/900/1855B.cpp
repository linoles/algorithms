#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1855A (900) - Наибольший интервал делителей, O(1)
int main()
{
  // Находим список значений lcm(1, 2, ..., k)
  vector<ll> lcm_list;
  ll cur_lcm = 1;
  for (int k = 1;; k++)
  {
    ll g = gcd(cur_lcm, (ll)k);
    if (cur_lcm / g * k > (ll)1e18)
      break;
    cur_lcm = cur_lcm / g * k;
    lcm_list.push_back(cur_lcm);
  }

  int t; // 1 ≤ t ≤ 10^4
  ll n;  // 1 ≤ n ≤ 10^18
  scanf("%d", &t);

  while (t--)
  {
    scanf("%lld", &n);

    int res = 1;
    ll cur = 1;
    for (int k = 2;; k++)
    {
      ll g = gcd(cur, (ll)k);
      if (cur / g > (ll)1e18 / k)
        break;
      cur = cur / g * k;
      if (n % cur == 0)
        res = k;
      else
        break;
    }
    
    printf("%d\n", res);
  }
}