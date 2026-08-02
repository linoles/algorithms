#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n, m, w, l, h;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    int f[n+2]; f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n+1; i++) f[i] = f[i-1] + f[i-2];
    
    string ans;
    while (m--)
    {
      scanf("%d %d %d", &w, &l, &h);
      ans += (int(w >= f[n] && l >= f[n] && h >= f[n] && max({w, l, h}) >= f[n+1]) + '0');
    }
    printf("%s\n", ans.c_str());
  }
}