#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
  int n;
  vi nums = {}, res = {}, temp_res = {};
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  for (int i = 0; i < size(nums); i++)
  {
    if (i == 0 || nums[i] > nums[i - 1])
    {
      if (i != 0 && find(temp_res.begin(), temp_res.end(), nums[i - 1]) == temp_res.end())
      {
        temp_res.insert(temp_res.begin(), nums[i - 1]);
      }
      temp_res.push_back(nums[i]);
      if (temp_res.size() > res.size())
      {
        res = {};
        res.resize(size(temp_res));
        copy(temp_res.begin(), temp_res.end(), res.begin());
      }
    }
    else
    {
      temp_res.clear();
    }
  }

  
  cout << "\n";
  for (int x : res) {
    printf("%d ", x);
  }

  return 0;
}