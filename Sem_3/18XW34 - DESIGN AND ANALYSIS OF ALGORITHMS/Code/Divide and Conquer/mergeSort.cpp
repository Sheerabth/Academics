#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>&left, vector<int>& right, vector<int>& vec)
{
    int lnum = left.size();
    int rnum = right.size();
    int i = 0, j = 0, k = 0;

    while (j < lnum && k < rnum) 
    {
        if (left[j] < right[k]) {
            vec[i] = left[j];
            j++;
        }
        else {
            vec[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < lnum) {
        vec[i] = left[j];
        j++; i++;
    }
    while (k < rnum) {
        vec[i] = right[k];
        k++; i++;
    }
}


void mergeSort(vector<int> &vec) 
{
    if (vec.size() <= 1) return;

    int mid = vec.size() / 2;
    vector<int> left;
    vector<int> right;

    for (int j = 0; j < mid;j++)
        left.push_back(vec[j]);
    for (int j = 0; j < (vec.size()) - mid; j++)
        right.push_back(vec[mid + j]);

    mergeSort(left);
    mergeSort(right);
    merge(left, right, vec);
}

int main() {
    vector<int> nums;
    for (size_t i = 10; i > 0; i--)
        nums.push_back(rand() % 10);

    mergeSort(nums);

    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}

