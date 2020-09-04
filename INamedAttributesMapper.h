#pragma once
struct INamedAttributesMapper
{
	virtual CString GetAttributeMapping(const CString& smartKeyName, BYTE Id) = 0;
};

