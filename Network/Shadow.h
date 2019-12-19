#pragma once

namespace Network
{
	class Shadow
	{
	public:
		static int initBless(OBJECTSTRUCT* lpObj, int szSource, int szTarget);
		static int initSoul(OBJECTSTRUCT* lpObj, int szSource, int szTarget);
		static int initLife(OBJECTSTRUCT* lpObj, int szSource, int szTarget);
	};
}