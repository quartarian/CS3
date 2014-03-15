// Adapted by Matt Bender
// 02/21/14

#ifndef Fill_H
#define Fill_H

// abstract body
class Fill{
public:
   Fill(char fillChar):fillChar_(fillChar){}
   virtual char getBorder()=0;
   virtual char getInternal()=0;
   virtual ~Fill(){}
protected:
   char fillChar_;
};
 
// concrete body
class Hollow: public Fill{
public:
   Hollow(char fillChar):Fill(fillChar){}
   char getBorder(){return fillChar_;}
   char getInternal(){return ' ';}
   ~Hollow(){}
};
 
// another concrete body
class Filled: public Fill {
public:
   Filled(char fillChar):Fill(fillChar){}
   char getBorder(){return fillChar_;}
   char getInternal(){return fillChar_;}
   ~Filled(){}
};

#endif
