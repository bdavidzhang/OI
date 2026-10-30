
https://codeforces.com/problemset/problem/1446/F

非常好的题，也很难。
重点有好几步，先从简单的来：

我们的目的是找到某个点对使得连接他们的直线到圆心的垂直距离第k小，然后
要返回这个距离，但是直接考虑所有点对需要n**2 的时间，显然是不行的。

这里的思路是采取一个近似的想法，就是我开始随便尝试某个距离r，显然当r
足够大的时候会包含所有点，而且包含点的数量随着r单调递减，所以我们可以
利用二分查找找到某个r使得正好包含k个点对，那这个r就只会比他们距离中心
的距离稍大一点点，称之为$\epsilon$ ，那我们其实可以控制这个误差：如果我们重复
这个过程60次，那二分查找的上线hi和下限lo的的差就会从最初的$d$ 变成$d/2^{60}$, 
完全可以计算这个值非常小。

所以现在任务就变成了找到某个r包含的点对的数量，这里需要一些几何：

与其考虑一个点在空间中的分布，不如把它映射到圆周上。这里可以通过两个切线把这个点投射到圆周的某个角度区间上，中心为$\theta$ $=$   `atan2(y/x)`, 然后区间两边的长度是$\delta = \frac{\sqrt{x^2+y^2}}{r}$ ，now I will switch to English because typing is a bit easier this way. 

Here our interval becomes $[\theta-\delta, \theta + \delta]$, and we can, for each point given, calculate this corresponding interval. Now there's a very nice correspondence. For points A,B, AB only intersects the circle if their intervals are disjoint. Otherwise, their intervals will overlap! so now we can instead try to find overlaps between these intervals, which becomes a range query problem. 

Andrew He's solution involves segment trees. 

我大概会一些线段树的内容，但是具体的原理没有搞清楚，需要
了解如何使用线段树求出interval overlaps。

