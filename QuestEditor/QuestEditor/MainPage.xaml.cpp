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

MainPage::MainPage()
{
	InitializeComponent();
}

void QuestEditor::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ input = questID->Text;
	wstring wsstr(input->Data());
	quest->questID = std::stoi(wsstr);
}
