/*----------------------------------------------------------------
     Resource: Vital.sandbox
     Script: Sandbox: js: public: index.h
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Sandbox Utilities
----------------------------------------------------------------*/


//////////////
// Imports //
//////////////

#pragma once
#include <System/public/vital.h>
#include <Vendor/duktape/duktape.h>


////////////////////
// Namespace: JS //
////////////////////

namespace Vital::Sandbox::JS {
    extern std::vector<std::string> vBlacklist;
    extern std::vector<std::string> vModules;
}