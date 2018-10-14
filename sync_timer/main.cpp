#include <iostream>
#include <boost/asio.hpp>

int main(int, char**)
{
	boost::asio::io_context context;
	boost::asio::steady_timer timer(context, boost::asio::chrono::seconds(5));
	timer.wait();
	std::cout << "Hello Timer." << std::endl;
	return 0;
}
