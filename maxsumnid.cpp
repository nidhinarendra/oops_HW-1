#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

/*

int main()
{
	ifstream file;
	int inputarr[100];
	file.open ( "max_sum data.txt");
	int x;
	//char cNum[10];
	
	/*file.open ("max_sum data.txt" , ifstream::in);
	if (file.is_open())
	{
		while (file.good())
		{
		cout << "file opened";
		file.getline (cNum, 256, ',');
		inputarr[x] = atoi(cNum);
		x++;
		}
	file.close();
	}
	else
	{
	cerr << "INVALID FILE" <<endl;
	}
return 0;
}
*/
/*	if (!file.is_open())
	{
	 cerr << "INVALID FILE" <<endl;
	}

	else
	{
	cout << "File opened successfully \n";
	char contents[1000];

		while(file >> contents)
	    	{
		char *endptr[1];
		strtol(contents, endptr, 0);
		if (*endptr == contents)
		continue;
		else
		{
	        int num = std::stoi( contents);
	        //cout << contents << "\n";
		cout << num << "\t"<< contents << "\n";
		}
      //cout << contents << "\t" << numb <<"\n";                                                                     
		}
	}

}


*/


/*string contents;
	  char c[] = ",";
	  int i = 0;
	  while(file >> contents)
		{
		  contents.erase(std::remove(contents.begin(),`contents.end(), ',' ).contents.end());
		  inputarr[i++] =  atoi(contents);
		  cout <<contents <<"\n";
		}
	}

return(0);
}

*/


int main()
{
  int arr[100], sum = 0, max = INT_MIN, num, index;
  cout << "enter the number of values\n";
  cin >> num;
  cout << "enter the numbers\n";
  
  for(int m = 0; m< num; m++)
    {
      cin >> arr[m];
    }
  
  for (int index = 0; index <num ; index++)
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


/*
for (int sub_array = 1; sub_array < num; sub_array++)
  {
    cout << "array size " << sub_array<<endl;
    for (index = 0; index < num; index++)
      {
	if((sub_array+index) > num)
	  break;

	sum =0;
	for(int i = index; i <= (index+sub_array); i++)
	  {
	    cout << "i is " << i <<endl;
	    sum = sum+ arr[i];
	    cout << "sum is " << sum << endl;
	    if(max <sum)
	      {
		max = sum;
	      }
	  }
      }
  }
 
cout << "max is " << max;
return 0;
} 
*/







