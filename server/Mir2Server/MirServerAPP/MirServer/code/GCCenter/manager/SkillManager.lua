SkillManager = {}
SkillManager.skills = {}

function SkillManager:addSkill(data)
	local skillid = data.skillid;
    local conf = skillConf[skillid];
	local skill = nil;

	if conf then
		local skillClass = "return "..conf.sz_class..":new()";
		local createSkillFunc = loadstring(skillClass);
		skill = createSkillFunc();

		skill:setBaseData(data);
		skill:initAttribute(conf);
		self:registSkill(skill);
	else
		print("no found skillid "..skillid.." in skillConf");
	end

	if not skill then
		print("init skillid "..skillid.." failed");
	end

    return skill;
end

function SkillManager:registSkill(skill)
    table.insert(self.skills, #self.skills+1, skill);
end
