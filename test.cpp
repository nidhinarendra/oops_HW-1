#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
double i;
int a=0;
double input_data[100];
double number;
string stream1;
string stream2;
	if (argc <= 2) 
	{
	ifstream file;
	file.open(argv[1]);
		while(!file.eof()){
			file >> stream1;
			stringstream ss(stream1);
			while ( getline (ss, stream1, ',')){
				stringstream ss(stream1);
				ss >> i;
				
				if ( !ss ) { cerr << "INVALID INPUT" <<endl;
						return -1;}
				else {
				for (a=0; a<100;a++)
				{
				if (file.eof()) break;				
				input_data[a] = i;
				cout << i << endl;}
				}
			}
		
		}
file.close();
	}
	else
	{
	cerr << "invalid input" <<endl;
	}
return 0;
}


