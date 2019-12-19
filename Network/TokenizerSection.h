#pragma once

namespace Network
{
	class TokenizerSection
	{
	public:
		std::map<int, TokenizerRow> Rows;
		int RowCount;

	public:
		TokenizerSection();
		TokenizerRow& operator[](int RowIndex);

	public:
		bool RowExists(int RowIndex);
	};
}