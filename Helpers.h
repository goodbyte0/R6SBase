#pragma once
#include "stdafx.h"

namespace Helpers
{
	void LogAddress(char* szName, int64_t iAddress);
	void LogFloat(char* szName, float fValue);
	void LogError(char* szMessage);
	void Log(char* szMessage);
	void LogString(char* szName, std::string sValue);
	void HookFunction(PVOID *oFunction, PVOID pDetour);
	void UnhookFunction(PVOID *oFunction, PVOID pDetour);
	std::string VariableText(const char* format, ...);
}