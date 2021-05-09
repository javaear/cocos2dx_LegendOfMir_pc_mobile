
#include "cocos2d.h"
#include <vector>

using namespace std;
using namespace cocos2d;

struct ImageInfo
{
	string name;
	string extension;
};

class AsyncLoader : public Node
{
public:
	AsyncLoader(void);
	~AsyncLoader(void);

	CREATE_FUNC(AsyncLoader);

	void				addLoadImg(const char* imgFilename, const char* extension);
	void				launchLoad(const char* callback);
	void                setIsLoadPlist(bool);
	float               getLoadingPercent();
	void                release();

private:
	void				loadingCallBack(Texture2D* texture);
	void				loadingThread();
	void                dispatcherEvent(const char* name, void* data=0);

	bool                m_isLoadPlist;
	bool                m_isLoading;
	int                 m_curLoadingPicCount;
	int                 m_curLoadingPlistCount;

	string              m_loadingCallBack;

	mutex				m_mutex;//线程互斥对象

	//img info vec
	vector<ImageInfo>   m_loadingImgInfoVec;
};

