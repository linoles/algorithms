#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1428C (1100) - ABBB, O(n)
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    string s;
    cin >> s;

    // Проходим по строке, пока не увидем AB или BB
    int i = 1;
    for (; i < s.size(); i++)
    {
      // Достаточно проверять только этот символ, так как i = 1 гарантирует, что предыдущий
      // существует, а в AB или BB неважно, какой первый, потому что могут быть только A и B
      if (s[i] == 'B')
      {
        s.erase(s.begin() + i - 1);
        s.erase(s.begin() + i - 1);

        // Дальше проверяем оставшуюся строку, учитывая то, что эти два символа могли измениться
        if (s.size() > 2)
          {
            i--;
            if (i > 0) i--;
          }
        else
          i = 0; // После i++, s[i] будет указывать, как раз, на 2 символ
      }
    }

    printf("%d\n", s.size());
  }

  return 0;
}