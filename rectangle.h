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
	struct Rectangle_VTbl* m_tbl;
};

struct Rectangle_VTbl
{
	void(*Scale_ptr)(struct Rectangle*);
	void(*Scale_Dbl_ptr)(struct Rectangle*, double);
	void(*DTOR_ptr)(struct Rectangle*);
	void(*Draw_ptr)(struct Rectangle*);
	double(*Area_ptr)(struct Rectangle*);
};

void Rectangle_CTOR(struct Rectangle* _this);
void Rectangle_CTOR_int(struct Rectangle* _this, int a);
void Rectangle_CTOR_int_int(struct Rectangle* _this, int a, int b);
void Rectangle_DTOR(struct Rectangle* _this);
double Rectangle_Area(struct Rectangle* _this);
void Rectangle_Scale(struct Rectangle* _this);
void Rectangle_Scale_Dbl(struct Rectangle*, double f);
void Rectangle_Draw(struct Rectangle* _this, enum ColorEnum c);


#endif

