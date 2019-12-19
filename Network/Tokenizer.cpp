#include "Library.h"

namespace Network
{
	Tokenizer::Tokenizer(std::string szFile)
	{
		this->Loaded = false;
		std::fstream f(szFile.c_str(), std::ios::in);
	
		if(f.is_open() && f.good())
		{
			TokenizerSection sec = TokenizerSection();
			
			int CurrentSection = 0;
			int RowIndex = 0;
			bool SectionOpen = false;

			while(!f.eof())
			{
				char temp[4096];
				char* dump = NULL;
				std::string line = "";
				ZeroMemory(&temp[0], 4096);
				f.getline(&temp[0], 4095);
				line.assign(&temp[0]);
				dump = (char*)line.c_str();

				bool finishstart = false;
				bool finishend = false;

				while(true)
				{
					if(line.length() > 0)
					{
						if(line.at(0) == ' ' || line.at(0) == '\t')	
						{
							line.erase(0, 1);
						}
						else
						{
							if(finishend)
							{
								break;
							}

							finishstart = true;
						}
					}
					else
					{
						break;
					}

					if(line.length() > 0)
					{
						if(line.at((line.length() - 1)) == ' ' || line.at((line.length() - 1)) == '\t')
						{
							line.erase((line.length() - 1), 1);
						}
						else
						{
							if(finishstart)
							{
								break;
							}

							finishend = true;
						}
					}
					else
					{
						break;
					}
				}

				if(line.substr(0, 2) == "//" || line.substr(0, 1) == "#" || line.substr(0, 1) == ";" || line == "")	
				{
					continue;
				}

				TokenizerRow row(line);

				if(!SectionOpen)
				{
					if(row.FieldCount == 2)
					{
						if(row[1].ToString() == "{")
						{
							//MessageBox(0, "Abrindo seção", "Seção", MB_OK);
							CurrentSection = row[0].ToInteger();
							SectionOpen = true;
							RowIndex = 0;
						}
					}
				}
				else
				{
					if(row.FieldCount == 1)
					{
						if(row[0].ToString() == "}" && SectionOpen)
						{
							//MessageBox(0, "Fechando", "Seção", MB_OK);
							this->Sections[CurrentSection] = sec;
							sec = TokenizerSection();
							SectionOpen = false;
							continue;
						}
					}
					
					sec[RowIndex++] = row;
					sec.RowCount++;
				}
			}

			this->Loaded = true;
		}
	}

	TokenizerSection& Tokenizer::operator[](int SectionIndex)
	{
		return this->Sections[SectionIndex];
	}

	bool Tokenizer::SectionExists(int SectionIndex)
	{
		std::map<int, TokenizerSection>::iterator it = this->Sections.find(SectionIndex);
		return (bool)(this->Sections.end() != it);
	}

	TokenizerEx::TokenizerEx(std::string szFile)
	{
		this->Loaded = false;
		std::fstream f(szFile.c_str(), std::ios::in);
	
		if(f.is_open() && f.good())
		{
			TokenizerSection sec = TokenizerSection();
			
			int CurrentSection = 0;
			int RowIndex = 0;
			bool SectionOpen = false;

			while(!f.eof())
			{
				char temp[4096];
				char* dump = NULL;
				std::string line = "";
				ZeroMemory(&temp[0], 4096);
				f.getline(&temp[0], 4095);
				line.assign(&temp[0]);
				dump = (char*)line.c_str();

				bool finishstart = false;
				bool finishend = false;

				while(true)
				{
					if(line.length() > 0)
					{
						if(line.at(0) == ' ' || line.at(0) == '\t')	
						{
							line.erase(0, 1);
						}
						else
						{
							if(finishend)
							{
								break;
							}

							finishstart = true;
						}
					}
					else
					{
						break;
					}

					if(line.length() > 0)
					{
						if(line.at((line.length() - 1)) == ' ' || line.at((line.length() - 1)) == '\t')
						{
							line.erase((line.length() - 1), 1);
						}
						else
						{
							if(finishstart)
							{
								break;
							}

							finishend = true;
						}
					}
					else
					{
						break;
					}
				}

				if(line.substr(0, 2) == "//" || line.substr(0, 1) == "#" || line.substr(0, 1) == ";" || line == "")	
				{
					continue;
				}

				TokenizerRow row(line);

				if(!SectionOpen)
				{
					if(row.FieldCount == 1)
					{
						if(row[0].ToString().length() < 3)
						{
							//MessageBox(0, "Abrindo seção", "Seção", MB_OK);
							CurrentSection = row[0].ToInteger();
							SectionOpen = true;
							RowIndex = 0;
						}
					}
				}
				else
				{
					if(row.FieldCount == 1)
					{
						if(row[0].ToString() == "end" && SectionOpen)
						{
							//MessageBox(0, "Fechando", "Seção", MB_OK);
							this->Sections[CurrentSection] = sec;
							sec = TokenizerSection();
							SectionOpen = false;
							continue;
						}
					}
					
					sec[RowIndex++] = row;
					sec.RowCount++;
				}
			}

			this->Loaded = true;
		}
	}

	TokenizerSection& TokenizerEx::operator[](int SectionIndex)
	{
		return this->Sections[SectionIndex];
	}

	bool TokenizerEx::SectionExists(int SectionIndex)
	{
		std::map<int, TokenizerSection>::iterator it = this->Sections.find(SectionIndex);
		return (bool)(this->Sections.end() != it);
	}
}