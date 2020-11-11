#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> vec, int toSearch)
{
    int l = 1;
    int r = vec.size();
    while(l <= r)
    {
        int m = (r+l)/2;
        if(toSearch == vec[m])
            return m;
        else if(toSearch < vec[m])
            r = m-1;
        else
            l = m+1;
    }
    return -1;
}

int main()
{
    vector<int> nums;

     for (size_t i = 0; i < 10; i++)
        nums.push_back(i);
    int ans = binarySearch(nums, 9);
    cout << ans << endl;
}