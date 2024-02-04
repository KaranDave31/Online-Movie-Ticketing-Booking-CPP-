#pragma once

#include<iostream>
using namespace std;

class Seat
{
protected:
    string seatNumber;
    string type;
    int price;
    //default value
    bool isBooked = false;

public:
    string getSeatNumber(){
        return seatNumber;
    }

    void setSeatNumber(string numberVal){
        seatNumber = numberVal;
    }

    string getType(){
        return type;
    }

    void setType(string typeVal){
        type = typeVal;
    }


    int getPrice(){
        return price;
    }

    void setPrice(int priceVal){
        price = priceVal;
    }

    bool getIsBooked(){
        return isBooked;
    }

    void setIsBooked(bool bookedVal){
        isBooked = bookedVal;
    }


    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Seat Type: " << type << "\t Seat Number : " << seatNumber << "\t Price : " << price <<"\tis Booked : " << isBooked << "\t" ;
        std::cout << "\n Seat Type: " << type << "\t Seat Number : " << seatNumber << "\t Price : " << price <<"\tis Booked : " << isBooked << "\t" ;

    } // void printMyDetails(){

};


class SeatNormal : public Seat
{
public:
    SeatNormal(){
       type = "Normal";
       price = 125;
    }

};


class SeatVIP : public Seat
{
public:
    SeatVIP(){
       type = "VIP";
       price = 400;
    }

};

class SeatDeluxe : public Seat
{
public:
    SeatDeluxe(){
       type = "Deluxe";
       price = 200;
    }

};

class SeatBox : public Seat
{
public:
    SeatBox(){
       type = "Box";
       price = 500;
    }

};


