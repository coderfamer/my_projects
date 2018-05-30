#ifndef __MAINTANK_H__ 
#define	__MAINTANK_H__

#include "tank.h"

class MainTank : public Tank
{
public:
	MainTank();
	~MainTank();

	void set_dir(Dir dir);
	void display();
	void move();

protected:
	void calculate_sphere();

	void draw_tank_body( );
};
#endif