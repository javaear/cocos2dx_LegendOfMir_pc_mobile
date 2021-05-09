#include "ODServer.h"
#include "ODSocket.h"

ODServer::ODServer(void)
{
	m_isListening = false;
}


ODServer::~ODServer(void)
{
}

bool ODServer::init()
{
	m_svrSocket = new ODSocket();
	((ODSocket*)m_svrSocket)->Init();

	initClientStorage(10);

	return true;
}

bool ODServer::initClientStorage(int num)
{
	for (int i=0;i<num;++i)
	{
		ODClient* client = ODClient::create();

		putClientInStorage(client);
	}

	return true;
}

void ODServer::putClientInStorage(ODClient* client)
{
	m_clientStorage.push_back(client);
}

ODClient* ODServer::getFreeClient()
{
	for (int i=0;i<m_clientStorage.size();++i)
	{
		ODClient* client = m_clientStorage[i];

		if (client->m_isUsed == false)
		{
			client->m_isUsed = true;
			return client;
		}
	}

	ODClient* client = ODClient::create();
	putClientInStorage(client);

	client->m_isUsed = true;
	
	return client;
}

bool ODServer::createSocket(int af, int type, int protocol)
{
	return ((ODSocket*)m_svrSocket)->Create(af, type, protocol);
}

ODClient* ODServer::accept()
{
	ODClient* client = getFreeClient();
	char ipSocket[64];

	ODSocket* socket = (ODSocket*)client->getODSocket();
	bool ret = ((ODSocket*)m_svrSocket)->Accept(*socket, ipSocket);

	if (ret)
	{
		client->setID(int(client));
		client->setConnectSuccess(true);

		return client;
	}
	else
		return 0;
}

bool ODServer::bind(int port)
{
	return ((ODSocket*)m_svrSocket)->Bind(port);
}

bool ODServer::listen(bool isLaunchThread)
{
	if (m_isListening)
		return false;

	auto ret = ((ODSocket*)m_svrSocket)->Listen();

	if (!ret)
		return false;

	if (isLaunchThread)
	{
		std::thread t(&ODServer::listenBackFunc, this);
		t.detach();
	}
	else
		listenBackFunc();

	return true;
}

void ODServer::listenBackFunc()
{
	m_isListening = true;

	while(m_isListening)
	{
		ODClient* client = accept();

		if (client == 0)
			return;

		m_mutex.lock();
		m_clientGroups.push_back(client);
		m_mutex.unlock();
	}

	m_isListening = false;
}

void ODServer::setListening(bool listening)
{
	m_isListening = listening;
}

/*
vector<ODClient*> ODServer::getClientGroups()
{
	return m_clientGroups;
}
*/
bool ODServer::hasClient()
{
	if (m_clientGroups.size() >= 1)
		return true;

	return false;
}

ODClient* ODServer::popBackClient()
{
	if (m_clientGroups.size() <= 0)
	{
		return 0;
	}

	ODClient* client = m_clientGroups[m_clientGroups.size()-1];
	m_clientGroups.pop_back();
	
	return client;
}

void ODServer::clearClientGroups()
{
	m_clientGroups.clear();
}

void ODServer::clean()
{
	((ODSocket*)m_svrSocket)->Close();
	((ODSocket*)m_svrSocket)->Clean();
	m_isListening = false;

	for (int i=0;i<m_clientStorage.size();++i)
	{
		ODClient* client = m_clientStorage[i];
		delete client;
	}

	m_clientStorage.clear();
	m_clientGroups.clear();
}

void ODServer::autorelease()
{

}
