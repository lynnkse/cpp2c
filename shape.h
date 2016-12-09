#ifndef __Shape__
#define __Shape__

#include "scaleable.h"
#include "color.h"

struct ShapeVtbl
{
	void(*scalePtrDbl)(struct Shape*, double);
	void(*DTORptr)(struct Shape*);
	void(*drawPtr)(struct Shape*);
	void(*drawPtrColor)(struct Shape*, enum ColorEnum);
	double(*areaPtr)(struct Shape*);
};

struct Shape
{
	struct Scaleable m_base;
	struct Shape* m_me;
	int m_id;
};

void ShapeCTOR(struct Shape* _this);
void ShapeCpyCTOR(struct Shape* _this, const struct Shape* _other);
void ShapeDTOR(struct Shape* _this);
void ShapeDraw(struct Shape* _this);
void ShapeDrawColor(struct Shape* _this, enum ColorEnum color);
void ShapeScale(struct Shape* _this, double x);
double ShapeArea(struct Shape* _this);
void ShapePrintInventory();
void ShapeAssignmentOp(const struct Shape* _other);

struct Shape* ShapeOperatorNew();
struct Shape* ShapeOperatorNewArr(size_t _numOfElements);

struct Shape* ShapeNewOperator();
struct Shape* ShapeNewOperatorArr(size_t _numOfElements);

void ShapeDeleteOperator(struct Shape* _this);
void ShapeDeleteOperatorArr(struct Shape* _this);


/*
class Shape : public Scaleable 
{
private:
	static int s_numOfShapes;

public:
	Shape();
	Shape(const Shape& other);
	virtual ~Shape(); 

	Shape& operator=(const Shape &_other);

	virtual void Draw() const;
	virtual void Draw(Color::ColorEnum c) const;
	virtual void Scale(double x);
	virtual double Area() { }

	static void PrintInventory();

protected:
	Shape *m_me;
	int m_id;

private:
};
*/

#endif

