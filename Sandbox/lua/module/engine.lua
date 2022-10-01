----------------------------------------------------------------
--[[ Resource: Vital.sandbox
     Script: Sandbox: lua: module: engine.lua
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Engine Utilities ]]--
----------------------------------------------------------------


-----------------
--[[ Imports ]]--
-----------------

local imports = {
    type = type,
    pairs = pairs
}


-----------------------
--[[ Class: Engine ]]--
-----------------------

local engine = class:create("engine", engine)
engine.private.binds = {
    key = {},
    command = {}
}

function engine.private.isBindSource(type, source, ref, exec)
    if not source or not ref or not type or not exec then return false end
    if (imports.type(source) ~= "string") or (imports.type(ref) ~= "string") or (imports.type(type) ~= "string") or (imports.type(exec) ~= "function") then return false end
    if not engine.private.binds[type] then return false end
    return true
end

function engine.private.bind(type, source, ref, exec)
    if not engine.private.isBindSource(type, source, ref, exec) then return false end
    engine.private.binds[type][ref] = engine.private.binds[type][ref] or {}
    engine.private.binds[type][ref][source] = engine.private.binds[type][ref][source] or {}
    if engine.private.binds[type][ref][exec] then return false end
    engine.private.binds[type][ref][exec] = true
    return true
end

function engine.private.unbind(type, source, ref, exec)
    if not engine.private.isBindSource(type, source, ref, exec) then return false end
    if not engine.private.binds[type][ref] or not engine.private.binds[type][ref][source] or not engine.private.binds[type][ref][exec] then return false end
    engine.private.binds[type][ref][exec] = nil
    return true
end

function engine.private.executeBind(type, ref)

    if not ref or (imports.type(source) ~= "string") then return false end
    if engine.private.binds[type][ref] then
        for i, j in imports.pairs(engine.private.binds[type][ref]) do
            for k, v in imports.pairs(j) do
                v()
            end
        end
    end

    if not engine.private.binds[type][ref] or not engine.private.binds[type][ref][source] or not engine.private.binds[type][ref][exec] then return false end
    engine.private.binds[type][ref][exec] = nil
    return true
end

function engine.public.bindKey(...) return engine.private.bind("key", ...) end
function engine.public.unbindKey(...) return engine.private.unbind("key", ...) end
function engine.public.executeBindKey(ref) return engine.private.executeBind("key", ref) end
function engine.public.bindCommand(...) return engine.private.bind("command", ...) end
function engine.public.unbindComand(...) return engine.private.unbind("command", ...) end
function engine.public.executeBindCommand(...) return engine.private.executeBind("command", ...) end

