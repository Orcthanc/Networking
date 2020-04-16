/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main test file
 *
 *        Version:  1.0
 *        Created:  04/01/2020 08:48:01 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */

#include "SocketAddress.hpp"
#include "Socket.hpp"

int main( int argc, char** argv ){
	Inet::inet_init();
	/*
	Inet::SocketAddress4( "192.168.178.32:55565" );
	Inet::SocketAddress4( "www.google.de:55565" );

	*/
	Inet::SocketAddress4 test( "localhost:55565" );

	Inet::SocketAddress4 bindto( htonl( INADDR_ANY ), 55564 );

	Inet::UDPSocket sock( bindto );
	std::cout << sock.send_to( "ASDF\n", 6, test ) << std::endl;

	Inet::inet_cleanup();

#ifdef _WIN32
	system("pause");
#endif
}
