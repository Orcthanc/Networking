/*
 * =====================================================================================
 *
 *       Filename:  Socket.hpp
 *
 *    Description:  Contains UDP and TCP sockets
 *
 *        Version:  1.0
 *        Created:  04/16/2020 04:40:26 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */
#pragma once

#include "SocketAddress.hpp"

namespace Inet {
	class UDPSocket {
		public:
			UDPSocket( const SocketAddress4& );
			~UDPSocket();

			UDPSocket( const UDPSocket& ) = delete;
			UDPSocket( UDPSocket&& ) = default;

			UDPSocket& operator=( const UDPSocket& ) = delete;
			UDPSocket& operator=( UDPSocket&& ) = default;

			int send_to( const void* data, size_t data_len, const SocketAddress4& to );
			int recv_from( void* data, size_t data_len, SocketAddress4& from );

		private:
			UDPSocket( int family );

			Socket sock;
	};

	using UDPSocket_p = std::shared_ptr<UDPSocket>;
}
