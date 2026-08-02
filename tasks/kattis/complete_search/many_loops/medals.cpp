
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// Скалярное произведение векторов
ld scalar_multiplication(vector<ld> &f, vector<ld> &s)
{
  ld x1 = f[0], x2 = s[0], y1 = f[1], y2 = s[1], z1 = f[2], z2 = s[2];
  return x1 * x2 + y1 * y2 + z1 * z2;
}

// Kattis medals, O(n)
int main()
{
  int c;
  while (true)
  {
    scanf("%d", &c);
    if (c == 0)
      break;

    unordered_map<string, vector<ld>> a;
    for (int i = 0; i < c; i++)
    {
      char buffer[20000];
      ld g, s, b; // золото, серебро, бронза
      scanf("%s %Lf %Lf %Lf", &buffer, &g, &s, &b);
      string name = buffer;
      a[name] = {g, s, b};
    }

    bool first = 0;
    // Подбираем j, k, l:  нужный вектор будет (1/n^j, 1/n^k, 1/n^l)
    // В некоторых тестах, видимо, требуются отрицательные коэффициенты, т.к. там не написано, что они unsigned
    for (int j = -20; j < 20 && !first; j++)
      for (int k = -20; k < 20 && !first; k++)
        for (int l = -20; l < 20 && !first; l++)
        {
          // Формируем веса и скалярное произведение медалей на веса для каждой страны
          vector<ld> weight = {1 / (ld)powl(c, j), 1 / (ld)powl(c, k), 1 / (ld)powl(c, l)};
          vector<pair<string, ld>> res;
          for (auto &[key, value] : a)
            res.push_back(make_pair(key, scalar_multiplication(weight, value)));

          // Ищем максимальный результат и результат Канады
          ld max_res = -1, canada_res = -1;
          for (pair<string, ld> x : res)
          {
            if (x.first == "Canada")
              canada_res = x.second;
            max_res = max(max_res, x.second);
          }

          if (max_res == canada_res)
            first = 1;
        }

    printf(first ? "Canada wins!\n" : "Canada cannot win.\n");
  }

  return 0;
}