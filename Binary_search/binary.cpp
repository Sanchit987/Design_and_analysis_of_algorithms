#include<iostream>
using namespace std;

int BinarySearch(int x,int low,int high,int arr[]){
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if (arr[mid] == x)
     			return mid;
		if (arr[mid] < x)
      			low = mid + 1;
		else
      			high = mid - 1;
	}
	return -1;
}

int main() {
	cout<<"Enter Number of Elements"<<endl;
	int num;
	cin>> num;

	int arr[num];
	for(int i=0;i<num;i++)
	{
		cout<<"Enter Element At "<<i<<" Position"<<endl;
		cin>> arr[i];
	}
	cout<<"Enter Element To Be Searched"<<endl;
	int ele;
	cin>>ele;
	
	int res = BinarySearch(ele,0,num-1,arr); 
	if(res == -1)
	{
		cout<<"Not Found."<<endl;
	}
	else
	{
		cout<<"Present at " << res <<endl;
	}

	return 0;
}
