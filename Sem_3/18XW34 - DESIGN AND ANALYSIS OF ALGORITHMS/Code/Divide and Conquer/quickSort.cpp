#include <iostream>
#include <vector>

using namespace std;


int getPartition(vector<int> &vec, int left, int right) 
{
    int &pivot = vec[left];  
    int i = left;
    int j = right;
    while (i < j && i <=right && j >=left) 
    {
        while (vec[i] <= pivot && i <right) 
            i++;
        while (vec[j] > pivot && j >left)
            j--;
        if (i < j) 
        {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    int temp = pivot;
    pivot = vec[j];
    vec[j] = temp;
    return j;
}

void quickSort(vector<int> &vec, int left, int right ) 
{
    if (left < right) 
    {
        int s = getPartition(vec, left, right);
        quickSort(vec, left, s-1);
        quickSort(vec, s+1, right);
    }
}

int main()
{
    vector<int> nums;
    for (size_t i = 4; i > 0; i--)
        nums.push_back(i);

    quickSort(nums, 0, nums.size()-1);

    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}