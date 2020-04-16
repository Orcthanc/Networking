/*
 * =====================================================================================
 *
 *       Filename:  SocketAddress.hpp
 *
 *    Description:  Represents a socket address
 *
 *        Version:  1.0
 *        Created:  04/01/2020 09:09:44 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */
#pragma once

#include "InetUtil.hpp"

namespace Inet {
	struct SocketAddress4 {
		SocketAddress4( uint32_t in_address, uint16_t in_port );
		SocketAddress4( const sockaddr& sock_addr );
		SocketAddress4( const char* address );
		sockaddr_in* get_sockaddr_inptr();
		size_t size() const;

		sockaddr socket_address;
	};

	using SocketAddress4_p = std::shared_ptr<SocketAddress4>;
}
