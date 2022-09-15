/*----------------------------------------------------------------
     Resource: Vital.sandbox
     Script: System: filesystem.h
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Module Initializer
----------------------------------------------------------------*/


//////////////
// Imports //
//////////////

#pragma once
#include <iostream>
#include <fstream>
#include <string>


////////////////////////////
// Namespace: FileSystem //
////////////////////////////

namespace Vital::FileSystem {
    static bool exists(std::string& path) {
        std::fstream handle(path, std::ios::in | std::ios::binary);
        const bool isValid = (handle.is_open() && true) || false;
        handle.close();
        return isValid;
    }

    static std::streampos getSize(std::fstream handle) {
        if (!handle.is_open()) return 0;
        handle.seekg(0, std::ios::end);
        return handle.tellg();
    }

    static char* read(std::string& path) {
        std::fstream handle(path, std::ios::in | std::ios::binary | std::ios::ate);
        char* buffer = nullptr;
        if (handle.is_open()) {
            const std::streampos size = handle.tellg();
            char* buffer = new char[size];
            handle.seekg(0, std::ios::beg);
            handle.read(buffer, size);
        }
        return buffer;
    }

    static bool write(std::string& path, char* buffer, std::streampos size) {
        std::fstream handle(path, std::ios::out | std::ios::binary | std::ios::trunc);
        handle.write(buffer, size);
        handle.close();
        return true;
    }
}