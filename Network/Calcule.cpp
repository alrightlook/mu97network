#include "Library.h"

namespace Network
{
	CalculeStruct Calcule::Struct;

	bool Calcule::initComponents()
	{
		Tokenizer _calcule(".\\Network\\Calcule\\Character.ut");

		if(_calcule.Loaded)
		{
			if(!_calcule.SectionExists(0))
			{
				return false;
			}
			else if(!_calcule.SectionExists(1))
			{
				return false;
			}
			else if(!_calcule.SectionExists(2))
			{
				return false;
			}
			else if(!_calcule.SectionExists(3))
			{
				return false;
			}
			else
			{
				Struct.SM.AttackDamageMinRight		= _calcule[0][0][0].ToInteger();
				Struct.SM.AttackDamageMaxRight		= _calcule[0][0][1].ToInteger();
				Struct.SM.AttackDamageMinLeft		= _calcule[0][0][2].ToInteger();
				Struct.SM.AttackDamageMaxLeft		= _calcule[0][0][3].ToInteger();
				Struct.SM.AttackSpeed				= _calcule[0][0][4].ToInteger();
				Struct.SM.MagicSpeed				= _calcule[0][0][5].ToInteger();
				Struct.SM.SuccessfulBlocking		= _calcule[0][0][6].ToInteger();
				Struct.SM.Defense					= _calcule[0][0][7].ToInteger();

				Struct.BK.AttackDamageMinRight		= _calcule[1][0][0].ToInteger();
				Struct.BK.AttackDamageMaxRight		= _calcule[1][0][1].ToInteger();
				Struct.BK.AttackDamageMinLeft		= _calcule[1][0][2].ToInteger();
				Struct.BK.AttackDamageMaxLeft		= _calcule[1][0][3].ToInteger();
				Struct.BK.AttackSpeed				= _calcule[1][0][4].ToInteger();
				Struct.BK.MagicSpeed				= _calcule[1][0][5].ToInteger();
				Struct.BK.SuccessfulBlocking		= _calcule[1][0][6].ToInteger();
				Struct.BK.Defense					= _calcule[1][0][7].ToInteger();

				Struct.ME.AttackDamageMinRight[0]	= _calcule[2][0][0].ToInteger();
				Struct.ME.AttackDamageMaxRight[0]	= _calcule[2][0][1].ToInteger();
				Struct.ME.AttackDamageMinLeft[0]	= _calcule[2][0][2].ToInteger();
				Struct.ME.AttackDamageMaxLeft[0]	= _calcule[2][0][3].ToInteger();
				Struct.ME.AttackDamageMinRight[1]	= _calcule[2][0][4].ToInteger();
				Struct.ME.AttackDamageMaxRight[1]	= _calcule[2][0][5].ToInteger();
				Struct.ME.AttackDamageMinLeft[1]	= _calcule[2][0][6].ToInteger();
				Struct.ME.AttackDamageMaxLeft[1]	= _calcule[2][0][7].ToInteger();
				Struct.ME.AttackSpeed				= _calcule[2][0][8].ToInteger();
				Struct.ME.MagicSpeed				= _calcule[2][0][9].ToInteger();
				Struct.ME.SuccessfulBlocking		= _calcule[2][0][10].ToInteger();
				Struct.ME.Defense					= _calcule[2][0][11].ToInteger();

				Struct.MG.AttackDamageMinRight[0]	= _calcule[3][0][0].ToInteger();
				Struct.MG.AttackDamageMaxRight[0]	= _calcule[3][0][1].ToInteger();
				Struct.MG.AttackDamageMinLeft[0]	= _calcule[3][0][2].ToInteger();
				Struct.MG.AttackDamageMaxLeft[0]	= _calcule[3][0][3].ToInteger();
				Struct.MG.AttackDamageMinRight[1]	= _calcule[3][0][4].ToInteger();
				Struct.MG.AttackDamageMaxRight[1]	= _calcule[3][0][5].ToInteger();
				Struct.MG.AttackDamageMinLeft[1]	= _calcule[3][0][6].ToInteger();
				Struct.MG.AttackDamageMaxLeft[1]	= _calcule[3][0][7].ToInteger();
				Struct.MG.AttackSpeed				= _calcule[3][0][8].ToInteger();
				Struct.MG.MagicSpeed				= _calcule[3][0][9].ToInteger();
				Struct.MG.SuccessfulBlocking		= _calcule[3][0][10].ToInteger();
				Struct.MG.Defense					= _calcule[3][0][11].ToInteger();

				return true;
			}
		}

		return false;
	}

