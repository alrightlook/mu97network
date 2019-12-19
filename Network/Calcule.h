#pragma once

namespace Network
{
	struct SmStruct
	{
		int AttackDamageMinRight;
		int AttackDamageMaxRight;
		int AttackDamageMinLeft;
		int AttackDamageMaxLeft;
		int AttackSpeed;
		int MagicSpeed;
		int SuccessfulBlocking;
		int Defense;
	};

	struct BkStruct
	{
		int AttackDamageMinRight;
		int AttackDamageMaxRight;
		int AttackDamageMinLeft;
		int AttackDamageMaxLeft;
		int AttackSpeed;
		int MagicSpeed;
		int SuccessfulBlocking;
		int Defense;
	};

	struct MeStruct
	{
		int AttackDamageMinRight[2];
		int AttackDamageMaxRight[2];
		int AttackDamageMinLeft[2];
		int AttackDamageMaxLeft[2];
		int AttackSpeed;
		int MagicSpeed;
		int SuccessfulBlocking;
		int Defense;
	};

	struct MgStruct
	{
		int AttackDamageMinRight[2];
		int AttackDamageMaxRight[2];
		int AttackDamageMinLeft[2];
		int AttackDamageMaxLeft[2];
		int AttackSpeed;
		int MagicSpeed;
		int SuccessfulBlocking;
		int Defense;
	};

	struct CalculeStruct
	{
		SmStruct SM;
		BkStruct BK;
		MeStruct ME;
		MgStruct MG;
	};

	class Calcule
	{
	public:
		static bool initComponents();
		static void initCharacter(DWORD dwIndex);
	
	public:
		static CalculeStruct Struct;
	};
}