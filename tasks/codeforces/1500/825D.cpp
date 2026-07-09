#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// CF 825D - Подходящая замена, O(|s| + |t|)
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);

  string s, t;
  cin >> s >> t;

  // Неважно, в каком расположении расставлены буквы в t, нам нужно просто сделать таких букв как
  // можно больше в строке s

  // Ищем все буквы в t и считаем их кол-во
  unordered_map<char, int> t_letters, s_letters;
  for (char x : t)
  {
    if (t_letters.count(x))
      t_letters[x]++;
    else
    {
      t_letters[x] = 1;
      s_letters[x] = 0;
    }
  }

  // Теперь считаем их кол-во и кол-во вопр. знаков в строке s
  vi qs_indx;
  int qs = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (t_letters.count(s[i]))
      s_letters[s[i]]++;
    else if (s[i] == '?')
    {
      qs++;
      qs_indx.push_back(i);
    }
  }

  // Ищем максимальное x такое, что все s_letters[i] / t_letters[i] >= x
  int lo = 0, hi = 1e6;
  while (lo < hi) // O(1)
  {
    int mid = (lo + hi + 1) / 2;

    // Для каждого символа t_letters[i] считаем, сколько нужно раз добавить такой символ, чтобы
    // s_letters[i] / t_letters[i] стало не меньше mid
    ll need = 0;
    for (const auto &[c, val] : t_letters)
    {
      ll target = mid * (ll)val;
      if (s_letters[c] < target)
      {
        need += target - s_letters[c];
        if (need > qs)
          break;
      }
    }

    if (need <= qs)
      lo = mid;
    else
      hi = mid - 1;
  }

  // Теперь пытаемся построить новую строку s. Для каждого символа сначала считаем, сколько
  // раз его нужно добавить (заменить ? на этот символ), затем уже меняем исходную строку
  int ptr = 0;
  char last;
  for (const auto &[c, val] : t_letters)
  {
    // lo * t_letters[c] - сколько должно присутствовать, s_letters[c] - сколько присутствует
    ll add = lo * t_letters[c] - s_letters[c];
    forn(i, add)
    {
      s[qs_indx[ptr]] = c;
      ptr++;
    }
    last = c;
  }

  // Заменяем оставшиеся ? последним символов. Не знаю, обязательно ли это, но боюсь, что нельзя
  // оставлять в строке s вопросительные знаки
  while (ptr < qs_indx.size())
  {
    s[qs_indx[ptr]] = last;
    ptr++;
  }

  cout << s;

  return 0;
}