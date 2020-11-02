#include <iostream>
#include <vector>
#include <list>

using namespace std;


//returns max of 2 binary numbers
list<int> getBigger(list<int> list_1, list<int> list_2)
{
    int size = list_1.size();
    list <int> :: iterator first = list_1.begin();
    list <int> :: iterator second = list_2.begin();
    while(first != list_1.end())
    {
        //checking if the bit of list_1 is 1
        if(*first == 1)
        {
            //checking if the bit of list_2 is 1 if it is one then we cant differentiate the binary numbers with this bit so going to next bit
            if(*second == 1)
            {
                first++;
                second++;
            }
            //else list_1 is bigger
            else
                return list_1;
        }

        //checking if the bit of list_1 is 0
        else
        {
            //checking if the bit of list_2 is 0 if it is one then we cant differentiate the binary numbers with this bit so going to next bit
            if(*second == 0)
            {
                first++;
                second++;
            }
            //else list_2 is bigger
            else
                return list_2;
        }
        
    }
    return list_1;
}

//returns max binary from a list
list<int> getMax(list<list<int>> binaryNums)
{
    //initializing max as first element 
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
    //calling the function getMax
    list<int> max = getMax(binaryNums);
    return 0;
}