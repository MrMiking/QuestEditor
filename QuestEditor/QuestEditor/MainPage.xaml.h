#pragma once

#include "MainPage.g.h"
#include "Quest.h"

namespace QuestEditor
{
	public ref class MainPage sealed
	{
	public:
		MainPage();
	private:
		void questID_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void npcID_Input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void questName_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void rewardType_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void objectiveType_Changed(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void objectiveQuantity_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void rewardQuantity_input(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
	};
}
