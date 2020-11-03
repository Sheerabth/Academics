#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int X;
    vector<int> array;
    int temp;

    cin >> n;
    cin >> X;
    for(int i = 0; i < n; i++){   
        cin >> temp;
        array.push_back(temp);
    }
    
    //merge sort
    sort(array.begin() , array.end());

    //binary search
     while(binary_search(array.begin() , array.end() ,++X))
         continue;
     
    cout << "The Value is " << X << endl;
    return 0;
}