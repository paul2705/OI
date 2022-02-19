#### $ST$

* $O(nlogn)-O(1)$

* 能够处理序列上区间最值，或其他区间操作（要求 该操作 满足 结合律）

* 以下用求区间最值作为例子

* 预处理出从$i$向后跳$2^0,2^1...,2^{t-1},2^t$步的最值

* 这里有个引理

* $$
  2^{[log_2\ {len}]}>\frac{len}{2}
  $$

* 然后再查询$[l,r]$的最值时，我们只要查询

* 记 $k=[log_2\ len]​$

* $$
  min(f[l][k],f[r-2^k][k])
  $$

* 如下图

  * $l+2^{[log_2\ len]}\geq\frac{r-l}{2}$  
  * $r-2^{[log_2\ len]}\leq\frac{r-l}{2}$

* 所以上面的式子就能覆盖整个区间，这里也可看出为什么 $ST​$ 要求操作满足 **结合律**，因为这两段区间覆盖了同一个区间

* ![ST_explain](/Users/duanlingbo/Desktop/OI/knowledge/数据结构/中级/ST/ST_explain.png)

* 应用：

  * 区间最值
  * 畸形：
    * $O(nlogn)-O(logn)\ LCA$
    * $O(nlogn)-O(1)\ LCA$

