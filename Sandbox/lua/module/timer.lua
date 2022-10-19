----------------------------------------------------------------
--[[ Resource: Vital.sandbox
     Script: Sandbox: lua: module: timer.lua
     Author: vStudio
     Developer(s): Aviril, Tron, Mario, Аниса
     DOC: 14/09/2022
     Desc: Timer Utilities ]]--
----------------------------------------------------------------


-----------------
--[[ Imports ]]--
-----------------

local imports = {
    type = type,
    tonumber = tonumber,
    coroutine = coroutine,
    math = math
}
--coroutine = nil


----------------------
--[[ Class: Timer ]]--
----------------------

local timer = class:create("timer")

function timer.public:create(...)
    local cTimer = self:createInstance()
    if cTimer and not cTimer:load(...) then
        cTimer:destroyInstance()
        return false
    end
    return cTimer
end

function timer.public:destroy(...)
    if not timer.public:isInstance(self) then return false end
    return self:unload(...)
end

function timer.public:load(exec, interval, executions, ...)
    if not timer.public:isInstance(self) then return false end
    interval, executions = imports.tonumber(interval), imports.tonumber(executions)
    if not exec or (imports.type(exec) ~= "function") or not interval or not executions then return false end
    interval, executions = imports.math.max(1, interval), imports.math.max(0, executions)
    self.exec = exec
    self.currentExec = 0
    self.interval, self.executions = interval, executions
    self.arguments = table.pack(...)
    imports.coroutine.resume(imports.coroutine.create(function()
        while ((self.executions == 0) or (self.currentExec < self.executions)) do
            print("PASSING TIME: "..self.interval)
            --coroutine.sleep(self.interval)
            local testSound = output("C:/Users/Tron/Documents/GITs/Test/Bells.mp3")
            if not timer.public:isInstance(self) then return false end
            self.currentExec = self.currentExec + 1
            if (self.executions > 0) and (self.currentExec >= self.executions) then
                self:destroy()
            end
            self.exec(table.unpack(self.arguments))
        end
    end))
    return self
end

function timer.public:unload()
    if not timer.public:isInstance(self) then return false end
    self:destroyInstance()
    return true
end