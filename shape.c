#include <stdio.h>
#include "shape.h"
#include "color.h"
#include "scaleable.h"

int s_numOfShapes = 0;

struct ShapeVtbl shapeVtbl = {
	ShapeScale,
	ShapeDTOR,
	ShapeDraw,
	ShapeDrawColor,
	ShapeArea
};

void ShapeCTOR(struct Shape* _this)
{
	/*MIL*/
	ScaleableCTOR((struct Scaleable*)_this);
	_this->m_id = ++s_numOfShapes;
	_this->m_me = _this;
	
	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &shapeVtbl;
	printf("    [%d] Shape::CTOR\n", _this->m_id);
	ShapeDrawColor(_this, Color_RED);
}

void ShapeCpyCTOR(struct Shape* _this, const struct Shape* _other)
{
	/*MIL*/
	ScaleableCTOR((struct Scaleable*)_this);
	_this->m_id = ++s_numOfShapes;
	_this->m_me = _this;

	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &shapeVtbl;
	printf("    [%d] Shape::CCTOR from [%d]\n", _this->m_id, _other->m_id);
	ShapeDraw(_this);
}

void ShapeDTOR(struct Shape* _this)
{
	((struct ShapeVtbl*)(((struct Scaleable*)(_this->m_me))->m_vtbl))->drawPtr(_this->m_me);
	printf("    [%d] Shape::DTOR\n", _this->m_id);
	--s_numOfShapes;
	((struct Scaleable*)_this)->m_vtbl = &scaleableVtbl;
	ScaleableDTOR((struct Scaleable*)_this);
}

void ShapeDraw(struct Shape* _this)
{
	printf("    [%d] Shape::Draw()\n", _this->m_id);
}

void ShapeDrawColor(struct Shape* _this, enum ColorEnum color)
{
	ColorSetColor(color);
	printf("    [%d] Shape::Draw(Color)\n", _this->m_id);
	ShapeDraw(_this);
	ColorSetColor(Color_DEFAULT);
}

void ShapePrintInventory()
{
	printf("Shape::printInventory - %d\n", s_numOfShapes);
}

void ShapeAssignmentOp(const struct Shape* _other)
{}

void ShapeScale(struct Shape* _this, double x)
{
	printf("    [%d] Shape::Scale(double)\n", _this->m_id);
}

double ShapeArea(struct Shape* _this)
{}

struct Shape* ShapeOperatorNew()
{
	return malloc(sizeof(struct Shape));
}

struct Shape* ShapeOperatorNewArr(size_t _numOfElements)
{
	size_t* arr = malloc(sizeof(struct Shape) * _numOfElements + sizeof(size_t));
	if(arr)
	{	
		*arr = _numOfElements;
		++arr;
	}
	return (struct Shape*) arr;
}

struct Shape* ShapeNewOperator()
{
	struct Shape* s = ShapeOperatorNew();
	ShapeCTOR(s);
	return s;
}

struct Shape* ShapeNewOperatorArr(size_t _numOfElements)
{
	struct Shape* arr = ShapeOperatorNewArr(_numOfElements);
	
	if(!arr) 
		return NULL;

	struct Shape* begin = arr;
	struct Shape* end = arr + _numOfElements;
	
	while(begin != end)
	{
		ShapeCTOR(begin++);
	}
	return arr;
}

void ShapeDeleteOperator(struct Shape* _this)
{
	ShapeDTOR(_this);
	free(_this);
}

void ShapeDeleteOperatorArr(struct Shape* _this)
{
	int i;	
	size_t numOfElements;
	size_t* s = (size_t*)_this;
	--s;
	numOfElements = *s;
	for(i = 0; i < numOfElements; ++i)
	{
		ShapeDTOR(_this + i);
	}
	free(s);
}

/*
int Shape::s_numOfShapes = 0;

Shape::Shape()
	: m_id(++s_numOfShapes), m_me(this) 
{
	printf("    [%d] Shape::CTOR\n", m_id);
	Draw(Color::RED);
}

Shape::Shape(const Shape& other)
	: m_id(++s_numOfShapes), m_me(this) 
{
	printf("    [%d] Shape::CCTOR from [%d]\n", m_id, other.m_id);
	Draw();
}

Shape::~Shape() 
{
	m_me->Draw();
	printf("    [%d] Shape::DTOR\n", m_id);
	--s_numOfShapes; 
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
	printf("Shape::printInventory - %d\n", s_numOfShapes);
}
*/
