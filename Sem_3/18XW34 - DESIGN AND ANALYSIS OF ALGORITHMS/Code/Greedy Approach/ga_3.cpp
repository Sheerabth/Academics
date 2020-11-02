#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sequence,input;
    cin >> sequence >> input;
    vector<pair<int,char>> v;

    for(int i = 0; i < input.length(); i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(input[i] == sequence[j])
            {
                v.push_back(make_pair(j,sequence[j]));
            }
        }
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < input.length(); i++){
        cout << v[i].second;
    }

    return 0;
}