#include <stdio.h>
#include "scaleable.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "color.h"
#include "empty.h"

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


double Glob_DrawBig_Rect(struct Rectangle* _rect)
{
	double a0 = _rect->m_tbl->Area_ptr(_rect);	
	_rect->m_tbl->Scale_Dbl_ptr(_rect, 5);
	double a1 = _rect->m_tbl->Area_ptr(_rect);
	return a1 - a0;
}

double Glob_DrawBig_Circle(struct Circle* _circle)
{
	double a0 = _circle->m_tbl->Area_ptr(_circle);	
	_circle->m_tbl->Scale_Dbl_ptr(_circle, 5);
	double a1 = _circle->m_tbl->Area_ptr(_circle);
	return a1 - a0;
}

void Rescale_Sclbl(struct Scaleable* sc) 
{
	(sc)->m_tbl->Scale_Dbl_ptr(sc, 2);
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

void doPointerArray() 
{
	int i;	

	struct Shape* array[] = {
		(struct Shape*)Circle_New_Operator_Dbl(3),
		(struct Shape*)Rectangle_New_Operator_Int(3),
		(struct Shape*)Circle_New_Operator_Dbl(4)
	};	

    for(i = 0; i < 3; ++i) 
		array[i]->m_tbl->Draw_ptr(array[i]);		

	printf("area: %f\n", DrawBig_Shape_Glob(array[2]));

    for(i = 0; i < 3; ++i) 
	{ 
		Shape_Delete((struct Shape*)array[i]);		
		array[i] = 0; 
	}
}

void doObjArray() 
{
	int i;	
	struct Circle c1;
	struct Circle c2;
	struct Rectangle r;

	Circle_Dbl_CTOR(&c1, 3);
	Rectangle_CTOR_int(&r, 4);
	Circle_Dbl_CTOR(&c2, 9);

	struct Shape objects[3];
	Shape_cpy_CTOR(objects + 0, (struct Shape*)&c1);
	Shape_cpy_CTOR(objects + 1, (struct Shape*)&r);
	Shape_cpy_CTOR(objects + 2, (struct Shape*)&c2);

	Circle_DTOR(&c1);
	Circle_DTOR(&c2);
	Rectangle_DTOR(&r);

    for(i = 0; i < 3; ++i)
		DrawBig_Shape_Glob(objects + i);

	for(i = 0; i < 3; ++i)
		Shape_DTOR(objects + i);
}

void DeleteArray(struct Rectangle *arr)
{
    Rectangle_Delete_Operator_Arr(arr);
}

int main(int argc, char **argv, char **envp)
{	
	int i;	
	struct Rectangle* fourRectangles;
	struct Circle c;
	struct Rectangle r;
	struct Circle c2;
	struct EmptyBag eb;
	puts("+++ Before Rectangle s");
	Rectangle_CTOR_int(&r, 4);

	if (argc > 0) 
	{		
		Circle_Dbl_CTOR(&c, 3);
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
	Glob_DrawBig_Rect(&r);

	puts("+++ PrintInventory");
    Shape_PrintInventory();

	puts("+++ Circle c2");
	Circle_Dbl_CTOR(&c2, 17);
	Circle_PrintInventory();
	puts("+++ Circle c2 Rescale");
	Rescale_Sclbl((struct Scaleable*)&c2);
	c2.m_tbl->Draw_ptr(&c2);
	Glob_DrawBig_Circle(&c2);

	puts("+++ Exiting Main");

	r.m_tbl->DTOR_ptr(&r);
	c2.m_tbl->DTOR_ptr(&c2);

	puts("+++ doPointerArray");
	doPointerArray();

	puts("+++ doObjArray");
	doObjArray();

	puts("+++ Olympics");
	struct Circle olympics[5];	
	DrawBig(olympics + 1);

	puts("+++ fourRectangles");	

	fourRectangles = Rectangle_New_Operator_Int_Arr(16, 4);

	Glob_DrawBig_Rect(fourRectangles);
	puts("+++ DeleteArray");	
	DeleteArray(fourRectangles);

	puts("+++ Empty Bag");
	
	EmptyBag_CTOR(&eb);

	puts("+++ Exiting Main");

	EmptyEmpty_DTOR(&eb);
	Rectangle_DTOR(&r);
	Circle_DTOR(&c);
	Circle_DTOR(&c2);

    return 0;
}



