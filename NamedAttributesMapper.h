#pragma once
#include "INamedAttributesMapper.h"

class NamedAttributesMapper : public INamedAttributesMapper
{
	protected:
		CString _strIniFilePath;
		bool _fileExists;

	public: 
		NamedAttributesMapper(const CString& strIniFilePath);

		virtual CString GetAttributeMapping(const CString& smartKeyName, BYTE Id);
};

