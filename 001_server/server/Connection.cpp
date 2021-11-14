/********************************************************************************
> FileName:	Connection.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Nov 14 10:31:05 2021
********************************************************************************/

#include "Connection.h"
#include <functional>
//#include <boost/bind.hpp>

static std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	time_t now = time(0);
	auto s = ctime(&now);
	return s;
}


Connection::pointer Connection::create(boost::asio::io_context& io_context)
{
	return pointer(new Connection(io_context));
}


void Connection::start()
{
	message_ = make_daytime_string();
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
			std::bind(&Connection::handle_write, this,
				std::placeholders::_1,
				std::placeholders::_2));
}


void Connection::handle_write(const boost::system::error_code& /*error*/,
		size_t /*bytes_transferred*/)
{
}
