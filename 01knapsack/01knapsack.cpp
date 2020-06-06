#include<iostream>
#include<algorithm>

#define MAX 10
using namespace std;

class knapsack
{
	private:
		int obj_num;
		int weight[MAX];
		int value[MAX];
		int capacity;
		int table[MAX][MAX];
		int total_profit;
		int sub_set[MAX];
	public:
		knapsack();
		void getKnapSackDetails();
		void calProfit();
		void findSubSet();
		void printFunction();
};

knapsack::knapsack()
{
	int i;
	total_profit=0;
	for(i=1;i<=obj_num;i++)
		sub_set[i]=0;
}

void knapsack::getKnapSackDetails()
{
	cout<<"How many object are there?"<<endl;
	cin>>obj_num;
	
	cout<<"Provide the weight of each corresponding object"<<endl;
	for(int i=1;i<=obj_num;i++)
	{
		cout<<"weight "<<i<<":";
		cin>>weight[i];
	}
		
	cout<<"Provide the value or amount of each corresponding object"<<endl;
	for(int i=1;i<=obj_num;i++)
	{	
		cout<<"value "<<i<<":";
		cin>>value[i];
	}
		
		
	cout<<"What is the total Capacity of Knapsack?"<<endl;
	cin>>capacity;
	
}

void knapsack::calProfit()
{
	int i,j;
	for(i=0;i<=obj_num;i++)
		table[i][0]=0;
	for(j=0;j<=capacity;j++)
		table[0][j]=0;
	for(i=1;i<=obj_num;i++)
	{
		for(j=1;j<=capacity;j++)
		{
			if(j-weight[i]>=0)
			{
				table[i][j]=max(table[i-1][j],table[i-1][j-weight[i]]+value[i]);
			}
			else
			{
				table[i][j]=table[i-1][j];
			}
		}
	}
}

void knapsack::findSubSet()
{
	int i,j;
	i=obj_num;
	j=capacity;
	while(i>=1 && j>=1)
	{
		if(table[i][j]!=table[i-1][j])
		{
			sub_set[i]=1;
			j=j-weight[i];
		}
		i--;
	}
}

void knapsack::printFunction()
{
	int i,j;
	cout<<"Table of knapsack is:"<<endl;
	for(i=0;i<=obj_num;i++)
	{
		for(j=0;j<=capacity;j++)
		{
			cout<<table[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<endl;
	
	total_profit=table[obj_num][capacity];
	cout<<"Total profit is:"<<endl<<total_profit<<endl;
	
	cout<<"object Selected are:"<<endl;
	for(i=1;i<=obj_num;i++)
	{
		if(sub_set[i]==1)
			cout<<i<<"	";
	}
	cout<<endl;
}

int main()
{	
	knapsack obj;
	obj.getKnapSackDetails();
	obj.calProfit();
	obj.findSubSet();
	obj.printFunction();
	return 0;
}
