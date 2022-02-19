群$——$一簇函数映射$($置换$)$的抽象

* 元素$\rightarrow$ 映射
* 运算$\rightarrow$ 复合
* 单位$\rightarrow$ 某函数

* * 循环节 
  * * $(1\ 2\ 3\ 4)\rightarrow(2\ 1\ 4\ 3)$ 
    * 循环节$:\ (1\ 2)\ (3\ 4)$
    * $(1\ 2\ 3\ 4)\rightarrow(2\ 3\ 4\ 1)$
    * 循环节$:\ (1\ 2\ 3\ 4)$或$(4\ 1\ 2\ 3)$
    * $(1\ 2\ 3\ 4)\rightarrow(1\ 2\ 3\ 4)$
    * 循环节$:\ (1)(2)(3)(4)$
    * $(1\ 2\ 3\ 4)\rightarrow(1\ 4\ 3\ 2)$
    * 循环节$:\ (1)\ (2\ 4)\ (3)$

详见$:\ https://blog.csdn.net/liangzhaoyang1/article/details/72639208$



* $Burnside$ 定理
  * 针对染色方案
  * 在一个置换中恒不变的算子个数为$cnt_i$
  * 本质不同的方案个数为$\frac{\Sigma\ cnt_i}{置换个数}$



* $Polya$ 定理
  * 针对染色
  * 对于一种置换恒不变的算子个数为$颜色个数^{循环节个数}$
    * 例$:\ (1)(2)(3)(4)\ $有$4$个循环节个数



* $Polya\ ($循环群$):\ 1/n*(\Sigma^n_1\ k^{gcd(n,i)}) \ \ \rightarrow\ \ 1/n*(\Sigma_{d|n}\ k^d*\phi(n/d))$

  * $k\ :\ $ 颜色个数

  * $n\ :\ |$群$|$
  * 计算$:$$1/n*(\Sigma_{d|n}\ k^d*\phi(n/d))\ \ (d|n$ 太大无法计算$)$
  * $\because\ d*d'=n\ $对称 只需计算$\sqrt n$



* $Polya($二面群$):\ 1/(2n)*(\Sigma_{g\in D_n}\ k^{|c(g)|})$
* * 



* $Polya($对称群$)$