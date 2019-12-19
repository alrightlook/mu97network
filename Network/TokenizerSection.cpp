#include "Library.h"

namespace Network
{
	TokenizerSection::TokenizerSection()
	{
		this->Rows.clear();
		this->RowCount = 0;
	}

	TokenizerRow& TokenizerSection::operator[](int RowIndex)
	{
		return this->Rows[RowIndex];
	}

	bool TokenizerSection::RowExists(int RowIndex)
	{
		std::map<int, TokenizerRow>::iterator it = this->Rows.find(RowIndex);
		return (bool)(it != this->Rows.end());
	}
}