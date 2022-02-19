* 算法
  * 数据结构
    * 线段树
      * 动态开点线段树
        * 只能对**单点修改**建动态开点线段树（内存$O(ClogC)$），不能对**区间修改**建动态开点线段树（内存$O(C^2)$） 来源：$bzoj1171$
  * 图论
    * 建图
      * 在图没有显式的给出需要自己构造时，要小心<font color="red">重复加边</font>（当图有对称性时），尤其是需要 对边权进行加和 时，如最小割。
    * 树
    * $DAG$
    * 一般图
    * 网络流
  * 数学
  * 分治
  * 最优化问题
    * 动态规划
    * 状压$dp$
        * 状态的下标$0..n-1$，正常下标$1..n$，编程时要注意之间的转化
  * 字符串
* 杂
  * 注意$long\ long$
    * <font color="red">尤其是在二分时</font> $mid=\frac{l+r}{2}$ <font color="red">中</font> $l+r$ <font color="red">会超</font>$long\ long$
  * 内存开太大会影响程序时间复杂度；内存开小会影响程序时间复杂度（TLE）
  * 不要去碰 <font color="red">计算几何题</font>
  * 在取$min$的$dp$中要注意每次计算前先判断$f$是否是$inf$，不然会爆$int/long\ long$
  * $std::queue$ <font color="red">是真的慢!</font>$2280ms$和



