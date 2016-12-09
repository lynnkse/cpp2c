#include "rectangle.h"
#include "shape.h"

static struct RectangleVtbl rectangleVtbl = {
	RectangleScaleDbl,	
	RectangleDTOR,
	ShapeDraw,
	ShapeDrawColor,
	RectangleArea
};

void RectangleCTORint(struct Rectangle* _this, int a)
{
	/*MIL*/
	ShapeCTOR((struct Shape*)_this);
	_this->m_a = a;
	_this->m_b = a;

	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &rectangleVtbl;
	printf("    [%d] Rectangle::CTOR(int) -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
}

void RectangleCTORintInt(struct Rectangle* _this, int a, int b)
{
	/*MIL*/
	ShapeCTOR((struct Shape*)_this);
	_this->m_a = a;
	_this->m_b = b;
	
	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &rectangleVtbl;
	printf("    [%d] Rectangle::CTOR(int,int) -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
}

void RectangleCpyCTOR(struct Rectangle* _this, const struct Rectangle* _other)
{
	/*MIL*/
	ShapeCpyCTOR((struct Shape*)_this, (struct Shape*)_other);
	_this->m_a = _other->m_a;
	_this->m_b = _other->m_b;

	/*body*/
	((struct Scaleable*)_this)->m_vtbl = &rectangleVtbl; /*???*/
	printf("    [%d] Rectangle::CCTOR -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
}

void RectangleDTOR(struct Rectangle* _this)
{
	((struct Scaleable*)_this)->m_vtbl = &rectangleVtbl;	
	printf("    [%d] Rectangle::DTOR -> a:%d/%d\n", ((struct Shape*)_this)->m_id, _this->m_a, _this->m_b);
	ShapeCTOR((struct Shape*)_this);
}

void RectangleDraw(struct Rectangle* _this, enum ColorEnum c);

void RectangleScaleDbl(struct Rectangle* _this, double f)
{
		_this->m_a *= f; 
		_this->m_b *= f;
}

double RectangleArea(struct Rectangle* _this)
{
	return _this->m_a * _this->m_b;
}

struct Rectangle* RectangleOperatorNew()
{
	return malloc(sizeof(struct Rectangle));
}

struct Rectangle* RectangleOperatorNewArr(size_t _numOfElements)
{
	size_t* arr = malloc(sizeof(struct Rectangle) * _numOfElements + sizeof(size_t));
	if(arr)
	{	
		*arr = _numOfElements;
		++arr;
	}
	return (struct Rectangle*) arr;
}

struct Rectangle* RectangleNewOperator(int a)
{
	struct Rectangle* s = RectangleOperatorNew();
	RectangleCTORint(s, a);
	return s;
}

struct Rectangle* RectangleNewOperatorArr(size_t _numOfElements)
{
	struct Rectangle* arr = RectangleOperatorNewArr(_numOfElements);
	
	if(!arr) 
		return NULL;

	struct Rectangle* begin = arr;
	struct Rectangle* end = arr + _numOfElements;
	
	while(begin != end)
	{
		RectangleCTORint(begin++, 16);
	}
	return arr;
}

void RectangleDeleteOperator(struct Rectangle* _this)
{
	RectangleDTOR(_this);
	free(_this);
}

void RectangleDeleteOperatorArr(struct Rectangle* _this)
{
	int i;	
	size_t numOfElements;
	size_t* s = (size_t*)_this;
	--s;
	numOfElements = *s;
	for(i = 0; i < numOfElements; ++i)
	{
		RectangleDTOR(_this + i);
	}
	free(s);
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
