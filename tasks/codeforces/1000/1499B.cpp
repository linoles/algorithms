#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    char buffer[101];
    scanf("%s", buffer);
    string s = buffer;

    // До встречи первых двух единиц подряд, все биты можно сделать нулями. Затем если после
    // такой встречи где-то будет два нуля подряд, то ответ NO

    bool found1 = 0, res = 1;
    for (int i = 1; i < s.size() && res; i++)
    {
      if (s[i - 1] == s[i] && s[i] == '1' && !found1)
        found1 = 1;
      else if (found1 && s[i - 1] == s[i] && s[i] == '0')
        res = 0;
    }

    printf(res ? "YES\n\n" : "NO\n\n");
  }
}