#include <stdio.h>
#include "scaleable.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "empty.h"

void GlobDrawShape(struct Shape* obj) 
{ 
	((struct ShapeVtbl*)(((struct Scaleable*)obj)->m_vtbl))->scalePtrDbl(obj, 2);
	((struct ShapeVtbl*)(((struct Scaleable*)obj)->m_vtbl))->drawPtr(obj);
}

void GlobDrawCircle(struct Circle* c) 
{ 
	//static Circle unit(1);
	static struct Circle unit;
	static int isSet = 0;
	
	if(!isSet)
	{
		CircleCTORDbl(&unit, 1);
		isSet = 1;
	}
	
	((struct CircleVtbl*)(((struct Scaleable*)&unit)->m_vtbl))->drawPtr(&unit);
	((struct CircleVtbl*)(((struct Scaleable*)c)->m_vtbl))->drawPtr(&c);

	/*FIXME DTOR in the end for static*/
}

void GlobDrawCircleInt(struct Circle* c, int scale) 
{ 
	if(scale != 0)
	{
		static int isSet = 0;		
		struct Circle unit;
		if(!isSet)
		{
			CircleCTORDbl(&unit, 1);
			isSet = 1;
		}
		((struct CircleVtbl*)(((struct Scaleable*)&unit)->m_vtbl))->drawPtr(&unit);
	}

	CircleScale(c, scale);	
	printf("COLOR: %d\n", CircleGetColor(c));
}

void GlobReportShape(const struct Shape* s) 
{
	puts("-----report-----");
	((struct ShapeVtbl*)(((struct Scaleable*)s)->m_vtbl))->drawPtr(s);	
	ShapePrintInventory();
}

