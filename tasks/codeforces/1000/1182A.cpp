#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  if (n % 2 == 1)
  {
    printf("0\n");
    return 0;
  }

  printf("%lld", (ll)powl(2, n / 2));
}