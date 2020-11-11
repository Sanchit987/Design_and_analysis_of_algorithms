#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
	int left_num = mid-low+1;
	int right_num = high-mid;
	int left[left_num],right[right_num];
	for(int i=0;i<left_num;i++)
        {
                left[i] = arr[low + i];
        }
	for(int i=0;i<right_num;i++)
        {
                right[i] = arr[mid + 1 + i];
        }
	int i=0,j=0,k=low;
	
	while(i<left_num && j<right_num)
	{
		if(left[i]<=right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<left_num)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<right_num)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}
int display(int arr[],int num){
	for(int i=0;i<num;i++)
        {
                cout<< arr[i] << " ";
        }
	cout<<endl;
	return 0;
}
void mergeSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid = low+(high-low)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	cout<<"Enter number of elements "<<endl;
	int num;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
	{
		cout<<"Enter Element At "<<i<<" Position"<<endl;
		cin>> arr[i];
	}
	cout<<"Array entered is "<<endl;
	display(arr,num);

	mergeSort(arr,0,num-1);

	cout<<"Sorted Array :"<<endl;
	display(arr,num);
}

