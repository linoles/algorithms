#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char buffer[n];
    scanf("%s", &buffer);
    string s = buffer;

    int tr = 0;
    forn(i, n - 1) if (s[i] != s[i + 1]) tr++;

    if (tr == 1)
      printf("2\n");
    else
      printf("1\n");
  }
}