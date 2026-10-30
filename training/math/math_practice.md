# 区域赛数学板子练习清单

配套板子：[math_template.md](math_template.md)。先完成基础部分，再验收备用工具。每题从纸质板子手敲一次，AC 后记录修改点。

## 第一轮：基础数论与组合数

| 完成 | 顺序 | 板子 | 题目 | 验收重点 |
| --- | --- | --- | --- | --- |
| ☐ | 1 | 快速幂 | [P1226 快速幂](https://www.luogu.com.cn/problem/P1226) | 模数由输入给出；指数为 0、乘法溢出、输出格式 |
| ☐ | 2 | 阶乘、逆阶乘、组合数 | [B3717 组合数问题](https://www.luogu.com.cn/problem/B3717) | 用 initComb(N) 预处理；最终输出所有答案的异或和；注意大量输入 |
| ☐ | 3 | 递推逆元 | [P3811 乘法逆元](https://www.luogu.com.cn/problem/P3811) | 调用 initInv(n, p) 后输出 iv[i]；明确素数模数及 n < p 的条件 |
| ☐ | 4 | exgcd 求逆元 | [P1082 同余方程](https://www.luogu.com.cn/problem/P1082) | 模数不保证为素数；将负数解规范化；本题保证有解 |
| ☐ | 5 | 线性筛 | [P3383 线性筛素数](https://www.luogu.com.cn/problem/P3383) | 上界为 10^8；只保留本题需要的筛法数组，避免把 mnp、phi、mu 全部开到该上界 |
| ☐ | 6 | Lucas | [P3807 Lucas 定理](https://www.luogu.com.cn/problem/P3807) | 每组先 initComb(p - 1, p)，再调用 lucas(n + m, n) |
| ☐ | 7 | CRT | [P1495 曹冲养猪](https://www.luogu.com.cn/problem/P1495) | 模数两两互质；直接使用统一后的 excrt(a, m)，a 为余数数组、m 为模数数组 |
| ☐ | 8 | exCRT | [P4777 扩展中国剩余定理](https://www.luogu.com.cn/problem/P4777) | 处理不互质模数与中间乘法溢出；本题保证有解，需另测无解分支 |

## 第二轮：备用工具

| 完成 | 顺序 | 板子 | 题目 | 验收重点 |
| --- | --- | --- | --- | --- |
| ☐ | 9 | 矩阵快速幂 | [P3390 矩阵快速幂](https://www.luogu.com.cn/problem/P3390) | 用 Mat A(n) 创建动态维度矩阵，将 MOD 改为 1e9 + 7，指数用 ll；测试指数为 0；负数元素取模规范化 |
| ☐ | 10 | 浮点高斯消元 | [P3389 高斯消元法](https://www.luogu.com.cn/problem/P3389) | 换主元、浮点判零；没有唯一解时输出 No Solution |
| ☐ | 11 | 模意义行列式 | [Library Checker：Determinant of Matrix](https://judge.yosupo.jp/problem/matrix_det) | 模数为 998244353；传入 vector<vll> 的 0 下标矩阵；测试换行变号与奇异矩阵 |
| ☐ | 12 | 自适应辛普森 | [P4525 自适应辛普森法 1](https://www.luogu.com.cn/problem/P4525) | 被积函数与现有板子一致；核对误差、终止条件和输出精度 |
| ☐ | 13 | 皮克定理 | [CSES：Polygon Lattice Points](https://cses.fi/problemset/task/2193) | 叉积面积、边界格点计数、皮克定理；全程整数计算，检查中间结果范围 |

行列式题的[官方题面源码](https://raw.githubusercontent.com/yosupo06/library-checker-problems/master/linear_algebra/matrix_det/task.md)可直接查看模数与约束。

暂不选 [P7112 行列式求值](https://www.luogu.com.cn/problem/P7112)：它不保证模数为素数，现有使用费马逆元的板子不能直接套用。

## 第三轮：组合建模与计数 DP

组合基础已熟悉，本轮重点练习从计数推导到高效算法的转换。按下列顺序练习；时间有限时先做 NEQ、Grid 2、Make Pair。先独立推导并实现，AC 后记录复杂度、重计 / 漏计原因与边界处理。

| 完成 | 顺序 | 内容 | 题目 | 验收重点 |
| --- | --- | --- | --- | --- |
| ☐ | 14 | 容斥、排列计数、组合恒等式 | [ABC172 E — NEQ](https://atcoder.jp/contests/abc172/tasks/abc172_e) | N ≤ M ≤ 5×10^5；将计数式化为单重求和，预处理后 O(N) 求和；检查交集大小范围与模减法 |
| ☐ | 15 | 组合路径计数、稀疏状态 DP | [DP Y — Grid 2](https://atcoder.jp/contests/dp/tasks/dp_y) | H、W ≤ 10^5，障碍数 K ≤ 3000；避免逐格 DP；验证障碍之间的可达关系、扣除方案时不重不漏 |
| ☐ | 16 | 多重集排列、组合 DP | [ABC234 F — Reordering](https://atcoder.jp/contests/abc234/tasks/abc234_f) | 字符串长度 ≤ 5000；相同字符不可区分，不同选择位置产生相同字符串时只计一次；排除空串 |
| ☐ | 17 | 排列计数、状态设计与转移优化 | [DP T — Permutation](https://atcoder.jp/contests/dp/tasks/dp_t) | N ≤ 3000；避免枚举排列，将总时间控制在 O(N²)；核对严格不等式、状态下标与模减法 |
| ☐ | 18 | 区间 DP、组合系数、操作顺序计数 | [ABC217 F — Make Pair](https://atcoder.jp/contests/abc217/tasks/abc217_f) | 2N ≤ 400；统计完整操作序列；区分最终配对相同但操作顺序不同的方案；检查空区间与区间长度奇偶 |

### NEQ 调试记录

- 按两组所选元素的交集大小 l 分类时，范围为 max(0, 2N-M) ≤ l ≤ N。
- 双重求和可通过交换求和顺序、组合数乘积拆分与 Vandermonde 恒等式化成单重求和。
- 自测 `N=2, M=4`，答案为 `84`；另测 N=M、N=1、M>2N。
- 取模减法统一规范到 [0, MOD)；C++ 的负数余数可能为负。
- 此前仅在临时副本中验证过优化版本：三个样例通过，并与所有 1 ≤ N ≤ M ≤ 6 的穷举结果一致；尚未据此标记 OJ AC。

## 有余力再补

- [ ] [P2158 仪仗队](https://www.luogu.com.cn/problem/P2158)：练习欧拉函数的应用，补验线性筛中的 phi。
- [ ] [P2455 线性方程组](https://www.luogu.com.cn/problem/P2455)：区分唯一解、无解与无穷多解，比 P3389 的解分类更完整。

## 补充自测

OJ 通过不代表覆盖了板子的所有分支，至少补这些小样例：

- [ ] 快速幂：指数为 0、底数为 0、底数大于模数。
- [ ] 组合数：C(0,0)、C(n,0)、C(n,n)、下标越界时返回 0。
- [ ] exgcd 逆元：a = 2、p = 4 时无逆元；确认不会返回伪逆元。
- [ ] exCRT 无解：x ≡ 0 (mod 2)，x ≡ 1 (mod 2)。
- [ ] exCRT 有解且模数不互质：x ≡ 2 (mod 4)，x ≡ 6 (mod 8)，最小非负解为 6。
- [ ] 矩阵快速幂：零次幂为单位矩阵。
- [ ] 高斯消元：需要换行才能找到非零主元；重复方程；矛盾方程。
- [ ] 行列式：单位矩阵为 1；交换两行后变号；两行相同为 0。

## 修改与验收记录

| 题号 | AC 日期 | 修复 / 注意事项 |
| --- | --- | --- |
| | | |
