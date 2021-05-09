#pragma once

#include "cocos2d.h"
#include <string>

USING_NS_CC;

class BitOperator : public Node
{
public:
	BitOperator(void);
	~BitOperator(void);

	//≥ı ºªØ
	bool init(){ return true;}
	CREATE_FUNC(BitOperator);

	std::string WStrToUTF8(const std::wstring& src);
};

