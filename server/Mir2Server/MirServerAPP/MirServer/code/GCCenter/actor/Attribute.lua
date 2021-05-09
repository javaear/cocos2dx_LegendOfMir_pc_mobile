-----------------------------------------------------------
--
--      瑙掕壊灞炴€х被,actor鍜宔quipment绫诲叡鏈夌殑灞炴€х被
--
-----------------------------------------------------------

Attribute = {}
Attribute.__index = Attribute

function Attribute:create()
    local attribute = {}
    setmetatable(attribute, Attribute)
    attribute:ctor();
    return attribute;
end

function Attribute:ctor()
    self.level       = 1

    --琛€閲?
    self.maxHp       = 100
    self.maxMp       = 100

    --娓告垙褰撳墠琛€閲忓拰榄旀硶閲?
    self.hp          = self.maxHp
    self.mp          = self.maxMp

    --鏀婚槻灞炴€?
    self.atk      = {{0,0}, {0,0}, {0,0}}   --1锛氱墿鐞嗘敾鍑?2锛氶瓟娉曟敾鍑?锛氶亾鏈敾鍑?
    self.dfs     = {0, 0, 0}     --1锛氱墿鐞嗛槻寰?2锛氶瓟娉曢槻寰?3锛氶亾鏈槻寰?

    --瑙掕壊鍩烘湰闈㈡澘灞炴€?
    self.lucky       = 0   --骞歌繍
    self.strength    = 0   --鍔涢噺
    self.magic       = 0   --榄旀硶
    self.aligity     = 0   --鏁忔嵎
    self.taoistMagic = 0   --閬撴湳

    --杩欎袱涓奖鍝嶆槸鍚︽毚鍑?鍏堣绠楁毚鍑?璁＄畻澶辫触鍦ㄨ绠楀嚮涓拰韬查伩
    self.critRate    = 0   --鏆村嚮鍔?
    self.defenCrit   = 0   --鎶楁毚鍑诲姏

    --杩欎笁涓浉浜掑奖鍝嶆槸鍚﹀嚮涓拰韬查伩
    self.lucky       = 0   --骞歌繍
    self.precise     = 0   --绮惧噯
    self.dodge       = 0   --韬查伩鍔?
    --self.atk = {};
    --self.dfs = {};
end

function Attribute:init(value)
    if value == nil then
        return;
    end

    --琛€閲?
    self.maxHp       = value.maxHp
    self.maxMp       = value.maxMp

    --娓告垙褰撳墠琛€閲忓拰榄旀硶閲?
    self.hp          = self.maxHp
    self.mp          = self.maxMp

    --鏀婚槻灞炴€?
    if value.atk then
        if value.atk[1] then
            self.atk[1]   = {value.atk[1][1],value.atk[1][2]}     --1锛氱墿鐞嗘敾鍑?2锛氶瓟娉曟敾鍑?锛氶亾鏈敾鍑?
        end

        if value.atk[2] then
            self.atk[2]   = {value.atk[2][1],value.atk[2][2]}     --1锛氱墿鐞嗘敾鍑?2锛氶瓟娉曟敾鍑?锛氶亾鏈敾鍑?
        end

        if value.atk[3] then
            self.atk[3]   = {value.atk[3][1],value.atk[3][2]}     --1锛氱墿鐞嗘敾鍑?2锛氶瓟娉曟敾鍑?锛氶亾鏈敾鍑?
        end
    end

    if value.dfs then
        self.dfs[1]      = value.dfs[1]     --1锛氱墿鐞嗛槻寰?2锛氶瓟娉曢槻寰?3锛氶亾鏈槻寰?
        self.dfs[2]      = value.dfs[2]     --1锛氱墿鐞嗛槻寰?2锛氶瓟娉曢槻寰?3锛氶亾鏈槻寰?
        self.dfs[3]      = value.dfs[3]     --1锛氱墿鐞嗛槻寰?2锛氶瓟娉曢槻寰?3锛氶亾鏈槻寰?
    end

    --瑙掕壊鍩烘湰闈㈡澘灞炴€?
    self.strength    = value.strength      --鍔涢噺
    self.magic       = value.magic         --榄旀硶
    self.aligity     = value.aligity       --鏁忔嵎
    self.taoistMagic = value.taoistMagic   --閬撴湳

    --杩欎袱涓奖鍝嶆槸鍚︽毚鍑?鍏堣绠楁毚鍑?璁＄畻澶辫触鍦ㄨ绠楀嚮涓拰韬查伩
    self.critRate    = value.critRate    --鏆村嚮鍔?
    self.defenCrit   = value.defenCrit   --鎶楁毚鍑诲姏

    --杩欎笁涓浉浜掑奖鍝嶆槸鍚﹀嚮涓拰韬查伩
    self.lucky       = value.lucky   --骞歌繍
    self.precise     = value.precise --绮惧噯
    self.dodge       = value.dodge   --韬查伩鍔?

	if value.slashSpeed then
		self.slashSpeed  = value.slashSpeed;
	end

	if value.castSpeed then
		self.castSpeed   = value.castSpeed;
	end

    if value.speed then
        self.speed   = {value.speed[1],value.speed[2]};
    end
