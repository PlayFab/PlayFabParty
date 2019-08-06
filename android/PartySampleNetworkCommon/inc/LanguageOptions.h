#pragma once

// Language options is a configurable file that provides the available cognitive services language
// codes and profiles, as specified by the following:
// Supported languages:
// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support

namespace PartySample
{
    
    class LanguageOptions
    {
    public:

        // Default language index to start the app with.
        static const int s_defaultLanguageIndex;

        // List of langauge codes that can be used with the chat control with cognitive services.
        static const char* s_languageCodes[];

        // The count of supported languages
        static const int s_numberOfLanguages;

        // Language names in a human readable format corresponding to the language codes above.
        static const char* s_languageNames[];

        // Cognitive services text to speech profiles that correspond to the language codes above.
        static const char* s_languageProfiles[];
    };

}
