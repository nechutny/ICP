/**
 * Connection
 *
 * @author	Stanislav Nechutný - xnechu01
 */
#ifndef CONNECTION_H
#define CONNECTION_H

#include <stdbool.h>


class Connection
{
	protected:
		int _socket;
		struct sockaddr_in _sin;

	public:
		/**
		 * Connect
		 */
		bool connectTo(char* host, int port);

		bool bindServer(int port);

		Connection* acceptConnection();

		bool send(char* message, int length);

		int receive(char* message, int length);

		void disconnect();

		void injectSocket(int sock);
};
#endif
