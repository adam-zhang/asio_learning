/********************************************************************************
> FileName:	Server.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Nov 14 10:30:55 2021
********************************************************************************/
#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include "Connection.h"

class Server
{
	public:
		explicit Server(boost::asio::io_context& io_context);
		~Server();
	private:
		void start_accept();

		void handle_accept(Connection::pointer new_connection, const boost::system::error_code& error);
		boost::asio::io_context& io_context_;
		boost::asio::ip::tcp::acceptor acceptor_;
};

#endif//SERVER_H
