
// Adapted by Matthew Bender
// 02/07/14

#ifndef SingletonSchedule_H 
#define  SingletonSchedule_H

#include <string>
using std::string;

class SingletonSchedule{
    public:
        static SingletonSchedule *instance(); // returns pointer to single instance

        bool addRequest(string time, string name);
        void printSchedule();

    private:
        SingletonSchedule(); // defined later to register behavior at destruction

        // copying prohibited
        SingletonSchedule(const SingletonSchedule&){}
        SingletonSchedule& operator=(const SingletonSchedule&){}

        static void cleanUp(); // correct object destruction
        static SingletonSchedule* onlyInstanceInt_; // pointer to its instance

        int stringToTime(string time);
        
        

        //Scheduling Data
        string acceptedReservations[8][2];
        string deniedReservations[100][2];

};

#endif
