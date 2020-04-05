/*
 * =====================================================================================
 *
 *       Filename:  SocketAddress.cpp
 *
 *    Description:  Implementation for SocketAddress.h
 *
 *        Version:  1.0
 *        Created:  04/01/2020 09:19:33 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */

#include "SocketAddress.hpp"

#include <iostream>

using namespace Inet;

SocketAddress4::SocketAddress4( uint32_t in_address, uint16_t in_port ){
	get_sockaddr_inptr()->sin_family = AF_INET;
	get_sockaddr_inptr()->sin_addr.s_addr = htonl( in_address );
	get_sockaddr_inptr()->sin_port = htons( in_port );
}

SocketAddress4::SocketAddress4( const sockaddr& addr ){
	memcpy( &socket_address, &addr, sizeof( socket_address ));
}

SocketAddress4::SocketAddress4( const char* address ){
	std::string addr( address );
	std::string host, port;

	auto pos = addr.find( ':' );

	if( pos == std::string::npos ){
		host = addr;
		port = std::to_string( DEFAULT_PORT );
	} else {
		host = addr.substr( 0, pos );
		port = addr.substr( pos + 1 );
	}

	addrinfo hint;
	memset( &hint, 0, sizeof( hint ));
	hint.ai_family = AF_INET;

	addrinfo* res;
	{
		int temp = getaddrinfo(host.c_str(), port.c_str(), &hint, &res);

		if (0 != temp) {
			throw std::runtime_error("SocketAddress4::SocketAddress4( const char* )");
		}
	}
	addrinfo* temp = res;

	while( !temp->ai_addr && temp->ai_next ){
		temp = temp->ai_next;
	}

	if( !temp->ai_addr )
		throw std::runtime_error( "SocketAddress4::SocketAddress4( const char* )" );

	char buf[100];
	inet_ntop( temp->ai_family, &((sockaddr_in*)temp->ai_addr)->sin_addr, buf, 100 );
	std::cout << buf << std::endl;


	memcpy( &this->socket_address, &temp->ai_addr, sizeof( socket_address ));
	freeaddrinfo( res );

}

size_t SocketAddress4::size(){
	return sizeof( socket_address );
}

sockaddr_in* SocketAddress4::get_sockaddr_inptr(){
	return reinterpret_cast<sockaddr_in*>( &socket_address );
}
