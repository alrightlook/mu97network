#pragma once

namespace Network
{
	struct HappyHourStruct
	{
		bool Enable;
		bool Start;
		unsigned long Duration;
		unsigned long Delay;
		unsigned char Count[2];
		float NewExperience;
		unsigned long NewDrop;
		float OldExperience;
		unsigned long OldDrop;
	};

	class HappyHour
	{
	public:
		static bool initComponents();
		static void initPrepare();
		static void initEvent(LPVOID lpParam);
		static void initFinish();

	public:
		static HappyHourStruct Struct;
	};
}