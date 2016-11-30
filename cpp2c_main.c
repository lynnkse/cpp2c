#include <stdio.h>
#include "scaleable.h"
#include "shape.h"
#include "rectangle.h"
/*#include "circle.h"*/

void Draw_Shape_Glob(struct Shape* obj) 
{ 
	((struct Rectangle*)obj)->m_tbl->Scale_Dbl_ptr((struct Rectangle*)obj, 2);		
	obj->m_tbl->Draw_ptr(obj);	
}

double DrawBig_Shape_Glob(struct Shape* obj)
{
	double a0 = obj->m_tbl->Area_ptr(obj);
	((struct Rectangle*)obj)->m_tbl->Scale_ptr((struct Rectangle*)obj);	
	double a1 = obj->m_tbl->Area_ptr(obj);
	return a1 - a0;
}

int main(int argc, char **argv, char **envp)
{	
 	struct Rectangle r;
	puts("+++ Before Rectangle s");
	Rectangle_CTOR_int(&r, 4);

	puts("+++ Draw/DrawBig(r)");
	Draw_Shape_Glob((struct Shape*) &r);
	DrawBig_Shape_Glob((struct Shape*) &r);

    return 0;
}

/*
void Report(const Shape& s) 
{
	puts("-----report-----");
	s.Draw(); 
	Shape::PrintInventory();
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

