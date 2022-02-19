#### $bzoj1101-POI2007$ $Zap$ 

* 题面描述

  * $FGD$正在破解一段密码，他需要回答很多类似的问题：
    * 对于给定的整数$a,b$和$d$，有多少正整数对$x,y$，满足$x\leq a,y\leq b$，并且$gcd(x,y)=d$。作为$FGD$的同学，$FGD$希望得到你的帮助。

* 输入格式

  * 第一行包含一个正整数$n$，表示一共有$n$组询问。$(1\leq n\leq 5*10^4)$接下来$n$行，每行表示一个询问，每行三个正整数，分别为$a,b,d$。$(1\leq d\leq a,b\leq 5*10^4)$

* 输出格式

  * 对于每组询问，输出一个正整数，表示满足条件的整数对数。

* 题解

  * 推一波式子

  * $$
    ans=\sum_{i=1}^a\sum_{j=1}^b [gcd(i,j)=d]\ (a<b)\\
    =\sum_{i=1}^{\frac{a}{d}}\sum_{j=1}^{\frac{b}{d}}[gcd(i,j)=1]\\
    =\sum_{i=1}^{\frac{a}{d}}\sum_{j=1}^{\frac{b}{d}}\sum_{d'|gcd(i,j)}\mu(d')\\
    =\sum_{x=1}^{\frac{a}{d}}\lfloor\frac{a}{xd}\rfloor\lfloor\frac{b}{xd}\rfloor\mu(x)\\
    $$

  * 由于$\lfloor\frac{a}{xd}\rfloor,\lfloor\frac{b}{xd}\rfloor$不同值的个数分别只有$O(\sqrt{\frac{a}{d}})$ 和$O(\sqrt{\frac{b}{d}})$因此先预处理$\mu(x)$的前缀和，然后对于每个询问用$O(\sqrt{\frac{a}{d}}+\sqrt{\frac{b}{d}})$的时间回答

