#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis classpicture, O(n! * n)
int main()
{
  int n, m;
  while (scanf("%d", &n) != EOF)
  {
    string p[n + 1];
    for (int i = 0; i < n; i++)
    {
      char buffer[21];
      scanf(" %s", &buffer);
      p[i] = buffer;
    }

    scanf("%d", &m);
    pair<string, string> q[m + 1];
    for (int i = 0; i < m; i++)
    {
      char buffer1[21], buffer2[21];
      scanf(" %s %s", &buffer1, &buffer2);
      q[i] = make_pair((string)buffer1, (string)buffer2);
    }

    sort(p, p + n);

    // Переводим все строки в индексы, чтоб было легче работать с ними
    unordered_map<string, int> indices;
    for (int i = 0; i < n; i++)
      indices[p[i]] = i;

    // Массив индексов изначального списка, над которым будут производится перестановки
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
      perm[i] = i;
  
    // conflict[i][j] = 1, если i и j не могут стоять рядом
    vector<vector<bool>> conflict(n, vector<bool>(n, false));
    for (int x = 0; x < m; x++)
    {
      int a = indices[q[x].first];
      int b = indices[q[x].second];
      conflict[a][b] = true;
      conflict[b][a] = true;
    }

    bool found = 0;
    do
    {
      // Проверка всех конфликтных пар
      bool good = 1;
      for (int i = 1; i < n && good; i++)
        if (conflict[perm[i - 1]][perm[i]])
          good = 0;

      if (good)
      {
        found = 1;
        for (int i = 0; i < n; i++)
          printf("%s ", p[perm[i]].c_str());
        printf("\n");
        break;
      }
    } while (next_permutation(perm.begin(), perm.end()));

    if (!found)
      printf("You all need therapy.\n");
  }

  return 0;
}