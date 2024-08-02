mcf stands for minimum cost flow. It's trying to solve the following lp
min w^Tx
  Mx = b
  0 <= x <= c

maxflow tries to solve:
max inflow to t
    f_x(u) = 0 for u != s,t
   0 <= x <= c

mcmf stands for minimum cost max flow tries to solve:
min w^T x
Where x is a optimal solution to maxflow.
