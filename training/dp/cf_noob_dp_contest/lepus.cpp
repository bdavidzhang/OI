#include<bits/stdc++.h>
using namespace std;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::freopen("lepus.in", "r", stdin);
  std::freopen("lepus.out", "w", stdout);
  
  int n;
  std::cin >> n;
  
  // Add validation for n
  // if (n < 0 || n > 1000000) {
  //   std::cerr << "Invalid stairs count: " << n << std::endl;
  //   return 1;
  // }
  
  string s;
  cin >> s;
  
  vector<int> dp(n,-1);  
  dp[0] = (s[0] == '"' ? 1 : 0);

  for(int i = 0; i < n-1; ++i){
    for(int j = 1; j <= min(5, n-i); j += 2){
      char c = s[i+j];
      if(c == 'w' || s[i] == 'w') continue;
      dp[i+j] = max(dp[i+j], dp[i] + (c == '"' ? 1 : 0));
    }
  }

  cout << dp[n-1] << endl;

  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  
  // Add validation for size
  if (size < 0 || size > 1000000) {
    throw std::invalid_argument("Invalid array size: " + std::to_string(size));
  }
  
  std::vector<T> array(size);
  for (auto& element : array) {
    in_stream >> element;
  }
  return array;
}