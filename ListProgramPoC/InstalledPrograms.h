#ifndef INSTALLED_PROGRAMS
#define INSTALLED_PROGRAMS
#include <vector>
#include <Windows.h>
#include "RegistryKey.h"
using namespace std;

std::wstring stringToWstring(const std::string& str);
std::string wstringToString(const std::wstring& wstr);

class Software
{
public:
	wstring DisplayName;
	wstring InstallLocation;
	wstring Version;
	wstring InstallDate;
	Arch Architecture; // 32 or 64
	string origin;
	Software(wstring, wstring, wstring, wstring, Arch);
	Software(wstring, wstring, wstring, wstring, Arch, string);
};


class InstalledPrograms
{
public:
	InstalledPrograms(void);
	~InstalledPrograms(void);
	static vector<Software>* GetInstalledPrograms(bool IncludeUpdates);
private:
	static vector<Software>* GetInstalledProgramsImp(bool IncludeUpdates);
	static vector<Software>* GetUninstallKeyPrograms(RegistryKey* UninstallKey, RegistryKey* ClassesKey, vector<Software>*, bool IncludeUpdates, string origin);
	static vector<Software>* GetUserInstallerKeyPrograms(RegistryKey* uInstallerKey, vector<Software>* ExistingProgramList, string origin);
};

#endif