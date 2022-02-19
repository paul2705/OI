$$
f[i][0/1]表示以i为根，(fa_i,i)边是否连并且i下方的关键点断开\\
f[u][0]=w[e]+\sum\min(f[v][0],f[v][1])\\
f[u][1]=\sum \min(f[v][0],f[v][1])\\
\Rightarrow f[u]=\min(w[e],\sum f[v])\ (if\ u\neq star)\\
f[u]=w[e]\ (if\ u=star)\\
$$

