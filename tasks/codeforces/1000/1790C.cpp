


#include <bits/stdc++.h>
using namespace std;

// Codeforces 1790C (1000) - Перестановка, O(n) не считая ввода O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    vector<vector<int>> np(n);        // Я имею в виду n (штук) p перестановок
    vector<int> first_freq(n + 1, 0); // Количество раз, когда каждое число встречается на 1 позиции
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n - 1; j++)
      {
        int temp;
        scanf("%d", &temp);
        np[i].push_back(temp);
      }
      first_freq[np[i][0]]++;
    }

    // В 1 примере:
    // np[0]: 4 2 1 (пропущен 4-ый элемент)
    // np[1]: 4 2 3 (пропущен 3-ый элемент)
    // np[2]: 2 1 3 (пропущен 1-ый элемент) - только тут первый элемент оказывается не p[0] (4), а p[1] (2)
    // np[3]: 4 1 3 (пропущен 2-ый элемент)
    int p1 = -1, p0 = -1;
    for (int i = 1; i <= n; i++)
    {
      if (first_freq[i] == n - 1)
        p0 = i;
      if (first_freq[i] == 1)
        p1 = i;
    }

    // Тут мы ищем ту последовательность, где первый элемент - p1
    // В ней все нужные элементы в правильном порядке, кроме p0
    vector<int> perm;
    for (int i = 0; i < n; i++)
    {
      if (np[i][0] == p1)
      {
        perm = np[i];
      }
    }
    perm.insert(perm.begin(), p0);

    for (int i = 0; i < n; i++)
      printf("%d ", perm[i]);
    printf("\n\n");
  }

  return 0;
}

// Моя первая попытка была O(n! * n²)