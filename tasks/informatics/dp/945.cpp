#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  const int SZ = 8; // размер доски
  int a, b;
  scanf("%d %d", &b, &a);
  vector<vector<ll>> dp(2, vector<ll>(SZ, 0));
  dp[0][b-1] = 1;
  int prev = 0;
  for (int i = a; i < SZ; i++)
  {
    dp[!prev][0] = dp[prev][1], dp[!prev][SZ-1] = dp[prev][SZ-2];
    for (int j = 1; j < SZ-1; j++)
      dp[!prev][j] = dp[prev][j-1] + dp[prev][j+1];
    prev = !prev;
  }

  ll sum = 0;
  for (ll x : dp[prev])
    sum += x;
  printf("%lld", sum);
}

/*
До оптимизации:

vector<vector<ll>> dp(SZ, vector<ll>(SZ, 0));
dp[a-1][b-1] = 1;
for (int i = a; i < SZ; i++)
{
  dp[i][0] = dp[i-1][1], dp[i][SZ-1] = dp[i-1][SZ-2];
  for (int j = 1; j < SZ-1; j++)
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
}

ll sum = 0;
for (ll x : dp[7])
  sum += x;
printf("%lld", sum);
*/