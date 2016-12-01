#include <stdio.h>
#include "circle.h"
#include "shape.h"
#include "color.h"

int Circle_s_numOfShapes = 10;
static struct Circle_VTbl tbl = {Circle_Scale_Dbl, Circle_DTOR, Circle_Draw, Circle_Area, Circle_GetColor_ptr};

void Circle_CTOR(struct Circle* _this)
{
	Shape_CTOR((struct Shape*)_this);	
	_this->m_radius = 3;
	Rectangle_CTOR_int_int(&(_this->m_boundingBox), 3 * 2, 3 * 2);

	printf("    [%d] Circle::CTOR(double) -> r:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 

	((struct Scaleable*)_this)->m_tbl = &tbl;
	((struct Shape*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
}

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
	Shape_Draw(((struct Shape*)_this)->m_me);/*FIXME use Vtbl here*/
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


