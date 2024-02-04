#pragma once

#include<iostream>

using namespace std;

class Offer
{
protected:
    string description;


public:
    string getDescription(){
        return description;
    }

    void setDescription(string descVal){
        description = descVal;
    }


    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Offer Description: " << description << "\t" ;
        std::cout << "\n Offer Description: " << description << "\t" ;
    } // void printMyDetails(){


};

