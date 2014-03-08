// Implements the State Design patter for a scheduler
// Adapated by Matt Bender, originall by Mikhail Nesterenko
// 3/07/2014
 
#include <iostream>
#include <string>
#include "Process.h"
#include "State.h"
using std::cin; using std::cout; using std::endl; using std::string;

int main(){
    Process prog;
    cout << prog.report() << endl;

    for(int i = 0; i < 9; i++) {
        if(i ==0)
            prog.admitted();
        if(i==1)
            prog.schedule();
        if(i==2)
            prog.iowait();
        if(i==3)
            prog.iocomplete();
        if(i==4)
            prog.schedule();
        if(i==5)
            prog.interrupt();
        if(i==6)
            prog.schedule();
        if(i==7)
            // Doesnt do anything
            prog.admitted();
        if(i==8)
            prog.exit();

        cout << prog.report() << endl;

    }
}
