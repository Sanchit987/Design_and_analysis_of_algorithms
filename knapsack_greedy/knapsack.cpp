#include<iostream>
using namespace std;

class knapsack {
	public:
		int weight, profit;
		float pbw;
		void input(int weight,int profit){
			this->weight = weight;
			this->profit = profit;
			pbw = probywe();
		}
		
		float probywe(){
			return float(profit)/float(weight);
		}

		void display(){
			cout<<"weight :"<< weight<<endl;
			cout<<"profit :"<< profit<<endl;
			cout<<"ratio :"<< pbw<<endl;
		}
};

		void display_pbw(knapsack arr[],int n)
                {
                        for(int i =0;i<n;i++)
                        {
                                cout<<arr[i].pbw<<" ";
                        }
                        cout<<endl;
                }
		void swap(knapsack* xp,knapsack* yp)
                {
                        knapsack temp = *xp;
                        *xp = *yp;
                        *yp = temp;
                }

                void sort(knapsack arr[],int n){
                        int i, j;
                        for (i = 0; i < n-1; i++)
                                for (j = 0; j < n-i-1; j++)
                                        if (arr[j].pbw > arr[j+1].pbw)
                                                swap(&arr[j], &arr[j+1]);
                }

int main(){
	cout<<"Enter Number of Elements to be entered :" <<endl;
	int num;
	cin>>num;
	cout<<"Enter Maximum knapsack Weight : "<<endl;
	int max_weight;
	cin>>max_weight;
	cout<<"Enter the weights and profits as : Weight Profit"<<endl;
	knapsack obj[num];
	for(int i=0;i<num;i++)
	{
		int w,p;
		cin>>w;
		cin>>p;
		cout<<endl;
		obj[i].input(w,p);
	}
	sort(obj,num);
	int i = num-1; 
	float profit = 0;
	while(max_weight != 0){
		if(max_weight <= 0)
		{
			break;
		}
		if(max_weight>0 && (max_weight - obj[i].weight) >=0 && i>0)
		{
			profit += obj[i].profit;
			max_weight -= obj[i].weight;
			i--;
		}
		else
		{
			if(max_weight>0 && (max_weight - obj[i].weight) <=0 && i>0)
			{
				profit += max_weight * obj[i].profit/obj[i].weight ;
                        	max_weight = 0;
                        	i--;
			}
			else
			{
				i--;
			}
		}
	}
	cout<<"Max profit is : "<<profit;
	cout<<endl;
	return 0;
}
