#include "pch.h"
#include <iostream>

using namespace std;

const int n = 7;
int i, j;
bool *visitedH = new bool[n];

int graph[n][n] = // матрица смежности графа
{
{0, 1, 0, 0, 1, 0, 1},
{1, 0, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 1},
{0, 1, 0, 0, 1, 1, 1},
{1, 0, 1, 1, 0, 0, 0},
{1, 0, 1, 1, 0, 0, 0},
{1, 0, 1, 1, 0, 0, 0}
};

void FindH(int start) // поиск в глубину
{
	int r;
	cout << start + 1 << " ";
	visitedH[start] = true;
	for (r = 0; r <= n; r++)
		if ((graph[start][r] != 0) && (!visitedH[r]))
			FindH(r);
}

void FindW(bool *visitedW, int vertex) // поиск в ширину
{
	int *queue = new int[n];
	int count, head;
	for (i = 0; i < n; i++) queue[i] = 0;
	count = 0; head = 0;
	queue[count++] = vertex;
	visitedW[vertex] = true;
	while (head < count)
	{
		vertex = queue[head++];
		cout << vertex + 1 << " ";
		for (i = 0; i < n; i++)
			if (graph[vertex][i] && !visitedW[i])
			{
				queue[count++] = i;
				visitedW[i] = true;
			}
	}
	delete[]queue;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int start; // стартовая вершина
	bool *visitedW = new bool[n];
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < n; i++)
	{
		visitedH[i] = false;
		visitedW[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Введите стартовую вершину: ";
	cin >> start;
	cout << "Порядок обхода по глубине: ";
	FindH(start - 1);
	delete[]visitedH;
	cout << endl;
	cout << "Порядок обхода по ширине: ";
	FindW(visitedW, start - 1);
	delete[]visitedW;
	system("pause");
}