#ifndef __Rectangle__
#define __Rectangle__

#include "shape.h"

/*class Rectangle : public Shape 
{
public:
	Rectangle(int a = 16);
	Rectangle(int a, int b);
	Rectangle(const Rectangle &other);
	~Rectangle();

    void Draw(Color::ColorEnum c) const;
	void Scale(double f = 5.0) { m_a *= f; m_b *= f; }
	double Area();

private:
	int m_a, m_b;
};*/

struct Rectangle
{
	struct Shape m_base;	
	int m_a;
	int m_b;
};

void Rectangle_CTOR(struct Rectangle* _this);
void Rectangle_CTOR_int(struct Rectangle* _this, int a);




#endif

