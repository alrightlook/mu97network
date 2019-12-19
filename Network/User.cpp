#include "Library.h"

namespace Network
{
	OBJECTSTRUCT Object[5800];
	PlayerStruct Player[1000];

	bool ITEMCLASS::IsItem()
	{
		if((int)this->m_Type == (-1))
		{
			return false;
		}

		return true;
	}

	void ITEMCLASS::PlusSpecial(int* Value, int Special)
	{
		if(!this->IsItem())
		{
			return;
		}

		if(this->m_Durability == 0.0f)
		{
			return;
		}

		for(int i = 0; i < this->m_SpecialNum; i++)
		{
			if(this->m_Special[i] == Special)
			{
				switch(Special)
				{
				case 82:
					{
						int Option = this->m_OptionAdditional * 5;
						Option -= (int)(Option * this->m_CurrentDurabilityState);
						*Value += Option;
					}break;
				case 84:
					{
						*Value += 4;
					}break;
				case 81:
				case 80:
				case 83:
					{
						int Option = this->m_OptionAdditional * 4;
						Option -= (int)(Option * this->m_CurrentDurabilityState);
						*Value += Option;
					}break;
				case 100:
				case 101:
					{
						int Option = (*Value + ((this->m_Level * 5) + 50));
						*Value += Option;
					}break;
				case 103:
					{
						*Value += 50;
					}break;
				case 105:
					{
						int Option = (*Value + ((this->m_Level * 5) + 10));
						*Value += Option;
					}break;
				default:
					{
						int Option = (*Value + (this->m_OptionAdditional * 4));
						*Value += Option;
					}break;
				}
			}
		}
	}

	void ITEMCLASS::PlusSpecialPercentEx(int* Value, int Source, int Special)
	{
		if(!this->IsItem())
		{
			return;
		}

		if(this->m_Durability == 0.0f)
		{
			return;
		}

		for(int i = 0; i < this->m_SpecialNum; i++)
		{
			if(this->m_Special[i] == Special)
			{
				int Option = (Source * this->m_OptionAdditional) / 100;
				Option -= (int)(Option * this->m_CurrentDurabilityState);
				*Value += Option;
			}
		}
	}

	int ITEMCLASS::ItemDefense()
	{
		if(!this->IsItem())
		{
			return 0;
		}
		else
		{
			int Defense = this->m_Defense;

			if(Defense < 0)
			{
				return 0;
			}
			else
			{
				this->PlusSpecial(&Defense, 83);
				return Defense;
			}
		}
	}
}