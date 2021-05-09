Monster = class("Monster", function()
    return Actor:new()
end)

function Monster:ctor()
end

function Monster:getAllowRun()
    return false;
end
