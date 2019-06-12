#ifndef GRAPHSTORE_hpp
#define GRAPHSTORE_hpp

class GraphStore
{
	private:
		std::vector< std::vector<int> > adjacent_vertices;
		std::vector< std::unordered_multiset<std::string> > vertex_labels;
		
	public:
		void CreateVertex();
		void CreateEdge(int a, int b);
		void AddLabel(int a, std::string s);
		void RemoveLabel(int a, std::string s);
		std::vector<int> ShortestPath(int a, int b, std::string s);
};

#endif

