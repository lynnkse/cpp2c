#include <stdio.h>
#include "shape.h"
#include "scaleable.h"
#include "color.h"

int Shape_s_numOfShapes = 0;
static struct Shape_VTbl tbl = {Shape_Scale_Dbl, Shape_DTOR, Shape_Draw, Shape_Area};

void Shape_CTOR(struct Shape* _this)
{
	Scaleable_CTOR((struct Scaleable*)_this);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	++Shape_s_numOfShapes;	
	_this->m_id = Shape_s_numOfShapes;
	_this->m_me = _this;
	printf("    [%d] Shape::CTOR\n", _this->m_id);
	Shape_Draw(_this);
}

void Shape_DTOR(struct Shape* _this)
{
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	
	Shape_Draw(_this->m_me);/*FIXME use Vtbl here*/
	printf("    [%d] Shape::DTOR\n", _this->m_id);
	--Shape_s_numOfShapes; 
	Scaleable_DTOR((struct Scaleable*)_this);
}

void Shape_Draw(struct Shape* _this)
{
	printf("    [%d] Shape::Draw()\n", _this->m_id);
}

void Shape_Scale_Dbl(struct Shape* _this, double x)
{
	printf("    [%d] Shape::Scale(double)\n", _this->m_id);
}

void Shape_PrintInventory()
{
	printf("Shape::printInventory - %d\n", Shape_s_numOfShapes);
}

struct Shape* Shape_Operator_Assn(struct Shape* _this, const struct Shape* _other)
{}

double Shape_Area(struct Shape* _this)
{
	return 0;
}

