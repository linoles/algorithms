#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Перебор со стеком
vector<char> cycle_solve(string line)
{
  vector<char> res;
  stack<char> items;
  vector<char> operators = {'/', '*', '-', '+'};
  unordered_map<char, int> prioritets;
  prioritets['/'] = 1;
  prioritets['*'] = 1;
  prioritets['+'] = 0;
  prioritets['-'] = 0;

  // Решение работает только с числами 0-9, так как мне лень делать нормальное преобразование
  for (char x : line)
  {
    if (x == ' ')
      continue;
    // Операнд
    else if (find(operators.begin(), operators.end(), x) == operators.end() && x != '(' && x != ')')
    {
      res.push_back(x);
    }
    // Открывающая скобка
    else if (x == '(')
    {
      items.push(x);
    }
    // Закрывающая скобка
    else if (x == ')')
    {
      while (items.top() != '(')
      {
        res.push_back(items.top());
        items.pop();
      }
      items.pop();
    }
    // Оператор
    else if (find(operators.begin(), operators.end(), x) != operators.end())
    {
      while (!items.empty() && items.top() != '(' && prioritets[items.top()] >= prioritets[x])
      {
        res.push_back(items.top());
        items.pop();
      }
      items.push(x);
    }
  }

  // Оставшиеся операции
  while (!items.empty())
  {
    res.push_back(items.top());
    items.pop();
  }

  return res;
}

int main()
{
  string line;
  getline(cin, line);

  for (char x : cycle_solve(line))
  {
    cout << x << " ";
  }

  return 0;
}