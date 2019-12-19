#include "Library.h"

namespace Network
{
	SettingStruct Setting::Struct;

	bool Setting::initComponents()
	{
		if(!Calcule::initComponents())
		{
			return false;
		}
		else if(!Map::initComponents())
		{
			return false;
		}
		else if(!Drop::initComponents())
		{
			return false;
		}
		else
		{
			BYTE btTemp;
			DWORD dwTemp, dwLoop;
	
			btTemp = (BYTE)GetPrivateProfileInt("Fix", "Pk", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x45508A) = 0x90;
				*(BYTE*)(0x45508B) = 0x90;
				*(BYTE*)(0x45508C) = 0x90;
				*(BYTE*)(0x45508D) = 0x90;
				*(BYTE*)(0x45508E) = 0x90;
				*(BYTE*)(0x4550AF) = 0x90;
				*(BYTE*)(0x4550B0) = 0x90;
				*(BYTE*)(0x4550B1) = 0x90;
				*(BYTE*)(0x4550B2) = 0x90;
				*(BYTE*)(0x4550B3) = 0x90;

				*(BYTE*)(0x4642A4) = 0x9C;
				*(BYTE*)(0x4642B0) = 0x9C;
				*(BYTE*)(0x4643C0) = 0x9C;
				*(BYTE*)(0x4643CC) = 0x9C;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "Potion", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x4119FE) = 0x90;
				*(BYTE*)(0x4119FF) = 0x90;
				*(BYTE*)(0x411A00) = 0x90;
				*(BYTE*)(0x411A01) = 0x90;
				*(BYTE*)(0x411A02) = 0x90;
				*(BYTE*)(0x411A03) = 0x90;
				*(BYTE*)(0x411A04) = 0x90;
				*(BYTE*)(0x411A05) = 0x90;
				*(BYTE*)(0x411A06) = 0x90;
				*(BYTE*)(0x411A07) = 0x90;
				*(BYTE*)(0x45BD58) = 0x90;
				*(BYTE*)(0x45BD59) = 0x90;
				*(BYTE*)(0x45BD5A) = 0x90;
				*(BYTE*)(0x45BD5B) = 0x90;
				*(BYTE*)(0x45BD5C) = 0x90;
				*(BYTE*)(0x45BD5D) = 0x90;
				*(BYTE*)(0x45BE0E) = 0x90;
				*(BYTE*)(0x45BE0F) = 0x90;
				*(BYTE*)(0x45BE10) = 0x90;
				*(BYTE*)(0x45BE11) = 0x90;
				*(BYTE*)(0x45BE12) = 0x90;
				*(BYTE*)(0x45BE13) = 0x90;
				*(BYTE*)(0x45BE14) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "PersonalID", 1, ".\\Network\\Setting.ut");	
			if(btTemp == 1)
			{
				*(BYTE*)(0x417781) = 0xEB;
				*(BYTE*)(0x420D2A) = 0x90;
				*(BYTE*)(0x420D2B) = 0x90;
				*(BYTE*)(0x420DEB) = 0x90;
				*(BYTE*)(0x420DEC) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "PartyZen", 1, ".\\Network\\Setting.ut");	
			if(btTemp == 1)
			{
				BYTE btParty[57] = {0x8B, 0x4D, 0x0C, 0x33, 0xC0, 0x8A, 0x41, 0x64, 0x83, 0xF8, 0x02, 0x74, 0x05, 0x83, 0xF8, 0x03, 0x75, 0x20, 0x8B, 
									0x91, 0xB4, 0x00, 0x00, 0x00, 0x89, 0x55, 0xF8, 0xDB, 0x45, 0xF8, 0xD8, 0x0D, 0xC8, 0x18, 0x6E, 0x00, 0xE8, 0x1C, 
									0x55, 0x0B, 0x00, 0x8B, 0x4D, 0x0C, 0x89, 0x81, 0xB4, 0x00, 0x00, 0x00, 0x5F, 0x5E, 0x5B, 0x8B, 0xE5, 0x5D, 0xC3};
				memcpy((int*)0x4E3437, btParty, sizeof(btParty));
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "Webzen", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x45D33A) = 0x01;
				*(BYTE*)(0x45D37B) = 0x01;
				*(BYTE*)(0x45D3E3) = 0x01;
			}
	
			btTemp = (BYTE)GetPrivateProfileInt("Fix", "AlreadyRunning", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x48F766) = 0xEB;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "NoStandBy", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x462C07) = 0x90;
				*(BYTE*)(0x462C08) = 0x90;
				*(BYTE*)(0x462C09) = 0x90;
				*(BYTE*)(0x462C0A) = 0x90;
				*(BYTE*)(0x462C0B) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "SocketSerial", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x414239) = 0xEB;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "DestroyGIocp", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x40165E) = 0xC3;
				*(BYTE*)(0x40165F) = 0x90;
				*(BYTE*)(0x401660) = 0x90;
				*(BYTE*)(0x401661) = 0x90;
				*(BYTE*)(0x401652) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "InvalidSocket", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x440EF8) = 0x90;
				*(BYTE*)(0x440EF9) = 0x90;
				*(BYTE*)(0x440F23) = 0xEB;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "ProtocolError", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				for(btTemp = 0; btTemp < 27; btTemp++)
				{
					*(BYTE*)(0x426EA1 + btTemp) = 0x90;
				}
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "HackReporting", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x41529B) = 0x90;
				*(BYTE*)(0x41529C) = 0x90;
				*(BYTE*)(0x4152B6) = 0xE9;
				*(BYTE*)(0x4152B7) = 0xC2;
				*(BYTE*)(0x4152B8) = 0x00;
				*(BYTE*)(0x4152B9) = 0x00;
				*(BYTE*)(0x4152BA) = 0x00;
				*(BYTE*)(0x4152BB) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Fix", "ErrorL2Index", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x44029B) = 0x90;
				*(BYTE*)(0x44029C) = 0x90;
				*(BYTE*)(0x44029D) = 0x90;
				*(BYTE*)(0x44029E) = 0x90;
				*(BYTE*)(0x44029F) = 0x90;
				*(BYTE*)(0x4402A0) = 0x90;
			}

			btTemp = (BYTE)GetPrivateProfileInt("Server", "Type", 0, ".\\Network\\Setting.ut");
			Struct.Type = btTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Server", "Quantity", 0, ".\\Network\\Setting.ut");
			Struct.Quantity = dwTemp;

			btTemp = (BYTE)GetPrivateProfileInt("Game", "CheckSum", 1, ".\\Network\\Setting.ut");
			if(btTemp == 1)
			{
				*(BYTE*)(0x415653) = 0x74;
			}
			else
			{
				*(BYTE*)(0x415653) = 0xEB;
			}

			dwTemp = (DWORD)GetPrivateProfileInt("Game", "PortUdp", 60006, ".\\Network\\Setting.ut");
			*(DWORD*)(0x48A099) = dwTemp;

			btTemp = (BYTE)GetPrivateProfileInt("Game", "NonPk", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x48C587) = btTemp;
			*(BYTE*)(0x48C784) = btTemp;
			*(BYTE*)(0x48C981) = btTemp;
			*(BYTE*)(0x48CA99) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("Game", "AutoAnnounce", 0, ".\\Network\\Setting.ut");
			Struct.Announce = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("Game", "WelcomeMessage", 0, ".\\Network\\Setting.ut");
			Struct.Welcome = btTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Max", "Level", 1000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x459BA5) = dwTemp;
			*(DWORD*)(0x462A35) = dwTemp;
			*(DWORD*)(0x48A2AA) = dwTemp;
			*(DWORD*)(0x496D94) = dwTemp;
			if(dwTemp > 350)
			{
				*(BYTE*)(0x48A2C0) = 0x01;
				*(BYTE*)(0x48A2E4) = 0x02;
				*(BYTE*)(0x48A2E5) = 0x00;
			}

			dwTemp = (DWORD)GetPrivateProfileInt("Max", "Player", 250, ".\\Network\\Setting.ut");
			*(DWORD*)(0x5133E8) = dwTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Max", "ZenInventory", 2100000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x41E40F) = dwTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Max", "ZenWarehouse", 2100000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x422DA4) = dwTemp;
			*(DWORD*)(0x422E9A) = dwTemp;
			*(DWORD*)(0x422DCF) = dwTemp;

			btTemp = (BYTE)GetPrivateProfileInt("Max", "Status", 0, ".\\Network\\Setting.ut");
			Struct.Status = btTemp;
			if(btTemp == 1)
			{
				*(BYTE*)(0x42856F) = 0xB7;
				*(BYTE*)(0x45C07E) = 0xB7;
				*(BYTE*)(0x45C10D) = 0xB7;
				*(BYTE*)(0x45C19C) = 0xB7;
				*(BYTE*)(0x45C22B) = 0xB7;
				*(BYTE*)(0x452027) = 0xB7;
				*(BYTE*)(0x45204E) = 0xB7;
				*(BYTE*)(0x452076) = 0xB7;
				*(BYTE*)(0x45209D) = 0xB7;
				*(BYTE*)(0x4520D0) = 0xB7;
				*(BYTE*)(0x4520EB) = 0xB7;
				*(BYTE*)(0x452107) = 0xB7;
				*(BYTE*)(0x452122) = 0xB7;
				*(BYTE*)(0x452153) = 0xB7;
				*(BYTE*)(0x45216E) = 0xB7;
				*(BYTE*)(0x45218A) = 0xB7;
				*(BYTE*)(0x4521A5) = 0xB7;
				*(BYTE*)(0x4521C3) = 0xB7;
				*(BYTE*)(0x4521DF) = 0xB7;
				*(BYTE*)(0x4521FC) = 0xB7;
				*(BYTE*)(0x452217) = 0xB7;
				*(BYTE*)(0x45257A) = 0xB7;
				*(BYTE*)(0x45537A) = 0xB7;
				*(BYTE*)(0x456250) = 0xB7;
				*(BYTE*)(0x45CC74) = 0xB7;
				*(BYTE*)(0x46AE75) = 0xB7;
				*(BYTE*)(0x47D334) = 0xB7;
				*(BYTE*)(0x47D50E) = 0xB7;
				*(BYTE*)(0x47D69E) = 0xB7;
				*(BYTE*)(0x4285B9) = 0xB7;
				*(BYTE*)(0x45C09A) = 0xB7;
				*(BYTE*)(0x45C129) = 0xB7;
				*(BYTE*)(0x45C1B8) = 0xB7;
				*(BYTE*)(0x45C247) = 0xB7;
				*(BYTE*)(0x451F96) = 0xB7;
				*(BYTE*)(0x451FB1) = 0xB7;
				*(BYTE*)(0x451FCD) = 0xB7;
				*(BYTE*)(0x451FE8) = 0xB7;
				*(BYTE*)(0x45201D) = 0xB7;
				*(BYTE*)(0x452044) = 0xB7;
				*(BYTE*)(0x45206C) = 0xB7;
				*(BYTE*)(0x452093) = 0xB7;
				*(BYTE*)(0x452584) = 0xB7;
				*(BYTE*)(0x4525D7) = 0xB7;
				*(BYTE*)(0x4525F1) = 0xB7;
				*(BYTE*)(0x452631) = 0xB7;
				*(BYTE*)(0x45264C) = 0xB7;
				*(BYTE*)(0x452669) = 0xB7;
				*(BYTE*)(0x452684) = 0xB7;
				*(BYTE*)(0x452998) = 0xB7;
				*(BYTE*)(0x4529B6) = 0xB7;
				*(BYTE*)(0x452CA9) = 0xB7;
				*(BYTE*)(0x452CD6) = 0xB7;
				*(BYTE*)(0x452CF3) = 0xB7;
				*(BYTE*)(0x455366) = 0xB7;
				*(BYTE*)(0x458772) = 0xB7;
				*(BYTE*)(0x45CC7E) = 0xB7;
				*(BYTE*)(0x46AE93) = 0xB7;
				*(BYTE*)(0x47D33E) = 0xB7;
				*(BYTE*)(0x47D518) = 0xB7;
				*(BYTE*)(0x47D6A8) = 0xB7;
				*(BYTE*)(0x45C0B8) = 0xB7;
				*(BYTE*)(0x45C147) = 0xB7;
				*(BYTE*)(0x45C1D6) = 0xB7;
				*(BYTE*)(0x45C265) = 0xB7;
				*(BYTE*)(0x4583A9) = 0xB7;
				*(BYTE*)(0x45CC8A) = 0xB7;
				*(BYTE*)(0x45CD8F) = 0xB7;
				*(BYTE*)(0x47D34A) = 0xB7;
				*(BYTE*)(0x47D524) = 0xB7;
				*(BYTE*)(0x47D6B4) = 0xB7;
				*(BYTE*)(0x47DF1A) = 0xB7;
				*(BYTE*)(0x47DF3D) = 0xB7;
				*(BYTE*)(0x47DF60) = 0xB7;
				*(BYTE*)(0x47DF83) = 0xB7;
				*(BYTE*)(0x45C0D6) = 0xB7;
				*(BYTE*)(0x45C165) = 0xB7;
				*(BYTE*)(0x45C1F4) = 0xB7;
				*(BYTE*)(0x45C283) = 0xB7;
				*(BYTE*)(0x4524C3) = 0xB7;
				*(BYTE*)(0x4524DE) = 0xB7;
				*(BYTE*)(0x455B37) = 0xB7;
				*(BYTE*)(0x455B61) = 0xB7;
				*(BYTE*)(0x455BB6) = 0xB7;
				*(BYTE*)(0x455BE0) = 0xB7;
				*(BYTE*)(0x455C32) = 0xB7;
				*(BYTE*)(0x455C5C) = 0xB7;
				*(BYTE*)(0x455CA3) = 0xB7;
				*(BYTE*)(0x455CCD) = 0xB7;
				*(BYTE*)(0x455CFA) = 0xB7;
				*(BYTE*)(0x455D24) = 0xB7;
				*(BYTE*)(0x455D64) = 0xB7;
				*(BYTE*)(0x4583BD) = 0xB7;
				*(BYTE*)(0x4583DB) = 0xB7;
				*(BYTE*)(0x458786) = 0xB7;
				*(BYTE*)(0x4587A5) = 0xB7;
				*(BYTE*)(0x4588CE) = 0xB7;
				*(BYTE*)(0x458A5F) = 0xB7;
				*(BYTE*)(0x458EC9) = 0xB7;
				*(BYTE*)(0x45CC96) = 0xB7;
				*(BYTE*)(0x45CE49) = 0xB7;
				*(BYTE*)(0x4790F6) = 0xB7;
				*(BYTE*)(0x479512) = 0xB7;
				*(BYTE*)(0x47D356) = 0xB7;
				*(BYTE*)(0x47D530) = 0xB7;
				*(BYTE*)(0x47D6C0) = 0xB7;
			}
	
			btTemp = (BYTE)GetPrivateProfileInt("LevelUpPoint", "All", 5, ".\\Network\\Setting.ut");
			*(BYTE*)(0x462AF7) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("LevelUpPoint", "MG", 7, ".\\Network\\Setting.ut");
			*(BYTE*)(0x462B0E) = btTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Party", "LevelDifference", 130, ".\\Network\\Setting.ut");
			*(DWORD*)(0x41ECCD) = dwTemp;
			*(DWORD*)(0x41EDB0) = dwTemp;
			*(DWORD*)(0x41EED8) = dwTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("Party", "RateExp2Players", 200, ".\\Network\\Setting.ut");
			*(DWORD*)(0x467E3F) = dwTemp;
			*(DWORD*)(0x467E06) = (dwTemp + 40);

			dwTemp = (DWORD)GetPrivateProfileInt("Party", "RateExp3Players", 230, ".\\Network\\Setting.ut");
			*(DWORD*)(0x467E18) = dwTemp;
			*(DWORD*)(0x467DE2) = (dwTemp + 50);

			dwTemp = (DWORD)GetPrivateProfileInt("Party", "RateExp4Players", 260, ".\\Network\\Setting.ut");
			*(DWORD*)(0x467E27) = dwTemp;
			*(DWORD*)(0x467DF1) = (dwTemp + 60);

			dwTemp = (DWORD)GetPrivateProfileInt("Party", "RateExp5Players", 290, ".\\Network\\Setting.ut");
			*(DWORD*)(0x467E36) = dwTemp;
			*(DWORD*)(0x467E00) = (dwTemp + 70);

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Index", 15, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B1F9) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Group", 12, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B1FB) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Excellent", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B208) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Option", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B20E) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Luck", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B210) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Skill", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B212) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("BloodCastle", "Level", 0, ".\\Network\\Setting.ut");
			*(BYTE*)(0x49B216) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("ChaosMachine", "MixItem10", 100, ".\\Network\\Setting.ut");
			*(BYTE*)(0x44926D) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("ChaosMachine", "MixItem11", 100, ".\\Network\\Setting.ut");
			*(BYTE*)(0x44927C) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("ChaosMachine", "MixWingMin", 100, ".\\Network\\Setting.ut");
			*(BYTE*)(0x44A27A) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("ChaosMachine", "MixWingMax", 100, ".\\Network\\Setting.ut");
			*(BYTE*)(0x44A286) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("JewelRate", "Life", 0, ".\\Network\\Setting.ut");
			for(dwTemp = 0, dwLoop = 100; dwTemp < 101; dwTemp++, dwLoop--)
			{
				if((BYTE)dwTemp == btTemp)
				{
					btTemp = (BYTE)dwLoop;
					break;
				}
			}
			*(BYTE*)(0x47A67B) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("JewelRate", "Soul", 0, ".\\Network\\Setting.ut");
			for(dwTemp = 0, dwLoop = 100; dwTemp < 101; dwTemp++, dwLoop--)
			{
				if((BYTE)dwTemp == btTemp)
				{
					btTemp = (BYTE)dwLoop;
					break;
				}
			}
			*(BYTE*)(0x47A06C) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("JewelRate", "SoulLuck", 100, ".\\Network\\Setting.ut");
			*(BYTE*)(0x479F8D) = btTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Bless", 9000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x480021) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Soul", 6000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x48003B) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Chaos", 810000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x480056) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Life", 45000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x480071) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Creation", 36000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x48008B) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Dinorant", 960000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x4800DB) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "Fruit", 3000000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x4800A6) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("JewelPrice", "BlueFeather", 180000, ".\\Network\\Setting.ut");
			*(DWORD*)(0x4800C1) = dwTemp;

			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "Apple", 10, ".\\Network\\Setting.ut");
			*(BYTE*)(0x427E37) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "SmallHP", 20, ".\\Network\\Setting.ut");
			*(BYTE*)(0x427E60) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "MediumHP", 30, ".\\Network\\Setting.ut");
			*(BYTE*)(0x427E89) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "LargeHP", 40, ".\\Network\\Setting.ut");
			*(BYTE*)(0x427EB2) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "SmallMP", 20, ".\\Network\\Setting.ut");
			*(BYTE*)(0x428008) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "MediumMP", 30, ".\\Network\\Setting.ut");
			*(BYTE*)(0x428047) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("PotionRate", "LargeMP", 40, ".\\Network\\Setting.ut");
			*(BYTE*)(0x428086) = btTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "BudgeDragon", 2, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458C9B) = dwTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "Giant", 7, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458CA4) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "SkeletonWarrior", 14, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458CAD) = dwTemp;

			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "PoisonBull", 8, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458CB6) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "ThunderLich", 9, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458CBF) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("RingTransform", "DeathCow", 41, ".\\Network\\Setting.ut");
			*(DWORD*)(0x458CC8) = dwTemp;

			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "Goblin", 26, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457E40) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "StoneGolem", 32, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457E71) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "Assassin", 21, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457EA2) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "EliteYeti", 20, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457ED3) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "DarkKnight", 10, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457F04) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "Bali", 150, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457F35) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("OrbSummon", "Soldier",	151, ".\\Network\\Setting.ut");
			*(BYTE*)(0x457F66) = btTemp;

			btTemp = (BYTE)GetPrivateProfileInt("ManaShield", "PercentStart", 30, ".\\Network\\Setting.ut");
			*(BYTE*)(0x458797) = btTemp;
	
			btTemp = (BYTE)GetPrivateProfileInt("ManaShield", "Duration", 30, ".\\Network\\Setting.ut");
			*(BYTE*)(0x4587B5) = btTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("ManaShield", "AdditionalAgility", 6800, ".\\Network\\Setting.ut");
			*(DWORD*)(0x45877A) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("ManaShield", "AdditionalEnergy", 6800, ".\\Network\\Setting.ut");
			*(DWORD*)(0x45878E) = dwTemp;
	
			dwTemp = (DWORD)GetPrivateProfileInt("ManaShield", "AdditionalEnergyEx", 6800, ".\\Network\\Setting.ut");
			*(DWORD*)(0x4587AD) = dwTemp;

			*(BYTE*)(0x45AC79) = 0x01;
		}

		return true;
	}

	void Setting::joinServer(PMSG_IDPASS* lpMsg, DWORD dwIndex)
	{
		BYTE btBux[3] = {0xFC, 0xCF, 0xAB};
		char szID[11];
		
		memset(&szID[0], 0x00, 11);
		memcpy_s(szID, 10, lpMsg->Id, sizeof(lpMsg->Id));
	
		for(int i = 0; i < 10; i++)
		{
			szID[i] ^= btBux[(i % 3)];
		}

		WORD szIndex = (WORD)(dwIndex - 4800);

		Connect::executeQuery(Query::Vip, szID);
		Player[szIndex].Vip = (unsigned char)Connect::getInteger(1);

		Player[szIndex].Post = true;
		Player[szIndex].Reset = 0;

		Disconnect::Check[szIndex].Send = true;
		Disconnect::Check[szIndex].Timer = 0;
		Disconnect::Check[szIndex].Count = 0;

		if(Setting::Struct.Type > 0)
		{
			bool szProceed = true;
		
			switch(Setting::Struct.Type)
			{
			case 1:
				{
					std::string szCharacter[5];
					unsigned int szReset = 0;

					Connect::executeQuery(Query::Data[0], szID);
					szCharacter[0] = Connect::getString(1);
					szCharacter[1] = Connect::ArrayValues[1];
					szCharacter[2] = Connect::ArrayValues[2];
					szCharacter[3] = Connect::ArrayValues[3];
					szCharacter[4] = Connect::ArrayValues[4];
					Connect::getString((-1));

					for(int i = 0; i < 5; i++)
					{
						if(!szCharacter[i].empty() && szCharacter[i].length() > 1)
						{
							Connect::executeQuery(Query::Data[1], szCharacter[i].c_str());
							szReset = (unsigned int)Connect::getInteger(1);

							if(szReset > (unsigned int)Setting::Struct.Quantity)
							{
								szProceed = false;
								break;
							}
						}
					}
				}break;
			case 2:
				{
					if(Player[szIndex].Vip < (unsigned char)Setting::Struct.Quantity)
					{
						szProceed = false;
					}
				}break;
			}

			if(!szProceed)
			{
				ServerJoinResult(0x09, dwIndex);
				return;
			}
		}
	
		ServerJoinIdPass(lpMsg, dwIndex);
	}

	void Setting::addPoints(PMSG_LVPOINTADD* lpMsg, DWORD dwIndex)
	{
		bool szProceed = true;
		WORD wdPoints = (Setting::Struct.Status == 1) ? 65534 : 32766;

		switch(lpMsg->Type)
		{
		case 0:
			{
				if(Object[dwIndex].Strength >= (wdPoints + 1))
				{
					szProceed = false;
				}
			}break;
		case 1:
			{
				if(Object[dwIndex].Agility >= (wdPoints + 1))
				{
					szProceed = false;
				}
			}break;
		case 2:
			{
				if(Object[dwIndex].Vitality >= (wdPoints + 1))
				{
					szProceed = false;
				}
			}break;
		case 3:
			{
				if(Object[dwIndex].Energy >= (wdPoints + 1))
				{
					szProceed = false;
				}
			}break;
		}

		if(!szProceed)
		{
			ServerMessageSend((char*)Message::Add[2].c_str(), dwIndex, 1);
			return;
		}

		ServerLevelUpPointAdd(lpMsg, dwIndex);
	}
}