#ifndef __Empty__
#define __Empty__

struct Empty
{
	char m_dummy;
};

void EmptyCTOR(struct Empty* _this) { puts("Empty()"); }
void EmptyDTOR(struct Empty* _this) { puts("~Empty()"); }

struct EmptyEmpty
{
	int m_i;
};

void EmptyEmptyCTOR(struct EmptyEmpty* _this) 
{ 
	EmptyCTOR((struct Empty*) _this);	
	puts("EmptyEmpty()"); 
}

struct EmptyBag
{
	struct Empty e1;
	struct Empty e2;
	struct EmptyEmpty ee;
};

void EmptyBagCTOR(struct EmptyBag* _this)
{
	puts("EmptyBag");
}

void EmptyBagDTOR(struct EmptyBag* _this)
{}

/*class Empty 
{
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

