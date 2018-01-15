#include "asio.hpp"
#include <iostream>
#include <chrono>	
#include <thread>

void timer_callback(std::system_error ec) {
	std::cout << "5 seconds  pass, thread id " << std::this_thread::get_id() << std::endl;
}

int main() {

	asio::io_service io_service;
	asio::steady_timer timer1(io_service, std::chrono::seconds(5));
	timer1.async_wait( &timer_callback);

	asio::steady_timer timer2(io_service, std::chrono::seconds(4));
	timer2.async_wait(&timer_callback);

	
	std::cout << "before timer , thread id  " << std::this_thread::get_id() << std::endl;
	int ret = io_service.run();

	std::cout << "test " << ret << std::endl;

	getchar();
}	