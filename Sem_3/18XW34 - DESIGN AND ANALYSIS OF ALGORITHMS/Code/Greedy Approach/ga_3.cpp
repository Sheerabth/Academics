#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    vector<pair<int,char>> v;

    for(int i = 0; i < t.length(); i++){
        for(int j = 0; j < 26; j++){
            if(t[i] == s[j]){
                v.push_back(make_pair(j,s[j]));
            }
        }
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < t.length(); i++){
        cout << v[i].second;
    }

    return 0;
}