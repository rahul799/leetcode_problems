Sorted Arrangements | Infosys Specialist Programmer | On campus hackerrank



rithiksingh098's avatar
rithiksingh098
157
Last Edit: August 31, 2019 12:00 PM

6.9K VIEWS

Your are given n and an input array with n numbers.
You have to tell the minimum number of operations needed to pick each element from the input array make a sorted arrangement.
Every insertion and removal is 1 operation.
A sorted arrangement is basically an array that is sorted.
lets understand with example..
let n be 4
and input array be 2 4 1 3
so first we take 2 and insert in the empty sorted arrangement. so 1 operation
then the sorted arrangement is- 2
then we pick 4 and put it in the sorted arrangement.. so we would put after 2 so 1 operation
then the sorted arrangement is- 2 ,4
then we pick 1 and put it in the left so 1 operation..
then the sorted arrangement is- 1,2,4
(now this is important)
now we pick 3 and put we can either remove 1 and 2 put 3 and then again put 2 and 1 back or we can remove 4 , put 3 and again put 4.
obviously the latter takes 3 operations and former takes 5 operations. so we would perform the latter one.
answer is 1+1+1+3=6 operations.

constraints
N<10^5



int BIT[100005], a[100005], n;
void update(int x, int delta)
{     
      for(; x <= n; x += x&-x){
        BIT[x] += delta;
      }
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
} 
 
long getCount( long number, int i){
    int left = query(number-1);
    int right = i - query(number);
    return left < right ? 2*left+1 : 2*right+1; 
}

long minimumOperations(vector<int> numbers) {
    long ans=0;
    n = 0;
    for(int i=0;i<numbers.size();i++){
         n = max(n, numbers[i]);
    }
    for(int i=0; i<numbers.size(); i++){
        ans += getCount(numbers[i], i);
        update(numbers[i],1);
    }
    return ans;
}






