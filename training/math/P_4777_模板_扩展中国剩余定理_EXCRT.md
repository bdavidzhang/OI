<!-- cph-statement -->
# P4777 【模板】扩展中国剩余定理（EXCRT）

https://www.luogu.com.cn/problem/P4777

Time limit: 1000 ms, memory limit: 500 MB

# P4777 【模板】扩展中国剩余定理（EXCRT）

## 题目描述

给定 $n$ 组非负整数 $a\_i, b\_i$ ，求解关于 $x$ 的方程组的最小非负整数解。 $$\\begin{cases}x\\equiv b\_1\\pmod{a\_1}\\\\x\\equiv b\_2\\pmod{a\_2}\\\\\\dots\\\\x\\equiv b\_n\\pmod{a\_n}\\end{cases}$$

## 输入格式

输入第一行包含整数 $n$。 接下来 $n$ 行，每行两个非负整数 $a\_i, b\_i$。

## 输出格式

输出一行，为满足条件的最小非负整数 $x$。

## 说明/提示

对于 $100 \\%$ 的数据，$1 \\le n \\le {10}^5$，$1 \\le a\_i \\le {10}^{12}$，$0\\leq b\_i \\leq 10^{12}$，保证所有 $a\_i$ 的最小公倍数不超过 ${10}^{18}$。 \*\*请注意程序运行过程中进行乘法运算时结果可能有溢出的风险。\*\* 数据保证有解。
