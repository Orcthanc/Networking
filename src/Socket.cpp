/*
 * =====================================================================================
 *
 *       Filename:  Socket.cpp
 *
 *    Description:  Definition for Socket.hpp
 *
 *        Version:  1.0
 *        Created:  04/16/2020 09:24:39 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */

#include "Socket.hpp"
#include <errno.h>

using namespace Inet;

UDPSocket::UDPSocket( int family ){
	sock = socket( family, SOCK_DGRAM, IPPROTO_UDP );

#ifdef _WIN32
	if( INVALID_SOCKET == sock ){
		throw std::runtime_error( "socket() returned INVALID_SOCKET (" + std::to_string( WSAGetLastError() ) + ")");
	}
#else
	if( 0 > sock ){
		throw std::runtime_error( "socket() returned no socket. (errno: " + std::to_string( errno ) + ")");
	}
#endif
}

UDPSocket::~UDPSocket(){
#ifdef _WIN32
	closesocket( sock );
#else
	close( sock );
#endif
}

UDPSocket::UDPSocket( const SocketAddress4& saddr ): UDPSocket( AF_INET ){
	if( 0 != bind( sock, &( saddr.socket_address ), saddr.size() )){
		throw std::runtime_error( "bind failed with error: " + std::to_string( last_error() ));
	}
}

int UDPSocket::send_to( const void* data, size_t data_len, const SocketAddress4& to ){
	return sendto( sock, static_cast<const char*>( data ), data_len, 0, &( to.socket_address ), to.size() );
}

int UDPSocket::recv_from( void* data, size_t data_len, SocketAddress4& to ){
	socklen_t size = to.size();
	return recvfrom( sock, data, data_len, 0, &( to.socket_address ), &size );
}

