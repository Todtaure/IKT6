#include "stdafx.h"

class CAppUtilImp
{
public:
	CAppUtilImp();
	CAppUtilImp(std::string str);
	~CAppUtilImp();

	std::string GetName();
	std::string MyAddString(std::string str1, std::string str2);

private:
	std::string _name;
};
