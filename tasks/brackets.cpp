#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> // Хеш-таблицы
using namespace std;

// Перебор со стеком
bool cycle_solve(string line)
{
  stack<char> items;
  vector<char> opens = {'{', '(', '['};
  unordered_map<char, char> brackets;
  brackets['{'] = '}';
  brackets['('] = ')';
  brackets['['] = ']';

  for (char x : line)
  {
    if (find(opens.begin(), opens.end(), x) != opens.end())
    {
      // Открывающая скобка
      items.push(x);
    }
    else
    {
      // Закрывающая скобка
      if (items.empty() || brackets[items.top()] != x)
        return 0; // Стек пуст, либо в стеке нет такой открывающейся скобки
      else
        items.pop();
    }
  }

  return 1;
}

int main()
{
  string line;
  getline(cin, line);

  cout << ((cycle_solve(line)) ? "YES" : "NO");

  return 0;
}