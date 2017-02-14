// BFSUsingQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n; // no of vertices
int adj[MAX][MAX]; // Adjacency Matrix
int state[MAX]; // can be initial waiting visited
void create_graph();
void BF_Traversal();
void BFS(int v);
int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_Queue();

int main()
{
	create_graph();
	BF_Traversal();
    return 0;
}

void create_graph()
{
	int i, max_edges, origin, destin;
	cout << "Enter the no of edges " << endl;
	cin >> n;
	for (int i = 1; i < max_edges; i++)
	{
		cout << "Enter -1 -1 to quit " << endl;
		cin >> origin >> destin;
		
		if ((origin == -1) && (destin == -1))
			break;
		if (origin >= n || destin >= -1 || origin < 0 || destin < 0)
		{
			cout << "In valid edge " << endl;
			i--;
		}
		else
			adj[origin][destin] = 1;
	}
}

void BF_Traversal()
{
	int v;
	for (v = 0; v < n; v++)
	{
		state[v] = initial;
	}
	cout << "Enter the starting vertex for BFS " << endl;
	cin >> v;
	BFS(v);
}

void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v] = waiting;
	while (!isEmpty_Queue())
	{
		v = delete_queue();
		cout << v << endl;
		state[v] = visited;
		for (i = 0; i < n; i++)
		{
			if (adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	cout << endl;
}

void insert_queue(int vertex)
{
	if (rear == MAX - 1)
		cout << "Queue Overflow " << endl;
	else
	{
		if (front == -1)
			front = 0;
		rear = rear + 1;
		queue[rear] = vertex;
	}
}

int isEmpty_Queue()
{
	if (front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		cout << "Queue Undeflow " << endl;
		exit(1);
	}
	del_item = queue[front];
	front = front + 1;
	return del_item;
}