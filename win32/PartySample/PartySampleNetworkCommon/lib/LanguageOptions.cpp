#include "pch.h"
#include "LanguageOptions.h"

// Supported languages:
// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support

using namespace PartySample;

const char* LanguageOptions::s_languageCodes[] =
{
    "ar-EG",
    "ca-ES",
    "zh-CN",
    "zh-HK",
    "zh-TW",
    "da-DK",
    "nl-NL",
    "en-AU",
    "en-CA",
    "en-IN",
    "en-NZ",
    "en-GB",
    "en-US",
    "fi-FI",
    "fr-CA",
    "fr-FR",
    "de-DE",
    "hi-IN",
    "it-IT",
    "ja-JP",
    "ko-KR",
    "nb-NO",
    "pl-PL",
    "pt-BR",
    "pt-PT",
    "ru-RU",
    "es-MX",
    "es-ES",
    "sv-SE",
    "th-TH"
};

const int LanguageOptions::s_numberOfLanguages = 30;
const int LanguageOptions::s_defaultLanguageIndex = 12;

const char* LanguageOptions::s_languageNames[LanguageOptions::s_numberOfLanguages] =
{
    "Arabic (Egypt)",
    "Catalan",
    "Chinese (Mandarin, Simplified)",
    "Chinese (Cantonese, Traditional)",
    "Chinese (Taiwanese Mandarin)",
    "Danish (Denmark)",
    "Dutch (Netherlands)",
    "English (Australia)",
    "English (Canada)",
    "English (India)",
    "English (New Zealand)",
    "English (United Kingdom)",
    "English (United States)",
    "Finnish (Finland)",
    "French (Canada)",
    "French (France)",
    "German (Germany)",
    "Hindi (India)",
    "Italian (Italy)",
    "Japanese (Japan)",
    "Korean (Korea)",
    "Norwegian (Norway)",
    "Polish (Poland)",
    "Portuguese (Brazil)",
    "Portuguese (Portugal)",
    "Russian (Russia)",
    "Spanish (Mexico)",
    "Spanish (Spain)",
    "Swedish (Sweden)",
    "Thai (Thailand)"
};
