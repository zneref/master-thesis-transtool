#include "listelem.h"

	ListElem(char* name, int nBmp) : _name(name), _nBmp(nBmp) { };
	char* GetName() const
	{
		return _name;
	};
	int GetNumBmp() const
	{
		return _nBmp;
	};