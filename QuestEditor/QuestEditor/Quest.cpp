#include "pch.h"
#include "Quest.h"

Platform::String^ Quest::convertFromString(const std::string& input) {
    std::wstring w_str = std::wstring(input.begin(), input.end());
    const wchar_t* w_chars = w_str.c_str();
    return (ref new Platform::String(w_chars));
}

string Quest::PlatformToString(Platform::String^ pstring) {
    std::wstring wsstr(pstring->Data());
    std::string output(wsstr.begin(), wsstr.end());
    return output;
}