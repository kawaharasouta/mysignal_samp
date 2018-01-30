#include<signal.h>

typedef void (*signalhandler_t)(int);

sighandler_t trap_signal(int sig, sighandler_t handler){
	struct sigaction act, old;

	//set signal handler. ignore sa_sigaction
	act.sa_handler = handler;
	//empty sa_mask
	sigemptyset(&act.sa_mask);
	//restart setting
	act.sa_flags = SA_RESTART;

	if (sigaction(sig, &act, &old) < 0) return NULL;
	return old.sa_handler;
}
