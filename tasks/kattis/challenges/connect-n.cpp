
#include <bits/stdc++.h>
using namespace std;

// Kattis Connect-N, O(x * y * n)
int main()
{
  int x, y, n;
  scanf("%d %d %d", &x, &y, &n);
  vector<vector<char>> f(x, vector<char>(y, 'O'));
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
      scanf(" %c", &f[i][j]);

  char winner = '-';
  // Проверка горизонталей
  for (int i = 0; i < x && winner == '-'; i++)
    for (int j = 0; j <= y - n; j++)
    {
      char cc = f[i][j];
      bool ok = true;
      for (int m = 1; m < n; m++)
        if (cc != f[i][j + m])
          ok = false;
      if (ok && cc != 'O')
        winner = cc;
    }

  // Проверка вертикалей
  for (int i = 0; i <= x - n && winner == '-'; i++)
    for (int j = 0; j < y; j++)
    {
      char cc = f[i][j];
      bool ok = true;
      for (int m = 1; m < n; m++)
        if (cc != f[i + m][j])
          ok = false;
      if (ok && cc != 'O')
        winner = cc;
    }

  // Проверка диагоналей слева направо
  for (int i = 0; i <= x - n; i++)
    for (int j = 0; j <= y - n; j++)
    {
      char cc = f[i][j];
      bool ok = true;
      for (int m = 1; m < n; m++)
        if (cc != f[i + m][j + m])
          ok = false;
      if (ok && cc != 'O')
        winner = cc;
    }

  // Проверка диагоналей справа налево
  for (int i = n - 1; i < x; i++)
    for (int j = 0; j <= y - n; j++)
    {
      char cc = f[i][j];
      bool ok = true;
      for (int m = 1; m < n; m++)
        if (cc != f[i - m][j + m])
          ok = false;
      if (ok && cc != 'O')
        winner = cc;
    }

  switch (winner)
  {
  case 'R':
    printf("RED WINS");
    break;

  case 'B':
    printf("BLUE WINS");
    break;

  default:
    printf("NONE");
    break;
  }

  return 0;
}