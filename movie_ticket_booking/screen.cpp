#pragma once

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>


#include "movie.cpp"
#include "showTiming.cpp"
#include "offer.cpp"
#include "seat.cpp"

using namespace std;


class Screen
{
protected:
    string screenName;
    vector<ShowTiming> showTimingList;
    vector<Offer> offerList;
    vector<Seat> seatList;
    Movie movie;


public:

    string getScreenName()
    {
        return screenName;
    }

    void setScreenName(string nameVal)
    {
        screenName = nameVal;
    }

    Movie getMovie()
    {
        return movie;
    }

    void setMovie(Movie movieVal)
    {
        movie = movieVal;
    }

    vector<ShowTiming> getShowTimingList(){
         return showTimingList ;
    }

    void setShowTimingList(vector<ShowTiming> listVal){
         showTimingList = listVal;
    }



    vector<Offer> getOfferList(){
         return offerList ;
    }

    void setOfferList(vector<Offer> listVal){
         offerList = listVal;
    }

    vector<Seat> getSeatList(){
         return seatList ;
    }

    void setSeatList(vector<Seat> listVal){
         seatList = listVal;
    }



    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Screen Name: " << screenName << "\t" ;
        std::cout << "\n Screen Name: " << screenName << "\t" ;
        movie.printMyDetails();
        std::cout << "\n";

        int listCounter;

        listCounter = 0;
        while (listCounter < (int) showTimingList.size())
        {
            ((ShowTiming)showTimingList.at(listCounter)).printMyDetails();
            listCounter++;
        }
        std::cout << "\n";

        listCounter = 0;
        while (listCounter < (int) offerList.size())
        {
            ((Offer)offerList.at(listCounter)).printMyDetails();
            listCounter++;
        }
        std::cout << "\n";

        listCounter = 0;
        while (listCounter < (int) seatList.size())
        {
            //((Seat)seatList.at(listCounter)).printMyDetails();
            listCounter++;
        }
        std::cout << "\n";

    } // void printMyDetails(){



};