end

function Attribute:setSlashSpeed(_slashSpeed)
    self.slashSpeed  = _slashSpeed;
end

function Attribute:setCastSpeed(_castSpeed)
    self.castSpeed  = _castSpeed;
end

function Attribute:setSpeed(_speed)
    self.speed = _speed;
end

function Attribute:plus(param)
    local hpPer = self.hp/self.maxHp;
	local mpPer = self.mp/self.maxMp;

    self.maxHp       = self:plusElement(self.maxHp, param.maxHp)
    self.maxMp       = self:plusElement(self.maxMp, param.maxMp)

    self.hp          = math.modf(hpPer*self.maxHp);--self:plusElement(self.hp, param.maxHp)
    self.mp          = math.modf(mpPer*self.maxMp);--self:plusElement(self.mp, param.maxMp)

    --鏀婚槻灞炴€?
    if param.atk then
        if param.atk[1] then
            self.atk[1][1]   = self:plusElement(self.atk[1][1], param.atk[1][1]);
            self.atk[1][2]   = self:plusElement(self.atk[1][2], param.atk[1][2]);
        end

        if param.atk[2] then
            self.atk[2][1]   = self:plusElement(self.atk[2][1], param.atk[2][1]);
            self.atk[2][2]   = self:plusElement(self.atk[2][2], param.atk[2][2]);
        end

        if param.atk[3] then
            self.atk[3][1]   = self:plusElement(self.atk[3][1], param.atk[3][1]);
            self.atk[3][2]   = self:plusElement(self.atk[3][2], param.atk[3][2]);
        end
    end

    if param.dfs then
        self.dfs[1]      = self:plusElement(self.dfs[1], param.dfs[1]);
        self.dfs[2]      = self:plusElement(self.dfs[2], param.dfs[2]);
        self.dfs[3]      = self:plusElement(self.dfs[3], param.dfs[3]);
    end

    --瑙掕壊鍩烘湰闈㈡澘灞炴€?
    self.strength    = self:plusElement(self.strength, param.strength)      --鍔涢噺
    self.magic       = self:plusElement(self.magic, param.magic)         --榄旀硶
    self.aligity     = self:plusElement(self.aligity,param.aligity)       --鏁忔嵎
    self.taoistMagic = self:plusElement(self.taoistMagic, param.taoistMagic)   --閬撴湳

    --杩欎袱涓奖鍝嶆槸鍚︽毚鍑?鍏堣绠楁毚鍑?璁＄畻澶辫触鍦ㄨ绠楀嚮涓拰韬查伩
    self.critRate    = self:plusElement(self.critRate, param.critRate)    --鏆村嚮鍔?
    self.defenCrit   = self:plusElement(self.defenCrit, param.defenCrit)   --鎶楁毚鍑诲姏

    --杩欎笁涓浉浜掑奖鍝嶆槸鍚﹀嚮涓拰韬查伩
    self.lucky       = self:plusElement(self.lucky, param.lucky)   --骞歌繍
    self.precise     = self:plusElement(self.precise, param.precise) --绮惧噯
    self.dodge       = self:plusElement(self.dodge, param.dodge)   --韬查伩鍔?

    self.slashSpeed  = self:plusElement(self.slashSpeed, param.slashSpeed)
	self.castSpeed   = self:plusElement(self.castSpeed, param.castSpeed)

    if param.speed then
        self.speed[1]    = self:plusElement(self.speed[1], param.speed[1])
        self.speed[2]    = self:plusElement(self.speed[2], param.speed[2])
    end
end

