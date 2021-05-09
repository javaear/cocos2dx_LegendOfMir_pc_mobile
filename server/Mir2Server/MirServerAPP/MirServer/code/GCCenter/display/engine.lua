engine = {}
engine.animationArray = {}

engine.initLabel = function(name)
    local label = cc.Label:create()--cc.Label:createWithTTF("","",10);
    label:setString(name);

    return label;
end

engine.initSpriteWithOffset = function(dir, file)
    local frame = engine.getSpriteFrame(dir.."/"..file);
    local str = split(file, ".");
    local offset = engine.registFramesOffset(dir.."/Placements/"..str[1]..".txt");

    local size = frame:getOriginalSize();
    frame:setOffset({x=offset.x, y=offset.y-size.height});

    local sprite = engine.initSpriteFromSpriteFrame(frame);
    sprite:setAnchorPoint(0, 0);
    return sprite;
end

engine.initSprite = function(imgPath)
    if not imgPath then
        return nil;
    end

    local sprite = et.SpriteX:create(imgPath);
    if not sprite then
        local frame = cc.SpriteFrameCache:getInstance():getSpriteFrame(imgPath);
        
        sprite = et.SpriteX:createWithSpriteFrame(frame);
    end 

    return sprite;
end

engine.initSpriteFromSpriteFrame = function(spriteFrame)
    return et.SpriteX:createWithSpriteFrame(spriteFrame);
end

engine.getBlankSprite = function()
    local aSprite = ActionSprite:create();
    local sprite = engine.initSprite("temporary/blank.png");
    sprite:retain();
    aSprite.sprite = sprite;

    return aSprite;
end

engine.getAnimation = function(name)
    local ani = cc.AnimationCache:getInstance():getAnimation(name)

    if not ani then
        g_rsyncLoader:loadPreloadAnimationData(name);
        ani = cc.AnimationCache:getInstance():getAnimation(name)
    end

    return ani;
end

engine.getSpriteFrame = function(name)
    local frame = cc.SpriteFrameCache:getInstance():getSpriteFrame(name);

    if not frame then
        local texture = cc.Director:getInstance():getTextureCache():addImage(name)

        if texture then
            local rect = cc.rect(0, 0, texture:getPixelsWide(), texture:getPixelsHigh())
            frame = cc.SpriteFrame:createWithTexture(texture, rect)
        end
    end

    return frame;
end

engine.getDefaultSpriteFrame = function()
    local texture = cc.Director:getInstance():getTextureCache():addImage("temporary/blank.png");
    local rect = cc.rect(0, 0, texture:getPixelsWide(), texture:getPixelsHigh())
    local frame = cc.SpriteFrame:createWithTexture(texture, rect)

    return frame;
end

engine.getTexture2D = function(name)
    return cc.TextureCache:getInstance():getTextureForKey(name);
end

engine.initSpriteWithRect = function(imgPath, rect)
    local sprite = et.SpriteX:create(imgPath, rect);
    
    if not sprite then
        TraceError(imgPath.." no found");
    end 

    return sprite;
end

engine.initSpriteWithRect = function(imgPath, x, y, width, height)
    local rect = {x = x, y = y, width = width, height = height}
    return et.SpriteX:create(imgPath,rect);
end

--额外添加一个增加每一帧对应的偏移位置
engine.registFramesOffset = function(fileName)
    local fileIsExit = cc.FileUtils:getInstance():isFileExist(fileName)
    if fileIsExit == false then
        TraceError("找不到该文件" .. fileName)
        return nil;
    end

    local fileData = cc.FileUtils:getInstance():getStringFromFile(fileName);
    local rows = split(fileData, "\r\n")
    local x = tonumber(rows[1]);
    local y = -tonumber(rows[2]) + TILE_HEIGHT;

    return {x=x, y=y};
end

