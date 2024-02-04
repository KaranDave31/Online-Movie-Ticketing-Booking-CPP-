#pragma once
#include<iostream>
#include "screen.cpp"
#include "snack.cpp"
#include "drink.cpp"
using namespace std;

class Theatre
{
protected:
    string theatreName;
    string address;
    vector<Screen> screenList;
    vector<Snack> snackList;
    vector<Drink> drinkList;

public:
    string getTheatreName(){
        return theatreName;
    }

    void setTheatreName(string textVal){
        theatreName = textVal;
    }

    string getAddress(){
        return address;
    }

    void setAddress(string textVal){
        address = textVal;
    }

    vector<Screen> getScreenList(){
         return screenList ;
    }

    void setScreenList(vector<Screen> listVal){
         screenList = listVal;
    }

    vector<Snack> getSnackList(){
         return snackList ;
    }

    void setSnackList(vector<Snack> listVal){
         snackList = listVal;
    }

    vector<Drink> getDrinkist(){
         return drinkList ;
    }

    void setDrinkList(vector<Drink> listVal){
         drinkList = listVal;
    }




    void printMyDetails()
    {

        //std::cout << "\n" << typeid(this).name() << "\t Theatre Name: " << theatreName << "\t Address : " << address << "\t" ;
        std::cout << "\n Theatre Name: " << theatreName << "\t Address : " << address << "\t" ;
        int listCounter;
        std::cout << "\n";

        listCounter = 0;
        while (listCounter < (int) screenList.size())
        {
            ((Screen)screenList.at(listCounter)).printMyDetails();
            //std::cout << "\n";
            listCounter++;
        }

        listCounter = 0;
        while (listCounter < (int) snackList.size())
        {
            ((Snack)snackList.at(listCounter)).printMyDetails();
            //std::cout << "\n";
            listCounter++;
        }

        listCounter = 0;
        while (listCounter < (int) drinkList.size())
        {
            ((Drink)drinkList.at(listCounter)).printMyDetails();
            //std::cout << "\n";
            listCounter++;
        }


    } // void printMyDetails(){

};
