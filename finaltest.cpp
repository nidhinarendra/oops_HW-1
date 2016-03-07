#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <ctime>

using namespace std;


int file_open (char *argv1, int *p_index)
{
 double finalfloat;
 int index=0;
 int length = 100;
 double *input_data = new double [length];
 double *input_data_old;
 string stream1;
 string stream2;
  ifstream file;
  file.open(argv1);
	if(!file.is_open())
	{
	  cerr << "File not found" <<endl;
	  return -2;
	}
	else
	{
	  while(!file.eof())
	  {
	    file >> stream1;
	    stringstream ss(stream1);
	    while ( getline (ss, stream1, ','))
	    {
	      stringstream ss(stream1);
	      ss >> finalfloat;
	      if ( !ss ) 
	      { 
		cerr << "INVALID INPUT" <<endl;
		return -3;
	      }
	      else
	      {
		if (file.eof()) 
		break;
		else if (index == length)
		{
		  length = length * 2;
		  input_data_old = input_data;
		  input_data = new double [length];
		  strncpy((char*)input_data, (const char*)input_data_old,sizeof(input_data_old));
		}
		input_data[index ++] = finalfloat;
	     }
	    } 
	  }
	}
  file.close();
  *p_index = index;
  return (input_data[index]);
}
	




      
//Brute force method
int nested_loop(double input_data[], int count_input)
{
  int start_time = clock();  //Execution time starts
  double sum = 0;	     
  double max_sum = INT_MIN; //Initialising the max_sum to the least value possible
  int index_point;          //The first element for any array
  int sub_array_length;    
  

  for (sub_array_length = 1; sub_array_length <= count_input ; sub_array_length++) 
    {

      for (index_point = 0; index_point <count_input; index_point++)
	{
	  if((sub_array_length+index_point) > count_input)
	    break;
	  sum = 0;
		for (int array_pointer = index_point; array_pointer < (sub_array_length+index_point); array_pointer++)
	        sum = sum + input_data[array_pointer];
	        if (max_sum < sum)
		{
		  max_sum = sum;
		}
	}
    }
  int stop_time = clock(); //Execution time ends
  cout << max_sum << "\t" << (stop_time-start_time)/double (CLOCKS_PER_SEC) << "[sec]" << endl;
  return 0;
}

//Divide and conqure

//Functions to get the maximum of 2 numbers
int max(int first_num, int second_num)
{ 
  return (first_num > second_num)? first_num : second_num; 
}

//Functions to get the maximum of 3 numbers
int max(int first_num, int second_num, int third_num) 
{ 
  return max(max(first_num, second_num), third_num); 
}

//Function to calculate the sum if there are odd number of inputs
int max_middle_sum(double input_data[],int ref1, int middle_point, int count)
{
  //Computation of the sum to the left side of the middle point.
  //int ref1 = 0; // reference point 2
  int sum = 0;
  int sum_left = INT_MIN;
  for (int i = middle_point; i >=ref1; i--)
  {
    sum = sum + input_data[i];
    if (sum > sum_left)
    {
      sum_left = sum;	
    }
  }

  //Computation of the sum to the right side of the middle point.
  int sum1 = 0;
  int sum_right = INT_MIN;
  for (int i = middle_point+1; i <=count; i++)
  {
    sum1 = sum1+ input_data[i];
    if(sum1 > sum_right)
    {
      sum_right = sum1;
    }
}
return sum_left+sum_right;
}






int divide_conquer (double input_data[],int ref1, int count_input)
{
// int ref1 = 0; // l reference point 1
 int count = count_input - 1;
 if ( ref1 == count)  //If there is only 1 element in the array
 {
   return input_data[ref1];
 }

int middle_point = (ref1+count)/2;

return max(divide_conquer(input_data, ref1, middle_point),
	   divide_conquer(input_data, middle_point+1, count),
	   max_middle_sum(input_data, ref1, middle_point, count));

}


//Main function
int main(int argc, char *argv[])
{
if (argc <= 2) 
{
  int index_func;
  file_open(argv [1], &index_func);
  double max_sum = nested_loop(input_data, index_func); //Calling Brute force function
  cout << max_sum << "\t" << (stop_time-start_time)/double (CLOCKS_PER_SEC) << "[sec]" << endl;
  double max_sum = divide_conquer(input_data,0, index_func); //Calling divide and conquer function
  cout << max_sum << endl;
}
else
{
  cerr << "Wrong number of arguments provided \n";  
      return -1;
}

}











