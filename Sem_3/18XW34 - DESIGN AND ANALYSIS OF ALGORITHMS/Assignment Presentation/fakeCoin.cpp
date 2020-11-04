#include <iostream>
#include <vector> 
#include <cmath> 

using namespace std;

int returnWeight(vector<int> coinList, int start, int end)
{
    int sum = 0;
    for(auto i = start; i <= end; i++)
        sum += coinList[i];
    return sum;    
}

int findImposter(vector<int> coinList, int start, int end)
{
    //if(s)

    int mid_1 = start + ceil((float)((end-start)/3));
    int mid_2 = start + ceil((float)((2*(end-start))/3))+1;

    return 0;
}

int main()
{
    vector<int> coinList;
    int val;
    cout << "Enter the list of coins " << endl;
    cout << "0 for Imposter, 1 for Original and -1 to stop" << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        coinList.push_back(val);
    }
    int size = coinList.size();
    cout << "size is " << size << endl;
    int index = findImposter(coinList, 5, 7);
    return 0;
}