double GlobDrawBigRect(struct Rectangle* shape)
{
	double a0 = ((struct RectangleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	((struct RectangleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->scalePtrDbl(shape, 5);
	double a1 = ((struct RectangleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	return a1 - a0;
}

double GlobDrawBigCircle(struct Circle* shape)
{
	double a0 = ((struct CircleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	((struct CircleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->scalePtrDbl(shape, 5);
	double a1 = ((struct CircleVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	return a1 - a0;
}

double GlobDrawBigShape(struct Shape* shape)
{
	double a0 = ((struct ShapeVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	((struct ShapeVtbl*)(((struct Scaleable*)shape)->m_vtbl))->scalePtrDbl(shape, 5);
	double a1 = ((struct ShapeVtbl*)(((struct Scaleable*)shape)->m_vtbl))->areaPtr(shape);
	return a1 - a0;
}

void Rescale(struct Scaleable *sc) 
{
	((struct Scaleable*)sc)->m_vtbl->scalePtrDbl(sc, 2.0);
	((struct Scaleable*)sc)->m_vtbl->scalePtrDbl(sc, 3.14);
}

void doPointerArray() 
{
	int i;	
	struct Shape* array[3];
	array[0] = CircleNewOperator(3);
	array[1] = RectangleNewOperator(3);
	array[2] = CircleNewOperator(4);	

    for(i = 0; i < 3; ++i) 
		((struct ShapeVtbl*)(((struct Scaleable*)array[i])->m_vtbl))->drawPtr(array[i]);

	printf("area: %f\n", GlobDrawBigShape(array[2])); 

    for(i = 0; i < 3; ++i) 
	{ 
		ShapeDeleteOperator(array[i]);
		array[i] = 0; 
	}
}

void doObjArray() 
{
	struct Circle c;
	struct Rectangle r;
	struct Shape objects[3];
	int i;
	
	CircleCTORDbl(&c, 3);
	ShapeCpyCTOR(objects + 0, &c);
	
	RectangleCTORint(&r, 4);
	ShapeCpyCTOR(objects + 1, &r);

	CircleCTORDbl(&c, 9);
	ShapeCpyCTOR(objects + 2, &c);

    for(i = 0; i < 3; ++i)
		GlobDrawBigShape(objects + i);

	for(i = 0; i < 3; ++i)
		ShapeDTOR(objects + i);

	CircleDTOR(&c);
	RectangleDTOR(&r);
}

/*
void Report(const Shape& s) 
{
	puts("-----report-----");
	s.Draw(); 
	Shape::PrintInventory();
}

inline void Draw(Shape& obj) 
{ 
	obj.Scale(2);
	obj.Draw();	
}

void Draw(Circle c) 
{ 
	static Circle unit(1);
	
	unit.Draw();
	c.Draw(); 
}

void Draw(Circle& c, int scale) 
{ 
	if(scale != 0) 
	{
		static Circle unit(1);			
		unit.Scale(scale);
		unit.Draw();
	}
	c.Scale(scale);	
	printf("COLOR: %d\n", c.GetColor());
}

void Rescale(Scaleable *sc) {
	sc->Scale();
	sc->Scale(3.14);
}

template <class T>
double DrawBig(T& shape)
{
	double a0 = shape.Area();
	shape.Scale();
	double a1 = shape.Area();
	return a1 - a0;
}

inline double DrawBig(Shape &shape)
{
	double a0 = shape.Area();
	shape.Scale(3.14);
	double a1 = shape.Area();
	return a1 - a0;
}

void doPointerArray() {
	Shape *array[] = {
	    new Circle(),
	    new Rectangle(3),
	    new Circle(4)
	};

    for(int i = 0; i < 3; ++i) 
		array[i]->Draw();

	printf("area: %f\n", DrawBig(*array[2]));

    for(int i = 0; i < 3; ++i) { 
		delete array[i]; 
		array[i] = 0; 
	}
}

void doObjArray() {
	Shape objects[] = {
	    Circle(),
	    Rectangle(4),
	    Circle(9)
	};

    for(int i = 0; i < 3; ++i)
		DrawBig(objects[i]);
}


void DeleteArray(Rectangle *arr)
{
    delete[] arr;
}
*/

int main(int argc, char **argv, char **envp)
{
	struct Rectangle r;
	struct Circle c;
	struct Circle olympics[5];
	struct EmptyBag eb;
	struct Rectangle* fourRectangles;
	int i;

	puts("+++ Before Rectangle s");
	RectangleCTORint(&r, 4);	
	
	if(argc > 0)
	{
		CircleCTORDbl(&c, 3);
		puts("+++ Draw(c) X 2");
		GlobDrawCircle(&c); 
		GlobDrawCircle(&c); 
		puts("+++ Draw(c, num) X 3");
		GlobDrawCircleInt(&c, 0);
		GlobDrawCircleInt(&c, 4);
		GlobDrawCircleInt(&c, 8);
		GlobReportShape((struct Shape*) &c);
		CircleDTOR(&c);
	}

	puts("+++ Draw/DrawBig(r)");
	GlobDrawShape(&r); 
	GlobDrawBigRect(&r);

	puts("+++ PrintInventory");
	ShapePrintInventory();

	puts("+++ Circle c2");
	CircleCTORDbl(&c, 17);
	CirclePrintInventory();
	puts("+++ Circle c2 Rescale");
	Rescale(&c);
	((struct CircleVtbl*)(((struct Scaleable*)&c)->m_vtbl))->drawPtr(&c);
	GlobDrawBigCircle(&c);

	puts("+++ doPointerArray");
	void doPointerArray(); 	

	puts("+++ doObjArray");
    doObjArray();

	puts("+++ Olympics");
    
	for(i = 0; i < 5; ++i)
	{
		CircleCTORDbl(olympics + i, 3);
	}

	GlobDrawBigCircle(olympics + 1);

	
	puts("+++ fourRectangles");
	fourRectangles = RectangleNewOperatorArr(4);
	GlobDrawBigRect(fourRectangles);
	puts("+++ DeleteArray");
	RectangleDeleteOperatorArr(fourRectangles);

	puts("+++ Empty Bag");
	EmptyBagCTOR(&eb);

	puts("+++ Exiting Main");

	RectangleDTOR(&r);
	CircleDTOR(&c);
	for(i = 0; i < 5; ++i)
	{
		CircleDTOR(olympics + i);
	}
	EmptyBagDTOR(&eb);

	return 0;
}

/*
int main(int argc, char **argv, char **envp)
{	
	puts("+++ Before Rectangle s");
 	Rectangle r(4);

	if (argc > 0) {
    	Circle c;
		puts("+++ Draw(c) X 2");
		Draw(c);
		Draw(c);
		puts("+++ Draw(c, num) X 3");
		Draw(c, 0);
		Draw(c, 4);
		Draw(c, 8);
		Report(c);
	
		r = c; //TODO ???
	}

	puts("+++ Draw/DrawBig(r)");
	Draw(r);
	DrawBig(r);

	puts("+++ PrintInventory");
    Shape::PrintInventory();

	puts("+++ Circle c2");
    Circle c2(17);
    c2.PrintInventory();
	puts("+++ Circle c2 Rescale");
	Rescale(&c2);
	c2.Draw();
	DrawBig(c2);

	puts("+++ doPointerArray");
	doPointerArray();

	puts("+++ doObjArray");
    doObjArray();


	puts("+++ Olympics");
    Circle olympics[5];
	DrawBig(olympics[1]);

	puts("+++ fourRectangles");
    Rectangle *fourRectangles = new Rectangle[4];
	DrawBig(*fourRectangles);
	puts("+++ DeleteArray");
    DeleteArray(fourRectangles);

	puts("+++ Empty Bag");
	EmptyBag eb;

	puts("+++ Exiting Main");
    return 0;
}
*/
