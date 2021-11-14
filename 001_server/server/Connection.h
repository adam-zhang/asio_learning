/********************************************************************************
> FileName:	Connection.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Nov 14 10:31:05 2021
********************************************************************************/
#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>
#include <memory>

class Connection
{
	public:
		typedef boost::shared_ptr<Connection> pointer;

		static pointer create(boost::asio::io_context& io_context);

		boost::asio::ip::tcp::socket& socket()
		{
			return socket_;
		}

		void start();

	private:
		explicit Connection(boost::asio::io_context& io_context)
			: socket_(io_context)
		{
		}

		void handle_write(const boost::system::error_code& /*error*/,
				size_t /*bytes_transferred*/);

		boost::asio::ip::tcp::socket socket_;
		std::string message_;
};

#endif// CONNECTION_H

