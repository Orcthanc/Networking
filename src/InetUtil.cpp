/*
 * =====================================================================================
 *
 *       Filename:  InetUtil.cpp
 *
 *    Description:  Required for Windows...
 *
 *        Version:  1.0
 *        Created:  04/03/2020 04:55:16 PM
 *       Revision:  none
 *
 *         Author:  Samuel Knoethig (), samuel@knoethig.net
 *
 * =====================================================================================
 */

#if _WIN32

#include "InetUtil.hpp"

using namespace Inet;

StaticInit Inet::wsa_init;

#endif
