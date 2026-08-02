#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; char c; string s = "codeforces";
  scanf("%d", &t);
  while (t--)
  {
    scanf(" %c", &c);
    printf((s.find(c) != -1) ? "YES\n" : "NO\n");
  }
}