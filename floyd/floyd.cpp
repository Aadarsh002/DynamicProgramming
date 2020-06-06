#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;
//all pair shortest path algorithm
class floyd
{
	private:
		int vertices;
	public:
		int cost[MAX][MAX];
		void getdata();
		void calpath();
		void printpathcost(); 
};

void floyd::getdata()
{
	cout<<"Enter the number of vertices: ";
	cin>>vertices;
	
	int i,j;
	cout<<"enter the adjacency matrix:"<<endl;
	for(i=0;i<vertices;i++)
		for(j=0;j<vertices;j++)
			cin>>cost[i][j];
}

void floyd::calpath()
{
	int i,j,k;
	for(k=0;k<vertices;k++)
	{
		for(i=0;i<vertices;i++)
		{
			for(j=0;j<vertices;j++)
			{
				cost[i][j]=min(cost[i][j],(cost[i][k]+cost[k][j]));
			}
		}
	}
}

void floyd::printpathcost()
{
	int i,j;
	cout<<"All pair shortest path are:"<<endl;
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			cout<<cost[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	floyd f1;
	f1.getdata();
	f1.calpath();
	f1.printpathcost();
	return 0;
}
