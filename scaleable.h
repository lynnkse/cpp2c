#ifndef __Scaleable__
#define __Scaleable__

#include <stdio.h>
/*
class Scaleable 
{
public:
	~Scaleable();

	virtual void Scale(double f = 2.0) = 0;
};

inline Scaleable::~Scaleable()
{
	puts("~Scaleable");
}
*/

struct Scaleable
{};

void Scaleable_CTOR(struct Scaleable* _this);

void Scaleable_DTOR(struct Scaleable* _this);

/*void Scale(struct Scalable* _this, double f = 2.0);*/

#endif
