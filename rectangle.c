#include "rectangle.h"
#include "color.h"

static struct Rectangle_VTbl tbl = {Rectangle_Scale_Dbl, Rectangle_DTOR, Rectangle_Draw, Rectangle_Area};

void Rectangle_CTOR_int(struct Rectangle* _this, int a)
{
	Shape_CTOR((struct Shape*)_this);	
	_this->m_a = a;
	_this->m_b = a;
	 printf("    [%d] Rectangle::CTOR(int) -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
}

void Rectangle_CTOR_int_int(struct Rectangle* _this, int a, int b)
{
	Shape_CTOR((struct Shape*)_this);	
	_this->m_a = a;
	_this->m_b = b;
	 printf("    [%d] Rectangle::CTOR(int) -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	_this->m_tbl = &tbl;
}

double Rectangle_Area(struct Rectangle* _this)
{
	return _this->m_a * _this->m_b;
}

void Rectangle_Scale_Dbl(struct Rectangle* _this, double f)
{
	_this->m_a *= f;
	_this->m_b *= f;
}

void Rectangle_DTOR(struct Rectangle* _this)
{
	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	
	printf("    [%d] Rectangle::DTOR -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	Shape_DTOR((struct Shape*)_this);
}

void Rectangle_Draw(struct Rectangle* _this, enum ColorEnum c)
{
	printf("    [%d] Rectangle::Draw(%d) -> a:%d/%d\n",  ((struct Shape*)_this)->m_id, c, _this->m_a, _this->m_b);
}

