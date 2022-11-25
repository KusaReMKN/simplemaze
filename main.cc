#include <csetjmp>
#include <csignal>
#include <iostream>
#include <random>

static std::jmp_buf env;

static void
handler(int sig)
{
	std::longjmp(env, sig);
}

int
main(int argc, char *argv[])
{
	std::random_device rand;
	std::mt19937 mt(rand());
	auto rand2 = [&mt](void) {
		std::uniform_int_distribution<> rand2(0, 1);
		return rand2(mt);
	};

	std::signal(SIGINT, handler);
	if (setjmp(env) != 0)
		goto quit;

	for (;;)
		std::cout << (rand2() ? '/' : '\\');
quit:
	std::cout << std::endl;

	return 0;
}