function Attribute:minus(param)
    local hpPer     = self.hp/self.maxHp;
	local mpPer     = self.mp/self.maxMp;

    self.maxHp       = self:minusElement(self.maxHp, param.maxHp)
    self.maxMp       = self:minusElement(self.maxMp, param.maxMp)
    self.hp          = math.modf(hpPer*self.maxHp);--self:minusElement(self.hp, param.maxHp)
    self.mp          = math.modf(mpPer*self.maxMp);--self:minusElement(self.mp, param.maxMp)

    if self.hp < 0 then
        self.hp = 0;
    end

    if self.mp < 0 then
        self.mp = 0;
    end

    --鏀婚槻灞炴€?
    if param.atk then
        if param.atk[1] then
            self.atk[1][1]   = self:minusElement(self.atk[1][1], param.atk[1][1]);
            self.atk[1][2]   = self:minusElement(self.atk[1][2], param.atk[1][2]);
        end

        if param.atk[2] then
            self.atk[2][1]   = self:minusElement(self.atk[2][1], param.atk[2][1]);
            self.atk[2][2]   = self:minusElement(self.atk[2][2], param.atk[2][2]);
        end

        if param.atk[3] then
            self.atk[3][1]   = self:minusElement(self.atk[3][1], param.atk[3][1]);
            self.atk[3][2]   = self:minusElement(self.atk[3][2], param.atk[3][2]);
        end
    end

    if param.dfs then
        self.dfs[1]      = self:minusElement(self.dfs[1], param.dfs[1]);
        self.dfs[2]      = self:minusElement(self.dfs[2], param.dfs[2]);
        self.dfs[3]      = self:minusElement(self.dfs[3], param.dfs[3]);
    end

    --瑙掕壊鍩烘湰闈㈡澘灞炴€?
    self.strength    = self:minusElement(self.strength, param.strength)      --鍔涢噺
    self.magic       = self:minusElement(self.magic, param.magic)         --榄旀硶
    self.aligity     = self:minusElement(self.aligity,param.aligity)       --鏁忔嵎
    self.taoistMagic = self:minusElement(self.taoistMagic, param.taoistMagic)   --閬撴湳

    --杩欎袱涓奖鍝嶆槸鍚︽毚鍑?鍏堣绠楁毚鍑?璁＄畻澶辫触鍦ㄨ绠楀嚮涓拰韬查伩
    self.critRate    = self:minusElement(self.critRate, param.critRate)    --鏆村嚮鍔?
    self.defenCrit   = self:minusElement(self.defenCrit, param.defenCrit)   --鎶楁毚鍑诲姏

    --杩欎笁涓浉浜掑奖鍝嶆槸鍚﹀嚮涓拰韬查伩
    self.lucky       = self:minusElement(self.lucky, param.lucky)   --骞歌繍
    self.precise     = self:minusElement(self.precise, param.precise) --绮惧噯
    self.dodge       = self:minusElement(self.dodge, param.dodge)   --韬查伩鍔?

    self.slashSpeed  = self:minusElement(self.slashSpeed, param.slashSpeed)
	self.castSpeed   = self:minusElement(self.castSpeed, param.castSpeed)

    if param.speed then
        self.speed[1]    = self:minusElement(self.speed[1], param.speed[1])
        self.speed[2]    = self:minusElement(self.speed[2], param.speed[2])
    end
end

function Attribute:plusElement(e1, e2)
    if not e1 then
        return e2 or 0;
    end

    if not e2 then
        return e1 or 0;
    end

    return e1 + e2;
end

function Attribute:minusElement(e1, e2)
    if not e1 then
        return e2 or 0;
    end

    if not e2 then
        return e1 or 0;
    end

    return e1 - e2;
end

function Attribute:toString()
	local text = "";

	if self.atk[1] and self.atk[1][1] ~= 0 or self.atk[1][2] ~= 0 then
		text = text.."物理攻击        "..self.atk[1][1].."-"..self.atk[1][2].."\n";
	end
	if self.atk[2] and self.atk[2][1] ~= 0 or self.atk[2][2] ~= 0 then
		text = text.."魔法攻击        "..self.atk[2][1].."-"..self.atk[2][2].."\n";
	end
	if self.atk[3] and self.atk[3][1] ~= 0 or self.atk[3][2] ~= 0 then
		text = text.."道术攻击        "..self.atk[3][1].."-"..self.atk[3][2].."\n";
	end

	if self.dfs[1] and self.dfs[1] ~= 0 then
		text = text.."物理防御        "..self.dfs[1].."\n";
	end
	if self.dfs[2] and self.dfs[2] ~= 0 then
		text = text.."魔法防御        "..self.dfs[2].."\n";
	end
	if self.dfs[3] and self.dfs[3] ~= 0 then
		text = text.."道术防御        "..self.dfs[3].."\n";
	end

	if self.maxHp ~= 0 then
		text = text.."最大生命值      "..self.maxHp.."\n";
	end

	if self.maxMp ~= 0 then
		text = text.."最大魔法值      "..self.maxMp.."\n";
	end

	if self.critRate and self.critRate ~= 0 then
		text = text.."暴击                "..self.critRate.."\n";
	end

	if self.defenCrit and self.defenCrit ~= 0 then
		text = text.."抗暴击            "..self.defenCrit.."\n";
	end

	if self.slashSpeed and self.slashSpeed ~= 0 then
		text = text.."攻速               "..(-self.slashSpeed).."\n";
	end

	if self.precise and self.precise ~= 0 then
		text = text.."精准                "..(self.precise).."\n";
	end

	if self.dodge and self.dodge ~= 0 then
		text = text.."闪避                "..(self.dodge).."\n";
	end

	text = string.sub(text, 1, string.len(text)-1);

	return text;
end
