#include "Library.h"

namespace Network
{
	TokenizerRow::TokenizerRow()
	{
		this->FieldCount = 0;
	}

	TokenizerRow::TokenizerRow(std::string strLine)
	{
		this->FieldCount = 0;

		std::string sep1 = "\\";
		std::string sep2 = " \t";
		std::string sep3 = "\"";
		boost::escaped_list_separator<char> sep(sep1, sep2, sep3);
		boost::tokenizer<boost::escaped_list_separator<char> > tok(strLine, sep);

		for(boost::tokenizer<boost::escaped_list_separator<char> >::iterator it = tok.begin(); it != tok.end(); ++it)
		{
			if((*it == ""))
			{
				continue;
			}

			this->Fields[FieldCount++] = TokenizerField(std::string(*it));
		}
	}

	TokenizerField& TokenizerRow::operator[](int FieldIndex)
	{
		return this->Fields[FieldIndex];
	}

	std::string TokenizerRow::GetField(int FieldIndex, std::string Default)
	{
		if((!this->FieldExists(FieldIndex)))
		{
			return Default;
		}

		return this->Fields[FieldIndex].ToString();
	}

	int TokenizerRow::GetField(int FieldIndex, int Default)
	{
		if((!this->FieldExists(FieldIndex)))
		{
			return Default;
		}

		return this->Fields[FieldIndex].ToInteger();
	}

	bool TokenizerRow::FieldExists(int FieldIndex)
	{
		std::map<int, TokenizerField>::iterator it = this->Fields.find(FieldIndex);
		return (bool)(it != this->Fields.end());
	}
}