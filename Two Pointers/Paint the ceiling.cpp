

https://leetcode.com/discuss/interview-question/892579/paint-the-ceiling-swe-hackerrank-test



Given an array, find total pairs such that we have area less than a


long int variantsCount(int n, int s0, int k, int b, int m, long int a)
{
    vector<long long int>v;
    v.push_back(s0);
    for (int i = 1; i < n; i++)
    {
        long long int x = ((k * v[i - 1] + b) % m) + 1 + v[i - 1];
        v.push_back(x);
    }
    long long int j = v.size() - 1;
    long res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (j > i && v[i]*v[j] > a)
            j--;

        if (v[i]*v[j] <= a)
        {
            long int len = j - i;
            res += len * 2;
            if (v[i]*v[i] <= a)
                res++;
        }
    }
    return res;
}
