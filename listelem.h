#include "vector"

class ClassListElem
{
public:
	ClassListElem(char* name, int nBmp) : _name(name), _nBmp(nBmp) { };
	char* GetClassName() const { return _name; };
	int GetNumBmp() const { return _nBmp; };
private:
	char* _name;
	int _nBmp;
};

typedef std::vector<ClassListElem*> ClassVec;

class SysListElem
{
public:
	SysListElem(char* sysName,ClassVec* pclassVec)  
			: _sysName(sysName), _pclassVec(pclassVec) { };
	char* GetSysName() const { return _sysName; };
	ClassVec* GetPtrClassVec() const { return _pclassVec; };
private:
	char* _sysName;
	ClassVec* _pclassVec;
};