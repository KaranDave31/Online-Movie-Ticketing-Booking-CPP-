#pragma once

#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Booking
{

private:
    unsigned long bookingNumber;
    string theatreDetails; //theatreName + address
    string movieDetails ; //movieName + movieLanguage
    string screenName;
    string showDetails ; // showStartTime + showEndTime
    string seatDetails ; // seatType + seatNumber
    string offerDetails ;
    string snackDetails ; // name & quantity
    string drinkDetails ; // name & quantity

    int totalOrderCost = 0; // seatPrice + GST + Snack + Drink) * respective order counts

public:
    static constexpr const char* DELIMITER = ",";

    Booking ()
    {
        milliseconds ms = duration_cast< milliseconds >(
                              system_clock::now().time_since_epoch()
                          );
        // to get unique booking number everytime
        //std::cout << "\n ms.count: " << ms.count();
        bookingNumber = ms.count();
        //std::cout << "\n bookingNumber : " << bookingNumber;

    } // Booking ()


    Booking (int bookingNumberVal, string theatreDetailsVal, string movieDetailsVal, string screenNameVal, string showDetailsVal, string seatDetailsVal, string offerDetailsVal, string snackDetailsVal, string drinkDetailsVal, int totalOrderCostVal )
    {
        bookingNumber = bookingNumberVal ;
        theatreDetails = theatreDetailsVal ;
        movieDetails = movieDetailsVal ;
        screenName = screenNameVal ;
        showDetails = showDetailsVal ;
        seatDetails = seatDetailsVal ;
        offerDetails = offerDetailsVal ;
        snackDetails = snackDetailsVal ;
        drinkDetails = drinkDetailsVal ;
        totalOrderCost = totalOrderCostVal ;
    } // Booking (......


    unsigned long getBookingNumber()
    {
        return bookingNumber;
    }


    string getTheatreDetails()
    {
        return theatreDetails;
    }

    void setTheatreDetails(string val)
    {
        theatreDetails = val;
    }

    string getMovieDetails()
    {
        return movieDetails;
    }

    void setMovieDetails(string val)
    {
        movieDetails = val;
    }
    string getScreenName()
    {
        return screenName;
    }
    void setScreenName(string val)
    {
        screenName = val;
    }

    string getShowDetails()
    {
        return showDetails;
    }
    void setShowDetails(string val)
    {
        showDetails = val;
    }
    string getSeatDetails()
    {
        return seatDetails;
    }

    void setSeatDetails(string val)
    {
        seatDetails = val;
    }
    string getSnackDetails()
    {
        return snackDetails;
    }
    void getSnackDetails(string val)
    {
        snackDetails = val;
    }
    string getDrinkDetails()
    {
        return drinkDetails;
    }

    void setDrinkDetails(string val)
    {
        drinkDetails = val;
    }

    int getTotalOrderCost()
    {
        return totalOrderCost;
    }

    void setTotalOrderCost(int val)
    {
        totalOrderCost = val;
    }


    string getOfferDetails()
    {
        return offerDetails;
    }

    void setOfferDetails(string val)
    {
        offerDetails = val;
    }

    void printMyDetails()
    {
        std::cout << "\n Booking Number " << bookingNumber << "\t Theatre Details : " << theatreDetails  << "\t Movie Details : " << movieDetails  << "\t Screen Name : " << screenName  << "\t Show Details : " << showDetails  << "\t Seat Details : " << seatDetails  << "\t Offer Details : " << offerDetails  << "\t Snack Details : " << snackDetails  << "\t Drink Details : " << drinkDetails  << "\t Total Order Cost : " << totalOrderCost << "\t" ;
    }


    void clearMyDetails()
    {
        // bookingNumber = -1; // DO not clear the bookingNumber
        theatreDetails = "";
        movieDetails = "";
        screenName = "";
        showDetails = "";
        seatDetails = "";
        offerDetails = "";
        snackDetails = "";
        drinkDetails = "";
        totalOrderCost = -1;

    } // void clearMyDetails(){

    string toCSV()
    {
        string retValue = "";

        retValue = to_string(bookingNumber) + DELIMITER + theatreDetails + DELIMITER + movieDetails + DELIMITER
            + screenName + DELIMITER + showDetails + DELIMITER + seatDetails + DELIMITER + offerDetails + DELIMITER
            + snackDetails + DELIMITER + drinkDetails + DELIMITER + to_string(totalOrderCost);

        return retValue;
    }

};
