
#include <bits/stdc++.h>
using namespace std;

// Kattis veci, O((log10 n)! * log10 n)
int main()
{
  int n;
  scanf("%d", &n);
  int smallest = n, start = n;
  // Переносим число в массив
  vector<int> x;
  while (n > 0)
  {
    x.push_back(n % 10);
    n /= 10;
  }

  sort(x.begin(), x.end());

  do
  {
    int num = 0;
    // Копия, чтоб не менять массив x
    vector<int> cpy(x.begin(), x.end());
    int r = cpy.size() - 1;
    for (int d : cpy)
    {
      num += d * pow(10, r);
      r--;
    }

    // Если smallest ещё не присваивался
    if (num > start && smallest == start)
      smallest = num;
    // Иначе просто присваение минимального
    else if (num > start)
      smallest = min(num, smallest);
  } while (next_permutation(x.begin(), x.end()));

  if (smallest == start)
    printf("0");
  else
    printf("%d", smallest);

  return 0;
}