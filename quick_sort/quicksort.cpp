#include<iostream>
using namespace std;

void quick_sort(int (&arr)[100],int low,int high);
int quick(int (&arr)[100],int low,int high);
void swap(int *a,int *b);

void display(int (&arr)[100],int n);

int main()
{
label1:
	int arr[100],n;
	cout<<"Enter the number of elements or (-1) to exit. :"<<endl;
	cin>>n;
	if(n == -1)
	{
		goto label2;
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter element No. "<<i<<" : ";
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Which Sorting would you like to preffer : "<<endl;
	int choice;
	cout<<"1. Quick Sort."<<endl;
	cout<<"2. Exit."<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			quick_sort(arr,0,n-1);
			display(arr,n);
			break;
		case 2:
			goto label2;
			break;
		default:
			goto label1;
	}
	goto label1;
label2:
	cout<<"Thanks for using."<<endl;
}


void quick_sort(int (&arr)[100],int low,int high)
{
	if(low<high)
	{
		int position = quick(arr,low,high);
		quick_sort(arr,low,position-1);
		quick_sort(arr,position+1,high);
	}
}

int quick(int (&arr)[100],int low,int high)
{
	int pivot = arr[high];
	int i = low-1;

	for(int j = low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void display(int (&arr)[100],int n)
{
	cout<<"Sorted Array : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
