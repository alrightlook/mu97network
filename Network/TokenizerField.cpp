#include "Library.h"

namespace Network
{
	TokenizerField::TokenizerField() 
	{
		this->Value = "";
	}

	TokenizerField::TokenizerField(std::string Val) 
	{
		this->Value = Val;
	}

	int	TokenizerField::ToInteger() 
	{
		return atoi(this->Value.c_str());
	}

	std::string TokenizerField::ToString() 
	{
		return this->Value;
	}
}