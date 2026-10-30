## 1. Finding $w$

  

Given $A = QR$, we want to find $w$ such that $A + uv^T = Q(R + wv^T)$.

  
  

$$A + uv^T = QR + uv^T$$

  

$$QR + uv^T = Q(R + Q^T uv^T)$$

  

Therefore, we can define $w$ as

  

$$w = Q^T u$$

  
  
  

## 2. Uppertriangularizing $wv^T$

To uppertriangularize the outer product $wv^T$ using $O(n)$ Givens rotations, we only need to focus on zeroing out the elements of the vector $w$ from the bottom up.

  

Let $G_{i, j}$ represent a Givens rotation applied to the $(i, j)$ plane.

We can construct a sequence of $n1$ Givens rotations by first useing $G_{n1, n}$ to zero out $w_n$, then $G_{n2, n1}$ to zero out $w_{n1}$, and continue this pattern up to $G_{1, 2}$.

Define this sequence of rotations as $Q_1 = G_{1, 2} G_{2, 3} \dots G_{n1, n}$.

Applying $Q_1$ to $w$ collapses all magnitude into the first entry, yielding $Q_1 w = \begin{pmatrix} ||w|| \\ 0 \\ \vdots \\ 0 \end{pmatrix} = ||w||e_1$.

Consequently, $Q_1 wv^T = (||w||e_1) v^T$. This resulting matrix has nonzero entries exclusively in its first row, making it strictly uppertriangular.

  
  
  

## 3. Proving $Q_1 R + Q_1 wv^T$ is Upper Hessenberg

We need to demonstrate that the combined matrix is upper Hessenberg.

  

From Step 2, we know that $Q_1 wv^T$ is an uppertriangular matrix.

The matrix $R$ is initially uppertriangular. When we apply our sequence of Givens rotations $Q_1 = G_{1, 2} \dots G_{n1, n}$ to $R$, each individual rotation $G_{k1, k}$ combines row $k1$ and row $k$.

Because $R$ is uppertriangular, mixing adjacent rows introduces exactly one nonzero subdiagonal element at the $(k, k1)$ position.

Applying the full sequence of $n1$ rotations introduces nonzeros exactly along the first subdiagonal, turning $Q_1 R$ into an upper Hessenberg matrix.

The sum of an upper Hessenberg matrix ($Q_1 R$) and an uppertriangular matrix ($Q_1 wv^T$) results in an upper Hessenberg matrix.

  
  
  

## 4. Reducing to UpperTriangular

To reduce our upper Hessenberg matrix $H = Q_1 R + Q_1 wv^T$ back to uppertriangular form, we apply a new sequence of $O(n)$ Givens rotations, this time from top to bottom.

  

Apply $G'_{1, 2}$ to zero out $H_{2, 1}$, then $G'_{2, 3}$ to zero out $H_{3, 2}$, and so forth, down to $G'_{n1, n}$.

Let $Q_2 = G'_{n1, n} \dots G'_{2, 3} G'_{1, 2}$.

Applying this to $H$ isolates our new uppertriangular matrix results in $R' = Q_2 H = Q_2 (Q_1 R + Q_1 wv^T)$.

  

Now we can reconstruct the full factorization

  

$$A + uv^T = Q(R + wv^T)$$

  

$$= Q Q_1^T (Q_1 R + Q_1 wv^T)$$

  

$$= Q Q_1^T Q_2^T Q_2 (Q_1 R + Q_1 wv^T)$$

  

This leaves us with our updated matrices

  

$$Q' = Q Q_1^T Q_2^T$$

$$R' = Q_2(Q_1 R + Q_1 wv^T)$$

  
  
  

## 5. Cost Analysis

  

To find $wv^T$, A standard matrix vector multiplication costs $O(n^2)$ operations.
 
Applying a single Givens rotation to a matrix only affects 2 rows, requiring $O(n)$ operations. Because we apply $O(n)$ rotations for both $Q_1$ and $Q_2$, this step takes $O(n^2)$ total operations.

Updating $Q'$ requires multiplying $Q$ by the $O(n)$ Givens rotations, which also takes $O(n^2)$ operations.

so the total is $O(n^2)$ which is much better than the default $O(n^3)$.