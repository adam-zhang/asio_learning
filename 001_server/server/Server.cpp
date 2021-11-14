/********************************************************************************
> FileName:	Server.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Nov 14 10:30:55 2021
********************************************************************************/

#include "Server.h"
#include <functional>

Server::Server(boost::asio::io_context& io_context)
	: io_context_(io_context),
	acceptor_(io_context, 
			boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 13))
{
	start_accept();
}
Server::~Server()
{
}


void Server::start_accept()
{
	Connection::pointer new_connection = Connection::create(io_context_);

	acceptor_.async_accept(new_connection->socket(),
			std::bind(&Server::handle_accept, this, new_connection,
				std::placeholders::_1));
}


void Server::handle_accept(Connection::pointer new_connection,
		const boost::system::error_code& error)
{
	if (!error)
	{
		new_connection->start();
	}

	start_accept();
}
