#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const double INF = 1e300;

int p, m;
double r;
vector<double> xs, ys;

double height(double x) {
    for (int i = 0; i + 1 < p; i++)
        if (xs[i] <= x && x <= xs[i+1])
            return ys[i] + (ys[i+1] - ys[i]) * (x - xs[i]) / (xs[i+1] - xs[i]);
    return 0;
}

double vol(int lo, int hi, double h) {
    double s = 0;
    for (int i = lo; i < hi; i++) {
        double w = xs[i+1] - xs[i], da = h - ys[i], db = h - ys[i+1];
        if (da >= 0 && db >= 0) s += (da + db) / 2 * w;
        else if (da > 0)        s += w * da * da / (2 * (da - db));
        else if (db > 0)        s += w * db * db / (2 * (db - da));
    }
    return s;
}

double bh(int i) { return (i == 0 || i == p - 1) ? INF : ys[i]; }

struct Lake { int lo, hi; double v; int d; };   

int main() {
  cin >> p >> r >> m;
    xs.resize(p); ys.resize(p);
    for (int i = 0; i < p; i++) {
      cin >> xs[i] >> ys[i];
    }
    vector<double> nx(m), nh(m), ans(m, -1);
    for (int j = 0; j < m; j++) { 
      cin >> nx[j];
      nh[j] = height(nx[j]);
    }

    vector<int> bnd = {0};
    for (int i = 1; i + 1 < p; i++)
        if (ys[i] > ys[i-1] && ys[i] > ys[i+1]) bnd.push_back(i);
    bnd.push_back(p - 1);

    vector<Lake> lakes;
    for (size_t k = 0; k + 1 < bnd.size(); k++) lakes.push_back({bnd[k], bnd[k+1], 0, 0});

    double t = 0;
    int left = m;
    while (left > 0) {
        int k = lakes.size();
        vector<double> inflow(k, 0);
        for (int i = 0; i < k; i++) {
            int s = i;
            while (lakes[s].d != 0) s += lakes[s].d;
            inflow[s] += r * (xs[lakes[i].hi] - xs[lakes[i].lo]);
        }

        double best = INF; int who = -1;
        for (int i = 0; i < k; i++) {
            if (lakes[i].d) continue;
            double rim = min(bh(lakes[i].lo), bh(lakes[i].hi));
            if (rim < INF) {
                double dt = (vol(lakes[i].lo, lakes[i].hi, rim) - lakes[i].v) / inflow[i];
                if (dt < best) { best = dt; who = i; }
            }
        }


        for (int j = 0; j < m; j++) {
            if (ans[j] >= 0) continue;
            int i = 0;
            while (!(xs[lakes[i].lo] < nx[j] && nx[j] < xs[lakes[i].hi])) i++;
            if (lakes[i].d) continue;
            double need = (vol(lakes[i].lo, lakes[i].hi, nh[j]) - lakes[i].v) / inflow[i];
            if (need <= best) { ans[j] = t + max(need, 0.0); left--; }
        }
        if (who < 0) break;

        for (int i = 0; i < k; i++) if (!lakes[i].d) lakes[i].v += inflow[i] * best;
        t += best;

        int d = bh(lakes[who].lo) < bh(lakes[who].hi) ? -1 : 1;
        int nb = who + d;
        if (lakes[nb].d == -d) {            
            int a = min(who, nb), b = max(who, nb);
            Lake merged = {lakes[a].lo, lakes[b].hi, lakes[a].v + lakes[b].v, 0};
            lakes.erase(lakes.begin() + a, lakes.begin() + b + 1);
            lakes.insert(lakes.begin() + a, merged);
        } else {
            lakes[who].d = d;
        }
    }

    for (int j = 0; j < m; j++) cout << setprecision(8) << fixed << ans[j] << endl;

}
