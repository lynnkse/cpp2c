#ifndef __Scaleable__
#define __Scaleable__

#include <stdio.h>

struct Scaleable
{
	struct Scaleable_VTbl* m_tbl;
};

struct Scaleable_VTbl
{
	void(*Scale_Dbl_ptr)(struct Scaleable*, double f);
};

void Scaleable_CTOR(struct Scaleable* _this);

void Scaleable_DTOR(struct Scaleable* _this);

void Scaleable_Scale_SclblDbl(struct Scaleable*, double f);

#endif
