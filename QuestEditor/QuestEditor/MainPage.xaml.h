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
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
