
#include "Graph.h"



Graph::Graph()
{
	
}


Graph::~Graph()
{
	
}

bool Graph::init()
{
	rectangle(10, 10, 600, 400);
	for (int i = 10; i < 600; i+=10)
	{
		for (int j = 10; j < 400; j+=10)
			circle(i + 5, j+5, 5);
	}

	return true;
}
