#pragma once

#include "TokenizerField.h"
#include "TokenizerRow.h"
#include "TokenizerSection.h"

namespace Network
{
	class Tokenizer
	{
	public:
		std::map<int, TokenizerSection> Sections;
		bool Loaded;

	public:
		Tokenizer(std::string szFile);
		 TokenizerSection& operator[](int SectionIndex);

	public:
		bool SectionExists(int SectionIndex);
	};

	class TokenizerEx
	{
	public:
		std::map<int, TokenizerSection> Sections;
		bool Loaded;

	public:
		TokenizerEx(std::string szFile);
		TokenizerSection& operator[](int SectionIndex);

	public:
		bool SectionExists(int SectionIndex);
	};
}