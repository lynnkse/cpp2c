#include <stdio.h>
#include "scaleable.h"
#include "shape.h"
#include "rectangle.h"
/*#include "circle.h"*/

int main(int argc, char **argv, char **envp)
{	
 	struct Rectangle r;
	puts("+++ Before Rectangle s");
	Rectangle_CTOR_int(&r, 4);

    return 0;
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
	
		r = c;
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


	puts("+++ Exiting Main");
    return 0;
}*/

