#ifndef __Empty__
#define __Empty__

class Empty {
public:
    Empty() { puts("Empty()"); }
   ~Empty() { puts("~Empty()");}	
};

class EmptyEmpty  : public Empty
{
	int m_i;

public:
	EmptyEmpty() { puts("EmptyEmpty()"); }
};

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
};

#endif

