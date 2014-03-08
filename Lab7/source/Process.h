#ifndef Process_H
#define Process_H 

#include<string>
using std::string;

class State;
 
// context
class Process{
public:
   Process();
   virtual ~Process(){}
   void admitted();
   void interrupt();
   void exit();
   void iocomplete();
   void iowait();
   void schedule();
   string report();
   void changeState(State* s){state_=s;}
private:
   State* state_;
};

#endif
