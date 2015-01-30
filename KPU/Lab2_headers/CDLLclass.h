#pragma once
#include "stdafx.h"
#include "CAppUtil.h"

class CDLLclass
{
public:
	virtual bool Init(CAppUtil * pUtil) = 0;
	virtual bool Run() = 0;
	virtual void TearDown() = 0;
};
