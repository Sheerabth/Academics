#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Please enter thee number" << endl;
    int val, temp;
    cin >> val;
    int ans = 0;
    temp = val-2;
    //if number is even 
    if(val%2 == 0)
    {
        ans = __gcd(val, val-3);
        temp = val-1;
    }
    //itreating till we get the gcd is 1
    while(ans != 1)
    {
        ans = __gcd(val, temp);
        if(ans != 1)
            ans = 0;
        temp = temp-2;
    }

    cout << "The value of the number which is a coprime of the given number and is less than given value - 1 is " << temp << endl;
    return 0;
}