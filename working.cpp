#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <ctime>

using namespace std;


//Brute force algorithm
int nested_loop(double input_data[], int count_input)
{
  int start_time = clock(); //Computation time starts for Brute force algorithm
  double sum = 0;
  double max_sum = INT_MIN;
  int index_point;
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
  int stop_time = clock();
  cout << max_sum << "\t" << (stop_time-start_time)/double (CLOCKS_PER_SEC) << "[sec]" << endl;
  return 0;
}

//Divide and conqure

//Functions to get the maximum of 2 numbers
double max(double first_num, double second_num)
{ 
  return (first_num > second_num)? first_num : second_num; 
}

//Functions to get the maximum of 3 numbers
double max(double first_num, double second_num, double third_num) 
{ 
  return max(max(first_num, second_num), third_num); 
}

//Function to calculate the sum if there are odd number of inputs
double max_middle_sum(double* input_data, int ref,
		      int middle_point, int count_input)
{
  //Computation of the sum to the left side of the middle point.
  double suml = 0;
  double sum_left = INT_MIN;
  for (int i = middle_point; i >=ref; i--)
    { 
      suml = suml + input_data[i];
      if (suml > sum_left)
	{
	  sum_left = suml;	
	}
    }
  
  //Computation of the sum to the right side of the middle point.
  double sumr = 0;
  double sum_right = INT_MIN;
  for (int i = middle_point+1; i <=count_input; i++)
    {
      sumr = sumr + input_data[i];
      if(sumr > sum_right)
	{
	  sum_right = sumr;
	}
    }
  
  return sum_left+sum_right;
}


//Divide and conquer main function
double dnc(double input_data[], int ref, int count_input)
{
  if (ref == count_input)
    {
      return input_data[ref];
    }

  int middle_point = (ref+count_input)/2;
  
  return max(dnc(input_data, ref, middle_point),
	     dnc(input_data, middle_point+1, count_input),
	     max_middle_sum(input_data, ref, middle_point, count_input));
}


int main(int argc, char *argv[])
{
  double finalfloat;
  int index=0;
  int length = 100;
  double *input_data = new double [length];
  double *input_data_old;
  string stream1;
  string stream2;
  
  if (argc <= 2) 
    {
      ifstream file;
      file.open(argv[1]);
      
      if(!file.is_open())
	{
	  cerr << "File not found" <<endl;
	  return -1;
	}
      
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
		  return -2;
		}
	      else
		{
		  if (file.eof()) 
		    break;	
		  else
		    {						
		      if (index == length)
			{
			  length = length * 2;
			  input_data_old = input_data;
			  input_data = new double [length];
			  strncpy((char*)input_data, (const char*)input_data_old,
				  sizeof(input_data_old));
			}
		      input_data[index ++] = finalfloat;
		    }
		}
	    }
	} 
      file.close();
      
      double max_sum_nested = nested_loop(input_data, index);
      int start_time = clock();
      double max_sum_dnc = dnc(input_data, 0 ,index-1);
      int end_time = clock();
      cout << max_sum_dnc << "\t" << (end_time-start_time)/double (CLOCKS_PER_SEC) << "[sec]" << endl;
      return 0;
    }
  else
    {
      cerr << "Wrong number of arguments provided \n";  
      return -3;
    }
  //should never come here
}



