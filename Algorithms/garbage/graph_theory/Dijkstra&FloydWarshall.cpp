#include <iostream>
#include <vector>
#include <functional>
#include <limits>

static const unsigned inf = std::numeric_limits<unsigned>::max();

std::vector<std::vector<unsigned>> graph = 
{
  { inf,	15,		7,		10,		inf,	inf,	inf },
  { 15,		inf,	inf,	4,		16,		inf,	inf },
  { 7,		inf,	inf,	inf,	inf,	10,		9 },
  { 10,		4,		inf,	inf,	3,		inf,	inf },
  { inf,	16,		inf,	3,		inf,	inf,	inf },
  { inf,	inf,	10,		inf,	inf,	inf,	5 },
  { inf,	inf,	9,		inf,	inf,	5,		inf }
};


void Dijkstra()
{
	std::function<void(unsigned)> djkstr = [&](unsigned origin)
	{
		std::vector<unsigned> minWays(graph.size());
		std::vector<char> visited(graph.size());
		for (size_t t = 0; t < graph.size(); ++t)
		{
			minWays[t] = graph[origin][t];
			visited[t] = false;
		}
		minWays[origin] = 0;

		size_t index = 0;
		for (size_t t = 0; t < graph.size(); ++t)
		{
			unsigned min = inf;
			for (size_t _t = 0; _t < graph.size(); ++_t)
				if (!visited[_t] && minWays[_t] < min)
				{
					min = minWays[_t];
					index = _t;
				}
			visited[index] = true;
			for (size_t _t = 0; _t < graph.size(); ++_t)
				if (!visited[_t] && graph[index][_t] != inf && minWays[index] != inf && (minWays[index] + graph[index][_t] < minWays[_t]))
					minWays[_t] = minWays[index] + graph[index][_t];
		}

		std::cout << "\nMinimal way's from #" << origin << " to other vertices:\n";
		for (size_t t = 0; t < graph.size(); ++t)
			if (minWays[t] != inf)
				std::cout << "\nFrom #" << origin << " to #" << t << ": " << minWays[t];
			else
				std::cout << "\nFrom #" << origin << " to #" << t << ": unaviable";
	};
	djkstr(0);
};
void FloydWarshall()
{
	std::function<void()> fw = [&]()
	{
		std::vector<std::vector<unsigned>> res(graph.size(), std::vector<unsigned>(graph.size()));
		for (size_t t = 0; t < graph.size(); ++t)
			for (size_t _t = 0; _t < graph.size(); ++_t)
				for (size_t __t = 0; __t < graph.size(); ++__t)
					if (graph[_t][t] < inf && graph[t][__t] < inf)
						if (graph[_t][t] + graph[t][__t] < graph[_t][__t])
							res[_t][__t] = graph[_t][t] + graph[t][__t];

		std::cout << "\nThe shortest graph paths:\n";
		for (size_t t = 0; t < graph.size(); ++t)
		{
			std::cout << "\nFrom #" << t;
			for (size_t _t = 0; _t < graph.size(); ++_t)
			{
				std::cout << "\n\tto #" << _t << " :" << res[t][_t];
			}
		}
	};
	fw();
};


int main()
{
	Dijkstra();
	std::cout << "\n\n";
	FloydWarshall();

	std::cin.get();
	return 0;
}