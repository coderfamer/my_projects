#pragma once
#include "public.h"
struct Srect
{
	unsigned short x;
	unsigned short y;
};

class Snake
{
public:
	Snake();
	~Snake();

private:
	vector<Srect> m_vnode;
};

