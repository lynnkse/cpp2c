#include "scaleable.h"
#include <stdlib.h>
#include <stdio.h>

static struct ScaleableVtbl scaleableVtbl = {
	PureVirtualFunctionCall
};

void ScaleableCTOR(struct Scaleable* _this)
{
	_this->m_vtbl = &scaleableVtbl;
}

void ScaleableDTOR(struct Scaleable* _this)
{ 
	puts("~Scaleable"); 
}

void PureVirtualFunctionCall() 
{
	puts("Pure virtual function called");
	exit(1);
}

void ScaleableFoo(struct Scaleable* _this)
{
	_this->m_vtbl->scalePtrDbl(_this, 2.0);
}


