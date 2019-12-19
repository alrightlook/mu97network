#pragma once

#include "Reset.h"
#include "Master.h"
#include "Marry.h"

namespace Network
{
	struct PostStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned char Color;
		unsigned long Delay;
		std::string Format;
		std::string String;
	};

	struct StatusStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct ZenStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct PointsStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct WebsiteStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct OnlineStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct DataStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
		std::string Day[7];
		std::string Month[12];
	};

	struct AddStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct ReAddStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct SelectStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct WarehouseStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct EvoStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct ClassStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct RepairStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct ClearStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
	};

	struct NameStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned long Delay;
		std::string String;
		std::string Pattern;
	};

	struct MoveStruct
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned int Price;
		unsigned long Reset;
		unsigned char Vip;
		unsigned char GM;
		unsigned char PK;
		unsigned char Map;
		unsigned char X;
		unsigned char Y;
		std::string String;
	};

	struct ReloadStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		unsigned long Index;
		std::string String;
	};
	
	struct BlockStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		std::string String;
	};

	struct TeleportStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		std::string String;
	};

	struct SkinStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		std::string String;
	};

	struct FireworkStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		std::string String;
	};

	struct SetStruct
	{
		unsigned char Enable;
		unsigned long Delay;
		std::string String[2];
	};

	struct CommandStruct
	{
		PostStruct Post;
		StatusStruct Status;
		ZenStruct Zen;
		PointsStruct Points;
		WebsiteStruct Website;
		OnlineStruct Online;
		DataStruct Data;
		AddStruct Add;
		ReAddStruct ReAdd;
		SelectStruct Select;
		WarehouseStruct Warehouse;
		EvoStruct Evo;
		ClassStruct Class;
		RepairStruct Repair;
		ClearStruct Clear;
		NameStruct Name;
		MoveStruct Move[100];
		ReloadStruct Reload;
		BlockStruct Block;
		TeleportStruct Teleport;
		SkinStruct Skin;
		FireworkStruct Firework;
		SetStruct Set;
	};

	class Command
	{
	public:
		static bool initComponents();
		static bool initGuild(DWORD dwIndex, std::string szMsg);
		static void initPost(DWORD dwIndex, std::string szMsg);
		static void initStatus(DWORD dwIndex);
		static void initNpcStatus(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc);
		static void initZen(DWORD dwIndex, std::string szMsg);
		static void initPoints(DWORD dwIndex);
		static void initWebsite(DWORD dwIndex);
		static void initOnline(DWORD dwIndex);
		static void initData(DWORD dwIndex);
		static void initAdd(DWORD dwIndex, std::string szMsg, BYTE btStatus);
		static void initReAdd(DWORD dwIndex);
		static void initSelect(DWORD dwIndex, BYTE btSelect);
		static void initWarehouse(DWORD dwIndex, std::string szMsg);
		static void initEvo(DWORD dwIndex);
		static void initClass(DWORD dwIndex, std::string szMsg);
		static void initRepair(DWORD dwIndex, BYTE btLocal);
		static void initClear(DWORD dwIndex, std::string szMsg, BYTE btLocal);
		static void initName(DWORD dwIndex, std::string szMsg);
		static void initMove(DWORD dwIndex, BYTE btMove);
		static void initReload(DWORD dwIndex);
		static void initThreadReload(LPVOID lpParam);
		static void initBlock(DWORD dwIndex, std::string szMsg, BYTE btBlock);
		static void initUnlock(DWORD dwIndex, std::string szMsg, BYTE btUnlock);
		static void initTeleport(DWORD dwIndex, std::string szMsg, BYTE btTeleport);
		static void initSkin(DWORD dwIndex, std::string szMsg);
		static void initFirework(DWORD dwIndex);
		static void initSet(DWORD dwIndex, std::string szMsg, BYTE btMode);

	public:
		static CommandStruct Struct[6];

	public:
		static std::string Msg;
		static unsigned long Calcule;
		static unsigned long Delay;
		static unsigned char Count;
	};
}