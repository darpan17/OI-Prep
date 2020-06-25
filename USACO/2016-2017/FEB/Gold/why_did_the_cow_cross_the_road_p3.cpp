// a pair (x,y) collides with a pair (p,q) if (x > p && x < q && y > q)
// maintain a set of pairs
// from 1 to n, find out position of pair (x,y) in the set
// now for the elements in the set before (x,y) we have to find how many such (p,q) are there such that q > x and q < y
// for elements in the set after (x,y) we have to find how many such (p,q) are there such that p < y and q > y
// this can be done using a segtree ? (this part's soln we have to find out)
