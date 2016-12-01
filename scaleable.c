#include"scaleable.h"

static struct Scaleable_VTbl tbl = {Scaleable_Scale_SclblDbl};

void Scaleable_Scale_SclblDbl(struct Scaleable* _this, double f){}

void Scaleable_CTOR(struct Scaleable* _this)
{
	_this->m_tbl = &tbl;
}

void Scaleable_DTOR(struct Scaleable* _this)
{
	_this->m_tbl = &tbl;	
	puts("~Scaleable");
}
