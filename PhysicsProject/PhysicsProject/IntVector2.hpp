//================================================================
//              IntVector2.hpp                                  
//================================================================
#pragma once
#ifndef _IntVector2_
#define _IntVector2_


//================================================================
class IntVector2
{
public:
	IntVector2();
	IntVector2(int x, int y);
	
	static IntVector2 ZERO;
	
	int x;
	int y;

};


#endif //!_IntVector2_