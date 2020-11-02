#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sequence,input;
    //taking input
    cin >> sequence >> input;

    vector<pair<int,char>> v;
    //itreating through each letter givin in the input
    for(int i = 0; i < input.length(); i++)
    {
        //itreating through each letter in the given sequence
        for(int j = 0; j < 26; j++)
        {
            //if both of the chars are same then we insert in to the vector pair v
            if(input[i] == sequence[j])
            {
                v.push_back(make_pair(j,sequence[j]));
            }
        }
    }

    //sorting based on int in v
    sort(v.begin(),v.end());

    //printing the vector
    for(int i = 0; i < input.length(); i++){
        cout << v[i].second;
    }

    return 0;
}