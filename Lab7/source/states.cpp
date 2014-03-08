#include"State.h"
// concrete states, singletons
 
class Full: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Full;
      return onlyInstance;
   }
   void skipLunch(Character *c);
   string report(){return "full";}
};
 
 
class Hungry: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Hungry;
      return onlyInstance;
   }
   void skipLunch(Character *c);
   void eat(Character *c);
   string report(){return "hungry";}
};
 
class Dead: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Dead;
      return onlyInstance;
   }
   string report(){return "dead";}
};
