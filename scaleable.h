#ifndef __Scaleable__
#define __Scaleable__

#include <stdio.h>

struct ScaleableVtbl
{
	void(*scalePtrDbl)(struct Scaleable*, double);
};

struct Scaleable
{
	struct ScaleableVtbl* m_vtbl;
};

void ScaleableCTOR(struct Scaleable* _this);
void ScaleableDTOR(struct Scaleable* _this);
void PureVirtualFunctionCall();
void ScaleableFoo(struct Scaleable* _this);

/*
class Scaleable 
{
public:
	~Scaleable();

	virtual void Scale(double f = 2.0) = 0;

	void Foo();
};

inline Scaleable::~Scaleable()
{
	puts("~Scaleable");
}*/

#endif

