#include "asio.hpp"
#include <iostream>
#include <chrono>	
#include <thread>

void timer_callback(std::system_error ec) {
	std::cout << "5 seconds  pass, thread id " << std::this_thread::get_id() << std::endl;
}

static void func(int n) {
	asio::io_service io_service;
	asio::steady_timer timer1(io_service, std::chrono::seconds(5));
	timer1.async_wait(&timer_callback);

	asio::steady_timer timer2(io_service, std::chrono::seconds(4));
	timer2.async_wait(&timer_callback);

	int ret = io_service.run();

	std::cout << "func  " << ret << std::endl;
}

static void func1(int n) {
	asio::io_service io_service;
	asio::steady_timer timer1(io_service, std::chrono::seconds(0));
	timer1.async_wait(&timer_callback);

	asio::steady_timer timer2(io_service, std::chrono::seconds(4));
	timer2.async_wait(&timer_callback);

	int ret = io_service.poll();

	std::cout << "func  " << ret << std::endl;
}

int main() {

	std::cout << "before timer , thread id  " << std::this_thread::get_id() << std::endl;

	std::thread t1(func,3);
	std::thread t2(func1, 3);

	t1.join();
	std::cout << "test " << std::this_thread::get_id() << std::endl;

	getchar();

	return 0;
}


int main1() {

	asio::io_service io_service;
	asio::steady_timer timer1(io_service, std::chrono::seconds(5));
	timer1.async_wait(&timer_callback);

	asio::steady_timer timer2(io_service, std::chrono::seconds(4));
	timer2.async_wait(&timer_callback);


	std::cout << "before timer , thread id  " << std::this_thread::get_id() << std::endl;
	int ret = io_service.run();

	std::cout << "test " << ret << std::endl;

	getchar();

	return 0;
}