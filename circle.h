#ifndef __Circle__
#define __Circle__

#include "shape.h"
#include "rectangle.h"

extern int Circle_s_numOfShapes;

struct Circle_VTbl
{
	void(*Scale_Dbl_ptr)(struct Circle*, double);
	void(*DTOR_ptr)(struct Shape*);
	void(*Draw_ptr)(struct Circle*);
	void(*Draw_Color_ptr)(struct Shape*);
	double(*Area_ptr)(struct Circle*);	
	enum ColorEnum(*GetColor_ptr)(struct Circle*);
};

struct Circle
{
	struct Shape m_base;
	double m_radius;
	struct Rectangle m_boundingBox;
	struct Circle_VTbl* m_tbl;
};

void Circle_Dbl_CTOR(struct Circle* _this, double r);
void Circle_DTOR(struct Circle* _this);
void Circle_Scale_Dbl(struct Circle* _this, double x);
double Circle_Area(struct Circle* _this);
void Circle_Draw(struct Circle* _this);
void Circle_PrintInventory();
enum ColorEnum Circle_GetColor_ptr(struct Circle* _this);
struct Rectangle Circle_OperatorRect(struct Circle* _this); /*return struct Rect. here because it needs to be returned by value as separate object and not as port of Circle object*/
struct Circle* Circle_New_Operator_Dbl(double _r);
struct Circle* Circle_New_Operator_Dbl_Arr(double _r, size_t _size);
void Circle_Operator_New_Dbl(struct Circle* _this, double _r);
void Circle_Operator_New_Dbl_Arr(struct Circle* _this, double _r, size_t _size);
void Circle_Operator_Delete(struct Circle* _this);
void Circle_Operator_Delete_Arr(struct Circle* _this);

#endif










































