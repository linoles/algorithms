#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

// Функция нахождения числа различных символов в строке
int f(string str)
{
  unordered_set<char> letters; // Сет - массив уникальных элементов
  for (char c : str)
  {
    letters.insert(c); // Не сохранит повторений
  }
  return letters.size();
}

// Codeforces 1791D - Непересекающееся разделение, O(n²)
int main()
{
  int t, n; // 1 ≤ t ≤ 10^4, 2 ≤ n ≤ 2*10^5
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char temp_s[n];
    scanf("%s", &temp_s);
    string s = temp_s; // std::string для использования функции substr

    // Подбираем строки - циклично разбираем на разные длины
    int max_res = 0;
    for (int i = 1; i < n - 1; i++)
    {
      int temp = f(s.substr(0, i)) + f(s.substr(i, n - i)); // находим f(a) + f(b)
      if (temp > max_res)
        max_res = temp;
    }

    printf("%d\n\n", (max_res == 0) ? 2 : max_res);
  }

  return 0;
}