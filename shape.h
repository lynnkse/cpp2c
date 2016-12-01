#ifndef __Shape__
#define __Shape__

#include "scaleable.h"
#include "color.h"

extern int Shape_s_numOfShapes;

struct Shape
{
	struct Scaleable m_base;
	struct Shape* m_me;
	int m_id;
	struct Shape_VTbl* m_tbl;
};

struct Shape_VTbl
{	
	void(*Scale_Dbl_ptr)(struct Shape*, double);	
	void(*DTOR_ptr)(struct Shape*);
	void(*Draw_ptr)(struct Shape*);
	double(*Area_ptr)(struct Shape*);
};

void Shape_CTOR(struct Shape* _this);
void Shape_cpy_CTOR(struct Shape* _this, const struct Shape* _other);
void Shape_DTOR(struct Shape* _this);
struct Shape* Shape_Operator_Assn(struct Shape* _this, const struct Shape* _other);
void Shape_Draw(struct Shape* _this);
void Shape_Scale(struct Shape* _this);
void Shape_Scale_Dbl(struct Shape* _this, double x);
double Shape_Area(struct Shape* _this);
void Shape_PrintInventory();

#endif

