# 区域赛数学精简板子

配套练习：[数学板子练习清单](math_practice.md)。

来源：`template.md`。按本次赛前时间紧的情况精简，原始完整版仍保留在 `template.md`，需要时再查。

## 保留范围

| 顺序 | 内容 | 赛前目标 |
| --- | --- | --- |
| 先测 | 快速幂、组合数、Lucas | 分清模数条件，熟悉组合数边界 |
| 先测 | 组合恒等式、插板法、容斥、错排、Catalan | 从计数模型推导公式，检查边界与模数条件 |
| 先测 | 递推计数、组合 DP、生成函数基础 | 分清顺序与重复选择，理解系数和卷积 |
| 先测 | 线性筛、逆元、exgcd、CRT / exCRT | 熟悉分解、无逆元和同余方程无解的情况 |
| 后测 | 矩阵快速幂、浮点高斯消元、模行列式 | 作为常用工具备用 |
| 按需测 | 自适应辛普森、皮克定理 | 配合几何和格点计数 |

本轮移除：杜教筛、Min25、Powerful Number 筛、二次剩余、原根、BSGS / exBSGS、exLucas、Miller–Rabin / Pollard–Rho、多项式算法与 FFT / NTT、FWT、子集卷积、Polya、BM、矩阵求逆、零散博弈笔记和图片资料。保留生成函数的基础公式与计数解释。这是针对当前时间预算的取舍，不代表区域赛不会考。

Miller–Rabin / Pollard–Rho 原实现需要核验模乘与判素范围，先从主板子移除。FFT / NTT 如果你们已有测过且熟悉的版本，可以另带备用，不占本轮训练时间。

## 尚缺的基础内容

组合计数基础已补入下文；后续优先补阶乘中质因数的指数，以及概率期望的线性性与期望 DP。

## 使用说明

写法对齐 `../geo/geometry.md` 和 `../geo/intro.md`：普通 for 循环、using 类型别名、简短函数名，保留 all / sz / pb，不用 rep / per。

先复制文件头，再按需复制章节。组合数、模行列式默认使用 MOD；Lucas 的模数通过 initComb(n, p) 设置。矩阵快速幂也默认使用 MOD，P3390 需要将 MOD 改为 1e9 + 7。

以下已做本地编译与小规模校验，尚未逐题提交 OJ。原始完整版仍保留在 template.md。

