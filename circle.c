#include <stdio.h>
#include "circle.h"
#include "shape.h"
#include "color.h"
#include <stdlib.h>

int Circle_s_numOfShapes = 10;
static struct Circle_VTbl tbl = {Circle_Scale_Dbl, Circle_DTOR, Circle_Draw, Shape_Draw_Color, Circle_Area, Circle_GetColor_ptr};

void Circle_Dbl_CTOR(struct Circle* _this, double r)
{
	Shape_CTOR((struct Shape*)_this);	
	_this->m_radius = r;
	Rectangle_CTOR_int_int(&(_this->m_boundingBox), r * 2, r * 2);
	printf("    [%d] Circle::CTOR(double) -> r:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 

	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;	
}

void Circle_DTOR(struct Circle* _this)
{
	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 
	_this->m_tbl->Draw_ptr(_this);	
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 	
		
	Shape_DTOR((struct Shape*)_this);
}

void Circle_Scale_Dbl(struct Circle* _this, double x)
{
	_this->m_radius *= x;
	Rectangle_Scale_Dbl(&(_this->m_boundingBox), x/2);
}

double Circle_Area(struct Circle* _this)
{ 
	return _this->m_radius * _this->m_radius * 3.1415;
}

void Circle_Draw(struct Circle* _this)
{
	printf("    [%d] Circle::Draw() -> m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius);
}

void Circle_PrintInventory()
{
	printf("Shape::printInventory - %d\n", Circle_s_numOfShapes);
}

enum ColorEnum Circle_GetColor_ptr(struct Circle* _this)
{
	return Color_DEFAULT;
}

struct Rectangle Circle_OperatorRect(struct Circle* _this)
{
	return _this->m_boundingBox;
}

struct Circle* Circle_New_Operator_Dbl(double _r)
{
	struct Circle* c = malloc(sizeof(struct Circle) + sizeof(size_t));
	if(c)
	{
		Circle_Operator_New_Dbl(c, _r);
	}
	return c;
}

struct Circle* Circle_New_Operator_Dbl_Arr(double _r, size_t _size)
{
	size_t* s = malloc(sizeof(struct Circle) * _size + sizeof(size_t));
	if(s)
	{
		*s = _size;		
		Circle_Operator_New_Dbl_Arr((struct Circle*)++s, _r, _size);
	}
	return s;
}

void Circle_Operator_New_Dbl(struct Circle* _this, double _r)
{
	Circle_Dbl_CTOR(_this, _r);
}

void Circle_Operator_New_Dbl_Arr(struct Circle* _this, double _r, size_t _size)
{
	struct Circle* end = _this + _size;
	while(_this != end)
	{
		Circle_Dbl_CTOR(_this, _r);
		++_this;
	}
}

void Circle_Operator_Delete(struct Circle* _this)
{
	if(_this)
	{
		Circle_DTOR(_this);
		free(_this);
	}
}

void Circle_Operator_Delete_Arr(struct Circle* _this)
{
	struct Circle* end;
	struct Circle* orr = _this;
	size_t* beg = (size_t*)_this;
	if(_this)
	{
		--beg;		
		end = _this + *beg;
		while(_this != end)
		{
			Circle_DTOR(_this++);
		}
		free(orr);
	}
}











































