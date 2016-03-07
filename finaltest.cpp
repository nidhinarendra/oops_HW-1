#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

using namespace std;
double* input_data = NULL; // Globally avaiable data and dynamically grows
	
void print_arr(double* arr, int len)
{
  for (int i=0; i <len ; i++)
    cout << arr[i] << " ";

  cout << "totall array count is" << len << "\n";
}

void file_open (char *argv1, int *p_index)
{
  double finalfloat;
  int index=0;
  int length = 10000;
  
  double* input_data_old;
  string stream1;
  string stream2;
  ifstream file;
  file.open(argv1);

  input_data = new double [length];
  if(!file.is_open())
    {
      cerr << "File not found" <<endl;
      return;
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
		  return;
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
		      memcpy((char*)input_data, (const char*)input_data_old,
			     (sizeof(double) * length));
		    }
		  input_data[index ++] = finalfloat;
		}
	      } 
	}
    }
  file.close();
  // print_arr(input_data_old, length);
  // abort();
  if (index != 0)
    *p_index = index;
  else
    cerr << "Input data is not valid\n"; 
  
  return;
}
      
//Brute force method
int nested_loop(double input_data[], int count_input)
{
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
int max_middle_sum(double* input_data, int ref1,
		   int middle_point, int count)
{
  //Computation of the sum to the left side of the middle point.
  //int ref1 = 0; // reference point 2
  double suml = 0;
  double sum_left = INT_MIN;
  for (int i = middle_point; i >=ref1; i--)
    { 
      int temp = suml;
      suml = temp + input_data[i];
      if (suml > sum_left)
	{
	  sum_left = suml;	
	}
    }
  
  //Computation of the sum to the right side of the middle point.
  double sumr = 0;
  double sum_right = INT_MIN;
  for (int i = middle_point+1; i <=count; i++)
    {
      sumr = sumr + input_data[i];
      if(sumr > sum_right)
	{
	  sum_right = sumr;
	}
    }
  
  return sum_left+sum_right;
}


int divide_conquer (double* input_data, int ref1, int count)
{
  //cout << "rec-Number" << rec_times++ << "\n";
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
    int num_of_input_elems = -1;
    file_open(argv [1], &num_of_input_elems);

    if (input_data == NULL || num_of_input_elems == -1)
      return -100;

    int start_time_nested = clock();
    double max_sum1 = nested_loop(input_data, num_of_input_elems); //Calling Brute force function
    int end_time_nested = clock();
    cout << max_sum1 << "\t"<< (end_time_nested - start_time_nested)/double (CLOCKS_PER_SEC) << "[sec]"<<endl;

    int start_time_dnc = clock();
    double max_sum2 = divide_conquer(input_data, 0, num_of_input_elems - 1); //Calling divide and conquer function
    int end_time_dnc = clock();
    cout << max_sum2 << "\t"<< (end_time_dnc - start_time_dnc)/double (CLOCKS_PER_SEC) << "[sec]"<<endl;
  }
 else
   {
     cerr << "Wrong number of arguments provided \n";  
  return -1;
   }


}











