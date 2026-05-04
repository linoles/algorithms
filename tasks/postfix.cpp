#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

// Перебор со стеком
int cycle_solve(string line)
{
  stack<int> operands;
  vector<char> operators = {'/', '*', '+', '-'};

  // Решение работает только с числами 0-9, так как мне лень делать нормальное преобразование
  for (char x : line)
  {
    // Операнд
    if (x != ' ' && find(operators.begin(), operators.end(), x) == operators.end())
    {
      operands.push(x - '0');
    }
    // Оператор
    else if (find(operators.begin(), operators.end(), x) != operators.end() && x != ' ')
    {
      // Последние два операнда
      vector<int> nums;
      int res;
      nums.push_back(operands.top());
      operands.pop();
      nums.push_back(operands.top());
      operands.pop();

      // Выполнение операции
      switch (x)
      {
      case '+':
        res = nums[1] + nums[0];
        break;
      case '-':
        res = nums[1] - nums[0];
        break;
      case '*':
        res = nums[1] * nums[0];
        break;
      case '/':
        res = nums[1] / nums[0];
        break;
      }

      // Добавляем результат в стек
      operands.push(res);
    }
  }

  return operands.top();
}

int main()
{
  string line;
  getline(cin, line);

  cout << cycle_solve(line);

  return 0;
}