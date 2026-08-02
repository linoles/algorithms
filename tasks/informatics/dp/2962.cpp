#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
map<pair<int, int>, ll> memo = { {{0, 0}, 1} }; // мемоизация
ll dp(int a, int b)
{
  if (a < 0 || b < 0 || a >= n || b >= m) return 0;                    // выход за границы
  pair<int, int> p = {a, b};                                           // координаты
  if (memo.count(p)) return memo[p];                                   // если уже вычислено
  int val = dp(a-1, b-2) + dp(a-2, b-1) + dp(a-2, b+1) + dp(a+1, b-2); // находим
  return memo[p] = val;                                                // присваиваем и возвращаем
}

int main()
{
  scanf("%d %d", &n, &m);
  printf("%lld", dp(n-1, m-1));
}

// Здесь нельзя заполнять циклически, т.к. тогда бы вызывались значения, которые ещё не были заполнены:
// dp[a+1][b-2], если заполнять сверху вниз; dp[a-2][b+1], если заполнять слева направо