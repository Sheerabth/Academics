#include <iostream>

using namespace std;

int getIndex(int arr[], int size, int val)
{
    for(int i = 0; i < size; i++)
        if(arr[i] == val)
            return i;
    return -1;
}

int merge(int arr[], int l, int m, int r, int x)
{
    int temp;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
     for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0; 
    int j = 0; 
    int k = l;
     
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
            if(x < R[j])
                temp = R[j];
        }
        else
        {
            arr[k] = R[j];
            j++;
            if(x < L[i])
                temp = L[i];
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
        if(x < L[i])
            temp = L[i];
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        if(x < R[j])
            temp = R[j];
    }
    return temp;
}
int mergeSort(int arr[], int l, int r, int x)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;
        int value1 = mergeSort(arr, l, m, x);
        int value2 = mergeSort(arr, m + 1, l, x);
        if(value1 > value2)
            value1 = value2;
        return merge(arr, l, m, r, value1);
    }
    else 
        return 0;
}
 

 int filter(int arr[], int size, int ans, int x)
 {
    int available = getIndex(arr, size, ans+1);
    if(available == -1)
        return ans+1;
    while(available != -1)
        available = getIndex(arr, size, ++ans);
    return x;
 }

int main()
{
    int len;
    cout << "Please enter the number of elements in a array: ";
    cin >> len;
    int* arr = new int [len];

    cout << "Please enter the values of the array" << endl;
    for(int i = 0; i < len; i++)
        cin >> arr[i];

    int x;
    cout << "Please enter the value of X: " << endl;
    cin >> x;
    int ans = mergeSort(arr, 0, len-1, x);
    cout << "The array is " << endl;
    for(int j = 0; j < len; j++)
        cout << arr[j] << " ";
    cout << endl << "Ans is " << ans << endl;
    ans = filter(arr, len, ans, x);
    cout << "The value z such that z is not in the array and is greater is than x is " << ans << endl;
}