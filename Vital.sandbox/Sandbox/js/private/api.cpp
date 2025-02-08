/*----------------------------------------------------------------
     Resource: Vital.sandbox
     Script: Sandbox: js: private: api.cpp
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса, A-Variakojiene
     DOC: 14/09/2022
     Desc: API Utilities
----------------------------------------------------------------*/


//////////////
// Imports //
//////////////

#pragma once
#include <Sandbox/js/public/api.h>


//////////////
// JS: API //
//////////////

namespace Vital::Sandbox::JS::API {
    // Handlers //
    std::map<vital_bind, vital_exec> vital_binds;
    std::function<void(const std::string&)> onErrorHandler = NULL;
    bool onErrorHandle(std::function<void(const std::string&)> exec) {
        onErrorHandler = exec;
        return true;
    }

    // Helpers //
    bool error(const std::string& error) {
        if (!onErrorHandler) return false;
        onErrorHandler(error);
        return true;
    }

    bool bind(const std::string& parent, const std::string& name, vital_exec exec) {
        vital_bind ref = {parent, name};
        vital_binds.emplace(ref, exec);
        return true;
    }
    bool unbind(const std::string& parent, const std::string& name) {
        vital_bind ref = {parent, name};
        vital_binds.erase(ref);
        return true;
    }

    // Booter //
    bool boot() {
        vSandbox_Engine();
        vSandbox_File();
        vSandbox_Crypto();
        return true;
    }
}