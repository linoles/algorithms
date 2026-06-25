#include <bits/stdc++.h>
using namespace std;

// Codeforces 1131C - День рождения, O(n * log n)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // Просто нужно сначала расположить неубывающую последовательность, а затем остальных,
  // отсортированных в убывающем порядке. При этом именно в неё нужно поместить макс. число из a
  // Значит можно отсортировать массив, а затем расположить элементы ceil(n / 2) элементов
  // вначале, а затем в обратном порядке остальные floor(n / 2)
  sort(a, a + n);

  vector<int> res;
  // Для этого можно использовать чётность
  for (int i = 1 - n % 2; i < n; i += 2)
    res.push_back(a[i]);
  for (int i = n - 2; i >= 0; i -= 2)
    res.push_back(a[i]);
  
  for (int x : res)
    printf("%d ", x);

  return 0;
}