#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

int main()
{
double arr[100]; 
double sum = 0;
double max = INT_MIN;
double num; 
int index;
cout << "enter the number of values\n";
cin >> num;
cout << "enter the numbers\n";
  
	for(int m = 0; m< num; m++)
	{
	cin >> arr[m];
	}
  
	for (index = 0; index <num ; index++)
	{
	int sum = 0;
		for (int sub_array = 1; sub_array <=num; sub_array++)
		{
			if((sub_array+index) > num)
			break;
			sum = sum + arr[index + sub_array-1];
				if (max < sum)
				{
				max = sum;
				}
		}
	}

cout << "max is " << max << endl;
return 0;
}






