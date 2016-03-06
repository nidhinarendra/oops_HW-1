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
double max_sum = INT_MIN;
double number_of_inputs; 
int index_sub_array;
cout << "enter the number of values\n";
cin >> number_of_inputs;
cout << "enter the numbers\n";
  
	for(int m = 0; m< number_of_inputs; m++)
	{
	cin >> arr[m];
	}
  
	for (index_sub_array = 0; index_sub_array <number_of_inputs ; index_sub_array++)
	{
	int sum = 0;
		for (int sub_array = 1; sub_array <=number_of_inputs; sub_array++)
		{
			if((sub_array+index_sub_array) > number_of_inputs)
			break;
			sum = sum + arr[index_sub_array + sub_array-1];
				if (max_sum < sum)
				{
				max_sum = sum;
				}
		}
	}

cout << "max is " << max_sum << endl;
return 0;
}






