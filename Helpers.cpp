
#include "Helpers.h"

//HOOKING
void Helpers::HookFunction(PVOID *oFunction, PVOID pDetour)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(oFunction, pDetour);
	DetourTransactionCommit();
}
void Helpers::UnhookFunction(PVOID *oFunction, PVOID pDetour)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(oFunction, pDetour);
	DetourTransactionCommit();
}

//MISCELLANEOUS
void Helpers::Log(char* szMessage)
{
	std::cout << "[+] " << szMessage << std::endl;
}
void Helpers::LogAddress(char* szName, int64_t iAddress)
{
	std::cout << "[+] " << szName << ": 0x" << std::hex << iAddress << std::endl;
}
void Helpers::LogFloat(char* szName, float fValue)
{
	std::cout << "[+] " << szName << ": " << std::defaultfloat << fValue << std::endl;
}
void Helpers::LogString(char* szName, std::string sValue)
{
	std::cout << "[+] " << szName << ": " << sValue << std::endl;
}
void Helpers::LogError(char* szMessage)
{
	std::cout << "[Error] " << szMessage << std::endl;
}

// CONVERTERS
std::string Helpers::VariableText(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);

	char buffer[2048];
	vsprintf(buffer, format, argptr);

	va_end(argptr);

	return buffer;
}