	void Calcule::initCharacter(DWORD dwIndex)
	{
		ITEMCLASS* Right  = &Object[dwIndex].pInventory[0];
		ITEMCLASS* Left   = &Object[dwIndex].pInventory[1];
		ITEMCLASS* Gloves = &Object[dwIndex].pInventory[5];
		ITEMCLASS* Amulet = &Object[dwIndex].pInventory[9];
		ITEMCLASS* Helper = &Object[dwIndex].pInventory[8];
		Object[dwIndex].HaveWeaponInHand = true;

		if(!Right->IsItem() && !Left->IsItem())
		{
			Object[dwIndex].HaveWeaponInHand = false;
		}
		else if(!Left->IsItem() && Right->m_Type == ITEMGET(4, 15))
		{
			Object[dwIndex].HaveWeaponInHand = false;
		}
		else if(!Right->IsItem())
		{
			if(Left->m_Type == ITEMGET(4, 7))
			{
				Object[dwIndex].HaveWeaponInHand = false;
			}
			else if((Left->m_Type / 32) == 6)
			{
				Object[dwIndex].HaveWeaponInHand = false;
			}
		}

		Object[dwIndex].AddLife = 0;
		Object[dwIndex].AddMana = 0;
		Object[dwIndex].MonsterDieGetMoney = 0;
		Object[dwIndex].MonsterDieGetLife = 0;
		Object[dwIndex].MonsterDieGetMana = 0;
		Object[dwIndex].DamageReflect = 0;
		Object[dwIndex].DamageMinus = 0;
		
		switch(Object[dwIndex].Class)
		{
		case 0:
			{
				Object[dwIndex].m_AttackDamageMinRight = (Object[dwIndex].Strength / Struct.SM.AttackDamageMinRight);
				Object[dwIndex].m_AttackDamageMaxRight = (Object[dwIndex].Strength / Struct.SM.AttackDamageMaxRight);
				Object[dwIndex].m_AttackDamageMinLeft = (Object[dwIndex].Strength / Struct.SM.AttackDamageMinLeft);
				Object[dwIndex].m_AttackDamageMaxLeft = (Object[dwIndex].Strength / Struct.SM.AttackDamageMaxLeft);
			}break;
		case 1:
			{
				Object[dwIndex].m_AttackDamageMinRight = (Object[dwIndex].Strength / Struct.BK.AttackDamageMinRight);
				Object[dwIndex].m_AttackDamageMaxRight = (Object[dwIndex].Strength / Struct.BK.AttackDamageMaxRight);
				Object[dwIndex].m_AttackDamageMinLeft = (Object[dwIndex].Strength / Struct.BK.AttackDamageMinLeft);
				Object[dwIndex].m_AttackDamageMaxLeft = (Object[dwIndex].Strength / Struct.BK.AttackDamageMaxLeft);
			}break;
		case 2:
			{
				Object[dwIndex].m_AttackDamageMinRight = (Object[dwIndex].Agility / Struct.ME.AttackDamageMinRight[1]) + (Object[dwIndex].Strength / Struct.ME.AttackDamageMinRight[0]);
				Object[dwIndex].m_AttackDamageMaxRight = (Object[dwIndex].Agility / Struct.ME.AttackDamageMaxRight[1]) + (Object[dwIndex].Strength / Struct.ME.AttackDamageMaxRight[0]);
				Object[dwIndex].m_AttackDamageMinLeft = (Object[dwIndex].Agility / Struct.ME.AttackDamageMinLeft[1]) + (Object[dwIndex].Strength / Struct.ME.AttackDamageMinLeft[0]);
				Object[dwIndex].m_AttackDamageMaxLeft = (Object[dwIndex].Agility / Struct.ME.AttackDamageMaxLeft[1]) + (Object[dwIndex].Strength / Struct.ME.AttackDamageMaxLeft[0]);
			}break;
		case 3:
			{
				Object[dwIndex].m_AttackDamageMinRight = (Object[dwIndex].Strength / Struct.MG.AttackDamageMinRight[0]) + (Object[dwIndex].Energy / Struct.MG.AttackDamageMinRight[1]);
				Object[dwIndex].m_AttackDamageMaxRight = (Object[dwIndex].Strength / Struct.MG.AttackDamageMaxRight[0]) + (Object[dwIndex].Energy / Struct.MG.AttackDamageMaxRight[1]);
				Object[dwIndex].m_AttackDamageMinLeft = (Object[dwIndex].Strength / Struct.MG.AttackDamageMinLeft[0]) + (Object[dwIndex].Energy / Struct.MG.AttackDamageMinLeft[1]);
				Object[dwIndex].m_AttackDamageMaxLeft = (Object[dwIndex].Strength / Struct.MG.AttackDamageMaxLeft[0]) + (Object[dwIndex].Energy / Struct.MG.AttackDamageMaxLeft[1]);
			}break;
		}

		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_AttackDamageMinRight, 80);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_AttackDamageMaxRight, 80);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_AttackDamageMinLeft, 80);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_AttackDamageMaxLeft, 80);
		
		if(Right->IsItem())
		{
			if(Right->m_Type >= ITEMGET(5, 0) && Right->m_Type <= ITEMGET(6, 0))
			{
				Object[dwIndex].m_AttackDamageMinRight += Right->m_DamageMin / 2;
				Object[dwIndex].m_AttackDamageMaxRight += Right->m_DamageMax / 2;
			}
			else
			{
				Object[dwIndex].m_AttackDamageMinRight += Right->m_DamageMin;
				Object[dwIndex].m_AttackDamageMaxRight += Right->m_DamageMax;
			}

			Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_AttackDamageMinRight, 80);
			Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_AttackDamageMaxRight, 80);
		}
		
		if(Left->IsItem())
		{
			Object[dwIndex].m_AttackDamageMinLeft += Left->m_DamageMin;
			Object[dwIndex].m_AttackDamageMaxLeft += Left->m_DamageMax;

			Object[dwIndex].pInventory[1].PlusSpecial(&Object[dwIndex].m_AttackDamageMinLeft, 80);
			Object[dwIndex].pInventory[1].PlusSpecial(&Object[dwIndex].m_AttackDamageMaxLeft, 80);
		}

		Object[dwIndex].m_CriticalDamage = 0;
		Object[dwIndex].m_ExcelentDamage = 0;
		Object[dwIndex].m_MagicDamageMin = Object[dwIndex].Energy / 9;
		Object[dwIndex].m_MagicDamageMax = Object[dwIndex].Energy / 4;

		Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[1].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[2].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[3].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[4].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[5].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[6].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_CriticalDamage, 84);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_MagicDamageMin, 81);
		Object[dwIndex].pInventory[7].PlusSpecial(&Object[dwIndex].m_MagicDamageMax, 81);

		if(Right->IsItem())
		{
			if(Object[dwIndex].pInventory[0].m_Type == ITEMGET(0, 31) || Object[dwIndex].pInventory[0].m_Type == ITEMGET(0, 21) ||  Object[dwIndex].pInventory[0].m_Type == ITEMGET(0, 23) || Object[dwIndex].pInventory[0].m_Type == ITEMGET(0, 25))
			{
				Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_MagicDamageMin, 80);
				Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_MagicDamageMax, 80);
			}
			else
			{
				Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_MagicDamageMin, 81);
				Object[dwIndex].pInventory[0].PlusSpecial(&Object[dwIndex].m_MagicDamageMax, 81);
			}
		}

		Object[dwIndex].m_AttackRating = (Object[dwIndex].Strength + Object[dwIndex].Agility) / 2;
		Object[dwIndex].m_AttackRating += Object[dwIndex].pInventory[5].ItemDefense();

		switch(Object[dwIndex].Class)
		{
		case 0:
			{
				Object[dwIndex].m_AttackSpeed = Object[dwIndex].Agility / Struct.SM.AttackSpeed;
				Object[dwIndex].m_MagicSpeed = Object[dwIndex].Agility / Struct.SM.MagicSpeed;
			}break;
		case 1:
			{
				Object[dwIndex].m_AttackSpeed = Object[dwIndex].Agility / Struct.BK.AttackSpeed;
				Object[dwIndex].m_MagicSpeed = Object[dwIndex].Agility / Struct.BK.MagicSpeed;
			}break;
		case 2:
			{
				Object[dwIndex].m_AttackSpeed = Object[dwIndex].Agility / Struct.ME.AttackSpeed;
				Object[dwIndex].m_MagicSpeed = Object[dwIndex].Agility / Struct.ME.MagicSpeed;		
			}break;
		case 3:
			{
				Object[dwIndex].m_AttackSpeed = Object[dwIndex].Agility / Struct.MG.AttackSpeed;
				Object[dwIndex].m_MagicSpeed = Object[dwIndex].Agility / Struct.MG.MagicSpeed;
			}break;
		}

		bool RightBoolean = false, LeftBoolean = false;

		if(Right->m_Type != ITEMGET(4, 7) && Right->m_Type != ITEMGET(4, 15) && Right->m_Type >= ITEMGET(0, 0) && Right->m_Type < ITEMGET(6, 0))
		{
			if(Right->IsItem())
			{
				RightBoolean = true;
			}
		}

		if(Left->m_Type != ITEMGET(4, 7) && Left->m_Type != ITEMGET(4, 15) && Left->m_Type >= ITEMGET(0, 0) && Left->m_Type < ITEMGET(6, 0))
		{
			if(Left->IsItem())
			{
				LeftBoolean = true;
			}
		}

		if(RightBoolean && LeftBoolean)
		{
			Object[dwIndex].m_AttackSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
			Object[dwIndex].m_MagicSpeed += (Right->m_AttackSpeed + Left->m_AttackSpeed) / 2;
		}
		else if(RightBoolean)
		{
			Object[dwIndex].m_AttackSpeed += Right->m_AttackSpeed;
			Object[dwIndex].m_MagicSpeed += Right->m_AttackSpeed;
		}
		else if(LeftBoolean)
		{
			Object[dwIndex].m_AttackSpeed += Left->m_AttackSpeed;
			Object[dwIndex].m_MagicSpeed += Left->m_AttackSpeed;
		}

		if(Gloves->IsItem())
		{
			Object[dwIndex].m_AttackSpeed += Gloves->m_AttackSpeed;
			Object[dwIndex].m_MagicSpeed += Gloves->m_AttackSpeed;
		}

		if(Helper->IsItem())
		{
			Object[dwIndex].m_AttackSpeed += Helper->m_AttackSpeed;
			Object[dwIndex].m_MagicSpeed += Helper->m_AttackSpeed;
		}

		if(Amulet->IsItem())
		{
			Object[dwIndex].m_AttackSpeed += Amulet->m_AttackSpeed;
			Object[dwIndex].m_MagicSpeed += Amulet->m_AttackSpeed;
		}

		DWORD dwAttackSpeed = *(DWORD*)(ServerAttackSpeed);
		int szMinimumSpeed = *(int*)(ServerMinimumSpeed);
		float szDecTimeAttack = *(float*)(ServerDecTimeSpeed);

		if(Object[dwIndex].Class == 0)
		{
			Object[dwIndex].m_DetectSpeedHackTime = (int)(dwAttackSpeed - ((Object[dwIndex].m_MagicSpeed * 2) * szDecTimeAttack));
		}
		else
		{
			Object[dwIndex].m_DetectSpeedHackTime = (int)(dwAttackSpeed - (Object[dwIndex].m_AttackSpeed * szDecTimeAttack));
		}

		if(Object[dwIndex].m_DetectSpeedHackTime < szMinimumSpeed)
		{
			Object[dwIndex].m_DetectSpeedHackTime = szMinimumSpeed;
		}
		
		switch(Object[dwIndex].Class)
		{
		case 0:
			{
				Object[dwIndex].m_SuccessfulBlocking = Object[dwIndex].Agility / Struct.SM.SuccessfulBlocking;
			}break;
		case 1:
			{
				Object[dwIndex].m_SuccessfulBlocking = Object[dwIndex].Agility / Struct.BK.SuccessfulBlocking;
			}break;
		case 2:
			{
				Object[dwIndex].m_SuccessfulBlocking = Object[dwIndex].Agility / Struct.ME.SuccessfulBlocking;
			}break;
		case 3:
			{
				Object[dwIndex].m_SuccessfulBlocking = Object[dwIndex].Agility / Struct.SM.SuccessfulBlocking;
			}break;
		}

		if(Left->IsItem())
		{
			Object[dwIndex].m_SuccessfulBlocking += Left->m_SuccessfulBlocking;
			Object[dwIndex].pInventory[1].PlusSpecial(&Object[dwIndex].m_SuccessfulBlocking, 82);
		}

		bool SuccessBoolean = true;

		switch(Object[dwIndex].Class)
		{
		case 3:
			{
				for(int i = 3; i <= 6; i++)
				{
					if(!Object[dwIndex].pInventory[i].IsItem())
					{
						SuccessBoolean = false;
						break;
					}
				}
			}break;
		default:
			{
				for(int i = 2; i <= 6; i++)
				{
					if(!Object[dwIndex].pInventory[i].IsItem())
					{
						SuccessBoolean = false;
						break;
					}
				}
			}break;
		}

		int LevelPlusCount[2] = {0};

		if(SuccessBoolean)
		{
			int in;

			switch(Object[dwIndex].Class)
			{
			case 3:
				{
					in = Object[dwIndex].pInventory[3].m_Type % 32;

					if(in != ITEMGET(0, 15) && in != ITEMGET(0, 20) && in != ITEMGET(0, 23) && in != ITEMGET(0, 33) && in != ITEMGET(0, 32) && in != ITEMGET(0, 37))
					{
						SuccessBoolean = false;
					}
					else
					{
						for(int i = 3; i <= 6; i++)
						{
							if(in != (Object[dwIndex].pInventory[i].m_Type % 32))
							{
								SuccessBoolean = false;
							}

							if(Object[dwIndex].pInventory[i].m_Level > 10)
							{
								LevelPlusCount[1]++;
							}
							else if(Object[dwIndex].pInventory[i].m_Level > 9)
							{
								LevelPlusCount[0]++;
							}
						}
					}
				}break;
			default:
				{
					in = Object[dwIndex].pInventory[2].m_Type % 32;

					for(int i = 2; i <= 6; i++)
					{
						if(in != (Object[dwIndex].pInventory[i].m_Type % 32))
						{
							SuccessBoolean = false;
						}
						
						if(Object[dwIndex].pInventory[i].m_Level > 10)
						{
							LevelPlusCount[1]++;
						}
						else if(Object[dwIndex].pInventory[i].m_Level > 9)
						{
							LevelPlusCount[0]++;
						}
					}
				}break;
			}

			if(SuccessBoolean)
			{
				Object[dwIndex].m_SuccessfulBlocking += Object[dwIndex].m_SuccessfulBlocking / 10;
			}
		}

		switch(Object[dwIndex].Class)
		{
		case 0:
			{
				Object[dwIndex].m_Defense = Object[dwIndex].Agility / Struct.SM.Defense;
			}break;
		case 1:
			{
				Object[dwIndex].m_Defense = Object[dwIndex].Agility / Struct.BK.Defense;
			}break;
		case 2:
			{
				Object[dwIndex].m_Defense = Object[dwIndex].Agility / Struct.ME.Defense;
			}break;
		case 3:
			{
				Object[dwIndex].m_Defense = Object[dwIndex].Agility / Struct.MG.Defense;
			}break;
		}
		
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[2].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[3].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[4].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[5].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[6].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[1].ItemDefense();
		Object[dwIndex].m_Defense += Object[dwIndex].pInventory[7].ItemDefense();
		
		if((LevelPlusCount[0] + LevelPlusCount[1]) >= 5)
		{
			if(SuccessBoolean)
			{
				if(LevelPlusCount[1] == 5)
				{
					Object[dwIndex].m_Defense += (Object[dwIndex].m_Defense * 10) / 100;
				}
				else //if(LevelPlusCount[0] == 5 || (LevelPlusCount[0] + LevelPlusCount[1]) == 5)
				{
					Object[dwIndex].m_Defense += (Object[dwIndex].m_Defense * 5) / 100;
				}
			}
		}

		Object[dwIndex].m_Defense = (Object[dwIndex].m_Defense * 10) / 20;

		/*if(Object[dwIndex].m_Change == 9)
		{
		}
		else if(Object[dwIndex].m_Change == 41)
		{
			Object[dwIndex].AddLife = ((int)(Object[dwIndex].LifeMax * 20.0f)) /100;
		}
		else if(Object[dwIndex].m_Change == 372)
		{
			Object[dwIndex].m_Defense += Object[dwIndex].m_Defense / 10;
			Object[dwIndex].AddLife += Object[dwIndex].Level;
		}
		else if(Object[dwIndex].m_Change == 374)
		{
			Object[dwIndex].m_AttackDamageMinRight += (Object[dwIndex].m_AttackDamageMinRight * 20) / 100;
			Object[dwIndex].m_AttackDamageMaxRight += (Object[dwIndex].m_AttackDamageMaxRight * 20) / 100;
			Object[dwIndex].m_AttackDamageMinLeft += (Object[dwIndex].m_AttackDamageMinLeft * 20) / 100;
			Object[dwIndex].m_AttackDamageMaxLeft += (Object[dwIndex].m_AttackDamageMaxLeft * 20) / 100;
			Object[dwIndex].m_MagicDamageMin += (Object[dwIndex].m_MagicDamageMin * 20) / 100;
			Object[dwIndex].m_MagicDamageMax += (Object[dwIndex].m_MagicDamageMax * 20) / 100;
		}*/
		
		if(Object[dwIndex].pInventory[8].m_Type == ITEMGET(13, 0))
		{
			Object[dwIndex].AddLife += 50;
		}

		int AddLife = 0, AddMana = 0;

		if(Object[dwIndex].pInventory[7].m_Type >= ITEMGET(12, 0) && Object[dwIndex].pInventory[7].m_Type <= ITEMGET(12, 6) || Object[dwIndex].pInventory[7].m_Type == ITEMGET(13, 30))
		{
			Object[dwIndex].pInventory[7].PlusSpecial(&AddLife, 100);
			Object[dwIndex].pInventory[7].PlusSpecial(&AddMana, 101);
			Object[dwIndex].AddLife += AddLife;
			Object[dwIndex].AddMana += AddMana;
		}

		if(Object[dwIndex].pInventory[8].m_Type == ITEMGET(13, 3))
		{
			Object[dwIndex].pInventory[8].PlusSpecial(&Object[dwIndex].AddBP, 103);
		}

		Object[dwIndex].pInventory[9].PlusSpecialPercentEx(&Object[dwIndex].AddBP, Object[dwIndex].MaxBP, 173);
		Object[dwIndex].pInventory[10].PlusSpecialPercentEx((int*)&Object[dwIndex].AddMana, (int)Object[dwIndex].ManaMax, 172);
		Object[dwIndex].pInventory[11].PlusSpecialPercentEx((int*)&Object[dwIndex].AddMana, (int)Object[dwIndex].ManaMax, 172);

		ServerNextExperience(&Object[dwIndex]);

		if(Left->m_Type >= ITEMGET(4, 0) && Left->m_Type < ITEMGET(4, 7) || Left->m_Type == ITEMGET(4, 17) || Left->m_Type == ITEMGET(4, 20) || Left->m_Type == ITEMGET(4, 21) || Left->m_Type == ITEMGET(4, 22))
		{
			if(Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 1)
			{
				Object[dwIndex].m_AttackDamageMinLeft += (WORD)((Object[dwIndex].m_AttackDamageMinLeft * 0.03f) + 1.0f);
				Object[dwIndex].m_AttackDamageMaxLeft += (WORD)((Object[dwIndex].m_AttackDamageMaxLeft * 0.03f) + 1.0f);
			}
			else if(Right->m_Type == ITEMGET(4, 15) && Right->m_Level == 2)
			{
				Object[dwIndex].m_AttackDamageMinLeft += (WORD)((Object[dwIndex].m_AttackDamageMinLeft * 0.05f) + 1.0f);
				Object[dwIndex].m_AttackDamageMaxLeft += (WORD)((Object[dwIndex].m_AttackDamageMaxLeft * 0.05f) + 1.0f);
			}
		}
		else if(Right->m_Type >= ITEMGET(4, 8) && Right->m_Type < ITEMGET(4, 15) || Right->m_Type >= ITEMGET(4, 16) && Right->m_Type < ITEMGET(5, 0))
		{
			if(Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 1)
			{
				Object[dwIndex].m_AttackDamageMinRight += (WORD)((Object[dwIndex].m_AttackDamageMinRight * 0.03f) + 1.0f);
				Object[dwIndex].m_AttackDamageMaxRight += (WORD)((Object[dwIndex].m_AttackDamageMaxRight * 0.03f) + 1.0f);
			}
			else if(Left->m_Type == ITEMGET(4, 7) && Left->m_Level == 2)
			{
				Object[dwIndex].m_AttackDamageMinRight += (WORD)((Object[dwIndex].m_AttackDamageMinRight * 0.05f) + 1.0f);
				Object[dwIndex].m_AttackDamageMaxRight += (WORD)((Object[dwIndex].m_AttackDamageMaxRight * 0.05f) + 1.0f);
			}
		}

		ServerReFillSend(Object[dwIndex].m_Index, (WORD)(Object[dwIndex].LifeMax + Object[dwIndex].AddLife), 0xFE, 0);
		ServerManaSend(Object[dwIndex].m_Index, (WORD)(Object[dwIndex].ManaMax + Object[dwIndex].AddMana), 0xFE, 0, (WORD)(Object[dwIndex].MaxBP + Object[dwIndex].AddBP));
	}
}