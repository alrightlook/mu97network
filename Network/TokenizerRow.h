#pragma once

namespace Network
{
	class TokenizerRow
	{
	public:
		std::map<int, TokenizerField> Fields;
		int FieldCount;

	public:
		TokenizerRow();
		TokenizerRow(std::string strLine);
		TokenizerField& operator[](int FieldIndex);

	public:
		int GetField(int FieldIndex, int Default);
		std::string GetField(int FieldIndex, std::string Default);
		bool FieldExists(int FieldIndex);
	};
}