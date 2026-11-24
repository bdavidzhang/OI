#include <atomic>
#include <bit>
#include<bits/stdc++.h>
#include <cstdint>
#include <iterator>
#include <ranges>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
#define sz(x) ((int)(x).size())

using Mask = uint32_t;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;

  vi a(m);
  for (auto & x : a){
    cin >> x;
    x = min(x, n - x);
  }

  vector<unordered_map<Mask,int>> memo(m);

  auto dfs = [&](this auto &&self, int day, Mask mask) -> int{
    vi sizes;
    int prev = -1;

    for(Mask bits = mask; bits; bits &= bits - 1){
      int last = countr_zero(bits);
      sizes.push_back(last-prev);
      prev = last;
    }

    int k = sz(sizes);
    int singles = int(ranges::count(sizes,1));

    if(day == m || singles == n)
      return singles;

    auto &cache = memo[day];
    if(auto it = cache.find(mask); it != cache.end())
      return it->second;

    vi suffix(k+1);
    for(int i = k - 1; i >= 0; --i)
      suffix[i] = suffix[i+1] + sizes[i];

    array<int, 31> cnt{};
    int best = singles;

    auto distribute = [&](this auto && enumerate, int i , int left, int prev) -> void{
      if( i == k){
        Mask next = 0;
        int end = -1;

        for(int s = 1; s <= n; ++s){
          for(int j = 0;j < cnt[s]; ++j){
            end += s;
            next |= Mask{1} << end;
          }
        }

        best = max(best, self(day+1, next));
        return;
      }
  
      int s = sizes[i];
      int lo = max(0, left - suffix[i+1]);
      int hi = min(s, left);

      if(i > 0 && s == sizes[i-1])
        lo = max(lo, prev);

      for(int x = lo; x <= hi && best < n; ++x){
        ++cnt[x];
        ++cnt[s-x];

        enumerate(i+1, left-x, x);

        --cnt[x];
        --cnt[s-x];
      }
    };

    distribute(0,a[day],0);
    cache.emplace(mask,best);
    return best;
  };

  cout << dfs(0, Mask{1} << (n-1)) << endl;

  return 0;
}



