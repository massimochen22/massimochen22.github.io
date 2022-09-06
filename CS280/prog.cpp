#include <iostream>
using namespace std;

bool recLinearSearch ( const int a[ ],  int   low, int   high, int   key){
    if(a[low]==key || a[high]==key){
        return true;
    }
    else{
        if(high-1>low){
            return recLinearSearch (a,low, high-1,key);
        }

        return false;
    }
}

int main()
{
	int myArray[] = { 125, 23, 300, 54, 75, 49, 36, 17};
	int keys1[] = {125, 17, 25 };
	int keys2[] = {300, 36, 70 };
	int low, high;
	bool flag;
	
	low = 0; high = 7; 
	for(int i = 0; i < 3 ; i++)
	{
		flag = recLinearSearch(myArray, low, high, keys1[i]);
		if (flag)
			cout << "The key value " << keys1[i] << " is found in the specified range " << low << "-" << high << endl;
		else
			cout << "The key value " << keys1[i] << " is not found in the specified range " << low << "-" << high << endl;
	}
	
	
	low = 2; high = 6; 
	for(int i = 0; i < 3 ; i++)
	{
		flag = recLinearSearch(myArray, low, high, keys2[i]);
		if (flag)
			cout << "The key value " << keys2[i] << " is found in the specified range " << low << "-" << high << endl;
		else
			cout << "The key value " << keys2[i] << " is not found in the specified range " << low << "-" << high << endl;
	}
	
	return 0;
}

