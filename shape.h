#ifndef __Shape__
#define __Shape__

#include "scaleable.h"
/*#include "color.h"*/

/*class Shape : public Scaleable 
{
private:
	static int s_numOfShapes;

public:
	Shape();
	Shape(const Shape& other);
	virtual ~Shape() = 0;

	Shape& operator=(const Shape &_other);

	virtual void Draw() const;
	virtual void Draw(Color::ColorEnum c) const;
	virtual void Scale(double x);
	virtual double Area() = 0;

	static void PrintInventory();

protected:
	Shape *m_me;
	int m_id;

private:
};*/

struct Shape
{
	struct Scaleable m_base;
	struct Shape* m_me;
	int m_id;
};

void Shape_CTOR(struct Shape* _this);
void Shape_cpy_CTOR(struct Shape* _this, const struct Shape* _other);
void Shape_DTOR(struct Shape* _this);
struct Shape* Shape_Operator_Assn(struct Shape* _this, const struct Shape* _other);
void Shape_Draw(struct Shape* _this);



#endif

