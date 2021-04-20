Given n eggs and k floors, your task is to find the minimum numbers of trials required to find the threshold floor. Threshold floor is one from which the egg starts breaking and also egg breaks for all the floors above. Also, if egg dropped from any floor below the threshold floor, it won’t break. You can assume following assertions to be true:

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If an egg breaks when dropped, then it would break if dropped from a higher floor.
If an egg survives a fall then it would survive a shorter fall.



Let’s start our game with the assertion that trials(n, k) returns the minimum number of trials required to find the threshold floor am k consecutive floors. 
Let’s choose some random floor y (y>1 and y<=k) to perform the first trial.
We now have 2 possibilities:



Egg breaks :- As explained before we can conclude that threshold floor will be below yth or yth floor. Hence, following relation is true:
trials(n, k) = 1 + trials(n-1, y-1)


Egg doesn’t break :- This implies that threshold floor is above yth floor and therefore, following relation is true:
trials(n, k) = 1 + trials(n, k-y)


Egg doesn’t break :- This implies that threshold floor is above yth floor and therefore, following relation is true:
trials(n, k) = 1 + trials(n, k-y)
In the worst case, the number of trials required will be maximum of cases when egg breaks and when it doesn’t. Speaking in the language of algorithm, we can say that:

trials(n, k) = 1 + max(trials(n-1, y-1), trials(n, k-y))
Now, only task left is to find the y for which trials(n, k) will be minimum which can be done easily by varying y from 1 to k and taking minimum of the values. 
Speaking about the base cases, In the beginning of the tutorial, we concluded that trials(n, k) = k for n=1. Also you can see that trials(n, 0) = 0. Hence, our final recursive relation 
looks like as follows:



trials(n, k) =  k if n=1,
                0 if k=0,
                min(1 + max(trials(n-1, y-1), trials(n, k-y))) for y in (1, k)
                
                
                
I don’t need to repeat the fact that above recursive relation runs in exponential time due to overlapping of subproblems. In fact we can use a 2-d array to store all the distinct n*k function calls possible. After that we can reuse the cached values wherever required instead of computing the function again and again. Let’s write our final efficient algorithm:

trials(n, k) =  dp[n][k] if array have stored value,
                dp[n][k] = k if n=1,
                dp[n][k] = 0 if k=0,
                dp[n][k] = min(1 + max(trials(n-1, y-1), trials(n, k-y))) 
                           for y in (1, k)


