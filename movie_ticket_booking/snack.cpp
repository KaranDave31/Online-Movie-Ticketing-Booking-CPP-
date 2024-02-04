#pragma once

#include<iostream>
using namespace std;

class Snack
{
protected:
    string name;
    int price;

public:
    string getName(){
        return name;
    }

    void setName(string nameVal){
        name = nameVal;
    }

    int getPrice(){
        return price;
    }

    void setPrice(int priceVal){
        price = priceVal;
    }

    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Name: " << name << "\tPrice : " << price << "\t" ;
        std::cout << "\n Snack Name: " << name << " Price : " << price << "\t" ;
    } // void printMyDetails(){

};


class SnackVadaPav : public Snack
{
public:
    SnackVadaPav(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "VadaPav";
       price = 20;
    } // void setMyDetails(){
};


class SnackBurger : public Snack
{
public:
    SnackBurger(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "Burger";
       price = 50;
    } // void setMyDetails(){
};

class SnackPopCorn : public Snack
{
public:
    SnackPopCorn(){
        setMyDetails();
    }


    void setMyDetails(){
       name = "PopCorn";
       price = 75;
    } // void setMyDetails(){
};

class SnackSamosa : public Snack
{
public:
    SnackSamosa(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "Samosa";
       price = 25;
    } // void setMyDetails(){
};


