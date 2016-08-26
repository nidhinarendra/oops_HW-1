#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

// A utility funtion to find maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// A utility funtion to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }
 
// Find the maximum possible sum in arr[] such that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)  //h is count_input - 1
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}
 
// Returns sum of maxium sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
   // Base Case: Only one element
   if (l == h)
     return arr[l];
 
   // Find middle point
   int m = (l + h)/2;
 
   /* Return maximum of following three possible cases
      a) Maximum subarray sum in left half
      b) Maximum subarray sum in right half
      c) Maximum subarray sum such that the subarray crosses the midpoint */
   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int arr[] = {1.1,2.2, -3, 0,3};
   int n = sizeof(arr)/sizeof(arr[0]);
cout << "size of arr is " << sizeof(arr) << "size of the first element is " << sizeof(arr[0]) << "n is " << n;
   int max_sum = maxSubArraySum(arr, 0, n-1); // in our prog n is the count_input 
   cout << "Maximum contiguous sum is " << max_sum << endl;
 //  getchar();
   return 0;
}
