
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall
as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the 
higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple
instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.


	
1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. For simplicity, we consider width as always smaller than or equal to depth.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
MSH(i) = Maximum possible Stack Height with box i at top of stack
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
If there is no such j then MSH(i) = height(i)

4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n

Following is the implementation of the above solution.
	
	
	
	
Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(12, 32, 10) (10, 12, 32) (6, 7, 4) (5, 6, 4)
(4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a height
greater than this.


Input:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15




#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct Cube
{
    int l;
    int b;
    int h;
    
    Cube(int len,int wid,int hei)
    {
        l = len;
        b = wid;
        h = hei;
    }
};

bool compare(Cube x, Cube y)
{
    int l1 = min(x.l,x.b);
    int b1 = max(x.l,x.b);
    int l2 = min(y.l,y.b);
    int b2 = max(y.l,y.b);


    if(l1 < l2 && b1 < b2)
        return true;
    
    if(l1 ==  l2)
        return b1 < b2;
    
    return l1 < l2;
    
}

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<Cube> v;
    for(int i=0; i<n; i++)
    {
        Cube x = Cube(length[i],width[i],height[i]);
        Cube y = Cube(length[i],height[i],width[i]);
        Cube z = Cube(width[i],height[i],length[i]);
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
    }
    
    sort(v.begin(),v.end(),compare);
    
    int l = 3*n;
    int dp[l];
    int ans = 0;
    
    for(int i=0; i<l; i++)
    {
        dp[i] = v[i].h;
        
        int l1 = min(v[i].l,v[i].b);
        int b1 = max(v[i].l,v[i].b);
        
        for(int j=0; j<i; j++)
        {
            int l2 = min(v[j].l,v[j].b);
            int b2 = max(v[j].l,v[j].b);
            
            if(l2 < l1 && b2 < b1)
                dp[i] = max(dp[i],dp[j] + v[i].h);
        }
        ans = max(ans,dp[i]);
    }
    
    return ans;
    
}
