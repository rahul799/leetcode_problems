Maximum occurring digit


Submissions: 
Given an array of numbers of size n and digit k, find the number with the maximum occurrence of k. In case there is more than one such number, return the smallest number.

 

Example 1:

Input:
n = 3
arr[] = {100, 202, 2000}
k = 0
Output:
2000
Explanation:
2000 contains 3 zeroes,which is the
maximum number of zeroes among all numbers.
Example 2:

Input:
n = 3
arr[] = {100, 200, 30}
k = 0
Output:
100
Explanation:
Since all three numbers contain equal number
of zeroes, 100 is the minimum number.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxoccourence() which takes an array of integers arr, 2 integers n and k, size of the array, and digit k respectively as input parameters and returns the number with the maximum number of occurrence of digit k. If digit k does not occur in any number, return -1.

 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ n ≤ 10000
1 ≤ arr[i] < 1e9
0 ≤ k ≤ 9
arr[i] does not contain any leading zeroes




class Solution
{

public:
    int maxoccourence(int arr[], int n, int k)
    {
        int cnt=0;
        int num=-1;
        for(int i=0;i<n;i++)
        {
            int temp = arr[i];
            int tcnt = 0;
            while(temp>0)
            {
                if(temp%10==k)
                tcnt++;
                temp/=10;
            }
            if(tcnt > cnt)
            {
                cnt = tcnt;
                 num = arr[i];
            }
            else if(tcnt == cnt)
            {
                num = min(arr[i],num);
            }
            
        
            
        }
        return num;
        
    
    }
}; 

















