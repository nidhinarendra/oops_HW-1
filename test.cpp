#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <ctime>

using namespace std;

int nested_loop(double input_data[], int count_input)
{
  int start_time = clock();
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
		//cout << "Max sum is "<< max_sum <<endl;
	}
    }
int stop_time = clock();
cout << max_sum << "\t" << (stop_time-start_time)/double (CLOCKS_PER_SEC) << "[sec]" << endl;
 return 0;
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
		      //cout << finalfloat << "!!!! COUNT is " << index << endl;
		    }
		}
	    }
	} 
      file.close();
      
      double max_sum = nested_loop(input_data, index);
      //cout << max_sum << endl;    
      return 0;
    }
  else
    {
      cerr << "Wrong number of arguments provided \n";  
      return -3;
    }
  //should never come here
}
     

