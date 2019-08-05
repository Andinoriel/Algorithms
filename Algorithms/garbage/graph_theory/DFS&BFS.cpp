// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <vector>
#include <functional>
#include <queue>

namespace DFSBFS
{
	std::vector<std::vector<unsigned short>> graph =
	{
	  { 0, 1, 1, 1, 0, 0, 0 },
	  { 1, 0, 0, 1, 1, 0, 0 },
	  { 1, 0, 0, 0, 0, 1, 1 },
	  { 1, 1, 0, 0, 1, 0, 0 },
	  { 0, 1, 0, 1, 0, 0, 0 },
	  { 0, 0, 1, 0, 0, 0, 1 },
	  { 0, 0, 1, 0, 0, 1, 0 }
	};
	std::vector<bool> visited;

	void depthFirstSearch()
	{
		visited.clear();
		visited.resize(graph.size());
		std::function<void(unsigned short)> dfs = [&](unsigned short vertex)
		{
			visited[vertex] = true;
			std::cout << "\nVertex #" << vertex << " visited!";
			for (size_t t = 0; t < graph.size(); ++t)
				if (!visited[t] && graph[vertex][t])
					dfs(static_cast<unsigned short>(t));
		};
		dfs(0);
	};
	void breadthFirstSearch()
	{
		visited.clear();
		visited.resize(graph.size());
		std::function<void(unsigned short)> bfs = [&](unsigned short vertex)
		{
			std::queue<unsigned short> queue;
			queue.push(vertex);
			visited[vertex] = true;
			while (!queue.empty())
			{
				vertex = queue.front();
				std::cout << "\nVertex #" << vertex << " visited!";
				queue.pop();
				for (size_t t = 0; t < graph.size(); ++t)
					if (!visited[t] && graph[vertex][t])
					{
						visited[t] = true;
						queue.push(static_cast<unsigned short>(t));
					}
			}
		};
		bfs(0);
	};

	int TEST()
	{
		std::cout << "\nDepth First Search:\n";
		depthFirstSearch();
		std::cout << "\n\n";
		std::cout << "\nBreadth First Search:\n";
		breadthFirstSearch();

		std::cin.get();
		return 0;
	}
};