BaseSpell = class("BaseSpell")

function BaseSpell:ctor()
    self.attack = 0;
    self.level = 1
    self.attackType = 1;  --1.鐗╃悊;2.榄旀硶;3.閬撴湳
    self.name = "slash"
    self.power = 1  --濞佸姏澶у埌涓€瀹氱▼搴︿細浣跨洰鏍囧悗锟?
    self.action = 1;      --瀵瑰簲鍔ㄤ綔id
    self.castClock = Clock:new();
    self.auto = true;   --鏄惁鍦ㄦ墽锟?
    self.priority = 1;
    self.flyEffectSpeedPerPixel = 0.0008;
	self.type = 2;

    --棰勭暀缁欏瓙绫荤殑鐗规晥
    self.effect = nil
end

--鎶€鑳藉熀鏈睘锟?
function BaseSpell:initAttribute(param)
    self.baseDamage  = param.baseDamage;
    self.growDamage  = param.growDamage;
    self.attackType  = param.attackType
    self.name        = param.sz_name
	self.sz_cn_name  = param.sz_cn_name
    self.event       = param.sz_event
    self.action      = param.action
    self.specialFunc = param.sepcialFunc;
    self.triggerRate = param.triggerRate;
    self.priority    = param.priority;
    self.castRange   = param.castRange;
	self.type        = param.type
	self.needMagic   = param.needMagic;
	self.petId       = param.petId;
    self.castClock:setRingTimeDelta(param.coolDown);

    --self.effect      = EffectManager:getEffect(param.effectid);
    --self.flyEffect   = EffectManager:getEffect(param.flyeffectid);
    --self.boomEffect  = EffectManager:getEffect(param.boomeffectid);
end

function BaseSpell:getType()
	return self.type;
end

function BaseSpell:getCastRange()
	return self.castRange;
end

function BaseSpell:setBaseData(data)
	self.baseData = data;
end

function BaseSpell:getBaseData()
	self.baseData.level = self.level;
	self.baseData.exc = self.exc;

	return self.baseData;
end

function BaseSpell:satifyCastPremise(object, values)
    if self.castClock:ring() == false then
        return false, "no cooling down";
    end


	--[[
    if self.triggerRate then
        local rate = FuncPack:getRandomNumber(1, 100)

        if rate > self.triggerRate * 100 then
            return false
        end
    end]]
	if self.needMagic > object:getMp() then
		return false, "no enough magic";
	end

    return true;
end

function BaseSpell:calcConsume(object)
	object:setMp(object:getMp() - self.needMagic);
end

function BaseSpell:getName()
	return self.name;
end
