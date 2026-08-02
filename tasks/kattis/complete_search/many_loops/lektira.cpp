
#include <bits/stdc++.h>
using namespace std;

// Kattis lektira, O(n²)
int main()
{
  string s;
  cin >> s;

  // Перебираем все возможные разбиения
  string best_str(100, 'z');
  for (int i = 1; i <= s.size() - 2; i++)       // Индекс первого разбиения
    for (int j = i + 1; j <= s.size() - 1; j++) // Индекс второго разбиения
    {
      // Разбиваем строку
      string first = s.substr(0, i);
      reverse(first.begin(), first.end());
      string second = s.substr(i, j - i);
      reverse(second.begin(), second.end());
      string third = s.substr(j, s.size() - j);
      reverse(third.begin(), third.end());

      string res = first + second + third;
      if (res < best_str)
        best_str = res;
    }

  printf("%s", best_str.c_str());

  return 0;
}