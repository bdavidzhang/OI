#include<algorithm>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
  long long mx, my;
  cin >> mx >> my;
  long long N = (mx + 1) * (my + 1);
  long long tot = N * (N-1) * (N-2) / 6;
  long long deg = 0; //degnerate 

  for(long long dx = 0; dx <= mx; dx++){
    for(long long dy = -my; dy <= my; ++dy){
      if(dx == 0 && dy <= 0) continue;
      long long g = gcd(dx,llabs(dy));
      deg += (mx + 1 - dx) * (my + 1 - llabs(dy)) * (g-1);
    }
  }

  long long right = 0, obstuse = 0;
  for(long long W = 1; W <= mx; ++W){
    for(long long H = 1; H <= my; ++H){
      long long R = 4, O = 0, bR = 0, bO = 0;
      for (long long y1 = 1; y1 < H; ++y1){
        long long q = y1*(H-y1);
        bO += min(W-1,(q+W-1) / W - 1);
        if(q % W == 0 && q / W >= 1 && q / W <= W-1) bR++;
      }
      for (long long x2 = 1; x2 < W; x2++) {
          long long q = x2 * (W - x2);
          bO += min(H - 1, (q + H - 1) / H - 1);
          if (q % H == 0 && q / H >= 1 && q / H <= H - 1) bR++;
      }
      R += 4 * bR; O += 4 * bO;
      for (long long x = 1; x < W; x++) {          
          long long s = x * (W - x);
          if (s > H * H) O += 2; else if (s == H * H) R += 2;
      }
      for (long long y = 1; y < H; y++) {
          long long s = y * (H - y);
          if (s > W * W) O += 2; else if (s == W * W) R += 2;
      }
      long long g = gcd(W, H);                   
      O += 2 * ((W + 1) * (H + 1) - 4 - (g - 1));
      long long place = (mx + 1 - W) * (my + 1 - H);
      right += R * place;
      obstuse += O * place;
    }
  }

  cout << tot - right - obstuse - deg << endl << right << endl << obstuse << endl << deg << endl;
}
