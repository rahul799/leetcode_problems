


https://www.geeksforgeeks.org/count-divisors-n-on13/





Count Divisors of n in O(n^1/3)
Difficulty Level : Hard
 Last Updated : 29 Jun, 2020
Given a number n, count all distinct divisors of it.

Examples:

Input : 18
Output : 6
Divisors of 18 are 1, 2, 3, 6, 9 and 18.

Input : 100
Output : 9
Divisors of 100 are 1, 2, 4, 5, 10, 20,
25, 50 and 100
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
A Naive Solution would be to iterate all the numbers from 1 to sqrt(n), checking if that number divides n and incrementing number of divisors. This approach takes O(sqrt(n)) time.

// C implementation of Naive method to count all 
// divisors 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to count the divisors 
int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    printf("Total distinct divisors of 100 are : %d", 
           countDivisors(100)); 
    return 0; 
} 

Output :

Total distinct divisors of 100 are : 9
Optimized Solution (O(n^1/3))

Split number n in two numbers x and y such that n=x*y where x contains only prime factors in range 2 <= x <= n(1/3) and y deals with higher prime factors greater than n(1/3).
Count total factors of x using the naive trial division method. Let this count be F(x).
Count total factors of y using the following three cases. Let this count be F(y).
If y is a prime number then factors will be 1 and y itself. That implies, F(y) = 2.
If y is square of a prime number, then factors will be 1, sqrt(y) and y itself. That implies, F(y) = 3.
If y is the product of two distinct prime numbers, then factors will be 1, both prime numbers and number y itself. That implies, F(y) = 4.
Since F(x*y) is a multiplicative function and gcd(x, y) = 1, that implies, F(x*y) = F(x)*F(y) which gives the count of total distinct divisors of n.
Note that, we have only these three cases for calculating factors of y since there can be at max two prime factors of y. If it would have had more than two prime factors, one of them would surely have been less than equal to n(1/3), and hence it would be included in x and not in y.


// C++ program to count distinct divisors 
// of a given number n 
#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(int n, bool prime[], 
                         bool primesquare[], int a[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (int i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (int i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    int j = 0; 
    for (int p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
int countDivisors(int n) 
{ 
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
  
    bool prime[n + 1], primesquare[n * n + 1]; 
  
    int a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(n, prime, primesquare, a); 
  
    // ans will contain total number of distinct 
    // divisors 
    int ans = 1; 
  
    // Loop for counting factors of n 
    for (int i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        int cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating the number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans = ans * cnt; 
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) 
        ans = ans * 2; 
  
    // Second case 
    else if (primesquare[n]) 
        ans = ans * 3; 
  
    // Third case 
    else if (n != 1) 
        ans = ans * 4; 
  
    return ans; // Total divisors 
} 
  
// Driver Program 
int main() 
{ 
    cout << "Total distinct divisors of 100 are : "
         << countDivisors(100) << endl; 
    return 0; 
} 
