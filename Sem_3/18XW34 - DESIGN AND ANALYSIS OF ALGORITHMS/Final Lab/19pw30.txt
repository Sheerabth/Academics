// S. Ranga Susanth Sai
//19pw30 3rd Sem 
// To find number of lucky elements

#include <iostream>
#include <vector>

using namespace std;

// Function with returns true if a pair is lucky
bool isLuckyPair(int num_1, int num_2)
{
    if(num_1 > num_2)
    {
        if(num_1 % num_2 == 0 || num_2 % num_1 == 0 )
            return true;
        else 
            return false;
    }
    else
        return false;
}

// Returns number of lucky numbers
int getLuckyNums(vector<int> vec)
{
    int mid  = vec.size()/2;
    int luckyNums = 0;
    for(int i = 0; i < mid; i++)
    {
        if(isLuckyPair(vec[i], vec[i+mid]))
            luckyNums++;
    }
    return luckyNums;
}

// Driver code
int main()
{
    vector<int> vec;
    int val;
    cout << "Enter the numbers ending with -1" << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        vec.push_back(val);
    }
    cout << "The number of lucky Nums is " << getLuckyNums(vec);
}