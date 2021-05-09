#include "AsyncLoader.h"

AsyncLoader::AsyncLoader(void)
{
	m_curLoadingPicCount = 0;
	m_curLoadingPlistCount = 0;
	m_isLoadPlist = false;
	m_isLoading = false;
}

AsyncLoader::~AsyncLoader(void)
{
}

void AsyncLoader::setIsLoadPlist(bool isLoadPlist)
{
	m_isLoadPlist = isLoadPlist;
}

void AsyncLoader::addLoadImg(const char* imgFilename, const char* extension)
{
	ImageInfo img;
	img.name = imgFilename;
	img.extension = extension;

	m_loadingImgInfoVec.push_back(img);
}

void AsyncLoader::launchLoad(const char* callback)
{
	m_isLoading = true;
	m_loadingCallBack = callback;

	for (int i=0;i<m_loadingImgInfoVec.size();++i)
	{
		ImageInfo img = m_loadingImgInfoVec[i];
		string fullImgPath = img.name+"."+img.extension;

		Director::getInstance()->getTextureCache()->addImageAsync(fullImgPath, 
			CC_CALLBACK_1(AsyncLoader::loadingCallBack, this));
	}
}

void AsyncLoader::loadingCallBack(Texture2D* texture)
{
	m_curLoadingPicCount ++;

	if (m_curLoadingPicCount >= m_loadingImgInfoVec.size()) 
	{
		if (m_isLoadPlist)
		{
			thread t1(&AsyncLoader::loadingThread, this);
			t1.detach();
		}

		m_isLoading = false;
	}

	if (m_isLoadPlist == false)
		dispatcherEvent(m_loadingCallBack.c_str());
}

void AsyncLoader::loadingThread()
{
	for (int i=0;i<m_loadingImgInfoVec.size();++i)
	{
		ImageInfo img = m_loadingImgInfoVec[i];
		string fullImgPath = img.name+"."+img.extension;
		string plistPath = img.name + ".plist";

		Texture2D* texture = Director::getInstance()->getTextureCache()->getTextureForKey(fullImgPath);
		texture->setAliasTexParameters();
		SpriteFrameCache::getInstance()->addSpriteFramesWithFileWithoutAutoRelease(plistPath, texture);

		m_mutex.lock();     //加锁  
		m_curLoadingPlistCount = i+1;
		m_mutex.unlock();   //解锁

		//发送加载资源进度事件
		dispatcherEvent(m_loadingCallBack.c_str());
	}
}

void AsyncLoader::dispatcherEvent(const char* name, void* data)
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	EventCustom newEvent(name);

	if (data != 0)
		newEvent.setUserData(data);

	dispatcher->dispatchEvent(&newEvent);
}

float AsyncLoader::getLoadingPercent()
{
	float percent = 0.0f;
	if (m_isLoadPlist)
		percent = (float)m_curLoadingPlistCount/(float)m_loadingImgInfoVec.size();
	else
		percent = (float)m_curLoadingPicCount/(float)m_loadingImgInfoVec.size();

	return percent;
}

void AsyncLoader::release()
{
	if (m_isLoading)
		return;

	m_loadingImgInfoVec.clear();
	m_curLoadingPicCount = 0;
	m_curLoadingPlistCount = 0;
	m_isLoadPlist = false;
}