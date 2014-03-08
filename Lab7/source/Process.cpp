#include"Process.h"
#include"State.h"

Process::Process(){      state_=New::instance();}
string Process::report(){return state_->report();}
void Process::admitted()  { state_->admitted(this); }
void Process::interrupt() { state_->interrupt(this); }
void Process::exit()      { state_->exit(this); }
void Process::iocomplete(){ state_->iocomplete(this); }
void Process::iowait()    { state_->iowait(this); }
void Process::schedule()  { state_->schedule(this); }
