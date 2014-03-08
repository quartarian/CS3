#include"Process.h"
#include"State.h"

// state transitions member functions
void New::admitted(Process * p){       changeState(p,Ready::instance());};
void Ready::schedule(Process * p){     changeState(p,Running::instance());};
void Waiting::iocomplete(Process * p){ changeState(p,Ready::instance());};
void Running::interrupt(Process * p){  changeState(p,Ready::instance());};
void Running::iowait(Process * p){     changeState(p,Waiting::instance());};
void Running::exit(Process * p){       changeState(p,Terminated::instance());};
