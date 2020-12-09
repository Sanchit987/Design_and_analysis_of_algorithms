#include<iostream>
using namespace std;

void display(int arr[50][50],int num)
{
	for(int i=0;i<num;i++)
        {
                for(int j=0;j<num;j++)
                {
                        cout<<arr[i][j]<<" ";
                }
		cout<<endl;
        }
	return ;
}

int main(){
	cout<<"Floyd Warshall."<<endl;
	cout<<"Enter the number of vertices of the graph: "<<endl;
	int num;
	cin>>num;
	int arr[50][50];
	int weight[num];
	for(int i=0;i<num;i++)
	{
		weight[i] == 999;
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			arr[i][j] == 999;
		}
	}
	cout<<"How many edges do you want : "<<endl;
	int edg;
	cin>>edg;
	for(int i=0;i<edg;i++)
	{
		cout<<"Enter start vertex,destination vertex,distance between them as u v d : "<<endl;
		int u,v,d;
		cin>>u>>v>>d;
		arr[u][v] = d;
	}
	int wei;
	cout<<"The weight of starting vertex i.e 0 is : "<<endl;
	cin>>wei;
	weight[0] = wei;
	int u,v,d;
	for(int move = 0;move<num-1;move++)
	{
	for(int i=0;i<num;i++)
        {
                for(int j=0;j<num;j++)
                {
                        u = i,v=j,d=arr[i][j];
			if(weight[u]+d < weight[v] and arr[i][j] != 999 and weight[u] != 999)
			{
				weight[v] = weight[u]+d;
			}
			else 
			{
				continue;
			}
                }
                cout<<endl;
        }
	}

	display(arr,num);
	cout<<endl;
	for(int i=0;i<num;i++)
        {
                cout<<weight[i]<<" ";
        }
	cout<<endl;
}
