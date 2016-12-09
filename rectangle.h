#ifndef __Rectangle__
#define __Rectangle__

#include "shape.h"
#include "color.h"

struct RectangleVtbl
{
	void(*scalePtrDbl)(struct Rectangle*, double);
	void(*DTORptr)(struct Rectangle*);
	void(*drawPtr)(struct Rectangle*);
	void(*drawPtrColor)(struct Rectangle*, enum ColorEnum);
	double(*areaPtr)(struct Rectangle*);
};

struct Rectangle
{
	struct Shape m_base;
	int m_a;
	int m_b;
};

void RectangleCTORint(struct Rectangle* _this, int a);
void RectangleCTORintInt(struct Rectangle* _this, int a, int b);
void RectangleCpyCTOR(struct Rectangle* _this, const struct Rectangle* _other);
void RectangleDTOR(struct Rectangle* _this);
void RectangleDraw(struct Rectangle* _this, enum ColorEnum c);
void RectangleScaleDbl(struct Rectangle* _this, double f);
double RectangleArea(struct Rectangle* _this);

struct Rectangle* RectangleOperatorNew();
struct Rectangle* RectangleOperatorNewArr(size_t _numOfElements);

struct Rectangle* RectangleNewOperator(int a);
struct Rectangle* RectangleNewOperatorArr(size_t _numOfElements);

void RectangleDeleteOperator(struct Rectangle* _this);
void RectangleDeleteOperatorArr(struct Rectangle* _this);

/*
class Rectangle : public Shape 
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
};
*/
#endif

