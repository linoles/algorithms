


#include <bits/stdc++.h>
using namespace std;

// Kattis zagrade, O(n! * n)
int main()
{
  char buffer[201];
  scanf("%s", &buffer);
  string s = buffer;

  // В pair: first - открывающая, second - закрывающая скобки
  vector<pair<int, int>> brackets;
  stack<int> st;

  // Ищем все скобки
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      st.push(i);
    else if (s[i] == ')')
    {
      brackets.push_back({st.top(), i});
      st.pop();
    }
  }

  unordered_set<string> out;
  // Перебираем все случаи, не берём случай, когда все скобки уже расставлены
  for (int mask = (1 << brackets.size()) - 1; mask > 0; mask--)
  {
    vector<bool> skip(s.size(), 0);
    // Добавляем скобки, которые должны быть пропущены
    for (int i = 0; i < brackets.size(); i++)
    {
      pair<int, int> br = brackets[i];
      if (mask & (1 << i))
      {
        skip[br.first] = 1;
        skip[br.second] = 1;
      }
    }
    string res;
    // Пропускаем те скобки, которые удалены маской
    for (int i = 0; i < s.size(); i++)
      if (!skip[i])
        res += s[i];
    out.insert(res);
  }

  // Изначально я создал множество, чтоб не дублировать строки, теперь для корректной сортировки, копируем в vector
  vector<string> out_cpy(out.begin(), out.end());
  sort(out_cpy.begin(), out_cpy.end());

  for (string x : out_cpy)
    printf("%s\n", x.c_str());

  return 0;
}