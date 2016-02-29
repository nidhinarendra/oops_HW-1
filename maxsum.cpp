#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>


using namespace std;
/*int main()
{
	ifstream file;
	file.open("max_sum data.txt");
	if (!file.is_open())
	{
	 cerr << "INVALID FILE" <<endl;
	}

	else
	{
	  char contents[1000];
	  //file >>contents;
	  while(file >> contents)
		{
		
		int arr_elements[1000];
		for (int m=0; m<=
		
		//cout <<"\n";
		}
	}

return(0);
}

*/

void subset_array(int inputarr[], int i, int j, int localarr[])
{
  for (int k=i, p=0; k<j; k++,p++)
    localarr[p] = inputarr[k];
}

int main()
{  
  int num;
  int sum = INT_MIN, max = INT_MIN;   
    cout<<"enter the number of values of array\n";
    cin>>num;
    cout<<"enter the values present in array\n";

    int inputarr[num];
    for (int i = 0; i < num; i++)
    {
	cin >> inputarr[i];
    }
    
    for (int i = 0; i<num; i++)
      for (int j=1; j < num; j++)
	{
	  if((i+j) < num)
	  {
	    //int temp[j-i]; 
	    //subset_array(inputarr, i, j, temp);
	    sum = 0; 
	    for (int k = i; k < (j-i); k ++)
	    {
	      sum = sum + inputarr[k];
	      cout << "sum:" << sum << " max:"<< max<< "inputatt:"<< 
		inputarr[k]<< "k:"<< k  <<"\n";
	    }
	    max = (max < sum) ? sum : max; 
	  }
	  else
	    continue;
	      
	 }

cout << "the max is " << max;
return 0;
}

	













