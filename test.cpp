#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

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
		     cout << finalfloat << endl;
		   }
	       }
	   }
       }     
     file.close();
     return 0;
   }
 else
   {
     cout << "Wrong number of arguments provided \n";
     return -3;
   }
 //should never come here
}
     

