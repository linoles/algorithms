
#include <bits/stdc++.h>
using namespace std;

// Kattis eenymeeny, O(n³)
int main()
{
  // Ввод считалочки
  string line, word;
  getline(cin, line);
  int words = 0; // Сама считалочка нам не нужна, только кол-во слов
  stringstream ss(line);
  while (ss >> word)
    words++;

  // Ввод имён
  int n;
  scanf("%d", &n);
  vector<string> names(n);
  for (int i = 0; i < n; i++)
  {
    char buffer[101];
    scanf(" %s", &buffer);
    names[i] = buffer;
  }

  vector<bool> used(n, 0); // Выбывшие

  // Теперь симулируем процесс считалочки n раз
  int cur = -1;        // 0-indexed
  vector<string> f, s; // Команды
  for (int i = 0; i < n; i++)
  {
    // Считалочка
    for (int j = 0; j < words; j++)
    {
      cur = (cur + 1) % n;
      while (used[cur])
        cur = (cur + 1) % n;
    }

    // Отмечаем выбывшим
    used[cur] = 1;

    // Распределяем в команду
    if (i % 2 == 0)
      f.push_back(names[cur]);
    else
      s.push_back(names[cur]);
  }

  printf("%d\n", f.size());
  for (string x : f)
    printf("%s\n", x.c_str());

  printf("%d\n", s.size());
  for (string x : s)
    printf("%s\n", x.c_str());

  return 0;
}