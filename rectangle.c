#include "rectangle.h"

static struct Rectangle_VTbl tbl = {Rectangle_Scale, Rectangle_Scale_Dbl, Rectangle_DTOR, Shape_Draw/*TODO implement its own func*/, Rectangle_Area};

void Rectangle_CTOR(struct Rectangle* _this)
{	
	Shape_CTOR((struct Shape*)_this);	
	_this->m_a = 16;
	_this->m_b = 16;
	 printf("    [%d] Rectangle::CTOR(int) -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
}

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

void Rectangle_Scale(struct Rectangle* _this)
{
	_this->m_a *= 5;
	_this->m_b *= 5;
}

void Rectangle_Scale_Dbl(struct Rectangle* _this, double f)
{
	_this->m_a *= f;
	_this->m_b *= f;
}

void Rectangle_DTOR(struct Rectangle* _this)
{
	printf("    [%d] Rectangle::DTOR -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	Shape_DTOR((struct Shape*)_this);
	Scaleable_DTOR((struct Scaleable*)_this);
}
/*
Rectangle::Rectangle(int a)
	: m_a(a), m_b(a) 
{ 
	printf("    [%d] Rectangle::CTOR(int) -> a:%d/%d\n", m_id, m_a, m_b);
}

Rectangle::Rectangle(int a, int b)
	: m_a(a), m_b(b) 
{ 
	printf("    [%d] Rectangle::CTOR(int,int) -> a:%d/%d\n", m_id, m_a, m_b);
}

Rectangle::Rectangle(const Rectangle &other )
	: Shape(other),m_a(other.m_a), m_b(other.m_b) 
{ 
	printf("    [%d] Rectangle::CCTOR -> a:%d/%d\n", m_id, m_a, m_b);
}

Rectangle::~Rectangle() 
{ 
	printf("    [%d] Rectangle::DTOR -> a:%d/%d\n", m_id, m_a, m_b);
}

void Rectangle::Draw(Color::ColorEnum c) const 
{
	printf("    [%d] Rectangle::Draw(%d) -> a:%d/%d\n",  m_id, c, m_a, m_b);
}

double Rectangle::Area()
{
	return m_a * m_b;
}
*/
