#include <stdio.h>
#include "shape.h"
#include "scaleable.h"
#include "color.h"

int Shape_s_numOfShapes = 0;
static struct Shape_VTbl tbl = {Shape_Scale, Shape_Scale_Dbl, Shape_DTOR, Shape_Draw, 0};

void Shape_CTOR(struct Shape* _this)
{
	Scaleable_CTOR((struct Scaleable*)_this);
	++Shape_s_numOfShapes;	
	_this->m_id = Shape_s_numOfShapes;
	_this->m_me = _this;
	printf("    [%d] Shape::CTOR\n", _this->m_id);
	Shape_Draw(_this);
	((struct Scaleable*)_this)->m_tbl = &tbl;
	_this->m_tbl = &tbl;
}

void Shape_DTOR(struct Shape* _this)
{
	Shape_Draw(_this->m_me);
	printf("    [%d] Shape::DTOR\n", _this->m_id);
	--Shape_s_numOfShapes; 
	Scaleable_DTOR((struct Scaleable*)_this);
}

void Shape_Draw(struct Shape* _this)
{
	printf("    [%d] Shape::Draw()\n", _this->m_id);
}

void Shape_Scale(struct Shape* _this)
{
	printf("    [%d] Shape::Scale(double)\n", _this->m_id);
}

void Shape_Scale_Dbl(struct Shape* _this, double x)
{
	printf("    [%d] Shape::Scale(double)\n", _this->m_id);
}

/*double Shape_Area(struct Shape* _this){}*/

void Shape_PrintInventory()
{
	printf("Shape::printInventory - %d\n", Shape_s_numOfShapes);
}

struct Shape* Shape_Operator_Assn(struct Shape* _this, const struct Shape* _other)
{}

/*
int Shape::Shape_s_numOfShapes = 0;

Shape::Shape()
	: m_id(++Shape_s_numOfShapes), m_me(this) 
{
	printf("    [%d] Shape::CTOR\n", m_id);
	Draw();
}

Shape::Shape(const Shape& other)
	: m_id(++Shape_s_numOfShapes), m_me(this) 
{
	printf("    [%d] Shape::CCTOR from [%d]\n", m_id, other.m_id);
	Draw();
}

Shape::~Shape() 
{
	m_me->Draw();
	printf("    [%d] Shape::DTOR\n", m_id);
	--Shape_s_numOfShapes; 
}

Shape& Shape::operator=(const Shape &_other)
{
}

void Shape::Draw() const 
{
	printf("    [%d] Shape::Draw()\n", m_id);
}

void Shape::Draw(Color::ColorEnum c) const {
	Color::SetColor(c);
	printf("    [%d] Shape::Draw(Color)\n", m_id);
	Draw();
	Color::SetColor(Color::DEFAULT);
}

void Shape::Scale(double x) 
{
	printf("    [%d] Shape::Scale(double)\n", m_id);
}

void Shape::PrintInventory() 
{
	printf("Shape::printInventory - %d\n", Shape_s_numOfShapes);
}*/

