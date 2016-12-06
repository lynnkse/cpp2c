#ifndef __Empty__
#define __Empty__

void Empty_CTOR(struct Empty* _this) { puts("Empty()"); }
void Empty_DTOR(struct Empty* _this) { puts("~Empty()"); }

struct Empty
{	
	char m_dummy;
};

struct EmptyEmpty
{
	//Empty m_base; - empty class, no need here
	int m_i;
};

void EmptyEmpty_CTOR(struct EmptyEmpty* _this) { puts("EmptyEmpty()"); }
void EmptyEmpty_DTOR(struct EmptyEmpty* _this) {}

struct EmptyBag
{
	struct Empty e1;
	struct Empty e2;
	struct EmptyEmpty ee;
};

void EmptyBag_CTOR(struct EmptyBag* _this) { puts("EmptyBag"); }

/*class Empty {
public:
    Empty() { puts("Empty()"); }
   ~Empty() { puts("~Empty()");}	
};*/

/*class EmptyEmpty  : public Empty
{
	int m_i;

public:
	EmptyEmpty() { puts("EmptyEmpty()"); }
};*/

/*
class EmptyBag 
{
	Empty e1;
	Empty e2;
	EmptyEmpty ee;

public: 
	EmptyBag() 
	{
		puts("EmptyBag");
	}
};*/

#endif

