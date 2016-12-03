#include "rectangle.h"
#include "color.h"

static struct Rectangle_VTbl tbl = {Rectangle_Scale_Dbl, Rectangle_DTOR, Rectangle_Draw, Shape_Draw_Color, Rectangle_Area};

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

struct Rectangle* Rectangle_New_Operator_Int(int a)
{
	struct Rectangle* r = malloc(sizeof(struct Rectangle));
	if(r)
	{
		Rectangle_Operator_New_Int(r, a);
	}
	return r;	
}

struct Rectangle* Rectangle_New_Operator_Int_Int(int a, int b)
{
	struct Rectangle* r = malloc(sizeof(struct Rectangle));
	if(r)
	{
		Rectangle_Operator_New_Int_Int(r, a, b);
	}
	return r;
}

struct Rectangle* Rectangle_New_Operator_Int_Arr(int a, size_t size)
{
	size_t* r = malloc(sizeof(struct Rectangle) * size + sizeof(size_t));
	if(r)
	{
		*r = size;
		++r;
		Rectangle_Operator_New_Int_Arr((struct Rectangle*)r, a, size);
	}
	return r;
}

struct Rectangle* Rectangle_New_Operator_Int_Int_Arr(int a, int b, size_t size)
{
	size_t* r = malloc(sizeof(struct Rectangle) * size + sizeof(size_t));
	if(r)
	{
		*r = size;
		++r;
		Rectangle_Operator_New_Int_Int_Arr((struct Rectangle*)r, a, b, size);
	}
	return r;
}

void Rectangle_Operator_New_Int(struct Rectangle* _this, int a)
{
	Rectangle_CTOR_int(_this, a);
}

void Rectangle_Operator_New_Int_Int(struct Rectangle* _this, int a, int b)
{
	Rectangle_CTOR_int_int(_this, a, b);
}

void Rectangle_Operator_New_Int_Arr(struct Rectangle* _this, int a, size_t size)
{
	struct Rectangle* end = _this + size;
	while(_this != end)
	{
		Rectangle_CTOR_int(_this++, a);
	}
}

void Rectangle_Operator_New_Int_Int_Arr(struct Rectangle* _this, int a, int b, size_t size)
{
	struct Rectangle* end = _this + size;
	while(_this != end)
	{
		Rectangle_CTOR_int_int(_this++, a, b);
	}
}

void Rectangle_Delete_Operator(struct Rectangle* _this)
{
	if(_this)
	{
		Rectangle_DTOR(_this);
		free(_this);
	}
}

void Rectangle_Delete_Operator_Arr(struct Rectangle* _this)
{
	struct Rectangle* orr = _this;
	size_t* beg = (size_t*)_this;
	struct Rectangle* end;
	if(_this)
	{
		--beg;
		struct Rectangle* end = _this + *beg;
		while(_this != end)
		{
			Rectangle_DTOR(_this);
		}
		free(orr);
	}
}








































