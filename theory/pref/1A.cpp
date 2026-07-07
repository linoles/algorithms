#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  vector<ll> pref(n + 1, 0);
  printf("0");
  for (int i = 0; i < n; i++)
  {
    pref[i + 1] = pref[i] + a[i];
    printf(" %lld", pref[i + 1]);
  }

  return 0;
}