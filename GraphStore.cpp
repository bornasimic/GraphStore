#include <bits/stdc++.h>
#include "GraphStore.hpp"

void GraphStore::CreateVertex()
{
	adjacent_vertices.push_back(std::vector<int>());
	vertex_labels.push_back(std::unordered_multiset<std::string>());
}

void GraphStore::CreateEdge(int a, int b)
{
	adjacent_vertices[a].push_back(b);
}

void GraphStore::AddLabel(int a, std::string s)
{
	vertex_labels[a].insert(s);
}

void GraphStore::RemoveLabel(int a, std::string s)
{
	vertex_labels[a].erase(vertex_labels[a].find(s));	
}

std::vector<int> GraphStore::ShortestPath(int a, int b, std::string s)
{
	if (vertex_labels[a].find(s) != vertex_labels[a].end())
	{	
		bool visited[adjacent_vertices.size()] = {0};
		int parent[adjacent_vertices.size()];
		for (int vertex = 0; vertex < adjacent_vertices.size(); vertex++) parent[vertex] = -1;
		std::queue<int> BFS_ordering;
		BFS_ordering.push(a);
		visited[a] = 1;
		parent[a] = a;
		while (BFS_ordering.size())
		{
			bool found = 0;
			int current_vertex = BFS_ordering.front();
			BFS_ordering.pop();
			for (int next_vertex : adjacent_vertices[current_vertex])
			{
				if (!visited[next_vertex] and (vertex_labels[next_vertex].find(s) != vertex_labels[next_vertex].end()))
				{
					visited[next_vertex] = 1;
					parent[next_vertex] = current_vertex;
					BFS_ordering.push(next_vertex);	
				}	
				if (next_vertex == b)
				{
					found = 1;
					break;	
				}
			}
			if (found) break;
		}
		if (parent[b] != -1)
		{
			std::vector<int> path = {b};
			int vertex = b;
			while (vertex != a)
			{
				vertex = parent[vertex];
				path.push_back(vertex);
			}
			std::reverse(path.begin(), path.end());
			return path;
		}
		else return std::vector<int>();
	}
	else return std::vector<int>();
}	
