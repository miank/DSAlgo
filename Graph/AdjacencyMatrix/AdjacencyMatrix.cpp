// AdjacencyMatrix.cpp : Creating adjacency matrix
//

#include "stdafx.h"
#include <iostream>
#define MAX 100;
using namespace std;

int main()
{
	int adj[100][100]; //Adjacency Matrix
	int n(0); // number of vertices 
	int max_edges, i, j, origin, destin;
	int graph_type;
	cout << "Enter 1 for undirected graph or 2 for directed graph " << endl;
	cin >> graph_type;
	cout << "Enter the number of vertices " << endl;
	cin >> n;
	if (graph_type == 1)
		max_edges = n * (n - 1) / 2;
	else
		max_edges = n * (n - 1);

	for (int i = 1; i <= max_edges; i++)
	{
		cout << "Enter edge -1 -1 to quit " << i << endl;
		cin >> origin >> destin;
		if ((origin == -1) && (destin == -1))
			break;
		if ((origin >= n || destin >= n) || origin < 0 || destin < 0)
		{
			cout << "Invalid vertex " << endl;
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			if (graph_type == 1) // If undirected graph
				adj[destin][origin] = 1;
		}
	}
	cout << "The adjacency matrix is : " << endl;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			cout << adj[i][j] << " \t";
		}
		cout << endl;
	}
    return 0;
}

