/*---------------------------------------------------------------------------*/
//       Author : Yury Malich
//         Mail : yurymalich@yandex.com
//          Web : https://malich.org
//      License : The MIT License
/*---------------------------------------------------------------------------*/
//  
#include "stdafx.h"
#include "NamedAttributesMapper.h"

//NamedAttributesMapping.ini content sample:
//[SmartSanDiskGb]
//A8=WearLevelingCount,RawValue,0,4
// it means map SMART attribute A8 RawValue bytes 0-3 as WearLevelingCount for SanDisk SSDs

NamedAttributesMapper::NamedAttributesMapper(const CString& strIniFilePath)
{
	_fileExists = false;
	_strIniFilePath = strIniFilePath;
	if (strIniFilePath.IsEmpty())
	{
		TCHAR* ptrEnd;
		TCHAR path[MAX_PATH];
		::GetModuleFileName(nullptr, path, MAX_PATH);
		if ((ptrEnd = _tcsrchr(path, '\\')) != nullptr)
		{
			*ptrEnd = '\0';
			_strIniFilePath = path;
		}

		_strIniFilePath += _T("\\CdiResource\\NamedAttributesMapping.ini");
		_fileExists = IsFileExist(_strIniFilePath);
		if (!_fileExists)
		{
			DebugPrint(_T("File ") + _strIniFilePath + _T(" doesn't exist. Check the path."));
		}
	}
}

CString NamedAttributesMapper::GetAttributeMapping(const CString& smartKeyName, BYTE id)
{
	CString cstr;
	if (!_fileExists)
	{
		return cstr;
	}

	TCHAR str[256] = { 0 };
	cstr.Format(_T("%02X"), id);

	GetPrivateProfileString(smartKeyName, cstr, _T(""), str, sizeof(str)/ sizeof(str[0]), _strIniFilePath);

	return CString(str);
}
