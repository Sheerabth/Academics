#include <iostream>

using namespace std;


int getIndex(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
void merge(int arr[], int l, int m, int r)
{
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
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


 int filter(int arr[], int size, int x)
 {
    int available = getIndex(arr, 0, size-1, x+1);
    if(available == -1)
        return x+1;
    while(available != -1)
        available = getIndex(arr, 0, size-1, ++x);
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
    mergeSort(arr, 0, len-1);
    cout << "The array is " << endl;
    for(int j = 0; j < len; j++)
        cout << arr[j] << " ";
    
    int ans = filter(arr, len, x);
    cout << "The value z such that z is not in the array and is greater is than x is " << ans << endl;
}