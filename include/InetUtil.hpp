/*
 * =====================================================================================
 *
 *       Filename:  InetUtil.hpp
 *
 *    Description:  Useful stuff regarding internet connections
 *
 *        Version:  1.0
 *        Created:  04/01/2020 08:49:01 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */
#pragma once

#define DEFAULT_PORT 51347

#ifdef _WIN32

	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX

	#include "Windows.h"
	#include "WinSock2.h"
	#include "Ws2tcpip.h"

	#pragma comment(lib, "Ws2_32.lib")

	using socklen_t = int;
	using Socket = SOCKET;

	#define INET_WOULD_BLOCK WSAEWOULDBLOCK
	#define INET_CONN_RESET WSAECONNRESET

#else

	#include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <errno.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <cstring>

	using Socket = int;
	using sockaddr_in = struct sockaddr_in;

	#define INET_WOULD_BLOCK EAGAIN
	#define INET_CONN_RESET ECONNRESET

#endif

#include <memory>
#include <stdexcept>

#include <vector>
#include <string>
#include <iostream>

namespace Inet {
	inline void inet_init(){
#ifdef _WIN32
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if ( iResult != NO_ERROR )
		{
			throw std::runtime_error( "Could not start WSA" );
		}
#endif
	}

	inline void inet_cleanup(){
#ifdef _WIN32
		WSACleanup();
#endif
	}
}
