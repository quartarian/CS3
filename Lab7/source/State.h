#ifndef State_H
#define State_H 

 
// absract state
class State{
public:
   virtual void admitted(Process*){}
   virtual void interrupt(Process*){} 
   virtual void exit(Process*){}
   virtual void iocomplete(Process*){}
   virtual void iowait(Process*){}
   virtual void schedule(Process*){}
   virtual string report() =0;
   void changeState(Process* p, State* s){
      p->changeState(s);
   }
};

class New: public State{
public:
   static State* instance(){
      static State* onlyInstance = new New;
      return onlyInstance;
   }
   //void skipLunch(Character *c);
   void admitted(Process * p);
   string report(){return "new";}
};
 
class Ready: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Ready;
      return onlyInstance;
   }
   void schedule(Process * p);
   string report(){return "ready";}
};
 
class Waiting: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Waiting;
      return onlyInstance;
   }
   void iocomplete(Process * p);
   string report(){return "waiting";}
};

class Running: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Running;
      return onlyInstance;
   }
   void interrupt(Process * p);
   void iowait(Process * p);
   void exit(Process * p);
   string report(){return "running";}
};

class Terminated: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Terminated;
      return onlyInstance;
   }
   string report(){return "terminated";}
};

#endif
 
