
// Adapted by Matthew Bender
// 02/14/14

#ifndef Figure_H 
#define  Figure_H

// base class
class Figure {
public:
  Figure(int size=0, int xorigin=0, int yorigin=0);
  virtual void draw(void) =0 ; // pure virtual function
 
  // template methods
  void alignLeft(void);
  void alignRight(void);
  void centerHorizontal(void);
  void centerVertical(void);

  bool setOriginX(int xorigin);
  bool setOriginY(int yorigin);

   virtual ~Figure(){}
protected:
  static const int SCREEN_HEIGHT=20;
  static const int SCREEN_WIDTH=80;
  int size_;
  int xorigin_;
  int yorigin_;
};

#endif
