#include <stdio.h>
#include "shape.h"
#include "scaleable.h"
#include "color.h"
#include <stdlib.h>

int Shape_s_numOfShapes = 0;
static struct Shape_VTbl tbl = {Shape_Scale_Dbl, Shape_DTOR, Shape_Draw, Shape_Draw_Color, Shape_Area};

void Shape_CTOR(struct Shape* _this)
{
	Scaleable_CTOR((struct Scaleable*)_this);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	++Shape_s_numOfShapes;	
	_this->m_id = Shape_s_numOfShapes;
	_this->m_me = _this;
	printf("    [%d] Shape::CTOR\n", _this->m_id);
	_this->m_tbl->Draw_Color_ptr(_this, Color_RED);
}

void Shape_cpy_CTOR(struct Shape* _this, const struct Shape* _other)
{
	Scaleable_CTOR((struct Scaleable*)_this);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	++Shape_s_numOfShapes;
	_this->m_id = Shape_s_numOfShapes;
	_this->m_me = _this;
	printf("    [%d] Shape::CCTOR from [%d]\n", _this->m_id, _other->m_id);
	_this->m_tbl->Draw_ptr(_this);
}

void Shape_DTOR(struct Shape* _this)
{
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
	
	_this->m_tbl->Draw_ptr(_this->m_me);
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

void Shape_Draw_Color(struct Shape* _this, enum ColorEnum c) 
{
	Color_SetColor(c);
	printf("    [%d] Shape::Draw(Color)\n", _this->m_id);
	_this->m_tbl->Draw_ptr(_this);
	Color_SetColor(Color_DEFAULT);
}

struct Shape* Shape_New_Operator()
{
	struct Shape* s = malloc(sizeof(struct Shape));
	if(s)
	{
		Shape_Operator_New(s);
	}
	return s;
}


struct Shape* Shape_New_Operator_Cpy(const struct Shape* _other)
{
	struct Shape* s = malloc(sizeof(struct Shape));
	if(s)
	{
		Shape_Operator_New_Cpy(s, _other);
	}
	return s;
}

struct Shape* Shape_New_Operator_Arr(size_t _size)
{
	size_t* s = malloc(sizeof(struct Shape) * _size + sizeof(_size));
	if(s)
	{
		*s = _size;
		Shape_Operator_New_Arr((struct Shape*)++s, _size);
	}
	return s;
}

void Shape_Operator_New(struct Shape* _this)
{
	Shape_CTOR(_this);
}

void Shape_Operator_New_Cpy(struct Shape* _this, const struct Shape* _other)
{
	Shape_cpy_CTOR(_this, _other);
}

void Shape_Operator_New_Arr(struct Shape* _this, size_t _size)
{
	struct Shape* end = _this + _size;
	while(_this != end)
	{
		Shape_CTOR(_this++);
	}
}
	
void Shape_Delete(struct Shape* _this)
{
	if(_this)
	{
		Shape_DTOR(_this);
		free(_this);	
	}
}

void Shape_Delete_Arr(struct Shape* _this)
{
	struct Shape* _orr  = _this;	
	size_t* beg = (size_t*)_this;	
	struct Shape* end;
	if(_this)
	{
		--beg;
		end = _this + *beg;
		while(_this != end)
		{
			Shape_DTOR(_this++);
		}
		free(_orr);	
	}
}






























