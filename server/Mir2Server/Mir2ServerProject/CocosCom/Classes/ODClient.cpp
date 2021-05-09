#include "ODClient.h"
#include "ODSocket.h"

ODClient::ODClient(void)
{
	m_isSuccess = false;
	m_currMsgIndex = 0;
	m_clientSocket = 0;
	m_isUsed = false;
	m_recvMsgHeadLength = 0;
	m_recvStatus = ClientRecvStatus::WAITING_FOR_MSG;
}


ODClient::~ODClient(void)
{
	if (m_clientSocket != 0)
		delete m_clientSocket;
}

bool ODClient::init()
{
	if (m_clientSocket == 0)
		m_clientSocket = new ODSocket();

	return true;//((ODSocket*)m_clientSocket)->Init();
}
	
bool ODClient::createSocket(int af, int type, int protocol)
{
	return ((ODSocket*)m_clientSocket)->Create(af, type, protocol);
}

bool ODClient::connect(const char* ip, unsigned short port)
{
	m_isSuccess = ((ODSocket*)m_clientSocket)->Connect(ip, port);

	return m_isSuccess;
}

bool ODClient::listen()
{
	if (m_isSuccess)
	{
		//std::thread t(&ODClient::listenBackFunc, this);
		//t.detach();

		return true;
	}
	else
		return false;
}

void ODClient::listenBackFunc()
{
	while(m_isSuccess)
	{
		char recvBuff[4];
		//char recvBuf[MSG_HEAD_LEN];// 获取请求头的 数据  
		int ret = ((ODSocket*)m_clientSocket)->Recv(recvBuff, 4,0);

		if (ret == SOCKET_ERROR || ret == 0)
		{
			clean();
			return;
		}
		
		//请求数据主体
		int msgLen;
		memcpy(&msgLen, recvBuff, sizeof(msgLen));

		//short msgLen = my_atoi(recvBuf);
		char* msgBuf = new char[msgLen];
		((ODSocket*)m_clientSocket)->Recv(msgBuf, msgLen,0);

		m_mutex.lock();
		m_msgVec.push_back(msgBuf);
		m_mutex.unlock();

		delete msgBuf;
	}
}

int	ODClient::send(const char* buf, int flags)
{
	if (m_isSuccess == false)
		return 0;

	int len = strlen(buf) + 1;

	char headBuff[4];
	memcpy(headBuff, &len, sizeof(len));

	//send msg head
	((ODSocket*)m_clientSocket)->Send(headBuff, 4, 0);

	int ret = ((ODSocket*)m_clientSocket)->Send(buf, len, 0);

	//send msg content
	return ret;
}

void ODClient::setConnectSuccess(bool success)
{
	m_isSuccess = success;
}

bool ODClient::getOffLine()
{
	if (m_clientSocket == 0)
		return true;

	return !m_isSuccess;
}

void ODClient::recvMsgHead()
{
	char recvBuff[4];
	//char recvBuf[MSG_HEAD_LEN];// 获取请求头的 数据  
	int ret = ((ODSocket*)m_clientSocket)->AsynRecv(recvBuff, 4,0);

	if (ret == SOCKET_ERROR || ret == 0)
		clean();
	else if(ret > 0)
	{
		memcpy(&m_recvMsgHeadLength, recvBuff, sizeof(m_recvMsgHeadLength));//获取消息头,表示后续消息的长度
		m_recvStatus = WAITING_FOR_MSG_CONTENT;
	}
}
	
void ODClient::recvMsgContent()
{
	char* msgBuf = new char[m_recvMsgHeadLength];

	int ret = ((ODSocket*)m_clientSocket)->Recv(msgBuf, m_recvMsgHeadLength,0);
	if (ret == SOCKET_ERROR || ret == 0)
		clean();
	else if(ret > 0)
	{
		m_msgVec.push_back(msgBuf);
		m_recvStatus = WAITING_FOR_MSG;
	}

	delete[] msgBuf;
}

bool ODClient::hasNewMessage()
{
	if (m_clientSocket != 0)
	{
		switch (m_recvStatus)
		{
			case ClientRecvStatus::WAITING_FOR_MSG:
				recvMsgHead();
				break;
			case ClientRecvStatus::WAITING_FOR_MSG_CONTENT:
				recvMsgContent();
				break;
		}
	}

	if (m_currMsgIndex < m_msgVec.size())
		return true;

	return false;
}

char* ODClient::getNewMessage()
{
	if (m_currMsgIndex >= m_msgVec.size())
		return 0;

	char* msg = (char*)m_msgVec[m_currMsgIndex].c_str();

	m_currMsgIndex ++;

	return msg;
}

void ODClient::setODSocket(void* socket)
{
	m_clientSocket = socket;
	m_isSuccess = true;
}

void ODClient::setID(int id)
{
	m_clientID = id;
}

int ODClient::getID()
{
	return m_clientID;
}


void ODClient::clean()
{
	if (m_clientSocket)
		((ODSocket*)m_clientSocket)->Close();

	//m_clientSocket = 0;
	m_isSuccess = false;
	m_isUsed = false;
	m_recvMsgHeadLength = 0;
	m_recvStatus = ClientRecvStatus::WAITING_FOR_MSG;
}

void* ODClient::getODSocket()
{
	return m_clientSocket;
}

void ODClient::autorelease()
{

}

int my_atoi(const char *str)
{
	int result = 0;
	int signal = 1; /* 默认为正数 */
	if((*str>='0'&&*str<='9')||*str=='-'||*str=='+')
	{
		if(*str=='-'||*str=='+')
		{
			if(*str=='-')
				signal = -1; /* 输入负数 */
			str++;
		}
	}
	else
		return result;

	while(*str>='0'&&*str<='9')
		result = result*10+(*str++ -'0');

	return signal*result;
}