/*----------------------------------------------------------------
     Resource: Vital.sandbox
     Script: Sandbox: lua: module: c++: coroutine.cpp
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Coroutine Utilities
----------------------------------------------------------------*/


//////////////
// Imports //
//////////////

#pragma once
#include <Sandbox/lua/public/api.h>


////////////////////////////
// Lua: Coroutine Binder //
////////////////////////////

namespace Vital::Sandbox::Lua::API {
    static bool isBound = false;
    void vSandbox_Coroutine() {
        if (isBound) return; isBound = true;

        bind("coroutine", "create", [](vital_ref* ref) -> int {
            auto vm = fetchVM(ref);
            return vm -> execute([&]() -> int {
                vm -> createThread();
                return 1;
            });
        });
    }
}
