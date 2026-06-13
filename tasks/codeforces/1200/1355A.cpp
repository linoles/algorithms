#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// minDigit f
int min_digit(ll x)
{
  std::string str = std::to_string(x);
  int res = str[0] - '0';
  for (char c : str)
    res = min(res, c - '0');
  return res;
}

// maxDigit f
int max_digit(ll x)
{
  std::string str = std::to_string(x);
  int res = str[0] - '0';
  for (char c : str)
    res = max(res, c - '0');
  return res;
}

// Codeforces 1355A (1200) - Последовательность с цифрами, O(log10 max(a) * K)
int main() {
  int t;
  ll K, a1;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld %lld", &a1, &K);

    // Считаем циклически числа последовательности, сохраняя последнее
    ll cur_a = a1;
    for (ll i = 2; i <= K; i++)
    {
      ll next = cur_a + min_digit(cur_a) * max_digit(cur_a);
      if (next == cur_a) break; // Если следующее число такое же, выходим (minDigit = 0)
      cur_a = next;
    }

    printf("%lld\n\n", cur_a);
  }

  return 0;
}