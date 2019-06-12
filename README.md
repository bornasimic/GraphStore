# GraphStore

GraphStore implements the functions required in the test project. 


## Usage

The class is implemented in a separate header and .cpp file. Vertices of the graph are nonnegative integers, and the labels are STL strings. If a shortest path does not exist, an empty vector is returned. For example, this snippet
```C++
#include <bits/stdc++.h>
#include "...\GraphStore.hpp"

using namespace std;

int main()
{

	GraphStore store;
	for (int i = 0; i < 7; i++) store.CreateVertex();
	
	store.CreateEdge(0, 1);
	store.CreateEdge(0, 2);
	store.CreateEdge(1, 6);
	store.CreateEdge(2, 3);
	store.CreateEdge(2, 5);
	store.CreateEdge(3, 4);
	store.CreateEdge(5, 3);
	store.CreateEdge(5, 6);
	
	store.AddLabel(0, "m");
	store.AddLabel(0, "u");
	store.AddLabel(1, "u");
	store.AddLabel(2, "m");

	//multiple copies of labels are supported
	
	store.AddLabel(2, "m");
	store.RemoveLabel(2, "m");	
	
	store.AddLabel(2, "k");
	store.AddLabel(3, "k");
	store.AddLabel(4, "u");
	store.AddLabel(5, "m");
	store.AddLabel(6, "m");
	store.AddLabel(6, "u");
	
	for (int i : store.ShortestPath(0,6,"m")) cout << i << ' ';
	cout << '\n';
	
	for (int i : store.ShortestPath(0,6,"u")) cout << i << ' ';
	cout << '\n';
	
	//paths between vertices contain their endpoints, and single-vertex paths are considered
	
	for (int i : store.ShortestPath(2,2,"k")) cout << i << ' ';
	cout << '\n';
		
	for (int i : store.ShortestPath(2,2,"h")) cout << i << ' ';
	cout << '\n';
	
	for (int i : store.ShortestPath(2,3,"k")) cout << i << ' ';
	cout << '\n';
	
	for (int i : store.ShortestPath(2,4,"k")) cout << i << ' ';
	cout << '\n';
	return 0;
}
```
will result in
``` Bash
0 2 5 6
0 1 6
2

2 3

```