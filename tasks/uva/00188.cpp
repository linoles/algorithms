
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// UVa 00188 - Perfect Hash, O(n²)
int main()
{
  string line;
  while (getline(cin, line))
  {
    vector<ll> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
      ll w = 0;
      int b = 0;
      // Сразу подсчёт слова в числовом виде
      for (int i = word.size() - 1; i >= 0; i--)
      {
        w += (1 << b) * (word[i] - 'a' + 1);
        b += 5;
      }
      words.push_back(w);
    }

    ll c = 1;
    while (true)
    {
      // Поиск конфликтов
      vector<pair<int, int>> cf;
      for (int i = 0; i < words.size() - 1; i++)
        for (int j = i + 1; j < words.size(); j++)
          if (ll(c / words[i]) % words.size() == ll(c / words[j]) % words.size())
            cf.push_back(make_pair(i, j));

      // Нет конфликтов
      if (cf.size() == 0)
        break;

      // Сортировка для поиска худшего (тут сортировка не нужна, нужно просто найти макс, но и так нет TLE)
      sort(cf.begin(), cf.end());

      // Нахождение следующего C
      int worst_i = cf[cf.size() - 1].first, worst_j = cf[cf.size() - 1].second;
      c = min(words[worst_i] * (1 + ll(c / words[worst_i])),
              words[worst_j] * (1 + ll(c / words[worst_j])));
    }

    printf("%s\n", line.c_str());
    printf("%lld\n\n", c);
  }

  return 0;
}