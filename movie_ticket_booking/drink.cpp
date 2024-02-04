#pragma once

#include<iostream>
using namespace std;

class Drink
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
        std::cout << "\n Name: " << name << "\tPrice : " << price << "\t" ;
    } // void printMyDetails(){

};


class DrinkCoffee : public Drink
{
    string type="Regular";

public:
    DrinkCoffee(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "Coffee";
       price = 11;
       type = "Black";
    } // void setMyDetails(){

    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Name: " << name << "\tPrice : " << price << "\tType : " << type << "\t";
        std::cout << "\n Drink Name: " << name << " Price : " << price << " Type : " << type << "\t";
    } // void printMyDetails(){

};


class DrinkTea : public Drink
{
public:
    DrinkTea(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "Tea";
       price = 22;
    } // void setMyDetails(){
};

class DrinkColdDrink : public Drink
{
public:
    DrinkColdDrink(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "ColdDrink";
       price = 33;
    } // void setMyDetails(){
};

class DrinkWater : public Drink
{
public:
    DrinkWater(){
        setMyDetails();
    }

    void setMyDetails(){
       name = "Water";
       price = 44;
    } // void setMyDetails(){
};


