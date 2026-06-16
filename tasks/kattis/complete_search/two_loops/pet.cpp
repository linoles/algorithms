#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis pet, O(n²) на ввод
int main()
{
  // Индекс победителя, сумма очков победителя
  int max_ind = -1, max_sum = -1;
  for (int i = 0; i < 5; i++)
  {
    int sum = 0;
    // Счёт оценок
    for (int j = 0; j < 4; j++)
    {
      int temp;
      scanf("%d", &temp);
      sum += temp;
    }

    // Присвоение нового победителя, если требуется
    if (max_sum < sum)
    {
      max_ind = i + 1;
      max_sum = sum;
    }
  }

  printf("%d %d", max_ind, max_sum);

  return 0;
}