#include<iostream>
#define MAX 10
using namespace std;
//trasitive closure of a graph
class warshall
{
	int vertices;
	int graph[MAX][MAX];
	public:
		void getGraph()
		{
			int i,j;
			cout<<"How Many Vertices Does The Graph contains?"<<endl;
			cin>>vertices;
			
			cout<<"Enter the Adjacency Matrix of graph:"<<endl;
			for(i=0;i<vertices;i++)
			{
				for(j=0;j<vertices;j++)
				{
					cin>>graph[i][j];
				}
			}
		}
		
		void findTransitiveClosure()
		{
			int i,j,k;
			for(k=0;k<vertices;k++)
			{
				for(i=0;i<vertices;i++)
				{
					for(j=0;j<vertices;j++)
					{
						if(graph[i][j] || (graph[i][k] && graph[k][j]))
							graph[i][j]=1;
					}
				}
			}
		}
		
		void printTransitiveClosureMatrix()
		{
			int i,j;
			cout<<"transitive closure matrix is:"<<endl;
			for(i=0;i<vertices;i++)
			{
				for(j=0;j<vertices;j++)
				{
					cout<<graph[i][j]<<"	";
				}
				cout<<endl;
			}
			cout<<endl;
		}
};

int main()
{
	warshall w1;
	w1.getGraph();
	w1.findTransitiveClosure();
	w1.printTransitiveClosureMatrix();
	return 0;
}
