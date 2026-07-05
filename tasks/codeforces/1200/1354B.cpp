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

// Codeforces 1354B - Троичная строка, O(n)
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    char buffer[200001];
    scanf("%s", &buffer);
    string s = buffer;

    vi cnt(3, 0); // Кол-во встреч каждой цифры
    int l = 0, ans = INT_MAX;
    forn(r, s.size())
    {
      cnt[s[r] - '1']++;

      // Двигаем левый указатель, пока все три символа используются
      while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
      {
        ans = min(ans, r - l + 1);
        cnt[s[l] - '1']--;
        l++;
      }
    }

    printf("%d\n\n", (ans == INT_MAX) ? 0 : ans);
  }

  return 0;
}