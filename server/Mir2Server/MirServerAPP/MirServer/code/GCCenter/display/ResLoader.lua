--region NewFile_1.lua
--Author : legend
--Date   : 2015/7/14
--此文件由[BabeLua]插件自动生成



--endregion
ResLoader = {}
ResLoader.framesOffset = {}

function ResLoader:readXFile(path)
    local fileData = cc.FileUtils:getInstance():getStringFromFile(path);
    local rows = split(fileData, "\r\n")

    for k,v in pairs(rows) do
        local data = split(v, " ");

        if data[1] == "2" then
            ResLoader:parseAnimation(data);
        elseif data[1] == "1" then
            ResLoader.framesOffset[data[2]] = {x=tonumber(data[8]), y=tonumber(data[9])};
        end
    end
end

function ResLoader:parseAnimation(data)
    local animation = cc.Animation:create();
    animation:retain();
    animation:setLoops(tonumber(data[4]));
    animation:setDelayPerUnit(tonumber(data[5]));

    if data[6] == "1" then
        animation:setRestoreOriginalFrame(true);
    else
        animation:setRestoreOriginalFrame(false);
    end

    local framesName = split(data[3], "&");
    for k,v in pairs(framesName) do
        local frame = engine.getSpriteFrame(v);
        local offset = ResLoader.framesOffset[v];

        local size = frame:getOriginalSize();
        frame:setOffset({x=offset.x, y=-offset.y-size.height+TILE_HEIGHT});

        if frame ~= 0 then
            animation:addSpriteFrame(frame);
        end
    end

    cc.AnimationCache:getInstance():addAnimation(animation, data[2]);
end