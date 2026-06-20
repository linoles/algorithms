#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s;

int ch_to_int(char x)
{
  return (x - 'a' > 0) ? x - 'a' : x - 'A';
}

// O(n!)
void gen(string cur, vector<bool> &used)
{
  if (cur.size() == s.size())
  {
    printf("%s\n", cur.c_str());
    return;
  }

  for (char x : s)
    if (!used[ch_to_int(x)])
    {
      cur.push_back(x);
      used[ch_to_int(x)] = 1;
      gen(cur, used);
      cur.pop_back();
      used[ch_to_int(x)] = 0;
    }
}

// Задача: дана строка S. Нужно вывести все перестановки символов
int main()
{
  char buffer[2001];
  scanf("%s", buffer);
  s = buffer;

  vector<bool> empty('Z' + 1, 0);
  gen("", empty);

  return 0;
}