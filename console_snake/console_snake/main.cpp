#include "public.h"
#include "graph.h"

int main()
{
	initgraph(640, 480);

	Graph graph;
	graph.init();

	

	system("pause");
	closegraph();
	
	return 0;
}