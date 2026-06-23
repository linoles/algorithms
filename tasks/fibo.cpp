#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

unordered_map<int, ll> memo;
memo[0] = 0;
memo[1] = 1;

// Фибоначчи с мемоизацией
ll fibo(int n)
{
  else if (memo[n])
    return memo[n];
  memo[n] = fibo(n - 2) + fibo(n - 1);
  return memo[n];
}

int main()
{
  int n;
  scanf("%d", &n);
  for (&[int key, ll value] : memo)
    printf("%lld", value);

  return 0;
}