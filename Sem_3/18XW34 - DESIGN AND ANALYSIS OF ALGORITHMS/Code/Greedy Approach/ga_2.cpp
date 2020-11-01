#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> getBigger(list<int> list_1, list<int> list_2)
{
    int size = list_1.size();
    list <int> :: iterator first = list_1.begin();
    list <int> :: iterator second = list_2.begin();
    while(first != list_1.end())
    {
        if(*first == 1)
        {
            if(*second == 1)
            {
                first++;
                second++;
            }
            else
                return list_1;
        }
        else
        {
            if(*second == 0)
            {
                first++;
                second++;
            }
            else
                return list_2;
        }
        
    }
    return list_1;
}

list<int> getMax(list<list<int>> binaryNums)
{
    list<int> max = binaryNums.front();
    for(auto eachList : binaryNums)
        max = getBigger(max, eachList);
    return max;
}

int main()
{
    list<list<int>> binaryNums;
    char check;
    int count = 0;
    int val;
    cout << "Please enter the Binary numbers " << endl;
    do
    {
        cout << "Please enter Binary Number (" << count + 1 << ") Press -1 to stop" << endl;
        list<int> vec;
        while(true)
        {
           cin >> val;
           if(val == -1)
                break;
            vec.push_back(val);
        }
        binaryNums.push_back(vec);
        cout << "Do you want to add a new number ? " << endl << "Press y to enter a new number n to stop: ";
        cin >> check;
        count++;
    }while(check == 'y');
    list<int> max = getMax(binaryNums);
    return 0;
}