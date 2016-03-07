#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Max_Subarray_Sum(int arr[],int n)	
{
	double max_sum_right;	
	if(n==1)
	{
		return arr[0];
	}
	int m = n/2;
	double left_MSS = Max_Subarray_Sum(arr,m);
	double right_MSS = Max_Subarray_Sum(arr+m,n-m);
	double leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
	for(int i=m;i < n; i++)
	{
		sum = sum+ arr[i];
		if (max_sum < sum)
				{
				max_sum_right = sum;
				}
	}
	sum = 0;
	for(int i= (m-1);i >= 0; i--)
	{
		sum = sum+ arr[i];
		leftsum = max(leftsum,sum);
	}
	int ans = max(left_MSS,right_MSS);
	return max(ans,leftsum+rightsum);
}


int main(int argc, char const *argv[])
{
	
double arr[100];
int array_count;
cout << "enter the number of inputs " << endl;
cin >> array_count;
cout << "enter the values " << endl;
for (int array_value = 0 ; array_value < array_count; array_value++)
{
cin >> arr[array_count];
}
	
cout<<Max_Subarray_Sum(arr,array_count)<<"\n";
	return 0;
}


