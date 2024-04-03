#pragma once
#include "Item.h"

class Quest
{
public:
	int questID;
	int npcID;
	string questName;

	enum rewardType { Money, Experience };
	int rewardQuantity;
	Item rewardItem;

	enum objectiveType { Slay, Loot, Save };
	int objectiveQuantity;

	string preQuestDialog;
	string questInProgressDialog;
	string postQuestDialog;
};