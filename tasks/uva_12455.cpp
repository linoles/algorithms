#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// UVa 12455 - Bars
int main()
{
  int n, x, i;
  vector<int> l; // 1 <= n <= 20
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    l.push_back(temp);
  }

  scanf("%d", &x);

  for (i = 0; i < (1 << n); i++) // i - bitmask
  {
    int sum = 0;
    for (int j = 0; j < n; j++) // Находим сумму, проверяя, какие биты равны 1
      if (i & (1 << j))         // Проверка, равен ли бит j единице
        sum += l[j];
    if (sum == x)
    {
      cout << "Answer is found";
      return 0;
    };
  }

  cout << "There is no answer";
  return 0;
}

// Да, у кода есть вариант немного быстрее - O(k * 2**n), тут же O(n * 2**n)
// Для этого варианта используется LSOne, и может он и уменьшает время выполнения, но данный код вряд ли получит TLE