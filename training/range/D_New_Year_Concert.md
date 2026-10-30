# New Year Concert

We are given a problem where we want to consider the length of 
the array in relation to GCDs.

Specifically, if the gcd of a_l, ... a_r = r - l + 1, then we have a magic array, and we want to do an operation to get rid of this magic array. 

To do this, we can choose a very large prime on the boundary, then all ranges containing this index will have gcd 1. 

For a fixed l, as r increases, r - l + 1 increases, but gcd(a_l, ... a_r) is non increasing, so there is at most one magic r for a fixed l, and the max number of such magic arrays is n.

So now we want to find the largest r such that 
gcd(a_l, ... a_r) >= r - l + 1 (which could be l), and then we replace it with a large prime so that for all segments longer than 1, they have gcd 1, and for segments of length 1, the gcd is the large prime. 

Now since we want to minimize the number of these operations required to address each prefix, we can fix r, use a moving pointer for l, find the first l beyond the previous segment that has equality, and blow it up. 

We can use a ST to handle gcd querys effectively. 






