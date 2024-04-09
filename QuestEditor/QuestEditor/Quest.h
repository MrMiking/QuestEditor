#pragma once
#include "Player.h"

class Quest
{
public:
	string questID;
	string npcID;
	string questName;

	bool started;

	string rewardType;
	string rewardQuantity;

	string objectiveType;
	string objectiveQuantity;

	string preQuestDialog;
	string questInProgressDialog;
	string postQuestDialog;

	Platform::String^ convertFromString(const std::string& input);
	string PlatformToString(Platform::String^ pstring);
};