// Adapated by Matt Bender
// 02/07/14
//
#include "SingletonSchedule.h"
#include<iostream>
#include <cstdlib>
#include<cctype>
#include <assert.h>
#include <iomanip> // << Cout Columns

using namespace std;

SingletonSchedule* SingletonSchedule::onlyInstanceInt_ = 0; // initializing pointer to its instance

// returns pointer to instance of singleton
SingletonSchedule* SingletonSchedule::instance(){
    if(onlyInstanceInt_ == 0)
        onlyInstanceInt_ = new SingletonSchedule;
    return onlyInstanceInt_;
}


SingletonSchedule::SingletonSchedule(){
    for(int i = 0; i < 8; i++) {
        this->acceptedReservations[i][0] = "";
        this->acceptedReservations[i][1] = "";
    }
    for(int i = 0; i < 100; i++) {
        this->deniedReservations[i][0] = "";
        this->deniedReservations[i][1] = "";
    }
    atexit(&cleanUp);
} // registering behavior at program shutdown

// deallocate instance, re-set pointer
void SingletonSchedule::cleanUp(){
    delete onlyInstanceInt_; onlyInstanceInt_ = 0;
}
void SingletonSchedule::printSchedule() {
    cout << "ROOM SCHEDULE" << endl;
    for(int i = 0; i < 8; i++){
        if(acceptedReservations[i][0] != "") {
            cout << left << setw(8) << acceptedReservations[i][0] << left << setw(25) << acceptedReservations[i][1]  << endl;
        }
    }

    cout << endl << "OPEN TIMES" << endl;
    for(int i=0;i<8;i++) {
        if(acceptedReservations[i][0] == "") {
            int time = i+8;
            if (time > 11) 
                time++;

            cout << time << ":00" << endl; 
        }
    }

    cout << endl << "DENIED REQUESTS" << endl;
    for(int i = 0; i < 100; i++) {
        if(deniedReservations[i][0] == "") {
            break;
        }
        cout << left << setw(8) << deniedReservations[i][0] << left << setw(25) << deniedReservations[i][1]  << endl;
    }
}

bool SingletonSchedule::addRequest(string time, string name) {
     //cout << time << " " << name << "\n";

    int arrayloc = -1;
    switch(this->stringToTime(time)) {
        case 8:
            arrayloc = 0;
            break;
        case 9:
            arrayloc = 1;
            break;
        case 10:
            arrayloc = 2;
            break;
        case 11:
            arrayloc = 3;
            break;                   
        case 13:
            arrayloc = 4;
            break;
        case 14:
            arrayloc = 5;
            break;
        case 15:
            arrayloc = 6;
            break;
        case 16:
            arrayloc = 7;
            break;
         default:
            break;
    }

    //cout << "DEBUG1 " << time << " -> " << arrayloc << endl;
    //cout << "\n";

    if(arrayloc != -1 && this->acceptedReservations[arrayloc][0] == "") {
        //cout << "DEBUG2  " << arrayloc << " | " << time << " | " << name << endl;
        acceptedReservations[arrayloc][0] = time;
        acceptedReservations[arrayloc][1] = name;
    }
    else if(arrayloc == -1 || this->acceptedReservations[arrayloc][0] != "") {
        //cout << "DEBUG3  " << arrayloc << " | " << time << " | " << name << endl;
        //this->deniedReservations[arrayloc][0] = time;
        for(int i = 0; i < 100; i++) {
            if(deniedReservations[i][0] == "") {
                deniedReservations[i][0] = time;
                deniedReservations[i][1] = name;
                break; //end early
            }
        }
    }


}
//Return hour
int SingletonSchedule::stringToTime(string time) {

    int iTime = 0;
    if(time[1] == ':' && isdigit(time[0]) ) {
        iTime = time[0] - 48;  
    }
    else if(isdigit(time[1])) {
        int digit = (time[0] - 48)*10;
        iTime = digit + (time[1] -48);
    }
    else {
        assert("Conversion error");
    }

    return iTime;
}
