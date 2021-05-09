Ticket = class("Ticket", function()
    return Item:new();
end)

function Ticket:ctor()
end

function Ticket:use(actor)
	local pid = actor:getID();
	local ret = Game.netDelItem(pid, self.id);

	if ret then
		Game.goHome(pid);
	end
end
