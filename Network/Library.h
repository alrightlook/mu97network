#pragma once

#include "Target.h"
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sql.h>
#include <sqlext.h>
#include <WinSock.h>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "User.h"
#include "Project.h"
#include "Tokenizer.h"
#include "Function.h"
#include "Connect.h"
#include "Setting.h"
#include "Manager.h"
#include "Message.h"
#include "Query.h"
#include "Command.h"
#include "Security.h"
#include "Event.h"

#define ITEMGET(X,Y)			((X * 32) + Y)

#define ServerInitGame			((void(*)()) 0x49F8E8)
#define ServerItemBlessUp		((int(*)(Network::OBJECTSTRUCT*, int, int)) 0x479A60)
#define ServerItemSoulUp		((int(*)(Network::OBJECTSTRUCT*, int, int)) 0x479E50)
#define ServerItemLifeUp		((int(*)(Network::OBJECTSTRUCT*, int, int)) 0x47A490)
#define ServerItemDrop			((int(*)(Network::PMSG_ITEMTHROW*, DWORD, int)) 0x4191B0)
#define ServerItemMove			((void(*)(Network::PMSG_INVENTORYITEMMOVE*, DWORD)) 0x41A6F0)
#define ServerItemMoveResult	((void(*)(DWORD, BYTE, BYTE, LPBYTE)) 0x41A670)
#define ServerRequestTrade		((void(*)(Network::PMSG_TRADE_REQUEST*, DWORD)) 0x41D3B0)
#define ServerResponseTrade		((void(*)(Network::PMSG_TRADE_RESPONSE*, DWORD)) 0x41D990)
#define ServerCancelTrade		((void(*)(DWORD)) 0x41E8A0)
#define ServerActionPlayer		((void(*)(Network::PMSG_ACTION*, DWORD)) 0x425CD0)
#define ServerCloseClient		((void(*)(DWORD, DWORD)) 0x401A28)
#define ServerCreateCharacter	((void(*)(Network::PMSG_CHARCREATE*, DWORD)) 0x417420)
#define ServerCharacterFailSend	((void(*)(DWORD, char*)) 0x410A50)
#define ServerCreateGuild		((void(*)(DWORD, Network::PMSG_GUILDINFOSAVE*)) 0x4211B0)
#define ServerUseItemRecv		((void(*)(Network::PMSG_USEITEM*, DWORD)) 0x427A70)
#define ServerReFillSend		((void(*)(DWORD, WORD, BYTE, BYTE)) 0x428FD0)
#define ServerInventoryDelete	((void(*)(DWORD, int)) 0x4695F0)
#define ServerInventorySend		((void(*)(DWORD)) 0x411010)
#define ServerWarehouseEnd		((void(*)(DWORD)) 0x423250)
#define ServerNpcTalk			((int(*)(Network::OBJECTSTRUCT*, Network::OBJECTSTRUCT*)) 0x487A50)
#define ServerNpcTalkSend		((void(*)(Network::OBJECTSTRUCT*, char*, DWORD)) 0x40147E)
#define ServerConnect			((short(*)(SOCKET, char*)) 0x45F0F0)
#define ServerDataRecv			((void(*)(BYTE, PBYTE, DWORD, DWORD, ...)) 0x414180)
#define ServerDataSend			((void(*)(DWORD, PBYTE, DWORD)) 0x440240)
#define ServerJoinIdPass		((void(*)(Network::PMSG_IDPASS*, DWORD)) 0x416A40)
#define ServerJoinResult		((void(*)(BYTE, DWORD)) 0x417140)
#define ServerLevelUp			((bool(*)(Network::OBJECTSTRUCT*, int, int, int)) 0x462A20)
#define ServerMonsterExp		((int(*)(Network::OBJECTSTRUCT*, Network::OBJECTSTRUCT*, int, int, bool&)) 0x467970)
#define ServerLevelUpPointAdd	((void(*)(Network::PMSG_LVPOINTADD*, DWORD)) 0x417B50)
#define ServerMessageSend		((void(*)(char*, DWORD, int)) 0x416430)
#define ServerSetMonster		((void(*)(DWORD, DWORD)) 0x45E6C0)
#define ServerAddMonster		((short(*)(BYTE)) 0x45F420)
#define ServerSetPosMonster		((void(*)(int, int)) 0x45E2E0)
#define ServerReloadMonster		((void(*)()) 0x48BA40)
#define ServerReloadShop		((void(*)()) 0x484FA0)
#define ServerReloadConfig		((void(*)()) 0x48C2E0)
#define ServerDelete			((short(*)(DWORD)) 0x460640)
#define ServerMoneySend			((void(*)(DWORD, DWORD)) 0x4185C0)
#define ServerPkSend			((void(*)(DWORD, BYTE)) 0x401D7F)
//#define ServerCalculeCharacter	((void(*)(DWORD)) 0x451DE0)
#define ServerTeleportSend		((void(*)(DWORD, int, int, int)) 0x40181B)
#define ServerRepairItems		((void(*)(Network::OBJECTSTRUCT*, Network::ITEMCLASS*, int, int)) 0x41CF60)
#define ServerWarehouseSend		((void(*)(Network::OBJECTSTRUCT*)) 0x41BD00)
#define ServerProtocolCreate	((void(*)(Network::OBJECTSTRUCT*)) 0x474E40)
#define ServerNextExperience	((void(*)(Network::OBJECTSTRUCT*)) 0x402040)
#define ServerManaSend			((void(*)(DWORD, WORD, BYTE, BYTE, WORD)) 0x429050)
#define ServerObjAttack			((void(*)(Network::PMSG_ATTACK*, DWORD)) 0x4254D0)
#define ServerMagicAttackNumber	((void(*)(Network::OBJECTSTRUCT*, BYTE, int, BYTE)) 0x426200)
#define ServerItemCreate		((int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD,DWORD)) 0x4121E0)
#define ServerTopHitDamage		((DWORD(*)(Network::OBJECTSTRUCT*)) 0x404D70)
#define ServerMonsterItemDrop	((int(*)(Network::OBJECTSTRUCT*, Network::OBJECTSTRUCT*)) 0x40A670)

#define ServerMonsterCount		0x634D8E4
#define ServerMonsterReads		0x634453C

#define ServerExperience		0x513674
#define ServerDrop				0x513650

#define ServerAttackSpeed		0x5136D8
#define ServerMinimumSpeed		0x5136E4
#define ServerDecTimeSpeed		0x5136E0