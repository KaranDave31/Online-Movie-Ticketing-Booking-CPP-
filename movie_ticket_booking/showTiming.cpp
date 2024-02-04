#pragma once

#include<iostream>
using namespace std;

class ShowTiming
{
protected:
    string startTime;
    string endTime;

public:
    string getStartTime(){
        return startTime;
    }

    void setStartTime(string timeVal){
        startTime = timeVal;
    }

    string getEndTime(){
        return endTime;
    }

    void setEndTime(string timeVal){
        endTime = timeVal;
    }

    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Start Time: " << startTime << "\t End Time : " << endTime << "\t" ;
        std::cout << "\n ShowTiming Start Time: " << startTime << "\t End Time : " << endTime << "\t" ;

    } // void printMyDetails(){

};

class earlyMorningShow : public ShowTiming
{
public:
    earlyMorningShow(){
       startTime = "08:30 am";
       endTime = "10:30 am";
    }
};


class morningShow : public ShowTiming
{
public:
    morningShow(){
       startTime = "10:00 am";
       endTime = "12:00 pm";
    }
};

class afternoonShow1 : public ShowTiming
{
public:
    afternoonShow1(){
       startTime = "12:30 pm";
       endTime = "02:30 pm";
    }
};

class afternoonShow2 : public ShowTiming
{
public:
    afternoonShow2(){
       startTime = "03:00 pm";
       endTime = "05:00 pm";
    }
};

class eveningShow1 : public ShowTiming
{
public:
    eveningShow1(){
       startTime = "05:30 pm";
       endTime = "07:30 pm";
    }
};


class eveningShow2 : public ShowTiming
{
public:
    eveningShow2(){
       startTime = "08:00 pm";
       endTime = "10:00 pm";
    }
};

class nightShow : public ShowTiming
{
public:
    nightShow(){
       startTime = "10:30 pm";
       endTime = "12:30 am";
    }
};

