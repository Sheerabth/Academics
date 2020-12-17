#include <iostream>
using namespace std;

int func(int n)
{
    int ans = 0;
    for(int i = 0; i <= n-2; i++)
        for(int j = i+1; j <= n-1; j++)
            ans++;
    return ans;
}

int main()
{
    int ans = func(30);
    cout << ans;
    return 0;
}