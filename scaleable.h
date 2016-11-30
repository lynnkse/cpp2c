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
{
	struct Scaleable_VTbl* m_tbl;
};

struct Scaleable_VTbl
{
	void(*Scale_ptr)(struct Scaleable*);
	void(*Scale_Dbl_ptr)(struct Scaleable*, double f);
};

void Scaleable_CTOR(struct Scaleable* _this);

void Scaleable_DTOR(struct Scaleable* _this);

void Scaleable_Scale_Sclbl(struct Scaleable*);
void Scaleable_Scale_SclblDbl(struct Scaleable*, double f);

#endif
