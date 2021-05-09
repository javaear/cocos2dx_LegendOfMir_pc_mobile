#include "ODClient.h"
#include <string>
#include <map>
#include <mutex>
#include <thread>

using namespace std;

class ODServer : public Node
{
public:
	ODServer(void);
	~ODServer(void);

	bool				init();               
	bool				createSocket(int af, int type, int protocol = 0);
	bool				bind(int port);
	bool				listen(bool isLaunchThread=false);
	void                listenBackFunc();
	void                setListening(bool listening);

	bool				initClientStorage(int num);
	void                putClientInStorage(ODClient* client);
	ODClient*			getFreeClient();

	//vector<ODClient*>	getClientGroups();
	bool				hasClient();
	ODClient*			popBackClient();
	void				clearClientGroups();

	//release
	void				autorelease();
	void				clean();

	CREATE_FUNC(ODServer);

private:
	ODClient*			accept();
	void*				m_svrSocket;
	bool				m_isListening;
	mutex				m_mutex;

	vector<ODClient*>	m_clientGroups;
	vector<ODClient*>	m_clientStorage;
};

