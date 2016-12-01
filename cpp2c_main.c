#include <stdio.h>
#include "scaleable.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "color.h"

void Draw_Shape_Glob(struct Shape* obj) 
{ 
	obj->m_tbl->Scale_Dbl_ptr(obj, 2);		
	obj->m_tbl->Draw_ptr(obj);	
}

double DrawBig_Shape_Glob(struct Shape* obj)
{
	double a0;
	double a1;
	a0 = obj->m_tbl->Area_ptr(obj);
	(obj)->m_tbl->Scale_Dbl_ptr(obj, 3.14);	
	a1 = (obj)->m_tbl->Area_ptr(obj);
	return a1 - a0;
}

void Rescale_Sclbl(struct Scaleable* sc) 
{
	(sc)->m_tbl->Scale_ptr(sc);
	(sc)->m_tbl->Scale_Dbl_ptr(sc, 3.14);
}

void Draw_Crcl_Glob(struct Circle c) 
{ 
	static int isFirst = 1;
	static struct Circle unit;
	if(isFirst)
	{
		Circle_Dbl_CTOR(&unit, 1);
		isFirst = 0;
	}
	
	unit.m_tbl->Draw_ptr(&unit);
	c.m_tbl->Draw_ptr(&c); 
}

void Draw_Crcl_Glob_int(struct Circle* c, int scale) 
{ 
	static int isFirst = 1;	
	static struct Circle unit;
	if(scale != 0) 
	{
		if(isFirst)
		{
			Circle_Dbl_CTOR(&unit, 1);
			isFirst = 0;
		}					
		unit.m_tbl->Scale_Dbl_ptr(&unit, scale);		
		unit.m_tbl->Draw_ptr(&unit);
	}
	c->m_tbl->Scale_Dbl_ptr(c, scale);	
	printf("COLOR: %d\n", c->m_tbl->GetColor_ptr(c));
}

void Report_Glob_Shape(struct Shape* s) 
{
	puts("-----report-----");
	s->m_tbl->Draw_ptr(s);
	Shape_PrintInventory();
}

int main(int argc, char **argv, char **envp)
{	
	puts("+++ Before Rectangle s");
 	struct Rectangle r;
	Rectangle_CTOR_int(&r, 4);

	if (argc > 0) 
	{
		struct Circle c;		
		Circle_CTOR(&c);
		puts("+++ Draw(c) X 2");
		Draw_Crcl_Glob(c);
		Draw_Crcl_Glob(c);
		puts("+++ Draw(c, num) X 3");
		Draw_Crcl_Glob_int(&c, 0);
		Draw_Crcl_Glob_int(&c, 4);
		Draw_Crcl_Glob_int(&c, 8);
		
		Report_Glob_Shape(&c);
	
		Shape_Operator_Assn(&r, &c);
	}

	puts("+++ Draw/DrawBig(r)");
	Draw_Shape_Glob((struct Shape*) &r);
	DrawBig_Shape_Glob((struct Shape*) &r);

	puts("+++ PrintInventory");
    Shape_PrintInventory();

	puts("+++ Circle c2");
	struct Circle c2;
	Circle_Dbl_CTOR(&c2, 17);
	Circle_PrintInventory();
	puts("+++ Circle c2 Rescale");
	Rescale_Sclbl((struct Scaleable*)&c2);
	c2.m_tbl->Draw_ptr(&c2);
	DrawBig_Shape_Glob((struct Shape*)&c2);

	puts("+++ Exiting Main");

	r.m_tbl->DTOR_ptr(&r);
	c.m_tbl->DTOR_ptr(&c);

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

