#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  vector<int> len(n, 1), pred(n, -1);
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[j] < a[i] && len[j] + 1 > len[i])
      {
        len[i] = len[j] + 1;
        pred[i] = j; // Сохраняем предшественника
      }
  int mx = 0; // Находим длину НВП в len
  for (int i = 1; i < n; i++)
    if (len[i] > len[mx])
      mx = i;
  vector<int> res;                      // Восстанавливаем ответ
  for (int i = mx; i >= 0; i = pred[i]) // Идём по предшественникам последнего элемента НВП
    res.push_back(a[i]);
  reverse(res.begin(), res.end());

  for (int x : res)
    printf("%d ", x);
}