#ifndef __Circle__
#define __Circle__

#include "shape.h"
#include "rectangle.h"

extern int Circle_s_numOfShapes;

struct Circle_VTbl
{
	void(*Scale_ptr)(struct Circle*);	
	void(*Scale_Dbl_ptr)(struct Circle*, double);
	void(*DTOR_ptr)(struct Shape*);
	void(*Draw_ptr)(struct Circle*);
	double(*Area_ptr)(struct Circle*);	
	enum ColorEnum(*GetColor_ptr)(struct Circle*);
};

struct Circle
{
	struct Shape m_base;
	double m_radius;
	struct Rectangle m_boundingBox;
	struct Circle_VTbl* m_tbl;
};

void Circle_CTOR(struct Circle* _this);
void Circle_Dbl_CTOR(struct Circle* _this, double r);
void Circle_DTOR(struct Circle* _this);
void Circle_Scale(struct Circle* _this);
void Circle_Scale_Dbl(struct Circle* _this, double x);
double Circle_Area(struct Circle* _this);
void Circle_Draw(struct Circle* _this);
void Circle_PrintInventory();
enum ColorEnum Circle_GetColor_ptr(struct Circle* _this);


/*
class Circle : public Shape 
{	
public:
	static void PrintInventory();

private:
	static int s_numOfShapes;

public:
	Circle(double r = 3);
	Circle(const Circle& other);
	~Circle();

	void Scale(double f = 2.5);
 	double Area();
	double Radius() const;

	virtual void Draw() const;
	virtual Color::ColorEnum GetColor();

	operator Rectangle();

private:
	Circle& operator=(const Circle &); // disabled, no implementation provided

	double m_radius;
	Rectangle m_boundingBox;
};*/

#endif

