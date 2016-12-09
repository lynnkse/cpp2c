#include <stdio.h>
#include "circle.h"
#include "color.h"
#include "rectangle.h"

int circleNumOfShapes = 10;

struct CircleVtbl circleVtbl = {
	CircleScale,	
	CircleDTOR,
	CircleDraw,
	ShapeDrawColor,
	CircleArea
};

void CirclePrintInventory()
{
	printf("Shape::printInventory - %d\n", circleNumOfShapes);	
}

void CircleCTORDbl(struct Circle* _this, double r)
{
	/*MIL*/
	ShapeCTOR((struct Shape*)_this);
	_this->m_radius = r; 
	RectangleCTORintInt(&(_this->m_boundingBox), r*2, r*2);

	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &circleVtbl;
	printf("    [%d] ----------Circle::CTOR(double) -> r:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 
}

void CircleCpyCTOR(struct Circle* _this, const struct Circle* _other)
{
	/*MIL*/
	ShapeCpyCTOR((struct Shape*)_this, (struct Shape*)_other);
	_this->m_radius = _other->m_radius;

	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &circleVtbl; /*???*/
	printf("    [%d] Circle::CCTOR -> m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius);
}

void CircleDTOR(struct Circle* _this)
{
	((struct Scaleable*)_this)->m_vtbl = &circleVtbl;
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 
	CircleDraw(((struct Shape*)_this)->m_me);	
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius); 
	ShapeDTOR((struct Shape*)_this);
}

void CircleScale(struct Circle* _this, double f)
{
	_this->m_radius *= f;
	RectangleScaleDbl(&(_this->m_boundingBox), f / 2);	
}

double CircleArea(struct Circle* _this)
{
	return _this->m_radius * _this->m_radius * 3.1415;	
}

double CircleRadius(struct Circle* _this);

void CircleDraw(struct Circle* _this)
{
	printf("    [%d] Circle::Draw() -> m_radius:%f\n", ((struct Shape*)_this)->m_id, _this->m_radius);
}

enum ColorEnum CircleGetColor(struct Circle* _this)
{
	return Color_DEFAULT;
}

struct Circle* CircleOperatorNew()
{
	return malloc(sizeof(struct Circle));
}

struct Circle* CircleOperatorNewArr(size_t _numOfElements)
{
	size_t* arr = malloc(sizeof(struct Circle) * _numOfElements + sizeof(size_t));
	if(arr)
	{	
		*arr = _numOfElements;
		++arr;
	}
	return (struct Circle*) arr;
}

struct Circle* CircleNewOperator(double r)
{
	struct Circle* s = CircleOperatorNew();
	CircleCTORDbl(s, r);
	return s;
}

struct Circle* CircleNewOperatorArr(size_t _numOfElements)
{
	struct Circle* arr = CircleOperatorNewArr(_numOfElements);
	
	if(!arr) 
		return NULL;

	struct Circle* begin = arr;
	struct Circle* end = arr + _numOfElements;
	
	while(begin != end)
	{
		CircleCTORDbl(begin++, 3);
	}
	return arr;
}

void CircleDeleteOperator(struct Circle* _this)
{
	CircleDTOR(_this);
	free(_this);
}

void CircleDeleteOperatorArr(struct Circle* _this)
{
	int i;	
	size_t numOfElements;
	size_t* s = (size_t*)_this;
	--s;
	numOfElements = *s;
	for(i = 0; i < numOfElements; ++i)
	{
		CircleDTOR(_this + i);
	}
	free(s);
}

/*
int Circle::s_numOfShapes = 10;

Circle::Circle(double r)
	: m_radius(r), m_boundingBox(r * 2, r * 2)
{ 
	printf("    [%d] Circle::CTOR(double) -> r:%f\n", m_id, m_radius); 
}

Circle::Circle(const Circle& other)
	: Shape(other), m_radius(other.m_radius) 
{ 
	printf("    [%d] Circle::CCTOR -> m_radius:%f\n", m_id, m_radius);
}

Circle::~Circle() 
{ 
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", m_id, m_radius); 
	m_me->Draw();
	printf("    [%d] Circle::DTOR ->  m_radius:%f\n", m_id, m_radius); 
}

void Circle::Draw() const 
{ 
	printf("    [%d] Circle::Draw() -> m_radius:%f\n", m_id, m_radius);
}

void Circle::Scale(double f) 
{
	m_radius *= f;
	m_boundingBox.Scale(f / 2);
}

double Circle::Area() 
{
	return m_radius * m_radius * 3.1415;	
}

double Circle::Radius() const
{ 
	printf("    [%d] Circle::radius()  -> m_radius:%f\n", m_id, m_radius);
	return m_radius;
}

Color::ColorEnum Circle::GetColor() 
{
	return Color::DEFAULT;
}

Circle::operator Rectangle()
{
	return m_boundingBox;
}

void Circle::PrintInventory() 
{
	printf("Shape::printInventory - %d\n", s_numOfShapes);
}
*/
