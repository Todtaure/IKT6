#include "stdafx.h"
#include "AppUtilImp.h"


CAppUtilImp::CAppUtilImp()
{
}

CAppUtilImp::CAppUtilImp(std::string name)
	:_name(name){}

CAppUtilImp::~CAppUtilImp()
{
}

std::string CAppUtilImp::GetName()
{
	return _name;
}

std::string CAppUtilImp::MyAddString(std::string str1, std::string str2)
{
	return str1 += str2;
}