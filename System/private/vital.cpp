/*----------------------------------------------------------------
     Resource: Vital.sandbox
     Script: System: public: vital.cpp
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Vital Utilities
----------------------------------------------------------------*/


//////////////
// Imports //
//////////////

#pragma once
#include <System/public/vital.h>


////////////
// Vital //
////////////

std::map<std::string, std::string> Vital::ErrorCodes = {
    {"request_failed", "failed to process request"},
    {"invalid_3d_sound", "invalid 3D sound"},
    {"file_nonexistent", "file non-existent"}
}

namespace Vital::System {
    unsigned int getSystemTick() {
        return static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000000);
    }

    unsigned int vApplicationTick;
    unsigned int getApplicationTick() {
        vApplicationTick = vApplicationTick ? vApplicationTick : getSystemTick();
        return static_cast<unsigned int>(getSystemTick() - vApplicationTick);
    }

    unsigned int vClientTick;
    unsigned int getClientTick() {
        vClientTick = vClientTick ? vClientTick : getApplicationTick();
        return static_cast<unsigned int>(getSystemTick() - vClientTick);
    }

    bool resetClientTick() {
        vClientTick = getApplicationTick();
        return true;
    }
}