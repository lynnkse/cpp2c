#ifndef __Rectangle__
#define __Rectangle__

#include "shape.h"
#include "color.h"

struct Rectangle
{
	struct Shape m_base;	
	int m_a;
	int m_b;
	struct Rectangle_VTbl* m_tbl;
};

struct Rectangle_VTbl
{
	void(*Scale_Dbl_ptr)(struct Rectangle*, double);
	void(*DTOR_ptr)(struct Rectangle*);
	void(*Draw_ptr)(struct Rectangle*);
	void(*Draw_Color_ptr)(struct Shape*);
	double(*Area_ptr)(struct Rectangle*);
};

void Rectangle_CTOR_int(struct Rectangle* _this, int a);
void Rectangle_CTOR_int_int(struct Rectangle* _this, int a, int b);
void Rectangle_DTOR(struct Rectangle* _this);
double Rectangle_Area(struct Rectangle* _this);
void Rectangle_Scale_Dbl(struct Rectangle*, double f);
void Rectangle_Draw(struct Rectangle* _this, enum ColorEnum c);
struct Rectangle* Rectangle_New_Operator_Int(int a);
struct Rectangle* Rectangle_New_Operator_Int_Int(int a, int b);
struct Rectangle* Rectangle_New_Operator_Int_Arr(int a, size_t size);
struct Rectangle* Rectangle_New_Operator_Int_Int_Arr(int a, int b, size_t size);
void Rectangle_Operator_New_Int(struct Rectangle* _this, int a);
void Rectangle_Operator_New_Int_Int(struct Rectangle* _this, int a, int b);
void Rectangle_Operator_New_Int_Arr(struct Rectangle* _this, int a, size_t size);
void Rectangle_Operator_New_Int_Int_Arr(struct Rectangle* _this, int a, int b, size_t size);
void Rectangle_Delete_Operator(struct Rectangle* _this);
void Rectangle_Delete_Operator_Arr(struct Rectangle* _this);

#endif

