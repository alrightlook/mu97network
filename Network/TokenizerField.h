#pragma once

namespace Network
{
	class TokenizerField
	{
	protected:
		std::string Value;

	public:
		TokenizerField();
		TokenizerField(std::string Val);

	public:
		int ToInteger();
		std::string ToString();
	};
}