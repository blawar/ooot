#include "Declaration.h"

#include "Globals.h"
#include "Utils/StringHelper.h"

Declaration::Declaration(offset_t nAddress, DeclarationAlignment nAlignment, size_t nSize,
                         const std::string& nText)
{
	address = nAddress;
	alignment = nAlignment;
	size = nSize;
	text = nText;
}

Declaration::Declaration(offset_t nAddress, DeclarationAlignment nAlignment, size_t nSize,
                         const std::string& nVarType, const std::string& nVarName, bool nIsArray,
                         const std::string& nText)
	: Declaration(nAddress, nAlignment, nSize, nText)
{
	varType = nVarType;
	varName = nVarName;
	isArray = nIsArray;
}

Declaration::Declaration(offset_t nAddress, DeclarationAlignment nAlignment, size_t nSize,
                         const std::string& nVarType, const std::string& nVarName, bool nIsArray,
                         size_t nArrayItemCnt, const std::string& nText)
	: Declaration(nAddress, nAlignment, nSize, nText)
{
	varType = nVarType;
	varName = nVarName;
	isArray = nIsArray;
	arrayItemCnt = nArrayItemCnt;
}

Declaration::Declaration(offset_t nAddress, DeclarationAlignment nAlignment, size_t nSize,
                         const std::string& nVarType, const std::string& nVarName, bool nIsArray,
                         const std::string& nArrayItemCntStr, const std::string& nText)
	: Declaration(nAddress, nAlignment, nSize, nText)
{
	varType = nVarType;
	varName = nVarName;
	isArray = nIsArray;
	arrayItemCntStr = nArrayItemCntStr;
}

Declaration::Declaration(offset_t nAddress, DeclarationAlignment nAlignment, size_t nSize,
                         const std::string& nVarType, const std::string& nVarName, bool nIsArray,
                         size_t nArrayItemCnt, const std::string& nText, bool nIsExternal)
	: Declaration(nAddress, nAlignment, nSize, nVarType, nVarName, nIsArray, nArrayItemCnt, nText)
{
	isExternal = nIsExternal;
}

Declaration::Declaration(offset_t nAddress, const std::string& nIncludePath, size_t nSize,
                         const std::string& nVarType, const std::string& nVarName)
	: Declaration(nAddress, DeclarationAlignment::Align4, nSize, "")
{
	includePath = nIncludePath;
	varType = nVarType;
	varName = nVarName;
}

bool Declaration::IsStatic() const
{
	switch (staticConf)
	{
	case StaticConfig::Off:
		return false;

	case StaticConfig::Global:
		return Globals::Instance->forceStatic;

	case StaticConfig::On:
		return true;
	}

	return false;
}

std::string Declaration::GetNormalDeclarationStr() const
{
	std::string output;

	if (preText != "")
		output += preText + "\n";

	if (IsStatic())
	{
		output += "static ";
	}

	if (isArray)
	{
		if (arrayItemCntStr != "" && (IsStatic() || forceArrayCnt))
		{
			output += StringHelper::Sprintf("%s %s[%s];\n", STR(varType), STR(varName),
			                                STR(arrayItemCntStr));
		}
		else if (arrayItemCnt != 0 && (IsStatic() || forceArrayCnt))
		{
			output += StringHelper::Sprintf("%s %s[%i] = {\n", STR(varType), STR(varName),
			                                arrayItemCnt);
		}
		else
		{
			output += StringHelper::Sprintf("%s %s[] = {\n", STR(varType), STR(varName));
		}

		output += text + "\n";
	}
	else
	{
		output += StringHelper::Sprintf("%s %s = { ", STR(varType), STR(varName));
		output += text;
	}

	if (output.back() == '\n')
		output += "};";
	else
		output += " };";

	if (rightText != "")
		output += " " + rightText + "";

	output += "\n";

	if (postText != "")
		output += postText + "\n";

	output += "\n";

	return output;
}

std::string Declaration::GetExternalDeclarationStr() const
{
	std::string output;

	if (preText != "")
		output += preText + "\n";

	if (IsStatic())
	{
		output += "static ";
	}

	if (arrayItemCntStr != "" && (IsStatic() || forceArrayCnt))
		output += StringHelper::Sprintf("%s %s[%s] = ", STR(varType), STR(varName),
		                                STR(arrayItemCntStr));
	else if (arrayItemCnt != 0 && (IsStatic() || forceArrayCnt))
		output +=
			StringHelper::Sprintf("%s %s[%i] = ", STR(varType), STR(varName), arrayItemCnt);
	else
		output += StringHelper::Sprintf("%s %s[] = ", STR(varType), STR(varName));

	output += StringHelper::Sprintf("{\n#include \"%s\"\n};", STR(includePath));

	if (rightText != "")
		output += " " + rightText + "";

	output += "\n";

	if (postText != "")
		output += postText + "\n";

	output += "\n";

	return output;
}

std::string Declaration::GetExternStr() const
{
	if (IsStatic() || varType == "" || isUnaccounted)
	{
		return "";
	}

	if (isArray)
	{
		if (arrayItemCntStr != "" && (IsStatic() || forceArrayCnt))
		{
			return StringHelper::Sprintf("extern %s %s[%s];\n", STR(varType), STR(varName),
			                             STR(arrayItemCntStr));
		}
		else if (arrayItemCnt != 0 && (IsStatic() || forceArrayCnt))
		{
			return StringHelper::Sprintf("extern %s %s[%i];\n", STR(varType), STR(varName),
			                             arrayItemCnt);
		}
		else
			return StringHelper::Sprintf("extern %s %s[];\n", STR(varType), STR(varName));
	}

	return StringHelper::Sprintf("extern %s %s;\n", STR(varType), STR(varName));
}

std::string Declaration::GetStaticForwardDeclarationStr() const
{
	if (!IsStatic() || isUnaccounted)
		return "";

	if (isArray)
	{
		if (arrayItemCntStr == "" && arrayItemCnt == 0)
		{
			// Forward declaring static arrays without specifying the size is not allowed.
			return "";
		}

		if (arrayItemCntStr != "")
		{
			return StringHelper::Sprintf("extern %s %s[%s];\n", STR(varType), STR(varName),
			                             STR(arrayItemCntStr));
		}
		else
		{
			return StringHelper::Sprintf("extern %s %s[%i];\n", STR(varType), STR(varName),
			                             arrayItemCnt);
		}
	}

	return StringHelper::Sprintf("extern %s %s;\n", STR(varType), STR(varName));
}
