#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s, d;
vector<int> results = {};

// sum - текущая прибыль/убыток, в m: 1 - месяц прибыльный, 0 - убыточный
void gen(vector<bool> m, int sum)
{
  bool ok = 1;
  // Считаем все подпоследовательности длины 5
  for (int i = 0; i < (int)m.size() - 4; i++)
    if (((!m[i] ? -d : s) + (!m[i + 1] ? -d : s) + (!m[i + 2] ? -d : s) + (!m[i + 3] ? -d : s) + (!m[i + 4] ? -d : s)) >= 0)
      ok = 0;

  if (!ok)
    return;
  if (m.size() == 12)
  {
    if (sum > 0)
      results.push_back(sum);
    return;
  }

  // Пробуем следующий месяц убыточным
  m.push_back(0);
  sum -= d;
  gen(m, sum);
  sum += d;
  m.pop_back();

  // Пробуем следующий месяц прибыльным
  m.push_back(1);
  sum += s;
  gen(m, sum);
  sum -= s;
  m.pop_back();
}

// UVa 10576 - Y2K Accounting Bug
int main()
{
  while (scanf("%d %d", &s, &d) != EOF)
  {
    // Условие максимально непонятное, но вот суть:
    // нужно взять месяца прибыльными и убытычными так, чтобы каждая последовательность из 5 месяцев была дефицитной
    // То есть, в сумме за 1...5, 2...6, 3...7 (и т.д.) месяца сумма выходила отрицательная
    vector<bool> months = {};
    gen(months, 0);

    if (results.size() == 0)
      printf("Deficit\n");
    else
      printf("%d\n", *max_element(results.begin(), results.end())); // Вывод максимального

    results = {};
  }

  return 0;
}