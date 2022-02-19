#### $min\_25$筛

* 用来解决一些要求要用低于$O(n^{\frac{2}{3}})$的时间复杂度求解$\sum_{i=1}^nf(i)$，但要求$f(i)$是积性函数，且$f(p)$以及$\sum_pf(p)$能够快速求得

* 前置技能

  * $\left\lfloor\frac{\left\lfloor\frac{x}{a}\right\rfloor}{b}\right\rfloor=\left\lfloor\frac{x}{ab}\right\rfloor$

    * $$
      proof.\ k=\left\lfloor\frac{\left\lfloor\frac{x}{a}\right\rfloor}{b}\right\rfloor \\
      \Rightarrow \left\lfloor\frac{x}{a}\right\rfloor=bk+c\ (c<b) \\
      \Rightarrow x=a(bk+c)+c'\ (c'<a)\\
      \Rightarrow x=abk+ac+c'\ (ac+c'<ac+a=a(c+1)\leq ab)\\
      \Rightarrow \left\lfloor\frac{x}{ab}\right\rfloor=k\\
      \therefore\left\lfloor\frac{\left\lfloor\frac{x}{a}\right\rfloor}{b}\right\rfloor=\left\lfloor\frac{x}{ab}\right\rfloor
      $$

* $min\_25$筛将这$1\sim n$数分为两类：

  * 质数
  * 合数

* 对于质数，我们记$P=\{p|p\in prime\}$，特别的我们记$P_x$为从$2$开始第$x$个质数。同时，我们定义$g(x,j)=\sum_{i=2}^xf(i)[i\in P_{1..j}\ or \ min(p)>P_j,p|i,p\in P]$ 

* 这东西有啥用呢？我们可以注意到这东西的取值又分为两类：

  * $P_j^2>x$
    * 当我们把$P_j$加进去的时候，对于$i\in P_{1..j}$没有任何贡献，而对于$min(p)>P_j,p|i,p\in P$最小的一个$i$为$P_j^2>x$，因此这一部分也没有贡献。$\therefore g(x,j)=g(x,j-1)$
  * $P_j^2\leq x$
    * 当我们把$P_j$加进去的时候，同样对于$i\in P_{1..j}$没有任何贡献，但对于$min(p)>P_j,p|i,p\in P$这一部分相比$P_{j-1}$的时候要加入的东西减少了，即$\{min(p)=P_j,p|i,p\in P\}$的这部分
    * 这部分的贡献为$f(P_j)*(g(\frac{x}{P_j},j-1)-\sum_{i=1}^{j-1}f(P_j))$

* 因此$g(x,j)$的计算式可以改写成：

  * $$
    g(x,j)=\begin{cases}
    	g(x,j-1)\quad P_j^2>x\\
    	g(x,j-1)-f(P_j)*(g(\frac{x}{P_j},j-1)-\sum_{i=1}^{j-1}f(P_i))\quad P_j^2\leq x\\
    \end{cases}
    $$

  * $g()$的边界：$g(x,0)=\sum_{i=1}^xf(i,把每个i都看成质数)$

* 说这么多有什么用？

  * 我们观察$g(x,j)$的计算式，不难发现$x$不是每个都出现的，结合$\left\lfloor\frac{\left\lfloor\frac{x}{a}\right\rfloor}{b}\right\rfloor=\left\lfloor\frac{x}{ab}\right\rfloor$，我们不难发现$x$出现的都是$\left\lfloor\frac{n}{i}\right\rfloor$，$x$共$O(\sqrt{n})$个取值。
  * 并且通过$P_j^2>n$时，$g()$值不再变，可知有效的$P_j<\sqrt{n}$，因此$j$共$O(\frac{\sqrt{n}}{ln\sqrt{n}})$
  * 再通过$P_j^2\leq x$限制，最后时间复杂度为$O(\frac{n^{\frac{3}{4}}}{\log n})$

* 再来看一下$g(x,j)$的含义，它相当于是在$1\sim x$中用$P_{1..j}$这些质数筛去后的数，而从$g(x,j-1)$推到$g(x,j)$就相当于是在$P_{1..j-1}$的基础上 用$P_j$筛去一些数。而最终$g(n,|P|)$就是所有$1\sim n$的质数的函数和。

* 这样质数部分就全部做完了，然后就剩下合数部分。记$S(n,j)=\sum_{i=2}^nf(i)[min(p)>P_j,p|i,p\in P]$ 

* $S(n,j)=g(n,|P|)-\sum_{i=1}^{j-1}f(P_i)+\sum_{i\geq j}\sum_ef(P_i^e)*S(\frac{n}{P_i^e},i+1)+f(P_i^{e+1})$

* 同样$S(n,j)$中$n$只有$O(\sqrt{n})$种取值，$j$只有$O(\frac{\sqrt{n}}{\log\sqrt{n}})$ ，