engine.getFramesInfoList = function(info, isReadOffset)
    local framesName = {};
    local framesOffset = {};

    for index = info.offset, info.offset + info.count - 1, info.step do
        local frameName = string.format(info.sz_path.."_%06d.png", index)

        table.insert(framesName, #framesName+1, frameName);
            
        --增加帧偏移量
        if isReadOffset == true then
            local frameOffsetFile = string.format(info.sz_path.."/Placements/%06d.txt", index)
            local offsetPoint = engine.registFramesOffset(frameOffsetFile);
            table.insert(framesOffset, #framesOffset+1, offsetPoint);
        end
    end

    return framesName, framesOffset;
end

engine.initSpriteFromFrameCache = function(name)
    local frameCache = cc.SpriteFrameCache:getInstance();
    local spriteFrame = frameCache:getSpriteFrame(name);
    local sprite = cc.Sprite:createWithSpriteFrame(spriteFrame);
    return sprite;
end

engine.initAnimationFromNames = function(aniName, names, delay, isLoops, offsetTable, backFirstFrame)
    local animation = cc.Animation:create();
    animation:setLoops(isLoops);
    animation:setDelayPerUnit(delay);
    animation:setRestoreOriginalFrame(backFirstFrame);

    for key, value in pairs(names) do
        local frame = engine.getSpriteFrame(value);
        
        --[[
        if not frame and key == 1 then
            return nil;]]
        if not frame then
            frame = engine.getDefaultSpriteFrame();
        end

        --设置帧偏移量
        if offsetTable ~= nil and offsetTable[key] ~= nil then 
            local size = frame:getOriginalSize();
            frame:setOffset({x=offsetTable[key].x, y=offsetTable[key].y-size.height})
        else
            TraceError(value.."设置偏移量失败:"..tostringex(offsetTable))
        end
        
        animation.addSpriteFrame(animation,frame)
    end
    
    local oldAnimation = cc.AnimationCache:getInstance():getAnimation(aniName)
    if oldAnimation ~= nil then
        TraceError(aniName.." already exit");
    end
    
    cc.AnimationCache:getInstance():addAnimation(animation,aniName)

    return animation;
end

engine.loadAnimationResource = function(conf, name, isReadOffset, backFirstFrame)
    local startOffset = conf[1].offset;

    if engine.animationArray[startOffset..name] ~= nil then
        return 0;  --已存在动画缓存
    end

    for index,info in pairs(conf) do
        --生成动画信息
        local framesName, framesOffset = engine.getFramesInfoList(info, isReadOffset);

        --增加缓冲动画
        local aniname = name..info.offset.."_"..index;
        local animation = engine.initAnimationFromNames(aniname, framesName, info.delay, info.isLoops, framesOffset, backFirstFrame);
        if animation == nil then
            TraceError(name.."的第"..index.."动画加载失败");
        end
    end
    
    engine.animationArray[startOffset..name] = conf;
    
    return 1;
end

engine.readAniConfToSprite = function(conf, name)
    local actions = {};
    local startOffset = conf[1].offset;

    for index=1, #conf, 1 do
        local offset = conf[index].offset;
        local animationName = name.."_"..startOffset.."_"..index;
        local animation = engine.getAnimation(animationName);
        
        if animation == nil then
            g_rsyncLoader:loadPreloadAnimationData(animationName);
            animation = engine.getAnimation(animationName);
            
            if not animation then
                

                TraceError(name.."_"..startOffset.."_"..index.." no found");
                return engine.getBlankSprite();
            end
        end
        
        local animate = cc.Animate:create(animation);
        actions[tostring(index)] = animate;
    end
    
    local aSprite = ActionSprite:create();
    aSprite:addActions(actions);
    
    return aSprite;
end

--[[
engine.readActionSpriteFromIndex = function(path)
    local spriteConf = readTabFile(path)
    
    if not spriteConf then
        return nil;
    end

    if engine.animationArray[path] == nil then   --该资源文件没有加载过   
        engine.loadAnimationResource(spriteConf, path, true, false)
    end
    
    return engine.readAniConfToSprite(spriteConf, path);
end]]

--生成精灵的读取配置表
--参数 1.文件路径  2.开始偏移位  3.动画帧数  4.动画数量   5.空图片数量  6.播放速度  7.是否循环
engine.figureSpriteConf = function(path, startOffset, framesPerAni, aniCount, interval, delay, isLoops)
    local confs = {};
    --(path, startOffset+0, 4, 8, 4, 0.2, -1)
    for i=0, aniCount-1 do
        local conf = {}
        conf.sz_name = path.."/"..startOffset.."/"..i;
        conf.sz_path = path;
        conf.offset = startOffset + (interval+framesPerAni)*i;
        conf.count = framesPerAni;
        conf.delay = delay;
        conf.isLoops = isLoops;
        conf.step = 1;

        table.insert(confs, #confs+1, conf);
    end

    return confs;
end

--------------------------读取角色动画的函数--------------------------
engine.readBodyMapSprite = function(path, startOffset)
    local spriteConf = nil;


    if engine.animationArray[path..startOffset] == nil then   --该资源文件没有加载过  
        spriteConf = engine.readBodyConf(path, startOffset);

        --engine.loadAnimationResource(spriteConf, path, true, false)
        engine.animationArray[path..startOffset] = spriteConf;
    else
        spriteConf = engine.animationArray[path..startOffset];
    end
  
    return engine.readAniConfToSprite(spriteConf, path);
end

engine.readBodyConf = function(path, startOffset)
    local conf = {};
    
    --stand    1
    local standArray = engine.figureSpriteConf(path, startOffset+0, 4, 8, 4, 0.2, -1);
    for k,v in pairs(standArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --walk     2
    local moveArray = engine.figureSpriteConf(path, startOffset+64, 6, 8, 2, 0.2, -1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end

    --attack   3
    local attackArray = engine.figureSpriteConf(path, startOffset+200, 6, 8, 2, 0.1, 1);
    for k,v in pairs(attackArray) do
        table.insert(conf, #conf+1, v);
    end

    --hurt   4
    local hurtArray = engine.figureSpriteConf(path, startOffset+472, 3, 8, 5, 0.1, 1);
    for k,v in pairs(hurtArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --die   5
    local dieArray = engine.figureSpriteConf(path, startOffset+536, 4, 8, 4, 0.1, 1);
    for k,v in pairs(dieArray) do
        table.insert(conf, #conf+1, v);
    end

    --run   6
    local moveArray = engine.figureSpriteConf(path, startOffset+128, 6, 8, 2, 0.2, -1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --idle   7 
    local attackArray = engine.figureSpriteConf(path, startOffset+192, 1, 8, 0, 0.1, 1);
    for k,v in pairs(attackArray) do
        table.insert(conf, #conf+1, v);
    end

    --attack2  8
    local attackArray = engine.figureSpriteConf(path, startOffset+264, 6, 8, 2, 0.1, 1);
    for k,v in pairs(attackArray) do
        table.insert(conf, #conf+1, v);
    end

    --cast    9
    local castArray = engine.figureSpriteConf(path, startOffset+392, 6, 8, 2, 0.1, 1);
    for k,v in pairs(castArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --drag    10
    local digArray = engine.figureSpriteConf(path, startOffset+456, 2, 8, 0, 0.2, 1);
    for k,v in pairs(digArray) do
        table.insert(conf, #conf+1, v);
    end
    
    return conf;
end

--怪物动画
engine.readMonsterSprite = function(path, startOffset)
    local spriteConf = nil;

    if engine.animationArray[path..startOffset] == nil then   --该资源文件没有加载过  
        spriteConf = engine.readMonsterConf(path, startOffset);
        --engine.loadAnimationResource(spriteConf, path, true, false)
        engine.animationArray[path..startOffset] = spriteConf;
    else
        spriteConf = engine.animationArray[path..startOffset];
    end

    return engine.readAniConfToSprite(spriteConf, path);
end

--怪物动画配置
engine.readMonsterConf = function(path, startOffset)
    local conf = {}

    --参数 1.文件路径  2.开始偏移位  3.动画帧数  4.动画数量   5.空图片数量  6.播放速度  7.是否循环
    --stand  1
    local standArray = engine.figureSpriteConf(path, startOffset+0, 4, 8, 6, 0.2, -1);
    for k,v in pairs(standArray) do
        table.insert(conf, #conf+1, v);
    end

    --walk   2
    local moveArray = engine.figureSpriteConf(path, startOffset+80, 6, 8, 4, 0.2, -1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --attack  3
    local moveArray = engine.figureSpriteConf(path, startOffset+160, 6, 8, 4, 0.2, 1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --hurt   4
    local moveArray = engine.figureSpriteConf(path, startOffset+240, 2, 8, 0, 0.2, 1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end
    
    --die   5
    local moveArray = engine.figureSpriteConf(path, startOffset+260, 10, 8, 0, 0.2, 1);
    for k,v in pairs(moveArray) do
        table.insert(conf, #conf+1, v);
    end
    
    return conf;
end

--读取只有一个状态即8个动画的动画精灵,一般用于特效
engine.readSingleSprite = function(param)
    if not param then
        return;
    end
    --[[
    local conf = engine.figureSpriteConf(param.sz_path, param.offset, param.framePerAni, param.aniCount, param.blankCount, param.delay, param.isLoop);

    if engine.animationArray[param.sz_path..param.offset] == nil then   --该资源文件没有加载过   
        engine.loadAnimationResource(conf, param.sz_path, true, true)
    end

    return engine.readAniConfToSprite(conf, param.sz_path);
    ]]

    local spriteConf = nil;
    local index = param.sz_path..param.offset;

    if engine.animationArray[index] == nil then   --该资源文件没有加载过  
        spriteConf = engine.figureSpriteConf(param.sz_path, param.offset, param.framePerAni, param.aniCount, param.blankCount, param.delay, param.isLoop);
        --engine.loadAnimationResource(spriteConf, param.sz_path, true, false)
        engine.animationArray[index] = spriteConf;
    else
        spriteConf = engine.animationArray[index];
    end

    return engine.readAniConfToSprite(spriteConf, param.sz_path);
end

--------------------------end--------------------------
--一些引擎函数
engine.listenerGroup = {};
engine.dispachEvent = function(name, info)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    local event = cc.EventCustom:new(name)
    event.info = info;
    eventDispatcher:dispatchEvent(event);
end

engine.addEventListenerWithScene = function(node, name, func)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()

    engine.listenerGroup[name] = cc.EventListenerCustom:create(name, func)
    --eventDispatcher:addCustomEventListener(name, func)

    eventDispatcher:addEventListenerWithSceneGraphPriority(engine.listenerGroup[name], node);
end

engine.addEventListener = function(name, func)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()

    engine.listenerGroup[name] = cc.EventListenerCustom:create(name, func)
    --eventDispatcher:addCustomEventListener(name, func)

    eventDispatcher:addEventListenerWithFixedPriority(engine.listenerGroup[name], 2);
end

engine.removeEventListener = function(name)
    eventDispatcher:removeCustomEventListeners(name);

    if engine.listenerGroup[name] then
        local listener = engine.listenerGroup[name];
        local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    
        eventDispatcher:removeEventListener(listener);
    end
end

engine.gettime = function()
    return socket.gettime();
end
