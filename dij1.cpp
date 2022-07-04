#include<iostream>
#include <conio.h>
#include<limits.h>
using namespace std;
int mindistance(int distance[], bool set[])
{
	int min= INT_MAX,idx;

	for(int i=0;i<6;i++)
	{
		if(set[i]==false && distance[i]<=min)
		{
			min=distance[i];
			idx=i;
		}
	}
	return idx;
}

void Dij(int graph[6][6],int src)
{
	int distance[6];
	bool set[6];

	for(int i = 0; i<6; i++)
	{
	    distance[i] = INT_MAX, set[i] = false;
	}

	distance[src] = 0;

	for(int i = 0; i<6; i++)
	{
		int m=mindistance(distance,set);
		set[m]=true;
		for(int i = 0; i<6; i++)
		{

			if(!set[i] && graph[m][i] && distance[m]!=INT_MAX && distance[m]+graph[m][i]<distance[i])
				distance[i]=distance[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tdistanceance"<<endl;
	for(int i = 0; i<6; i++)
	{
		char str=65+i;
		cout<<str<<"\t\t\t"<<distance[i]<<endl;
	}
}

int main()
{
	int graph[6][6]={
		{0, 1, 2, 1, 0, 0},
        {1, 0, 0, 4, 1, 0},
        {2, 0, 0, 5, 3, 0},
        {0, 5, 2, 3, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 1, 2, 1, 0}};
	Dij(graph,0);
	return 0;
}

