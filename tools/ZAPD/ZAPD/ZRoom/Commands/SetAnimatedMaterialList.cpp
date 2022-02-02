/**
 * File: SetAnimatedMaterialList.cpp
 * Description: Defines a class SetAnimatedMaterialList to enable ZRoom to declare
 * ZTextureAnimations, using that ZResource to do the work.
 */
#include "SetAnimatedMaterialList.h"

#include "Globals.h"
#include "Utils/BitConverter.h"
#include "Utils/StringHelper.h"
#include "ZFile.h"
#include "ZRoom/ZRoom.h"
#include "ZTextureAnimation.h"

SetAnimatedMaterialList::SetAnimatedMaterialList(ZFile* nParent)
	: ZRoomCommand(nParent), textureAnimation(nParent)
{
}

void SetAnimatedMaterialList::ParseRawData()
{
	ZRoomCommand::ParseRawData();
	textureAnimation.ExtractFromFile(segmentOffset);
}

void SetAnimatedMaterialList::DeclareReferences(const std::string& prefix)
{
	textureAnimation.SetName(textureAnimation.GetDefaultName(STR(prefix)));
	textureAnimation.DeclareReferences(prefix);
	textureAnimation.GetSourceOutputCode(prefix);
}

std::string SetAnimatedMaterialList::GetBodySourceCode() const
{
	std::string listName;
	Globals::Instance->GetSegmentedPtrName(cmdArg2, parent, "AnimatedMaterial", listName);
	return StringHelper::Sprintf("SCENE_CMD_ANIMATED_MATERIAL_LIST(%s)", STR(listName));
}

std::string SetAnimatedMaterialList::GetCommandCName() const
{
	return "SCmdTextureAnimations";
}

RoomCommand SetAnimatedMaterialList::GetRoomCommand() const
{
	return RoomCommand::SetAnimatedMaterialList;
}
