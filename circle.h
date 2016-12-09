#ifndef __Circle__
#define __Circle__

#include "shape.h"
#include "rectangle.h"
#include "color.h"

struct CircleVtbl
{
	void(*scalePtrDbl)(struct Shape*, double);
	void(*DTORptr)(struct Shape*);
	void(*drawPtr)(struct Shape*);
	void(*drawPtrColor)(struct Shape*, enum ColorEnum);
	double(*areaPtr)(struct Shape*);
};

struct Circle
{
	struct Shape m_base;
	double m_radius;
	struct Rectangle m_boundingBox;
};

void CirclePrintInventory();
void CircleCTORDbl(struct Circle* _this, double r);
void CircleCpyCTOR(struct Circle* _this, const struct Circle* _other);
void CircleDTOR(struct Circle* _this);
void CircleScale(struct Circle* _this, double f);
double CircleArea(struct Circle* _this);
double CircleRadius(struct Circle* _this);
void CircleDraw(struct Circle* _this);
enum ColorEnum CircleGetColor(struct Circle* _this);

struct Circle* CircleOperatorNew();
struct Circle* CircleOperatorNewArr(size_t _numOfElements);

struct Circle* CircleNewOperator(double r);
struct Circle* CircleNewOperatorArr(size_t _numOfElements);

void CircleDeleteOperator(struct Circle* _this);
void CircleDeleteOperatorArr(struct Circle* _this);

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
};
*/
#endif