## 基础依赖

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using db = double;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const ll MOD = 998244353; // or 1e9 + 7
const db eps = 1e-9;
```

## 优先实测：基础数论与组合数

### 快速幂

p > 0，b >= 0。mul 用 __int128 处理乘法中间结果；a、b 可以是负数。

```cpp
ll mul(ll a, ll b, ll p) {
    a %= p;
    if(a < 0) a += p;
    b %= p;
    if(b < 0) b += p;
    return (__int128)a * b % p;
}
ll qpow(ll a, ll b, ll p = MOD) {
    ll r = 1 % p;
    a %= p;
    if(a < 0) a += p;
    while(b) {
        if(b & 1) r = mul(r, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return r;
}
```

### 阶乘、逆阶乘、组合数与 Lucas

initComb(n, p) 要求 p 是不超过 2^31-1 的素数且 0 <= n < p；C(n, k) 要求 n 不超过预处理上界。
Lucas 用于小素数模数，先 initComb(p - 1, p)。不要按默认大模数预处理到 MOD - 1。

```cpp
ll combMod;
vll fac, ifac;
void initComb(int n, ll p = MOD) {
    combMod = p;
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p;
    ifac[n] = qpow(fac[n], p - 2, p);
    for (int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % p;
}
ll C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % combMod * ifac[n - k] % combMod;
}
ll lucas(ll n, ll k) {
    if(k == 0) return 1;
    return C(n % combMod, k % combMod) * lucas(n / combMod, k / combMod) % combMod;
}
```

### 线性筛

mnp 是最小质因子；每次用 mnp[x] 除掉一个质因子，可在 O(log x) 次操作内分解 x。sieve 可重复调用；n >= 1。
P3383 的上界为 10^8，只测质数时删去 phi / mu 等不需要的数组，避免额外内存。

```cpp
vi pri, mnp, phi, mu; //primes, min prime, euler phi, mobius
void sieve(int n) {
    pri.clear();
    mnp.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    phi[1] = mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if(!mnp[i]) {
            pri.pb(i);
            mnp[i] = i;
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for (int p : pri) {
            if(1LL * i * p > n) break;
            int x = i * p;
            mnp[x] = p;
            if(i % p == 0) {
                phi[x] = phi[i] * p;
                mu[x] = 0;
                break;
            }
            phi[x] = phi[i] * (p - 1);
            mu[x] = -mu[i];
        }
    }
}
```

### exgcd 与逆元

exgcd：a、b 为非负整数且不同时为 0，返回 gcd(a,b)，并满足 ax + by = gcd(a,b)。
inv：p >= 2，无逆元返回 -1，不要求模数为素数。

```cpp
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
ll inv(ll a, ll p) {
    a %= p;
    if(a < 0) a += p;
    ll x, y;
    if(exgcd(a, p, x, y) != 1) return -1;
    x %= p;
    if(x < 0) x += p;
    return x;
}
```

递推逆元要求 p 为不超过 2^31-1 的素数、1 <= n < p。函数名用 initInv，数组名用 iv，避免与 inv 冲突。

```cpp
vll iv;
void initInv(int n, ll p) {
    iv.assign(n + 1, 0); iv[1] = 1;
    for (int i = 2; i <= n; ++i) iv[i] = (p - p / i) * iv[p % i] % p;
}
```

### CRT / exCRT

统一用逐个合并：互质模数的普通 CRT 也可以调用这一份。
输入 a[i] 是余数，m[i] 是正模数；无解返回 -1。
要求两数组等长，所有模数的最小公倍数不超过 long long 范围；中间乘法用 __int128。

```cpp
bool mergeCRT(ll& a, ll& m, ll b, ll n) { // 合并 x = a (mod m), x = b (mod n)
    b %= n;
    if(b < 0) b += n;
    ll x, y, g = exgcd(m, n, x, y);
    ll d = b - a;
    if(d % g != 0) return false;
    ll k = mul(x, d / g, n / g);
    ll mod = (ll)((__int128)m * (n / g));
    a = ((__int128)m * k + a) % mod;
    m = mod;
    return true;
}
ll excrt(vll& a, vll& m) {
    ll r = 0, mod = 1;
    for (int i = 0; i < sz(a); ++i) {
        if(!mergeCRT(r, mod, a[i], m[i])) return -1;
    }
    return r;
}
```

## 优先实测：组合数学与计数

组合恒等式参考 `../../模板.pdf` 第 60 页，其余补充基础模型。公式先按整数理解，取模时除法要换成逆元；使用 C 的代码都依赖前面的 initComb / C，并按 combMod 取模。其余计数代码默认按 MOD 取模。

### 组合恒等式与常见模型

约定 n >= 0，k < 0 或 k > n 时 $\binom nk=0$，$\binom00=1$。以下变量均为非负整数；具体范围见公式旁说明。

| 模型 | 方案数 | 条件 / 解释 |
| --- | --- | --- |
| 从 n 个不同元素中选 k 个，无序 | $\binom nk$ | 不重复选择 |
| 从 n 个不同元素中选 k 个并排列 | $n!/(n-k)!$ | 0 <= k <= n |
| 多重集排列 | $n!/\prod_i a_i!$ | 第 i 类有 a_i 个相同元素，$\sum_i a_i=n$ |
| 网格中向右走 a 步、向上走 b 步 | $\binom{a+b}{a}$ | 无障碍、无额外路径限制 |

对称性与 Pascal 递推（递推式中 n >= 1）：

$$
\binom nk=\binom n{n-k},\qquad
\binom nk=\binom{n-1}k+\binom{n-1}{k-1}.
$$

二项式定理与求和：

$$
(x+y)^n=\sum_{k=0}^n\binom nk x^k y^{n-k},\qquad
\sum_{k=0}^n\binom nk=2^n.
$$

当 n >= 1 时，偶数项和与奇数项和都为 $2^{n-1}$，且 $\sum_{k=0}^n(-1)^k\binom nk=0$；n = 0 时偶数项和为 1，奇数项和为 0。

曲棍球棒恒等式，按选中元素中的最大值分类：

$$
\sum_{i=r}^n\binom ir=\binom{n+1}{r+1}\quad(0\le r\le n),\qquad
\sum_{i=0}^m\binom{n+i}n=\binom{n+m+1}m.
$$

改变选择顺序，先选 m 个再从中选 k 个，等价于先选 k 个再补 m-k 个：

$$
\binom nm\binom mk=\binom nk\binom{n-k}{m-k}\quad(0\le k\le m\le n).
$$

Vandermonde 恒等式，从大小为 n、m 的两个不相交集合中共选 k 个：

$$
\sum_{i=0}^k\binom ni\binom m{k-i}=\binom{n+m}k.
$$

### 插板法（隔板法）

m 个相同物品分给 k 个不同盒子，k >= 1。盒子有区别，盒内不计顺序。

| 限制 | 方程 | 方案数 |
| --- | --- | --- |
| 允许空盒 | $x_1+\cdots+x_k=m,\ x_i\ge0$ | $\binom{m+k-1}{k-1}$，m >= 0 |
| 每盒至少一个 | $x_1+\cdots+x_k=m,\ x_i\ge1$ | $\binom{m-1}{k-1}$，m >= k；否则为 0 |
| 每盒至少 l_i 个 | $x_i\ge l_i$ | 令 $M=m-\sum_i l_i$，答案为 $\binom{M+k-1}{k-1}$；M < 0 时为 0 |

若每盒满足 $0\le x_i\le b$，b >= 0，用容斥排除超出上界的盒子：

$$
\sum_{j=0}^{\min(k,\lfloor m/(b+1)\rfloor)}
(-1)^j\binom kj\binom{m-j(b+1)+k-1}{k-1}.
$$

若上界各不相同，$0\le x_i\le b_i$，枚举被指定超界的盒子集合 S，将这些变量各减去 b_i+1：

$$
\sum_{S\subseteq\{1,\ldots,k\}}(-1)^{|S|}
\binom{m-\sum_{i\in S}(b_i+1)+k-1}{k-1}.
$$

剩余物品数为负的项按 0 处理，不调用负上标的 C。各不相同的上下界先平移为 $0\le y_i\le u_i-l_i$；若某个 u_i < l_i 则无解。公式中的最大组合数上标必须在预处理范围内且小于 combMod。

### 容斥原理

“至少满足一个条件”对应集合的并集，非空子集奇加偶减：

$$
\left|\bigcup_{i=1}^k A_i\right|
=\sum_{\varnothing\ne S\subseteq\{1,\ldots,k\}}
(-1)^{|S|+1}\left|\bigcap_{i\in S}A_i\right|.
$$

“一个坏条件都不满足”则用全集减去并集；也可把空集项（全集大小）纳入求和，符号改为 $(-1)^{|S|}$。取模减法须规范到非负余数。

例：统计 [1,n] 中至少被一个 a[i] 整除的整数。交集大小是 $\lfloor n/\operatorname{lcm}(a_i:i\in S)\rfloor$；只有两两互质时才能把 lcm 换成乘积。

下面使用 lcm，支持重复或不互质的除数。要求 0 <= n <= 10^18、a[i] >= 1、k <= 20；复杂度 O(k 2^k log n)，答案是整数，不取模。

```cpp
ll countMultiples(ll n, const vll& a) {
    int k = sz(a);
    __int128 ans = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        ll l = 1;
        bool over = false;
        for (int i = 0; i < k; ++i) {
            if(!(mask >> i & 1)) continue;
            ll t = a[i] / gcd(l, a[i]);
            if(l > n / t) { over = true; break; }
            l *= t;
        }
        if(over) continue;
        if(__builtin_popcount((unsigned)mask) & 1) ans += n / l;
        else ans -= n / l;
    }
    return (ll)ans;
}
```

### 递推计数与错排

先定义状态，按最后一步或一个指定元素的去向分类；各类必须互不重叠且覆盖全部方案。空对象通常贡献 1 种方案，例如 dp[0] = 1。

错排 D_n：n 个不同元素的排列中，每个元素都不在原位置。

$$
D_0=1,\quad D_1=0,\quad
D_n=(n-1)(D_{n-1}+D_{n-2})\quad(n\ge2).
$$

推导：元素 1 选一个非原位 j，共 n-1 种；若 j 回到位置 1，剩下 D_{n-2} 种，否则压缩成 D_{n-1} 种。

容斥表达式：$D_n=\sum_{i=0}^n(-1)^i\binom ni(n-i)!$。恰好有 r 个元素在原位的排列数为 $\binom nrD_{n-r}$（0 <= r <= n）。

```cpp
vll derange(int n) { // n >= 0，O(n)
    vll d(n + 1);
    d[0] = 1;
    for (int i = 2; i <= n; ++i)
        d[i] = (i - 1LL) * ((d[i - 1] + d[i - 2]) % MOD) % MOD;
    return d;
}
```

### Catalan 数（卡特兰数）

Cat_n 统计 n 对合法括号；也统计从 (0,0) 到 (n,n)、只向右或向上且始终满足 y <= x 的路径，以及 n+1 个叶子的有序满二叉树。

$$
\mathrm{Cat}_0=1,\qquad
\mathrm{Cat}_n=\sum_{i=0}^{n-1}\mathrm{Cat}_i\mathrm{Cat}_{n-1-i}
=\frac1{n+1}\binom{2n}n
=\binom{2n}n-\binom{2n}{n-1}.
$$

括号递推按第一个左括号匹配的位置拆成 `(A)B`；组合数差式可由反射法得到。前几项（从 n=0 开始）：1, 1, 2, 5, 14, 42。

下面采用差式，避免额外除以 n+1；仍要求先 initComb(2*n, p) 且 2*n < p。题目给括号总长度 L 时，L 为奇数答案为 0，否则计算 catalan(L/2)。

```cpp
ll catalan(int n) { // n >= 0，依赖 C；每次 O(1)
    return (C(2 * n, n) - C(2 * n, n - 1) + combMod) % combMod;
}
```

### 组合 DP：硬币计数与循环顺序

硬币面值为互不相同的正整数 c[i]，目标和 s >= 0；同面值硬币不可区分。状态 dp[j] 表示组成和 j 的方案数，dp[0] = 1。以下时间复杂度 O(n s)、空间 O(s)。

| 选择规则 | 循环顺序 | 计数含义 |
| --- | --- | --- |
| 每种无限次，不计顺序 | 外层硬币，内层金额递增 | 每个面值的使用次数决定方案 |
| 每个物品至多一次，不计顺序 | 外层物品，内层金额递减 | 按物品身份选择子集；相同面值但身份不同仍是不同物品 |
| 每种无限次，计顺序 | 外层金额递增，内层硬币 | 按最后一枚硬币分类，统计序列 |

```cpp
ll coinWays(const vi& c, int s) { // 无限次，不计顺序
    vll dp(s + 1);
    dp[0] = 1;
    for (int v : c)
        for (int j = v; j <= s; ++j)
            dp[j] = (dp[j] + dp[j - v]) % MOD;
    return dp[s];
}
ll coinSeq(const vi& c, int s) { // 无限次，计顺序
    vll dp(s + 1);
    dp[0] = 1;
    for (int j = 1; j <= s; ++j)
        for (int v : c)
            if(v <= j) dp[j] = (dp[j] + dp[j - v]) % MOD;
    return dp[s];
}
```

例如 c = {1,2}、s = 3：不计顺序为 2 种（1+1+1、1+2），计顺序为 3 种（另有 2+1）。

### 生成函数基础

普通生成函数 $F(x)=\sum_{s\ge0}f_sx^s$，记 $[x^s]F(x)=f_s$。指数记录大小或总和，系数记录方案数；x 是形式变量，不需要讨论数值收敛。

独立选择的生成函数相乘，总和对应指数相加。设 $A(x)=\sum_i a_ix^i$、$B(x)=\sum_j b_jx^j$，则

$$
[x^s]A(x)B(x)=\sum_{i=0}^s a_i b_{s-i}.
$$

这就是卷积，也就是合并两组选择的计数 DP。

| 单个变量 / 一类物品的选择 | 生成函数 |
| --- | --- |
| 大小 v 的物品选 0 或 1 个 | $1+x^v$ |
| 大小 v 的物品可选任意个 | $1+x^v+x^{2v}+\cdots=1/(1-x^v)$ |
| 大小 v 的物品最多选 b 个 | $1+x^v+\cdots+x^{bv}=(1-x^{(b+1)v})/(1-x^v)$ |
| 整数变量满足 l <= y <= u | $x^l+x^{l+1}+\cdots+x^u$（0 <= l <= u） |

不计顺序的无限硬币计数：

$$
\mathrm{coinWays}(c,s)=[x^s]\prod_i\frac1{1-x^{c_i}}.
$$

计顺序时，先令 $A(x)=\sum_i x^{c_i}$，长度为 t 的序列对应 $A(x)^t$，包括空序列后：

$$
\mathrm{coinSeq}(c,s)=[x^s]\sum_{t\ge0}A(x)^t
=[x^s]\frac1{1-A(x)}.
$$

插板法对应 $[x^m](1-x)^{-k}=\binom{m+k-1}{k-1}$；统一上界 b 时乘上 $(1-x^{b+1})^k$，展开分子就得到上面的容斥公式。

Catalan 递推对应 $F(x)=1+xF(x)^2$。基础练习先用 DP 求系数，只保留到目标次数；本节不依赖 FFT / NTT，也不包含形式幂级数求逆、求对数等进阶算法。

## 备用：线性代数

### 矩阵快速幂

保持固定维度的写法，按题修改 K。矩阵元素应先规范到 [0, MOD)，MOD 取 998244353 或 1e9 + 7。

```cpp
const int K = 2;
struct Mat {
    ll a[K][K] = {};
    Mat operator*(const Mat& b) const {
        Mat r;
        for (int i = 0; i < K; ++i) {
            for (int k = 0; k < K; ++k) {
                if(!a[i][k]) continue;
                for (int j = 0; j < K; ++j)
                    r.a[i][j] = (r.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
            }
        }
        return r;
    }
};
Mat qpow(Mat a, ll b) {
    Mat r;
    for (int i = 0; i < K; ++i) r.a[i][i] = 1;
    while(b) {
        if(b & 1) r = r * a;
        a = a * a;
        b >>= 1;
    }
    return r;
}
```

### 浮点高斯消元

n 行 n+1 列的增广矩阵，0 下标。会修改 A，唯一解写入 ans。
返回 true 表示唯一解；false 表示没有唯一解。本版不区分无解和无穷多解。

```cpp
bool gauss(vector<vector<db>>& A, vector<db>& ans) {
    int n = sz(A);
    for (int i = 0; i < n; ++i) {
        int p = i;
        for (int j = i + 1; j < n; ++j)
            if(fabs(A[j][i]) > fabs(A[p][i])) p = j;
        if(fabs(A[p][i]) < eps) return false;
        swap(A[i], A[p]);
        db v = A[i][i];
        for (int j = i; j <= n; ++j) A[i][j] /= v;
        for (int j = 0; j < n; ++j) {
            if(j == i) continue;
            db k = A[j][i];
            A[j][i] = 0;
            for (int t = i + 1; t <= n; ++t) A[j][t] -= k * A[i][t];
        }
    }
    ans.resize(n);
    for (int i = 0; i < n; ++i) ans[i] = A[i][n];
    return true;
}
```

### 模意义行列式

要求 MOD 为素数。0 下标，会修改 A；依赖前面的整数 qpow。

```cpp
ll det(vector<vll>& A) {
    int n = sz(A);
    ll r = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] %= MOD;
            if(A[i][j] < 0) A[i][j] += MOD;
        }
    }
    for (int i = 0; i < n; ++i) {
        int p = i;
        while(p < n && !A[p][i]) ++p;
        if(p == n) return 0;
        if(p != i) { swap(A[i], A[p]); r = (MOD - r) % MOD; }
        r = r * A[i][i] % MOD;
        ll iv = qpow(A[i][i], MOD - 2);
        for (int j = i + 1; j < n; ++j) {
            ll k = A[j][i] * iv % MOD;
            for (int t = i; t < n; ++t)
                A[j][t] = (A[j][t] - k * A[i][t] % MOD + MOD) % MOD;
        }
    }
    return r;
}
```

## 备用：数值积分与格点计数

### 辛普森积分

替换 f(x)，确认区间无奇点。调用 asr(l, r, 1e-8)；若达到递归深度上限，返回当前近似值，不保证误差达标。

```cpp
db a, b, c, d;
db f(db x) { return (c * x + d) / (a * x + b); }
db simpson(db l, db r) {
    db m = (l + r) / 2;
    return (f(l) + 4 * f(m) + f(r)) * (r - l) / 6;
}
db asr(db l, db r, db e, db s, int dep) {
    db m = (l + r) / 2;
    if(m == l || m == r) return s;
    db x = simpson(l, m), y = simpson(m, r), delta = x + y - s;
    if(fabs(delta) <= 15 * e || dep == 0) return x + y + delta / 15;
    return asr(l, m, e / 2, x, dep - 1) + asr(m, r, e / 2, y, dep - 1);
}
db asr(db l, db r, db e) { return asr(l, r, e, simpson(l, r), 30); }
```

