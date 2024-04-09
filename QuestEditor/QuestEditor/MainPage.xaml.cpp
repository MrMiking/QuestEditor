#include "pch.h"
#include "MainPage.xaml.h"

using namespace QuestEditor;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

Quest* quest = new Quest();
Player* player = new Player();

MainPage::MainPage()
{
	InitializeComponent();

	questID->Text = rewardType->Text;
}

void QuestEditor::MainPage::questID_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->questID = quest->PlatformToString(questID->Text);
}

void QuestEditor::MainPage::npcID_Input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->npcID = quest->PlatformToString(npcID->Text);
}

void QuestEditor::MainPage::questName_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->questName = quest->PlatformToString(questName->Text);
}

void QuestEditor::MainPage::rewardType_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (safe_cast<ComboBoxItem^>(rewardType->SelectedItem)->Content->ToString() == "Money") {
		quest->rewardType = "Money";
	}
	else if (safe_cast<ComboBoxItem^>(rewardType->SelectedItem)->Content->ToString() == "Experience") {
		quest->rewardType = "Experience";
	}
}

void QuestEditor::MainPage::objectiveType_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (safe_cast<ComboBoxItem^>(objectiveType->SelectedItem)->Content->ToString() == "Slay") {
		quest->objectiveType = "Slay";
	}
	else if (safe_cast<ComboBoxItem^>(objectiveType->SelectedItem)->Content->ToString() == "Loot") {
		quest->objectiveType = "Loot";
	}
	else if (safe_cast<ComboBoxItem^>(objectiveType->SelectedItem)->Content->ToString() == "Save") {
		quest->objectiveType = "Save";
	}
}

void QuestEditor::MainPage::objectiveQuantity_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->objectiveQuantity = quest->PlatformToString(objectiveQuantity->Text);
}

void QuestEditor::MainPage::rewardQuantity_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->rewardQuantity = quest->PlatformToString(rewardQuantity->Text);
}

void QuestEditor::MainPage::talkToNPC_Button(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (quest->started == false) {
		dialogText->Text = quest->convertFromString(quest->preQuestDialog);
		quest->started = true;
	}
}

void QuestEditor::MainPage::retalkToNPC_Button(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (quest->started == true) {
		dialogText->Text = quest->convertFromString(quest->questInProgressDialog);
	}
}

void QuestEditor::MainPage::endQuest_Button(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (quest->started == true) {
		dialogText->Text = quest->convertFromString(quest->postQuestDialog);
		if (quest->rewardType == "Money") {
			player->money += stoi(quest->rewardQuantity);
			playerMoney->Text = "Money = " + player->money.ToString();
		}
		else if (quest->rewardType == "Experience") {
			player->experience += stoi(quest->rewardQuantity);
			playerExperience->Text = "Experience = " + player->experience.ToString();
		}
		quest->started = false;
	}
}

void QuestEditor::MainPage::preQuestDialog_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->preQuestDialog = quest->PlatformToString(preQuestDialog->Text);
}

void QuestEditor::MainPage::questInProgressDialog_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->questInProgressDialog = quest->PlatformToString(questInProgressDialog->Text);
}

void QuestEditor::MainPage::postQuestDialog_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	quest->postQuestDialog = quest->PlatformToString(postQuestDialog->Text);
}