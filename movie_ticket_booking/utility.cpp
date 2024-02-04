#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

#include <string>
#include <windows.h>
#include <unistd.h>

#include "customer.cpp"
#include "booking.cpp"
#include "theatre.cpp"
#include "screen.cpp"
#include "showTiming.cpp"
#include "offer.cpp"
#include "seat.cpp"
#include "movie.cpp"
#include "snack.cpp"
#include "drink.cpp"



using namespace std;


class Utility
{
    void setTheatre();
    void setScreens();
    void setMovies();
    void setShowTimings();
    void offers();
    void setSeats();
    void setSnacks();
    void setDrinks();
    void getTheatres();
    void getScreens();
    void getMovies();
    void getShowTimings();
    void getOffers();

    void loadBookingData()
    {

    };


public:
    static constexpr const char* DELIMITER = ",";
    static constexpr const char* DELIMITER_LEVEL2 = "#";
    static constexpr const char* DELIMITER_LEVEL3 = "$";
    int MAX_SEAT_SIZE = 10;


    void console_clear_screen()
    {
        system("cls");
    }



    void writeToFile (string fileName, string fileDataRow)
    {

        ofstream outFile;

        outFile.open(fileName, ios::out | ios::app);

        // check if file exists
        if (!outFile.is_open())
        {
            setTextColor(4);
            cout << "\n" << fileName << " not found\n";
            setTextColor(7);
        }
        else
        {
            outFile << fileDataRow << "\n";
            outFile.close();
        }

    } // void writeToFile (string fileName, string fileDataRow){



    vector<Customer> readCustomerDataFromFile (string fileName)
    {

        ifstream  inFile;

        vector<Customer> customerList;

        inFile.open(fileName, ios::in);

        // check if file exists
        if (!inFile.is_open())
        {
            setTextColor(4);
            cout << "\n" << fileName << " not found\n";
            setTextColor(7);
        }
        else
        {
            string fileDataRow;
            int rowCounter = 0;

            // read one line at a time, from file
            while (getline (inFile, fileDataRow))
            {

                // show one line of the text from the file
                //cout << "\n Row " << rowCounter << " Data # " << fileDataRow << " #";
                rowCounter++;

                unsigned long customerId;
                string customerName;
                string emailAddress;
                string password;
                bool loggedIn;

                istringstream lineData(fileDataRow);
                int colCounter = 1;
                string colData;
                char delimitor = *DELIMITER ; // ','

                // read one delimited word at a time, from the one row data
                while (std::getline(lineData, colData, delimitor))
                {

                    // show one word of the line
                    // cout << "\n Column " << colCounter << " Data # " << colData << " #";

                    switch (colCounter)
                    {
                    case 1:
                    {
                        // convert from string to unsigned long
                        customerId = stoul(colData);
                        break;
                    }

                    case 2:
                    {
                        customerName = colData;
                        break;
                    }

                    case 3:
                    {
                        password = colData;
                        break;
                    }

                    case 4:
                    {
                        emailAddress = colData;
                        break;
                    }

                    case 5:
                    {
                        if (colData.compare("1") != 0)
                        {
                            loggedIn = false;
                        }
                        else
                        {
                            loggedIn = true;
                        }

                        break;
                    }

                    }


                    colCounter++;

                } //  while (std::getline(lineData, colData, DELIMITER)) {

                // create one custom and add / push to the customer vector
                Customer oneCustomer (customerId, customerName, password, emailAddress, loggedIn);
                //oneCustomer.printMyDetails();

                // add one customer record to the vector.
                customerList.push_back(oneCustomer);


            } // while (getline (inFile, fileDataRow)) {


            inFile.close();
        }


        displayCustomerData(customerList);

        return customerList;


    } // void readCustomerDataFromFile (string fileName, string fileDataRow){

    // display content of the customerList vector
    void displayCustomerData(vector<Customer> allCustomerList)
    {

        int customerListSize = allCustomerList.size();
        cout << "\n\n\t\tNumber of Registered Customers # " << customerListSize << " #\n\n";
        cout<<"===========================================================================================================================================================================\n\n";

        int customerCounter = 0;
        while (customerCounter < customerListSize)
        {
            Customer oneCustomer = allCustomerList.at(customerCounter);
            cout<<customerCounter+1<<">";
            oneCustomer.printMyDetails();

            customerCounter++;
        } // while (customerCounter <= customerListSize) {


    } // void displayCustomerData(vector<Customer> allCustomerList){


    // display content of the customerList vector
    Customer validateUserLogin (vector<Customer> allCustomerList, string userInputName, string userInputPassword)
    {
        Customer LoggedInCustomer;
        LoggedInCustomer.setLoggedIn(false);

        int customerListSize = allCustomerList.size();

        int customerCounter = 0;

        //std::cout << "\nCustomer LOGIN check .. \n";
        while (customerCounter < customerListSize)
        {
            Customer oneCustomer =  allCustomerList.at(customerCounter);
            oneCustomer.setLoggedIn(false);

            if (userInputName.compare(oneCustomer.getCustomerName()) != 0)
            {
                //std::cout << "\nIncorrect Customer Name .. \n";

            }
            else
            {
                // Customer Name is OK
                //std::cout << "\nCustomer Name OK.. \n";

                if (userInputPassword.compare(oneCustomer.getPassword()) != 0)
                {
                    //std::cout << "\nIncorrect Password .. \n";

                }
                else
                {
                    // Customer LOGIN is all OK
                    //std::cout << "\nCustomer LOGIN is all OK .. \n";
                    oneCustomer.setLoggedIn(true);
                    LoggedInCustomer = oneCustomer;
                    break;
                }
            }


            customerCounter++;
        } // while (customerCounter <= customerListSize) {

        return LoggedInCustomer;
    } // Customer validateUserLogin (vector<Customer> allCustomerList, string userInputName, string userInputPassword){


    void hideUserInput()//directly from net
    {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        // disabled the input hiding
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    }


    void showUserInput()
    {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode);
    }


    /*  colorCode numbers
        Name | Value
        Black | 0
        Blue | 1
        Green | 2
        Cyan | 3
        Red | 4
        Magenta | 5
        Brown | 6
        Light Gray | 7
        Dark Gray | 8
        Light Blue | 9
        Light Green | 10
        Light Cyan | 11
        Light Red | 12
        Light Magenta| 13
        Yellow | 14
        White | 15
    */
    void setTextColor(int colorCode)//directly from net
    {
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );//modified property of console (can even change the font, it didnt apply only to a particular place but did to entire project)

        if (hConsole != INVALID_HANDLE_VALUE)
        {
            SetConsoleTextAttribute( hConsole, colorCode );
        }

    }

    void setTextColorBold(int colorCode)
    {
        CONSOLE_FONT_INFOEX  fontex;
        fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);

        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

        if (hConsole != INVALID_HANDLE_VALUE)
        {
            GetCurrentConsoleFontEx(hConsole, 0, &fontex);
            fontex.FontWeight = 50;
            fontex.dwFontSize.X = 25;
            fontex.dwFontSize.Y = 25;
            SetCurrentConsoleFontEx(hConsole, NULL, &fontex);
            SetConsoleTextAttribute( hConsole, colorCode );
        }


    }



    Theatre SetupTheatreCineMagic()
    {


        Theatre tempTheatre1;

        std::cout << "\n Starting CineMagic Theatre Setup \t ***********************";

        tempTheatre1.setTheatreName("CineMagic");
        tempTheatre1.setAddress("Andheri (West)");

        vector<Screen> screenList;

        int screenCounter = 1;
        int sreenSize = 4;
        while (screenCounter <= sreenSize)
        {

            // add new screen details **************************************************
            Screen screenOne;
            screenOne.setScreenName("Mars " + to_string(screenCounter));

            std::cout << "\n Adding Screen # : " << screenCounter << "\t with Name : " << screenOne.getScreenName() << "\t" ;

            Movie movie;


            switch (screenCounter)
            {
            case 1:
            {
                MovieEnglish movie1;
                movie = movie1;
            }
            break;

            case 2:
            {
                MovieEnglish movie2;
                movie = movie2;
            }
            break;

            case 3:
            {
                MovieHindi movie3;
                movie = movie3;
            }
            break;

            case 4:
            {
                MovieHindi movie4;
                movie = movie4;
            }
            break;

            } // switch (screenCounter)


            movie.setName("Lord of the Rings "+ to_string(screenCounter));

            std::cout << "\n Adding Movie # : " << screenCounter << "\t with Name : " << movie.getName() << "\t of Language : " << movie.getLanguage() << "\t" ;

            // added movie to one screen
            screenOne.setMovie(movie);

            vector<Offer> offerList;

            Offer myOffer1;
            Offer myOffer2;
            Offer myOffer3;
            Offer myOffer4;

            myOffer1.setDescription("Buy 5 SeatDeluxe and get 5 teas at half price");
            myOffer2.setDescription("Buy 5 SeatVIP and get 5 SnackVadaPav at half price");
            myOffer3.setDescription("Buy 5 SeatBox and get 5 SnackVadaPav free");
            myOffer4.setDescription("Buy 5 SeatBox and get 5 SnackPopCorn at half price");

            offerList.push_back(myOffer1);
            offerList.push_back(myOffer2);
            offerList.push_back(myOffer3);
            offerList.push_back(myOffer4);

            // added offerList to one screen
            screenOne.setOfferList(offerList);


            vector<ShowTiming> showTimingList;

            earlyMorningShow myShow1;
            morningShow myShow2;
            afternoonShow1 myShow3;
            afternoonShow2 myShow4;
            eveningShow1 myShow5;
            eveningShow2 myShow6;
            nightShow myShow7;

            showTimingList.push_back(myShow1);
            showTimingList.push_back(myShow2);
            showTimingList.push_back(myShow3);
            showTimingList.push_back(myShow4);
            showTimingList.push_back(myShow5);
            showTimingList.push_back(myShow6);

            // added showTimingList to one screen
            screenOne.setShowTimingList(showTimingList);


            vector<Seat> seatList;

            int seatCounter = 0;
            int seatSize = 0;

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatNormal mySeat1;
                mySeat1.setSeatNumber("SN-" + to_string(seatCounter));
                seatList.push_back(mySeat1);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatVIP mySeat2;
                mySeat2.setSeatNumber("SV-" + to_string(seatCounter));
                seatList.push_back(mySeat2);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatDeluxe mySeat3;
                mySeat3.setSeatNumber("SD-" + to_string(seatCounter));
                seatList.push_back(mySeat3);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatBox mySeat4;
                mySeat4.setSeatNumber("SB-" + to_string(seatCounter));
                seatList.push_back(mySeat4);

                seatCounter++;
            }

            // added seatList to one screen
            screenOne.setSeatList(seatList);

            // added one screen to Theatre
            screenList.push_back(screenOne);

            screenCounter++;
        } // while (screenCounter <= sreenSize)

        // add screens to Theatre
        tempTheatre1.setScreenList(screenList);


        vector<Drink> drinkList;

        DrinkCoffee myDrink1;
        DrinkTea myDrink2;
        DrinkColdDrink myDrink3;
        DrinkWater myDrink4;

        myDrink1.setMyDetails() ;
        myDrink2.setMyDetails() ;
        myDrink3.setMyDetails() ;
        myDrink4.setMyDetails() ;

        drinkList.push_back(myDrink1);
        drinkList.push_back(myDrink2);
        drinkList.push_back(myDrink3);
        drinkList.push_back(myDrink4);

        tempTheatre1.setDrinkList(drinkList);



        vector<Snack> snackList;

        SnackVadaPav mySnack1;
        SnackBurger mySnack2;
        SnackPopCorn mySnack3;
        SnackSamosa mySnack4;

        mySnack1.setMyDetails() ;
        mySnack2.setMyDetails() ;
        mySnack3.setMyDetails() ;
        mySnack4.setMyDetails() ;

        snackList.push_back(mySnack1);
        snackList.push_back(mySnack2);
        snackList.push_back(mySnack3);
        snackList.push_back(mySnack4);

        tempTheatre1.setSnackList(snackList);



        std::cout << "\n Ending CineMagic Theatre Setup \t ***********************\n";

        // std::cout << "\n Displaying CineMagic Theatre Setup \t ######################### \n";
        // tempTheatre1.printMyDetails();


        return tempTheatre1;

    } // Theatre SetupTheatreCineMagic()



    Theatre SetupTheatreCineMax()
    {
        Theatre tempTheatre1;


        std::cout << "\n Starting CineMax Theatre Setup \t ***********************";

        tempTheatre1.setTheatreName("CineMax");
        tempTheatre1.setAddress("Parle (West)");

        vector<Screen> screenList;

        int screenCounter = 1;
        int sreenSize = 4;
        while (screenCounter <= sreenSize)
        {

            // add new screen details **************************************************
            Screen screenOne;
            screenOne.setScreenName("Europa " + to_string(screenCounter));

            std::cout << "\n Adding Screen # : " << screenCounter << "\t with Name : " << screenOne.getScreenName() << "\t" ;

            Movie movie;


            switch (screenCounter)
            {
            case 1:
            {
                MovieEnglish movie1;
                movie = movie1;
            }
            break;

            case 2:
            {
                MovieHindi movie2;
                movie = movie2;
            }
            break;

            case 3:
            {
                MovieEnglish movie3;
                movie = movie3;
            }
            break;

            case 4:
            {
                MovieHindi movie4;
                movie = movie4;
            }
            break;

            } // switch (screenCounter)


            movie.setName("Hobbit "+ to_string(screenCounter));

            std::cout << "\n Adding Movie # : " << screenCounter << "\t with Name : " << movie.getName() << "\t of Language : " << movie.getLanguage() << "\t" ;

            // added movie to one screen
            screenOne.setMovie(movie);

            vector<Offer> offerList;

            Offer myOffer1;
            Offer myOffer2;
            Offer myOffer3;
            Offer myOffer4;

            myOffer1.setDescription("Buy 4 SeatDeluxe and get 4 teas at half price");
            myOffer2.setDescription("Buy 4 SeatVIP and get 4 SnackVadaPav at half price");
            myOffer3.setDescription("Buy 4 SeatBox and get 4 SnackVadaPav free");
            myOffer4.setDescription("Buy 4 SeatBox and get 4 SnackPopCorn at half price");

            offerList.push_back(myOffer1);
            offerList.push_back(myOffer2);
            offerList.push_back(myOffer3);
            offerList.push_back(myOffer4);

            // added offerList to one screen
            screenOne.setOfferList(offerList);


            vector<ShowTiming> showTimingList;

            earlyMorningShow myShow1;
            morningShow myShow2;
            afternoonShow1 myShow3;
            afternoonShow2 myShow4;
            eveningShow1 myShow5;
            eveningShow2 myShow6;
            nightShow myShow7;

            showTimingList.push_back(myShow1);
            showTimingList.push_back(myShow2);
            showTimingList.push_back(myShow3);
            showTimingList.push_back(myShow4);
            showTimingList.push_back(myShow5);
            showTimingList.push_back(myShow6);

            // added showTimingList to one screen
            screenOne.setShowTimingList(showTimingList);


            vector<Seat> seatList;

            int seatCounter = 0;
            int seatSize = 0;

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatNormal mySeat1;
                mySeat1.setSeatNumber("SN-" + to_string(seatCounter));
                seatList.push_back(mySeat1);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatVIP mySeat2;
                mySeat2.setSeatNumber("SV-" + to_string(seatCounter));
                seatList.push_back(mySeat2);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatDeluxe mySeat3;
                mySeat3.setSeatNumber("SD-" + to_string(seatCounter));
                seatList.push_back(mySeat3);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatBox mySeat4;
                mySeat4.setSeatNumber("SB-" + to_string(seatCounter));
                seatList.push_back(mySeat4);

                seatCounter++;
            }

            // added seatList to one screen
            screenOne.setSeatList(seatList);

            // added one screen to Theatre
            screenList.push_back(screenOne);

            screenCounter++;
        } // while (screenCounter <= sreenSize)

        // add screens to Theatre
        tempTheatre1.setScreenList(screenList);


        vector<Drink> drinkList;

        DrinkCoffee myDrink1;
        DrinkTea myDrink2;
        DrinkColdDrink myDrink3;
        DrinkWater myDrink4;

        myDrink1.setMyDetails() ;
        myDrink2.setMyDetails() ;
        myDrink3.setMyDetails() ;
        myDrink4.setMyDetails() ;

        drinkList.push_back(myDrink1);
        drinkList.push_back(myDrink2);
        drinkList.push_back(myDrink3);
        drinkList.push_back(myDrink4);

        tempTheatre1.setDrinkList(drinkList);



        vector<Snack> snackList;

        SnackVadaPav mySnack1;
        SnackBurger mySnack2;
        SnackPopCorn mySnack3;
        SnackSamosa mySnack4;

        mySnack1.setMyDetails() ;
        mySnack2.setMyDetails() ;
        mySnack3.setMyDetails() ;
        mySnack4.setMyDetails() ;

        snackList.push_back(mySnack1);
        snackList.push_back(mySnack2);
        snackList.push_back(mySnack3);
        snackList.push_back(mySnack4);

        tempTheatre1.setSnackList(snackList);



        std::cout << "\n Ending CineMax Theatre Setup \t ***********************\n";

        //std::cout << "\n Displaying CineMax Theatre Setup \t ######################### \n";
        //tempTheatre1.printMyDetails();



        return tempTheatre1;

    } // Theatre SetupTheatreCineMax()



    Theatre SetupTheatreCineWorld()
    {
        Theatre tempTheatre1;

        std::cout << "\n Starting CineWorld Theatre Setup \t ***********************";

        tempTheatre1.setTheatreName("CineWorld");
        tempTheatre1.setAddress("Andheri (East)");

        vector<Screen> screenList;

        int screenCounter = 1;
        int sreenSize = 4;
        while (screenCounter <= sreenSize)
        {

            // add new screen details **************************************************
            Screen screenOne;
            screenOne.setScreenName("Moon " + to_string(screenCounter));

            std::cout << "\n Adding Screen # : " << screenCounter << "\t with Name : " << screenOne.getScreenName() << "\t" ;

            Movie movie;


            switch (screenCounter)
            {
            case 1:
            {
                MovieEnglish movie1;
                movie = movie1;
            }
            break;

            case 2:
            {
                MovieHindi movie2;
                movie = movie2;
            }
            break;

            case 3:
            {
                MovieMarathi movie3;
                movie = movie3;
            }
            break;

            case 4:
            {
                MovieGujrati movie4;
                movie = movie4;
            }
            break;

            } // switch (screenCounter)


            movie.setName("Star Wars "+ to_string(screenCounter));

            std::cout << "\n Adding Movie # : " << screenCounter << "\t with Name : " << movie.getName() << "\t of Language : " << movie.getLanguage() << "\t" ;

            // added movie to one screen
            screenOne.setMovie(movie);

            vector<Offer> offerList;

            Offer myOffer1;
            Offer myOffer2;
            Offer myOffer3;
            Offer myOffer4;

            myOffer1.setDescription("Buy 3 SeatDeluxe and get 3 teas at half price");
            myOffer2.setDescription("Buy 3 SeatVIP and get 3 SnackVadaPav at half price");
            myOffer3.setDescription("Buy 3 SeatBox and get 3 SnackVadaPav free");
            myOffer4.setDescription("Buy 3 SeatBox and get 3 SnackPopCorn at half price");

            offerList.push_back(myOffer1);
            offerList.push_back(myOffer2);
            offerList.push_back(myOffer3);
            offerList.push_back(myOffer4);

            // added offerList to one screen
            screenOne.setOfferList(offerList);


            vector<ShowTiming> showTimingList;

            earlyMorningShow myShow1;
            morningShow myShow2;
            afternoonShow1 myShow3;
            afternoonShow2 myShow4;
            eveningShow1 myShow5;
            eveningShow2 myShow6;
            nightShow myShow7;

            showTimingList.push_back(myShow1);
            showTimingList.push_back(myShow2);
            showTimingList.push_back(myShow3);
            showTimingList.push_back(myShow4);
            showTimingList.push_back(myShow5);
            showTimingList.push_back(myShow6);

            // added showTimingList to one screen
            screenOne.setShowTimingList(showTimingList);


            vector<Seat> seatList;

            int seatCounter = 0;
            int seatSize = 0;

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatNormal mySeat1;
                mySeat1.setSeatNumber("SN-" + to_string(seatCounter));
                seatList.push_back(mySeat1);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatVIP mySeat2;
                mySeat2.setSeatNumber("SV-" + to_string(seatCounter));
                seatList.push_back(mySeat2);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatDeluxe mySeat3;
                mySeat3.setSeatNumber("SD-" + to_string(seatCounter));
                seatList.push_back(mySeat3);

                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatBox mySeat4;
                mySeat4.setSeatNumber("SB-" + to_string(seatCounter));
                seatList.push_back(mySeat4);

                seatCounter++;
            }

            // added seatList to one screen
            screenOne.setSeatList(seatList);

            // added one screen to Theatre
            screenList.push_back(screenOne);

            screenCounter++;
        } // while (screenCounter <= sreenSize)

        // add screens to Theatre
        tempTheatre1.setScreenList(screenList);



        vector<Drink> drinkList;

        DrinkCoffee myDrink1;
        DrinkTea myDrink2;
        DrinkColdDrink myDrink3;
        DrinkWater myDrink4;

        myDrink1.setMyDetails() ;
        myDrink2.setMyDetails() ;
        myDrink3.setMyDetails() ;
        myDrink4.setMyDetails() ;

        drinkList.push_back(myDrink1);
        drinkList.push_back(myDrink2);
        drinkList.push_back(myDrink3);
        drinkList.push_back(myDrink4);

        tempTheatre1.setDrinkList(drinkList);



        vector<Snack> snackList;

        SnackVadaPav mySnack1;
        SnackBurger mySnack2;
        SnackPopCorn mySnack3;
        SnackSamosa mySnack4;

        mySnack1.setMyDetails() ;
        mySnack2.setMyDetails() ;
        mySnack3.setMyDetails() ;
        mySnack4.setMyDetails() ;

        snackList.push_back(mySnack1);
        snackList.push_back(mySnack2);
        snackList.push_back(mySnack3);
        snackList.push_back(mySnack4);

        tempTheatre1.setSnackList(snackList);


        std::cout << "\n Ending CineWorld Theatre Setup \t ***********************\n";

        // std::cout << "\n Displaying CineWorld Theatre Setup \t ######################### \n";
        // tempTheatre1.printMyDetails();



        return tempTheatre1;

    } // Theatre SetupTheatreCineWorld()



    Theatre SetupTheatreFunRepublic()
    {
        Theatre tempTheatre1;

        std::cout << "\n Starting FunRepublic Theatre Setup \t ***********************";

        tempTheatre1.setTheatreName("FunRepublic");
        tempTheatre1.setAddress("Andheri (West)");

        vector<Screen> screenList;

        int screenCounter = 1;
        int sreenSize = 4;
        while (screenCounter <= sreenSize)
        {

            // add new screen details **************************************************
            Screen screenOne;
            screenOne.setScreenName("Titan " + to_string(screenCounter));

            std::cout << "\n Adding Screen # : " << screenCounter << "\t with Name : " << screenOne.getScreenName() << "\t" ;

            Movie movie;


            switch (screenCounter)
            {
            case 1:
            {
                MovieEnglish movie1;
                movie = movie1;
            }
            break;

            case 2:
            {
                MovieHindi movie2;
                movie = movie2;
            }
            break;

            case 3:
            {
                MovieMarathi movie3;
                movie = movie3;
            }
            break;

            case 4:
            {
                MovieGujrati movie4;
                movie = movie4;
            }
            break;

            } // switch (screenCounter)


            movie.setName("Star Track "+ to_string(screenCounter));

            std::cout << "\n Adding Movie # : " << screenCounter << "\t with Name : " << movie.getName() << "\t of Language : " << movie.getLanguage() << "\t" ;

            // added movie to one screen
            screenOne.setMovie(movie);

            vector<Offer> offerList;

            Offer myOffer1;
            Offer myOffer2;
            Offer myOffer3;
            Offer myOffer4;

            myOffer1.setDescription("Buy 2 SeatDeluxe and get 2 teas at half price");
            myOffer2.setDescription("Buy 2 SeatVIP and get 2 SnackVadaPav at half price");
            myOffer3.setDescription("Buy 2 SeatBox and get 2 SnackVadaPav free");
            myOffer4.setDescription("Buy 2 SeatBox and get 2 SnackPopCorn at half price");

            offerList.push_back(myOffer1);
            offerList.push_back(myOffer2);
            offerList.push_back(myOffer3);
            offerList.push_back(myOffer4);

            // added offerList to one screen
            screenOne.setOfferList(offerList);


            vector<ShowTiming> showTimingList;

            earlyMorningShow myShow1;
            morningShow myShow2;
            afternoonShow1 myShow3;
            afternoonShow2 myShow4;
            eveningShow1 myShow5;
            eveningShow2 myShow6;
            nightShow myShow7;

            showTimingList.push_back(myShow1);
            showTimingList.push_back(myShow2);
            showTimingList.push_back(myShow3);
            showTimingList.push_back(myShow4);
            showTimingList.push_back(myShow5);
            showTimingList.push_back(myShow6);

            // added showTimingList to one screen
            screenOne.setShowTimingList(showTimingList);


            vector<Seat> seatList;

            int seatCounter = 0;
            int seatSize = 0;

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatNormal mySeat1;
                mySeat1.setSeatNumber("SN-" + to_string(seatCounter));
                seatList.push_back(mySeat1);
                seatCounter++;

            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatVIP mySeat2;
                mySeat2.setSeatNumber("SV-" + to_string(seatCounter));
                seatList.push_back(mySeat2);
                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatDeluxe mySeat3;
                mySeat3.setSeatNumber("SD-" + to_string(seatCounter));
                seatList.push_back(mySeat3);
                seatCounter++;
            }

            seatCounter = 1;
            seatSize = MAX_SEAT_SIZE;
            while (seatCounter <= seatSize)
            {
                SeatBox mySeat4;
                mySeat4.setSeatNumber("SB-" + to_string(seatCounter));
                seatList.push_back(mySeat4);

                seatCounter++;
            }

            // added seatList to one screen
            screenOne.setSeatList(seatList);

            // added one screen to Theatre
            screenList.push_back(screenOne);

            screenCounter++;
        } // while (screenCounter <= sreenSize)

        // add screens to Theatre
        tempTheatre1.setScreenList(screenList);


        vector<Drink> drinkList;

        DrinkCoffee myDrink1;
        DrinkTea myDrink2;
        DrinkColdDrink myDrink3;
        DrinkWater myDrink4;

        myDrink1.setMyDetails() ;
        myDrink2.setMyDetails() ;
        myDrink3.setMyDetails() ;
        myDrink4.setMyDetails() ;

        drinkList.push_back(myDrink1);
        drinkList.push_back(myDrink2);
        drinkList.push_back(myDrink3);
        drinkList.push_back(myDrink4);

        tempTheatre1.setDrinkList(drinkList);



        vector<Snack> snackList;

        SnackVadaPav mySnack1;
        SnackBurger mySnack2;
        SnackPopCorn mySnack3;
        SnackSamosa mySnack4;

        mySnack1.setMyDetails() ;
        mySnack2.setMyDetails() ;
        mySnack3.setMyDetails() ;
        mySnack4.setMyDetails() ;

        snackList.push_back(mySnack1);
        snackList.push_back(mySnack2);
        snackList.push_back(mySnack3);
        snackList.push_back(mySnack4);

        tempTheatre1.setSnackList(snackList);


        std::cout << "\n Ending FunRepublic Theatre Setup \t ***********************\n";

        //std::cout << "\n Displaying FunRepublic Theatre Setup \t ######################### \n";
        //tempTheatre1.printMyDetails();


        return tempTheatre1;

    } // Theatre SetupTheatreFunRepublic()



    vector<Theatre> SetupAllTheatres()
    {

        vector<Theatre> allTheatreList;
        Theatre oneTheatre;

        oneTheatre = SetupTheatreCineWorld();
        allTheatreList.push_back(oneTheatre);

        oneTheatre = SetupTheatreCineMagic();
        allTheatreList.push_back(oneTheatre);

        oneTheatre = SetupTheatreCineMax();
        allTheatreList.push_back(oneTheatre);

        oneTheatre = SetupTheatreFunRepublic();
        allTheatreList.push_back(oneTheatre);

        // display content of the all Theatres
        //displayAllTheatreData(allTheatreList);

        return allTheatreList;

    } // vector<Theatre> SetupAllTheatres(){


    // display content of the Theatre vector
    void displayAllTheatreData(vector<Theatre> allTheatreList)
    {

        int theatreListSize = allTheatreList.size();
        cout << "\n Number of Theatres # " << theatreListSize << " #";

        int theatreCounter = 0;
        while (theatreCounter < theatreListSize)
        {
            Theatre oneTheatre = allTheatreList.at(theatreCounter);
            oneTheatre.printMyDetails();

            theatreCounter++;
        } // while (theatreCounter <= theatreListSize) {


    } // void displayCustomerData(vector<Customer> allCustomerList){



    // display names of the Theatre vector
    void displayTheatreNames(vector<Theatre> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            Theatre oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " for " << oneData.getTheatreName() << " at " << oneData.getAddress()<< " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }


    // display names of the Screen vector
    void displayMovieNames(vector<Screen> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            Screen oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " for " << oneData.getMovie().getName() << " in " << oneData.getMovie().getLanguage() << " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }


    // display names of the Screen vector
    void displayShowTiming(vector<ShowTiming> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            ShowTiming oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " for show starting at " << oneData.getStartTime() << " and ending at " << oneData.getEndTime() << " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }


    // display names of the Screen vector
    void displaySeat(vector<Seat> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;

        while (dataCounter < dataSize)
        {
            Seat oneData = allList.at(dataCounter);

            // check for booked seat
            if (oneData.getIsBooked())
            {
                setTextColor(4);
                std::cout << "\Booked " << " Seat Type: " << oneData.getType() << " and Seat Number: " << oneData.getSeatNumber() << " for INR " << oneData.getPrice() << " \n";
                setTextColor(7);
            }
            else
            {
                //setTextColor(2);
                //std::cout << "\n\nAvailability --> YES Select "  << (dataCounter+1) << " For Seat Type: " << oneData.getType() << " and Seat Number: " << oneData.getSeatNumber() << " for INR " << oneData.getPrice() << " \n";

               std::cout <<"Select "  << (dataCounter+1) << "\nFor Seat Type: " << oneData.getType()<<"\nHaving Seat Number: " << oneData.getSeatNumber() <<" for INR " << oneData.getPrice()<< "\nAvailability --> YES  "<< " \n\n";

                //setTextColor(7);
            }
            dataCounter++;
        } // while (dataCounter <= dataSize) {
        std::cout << "\n";
    }


    // display names of the Screen vector
    void displayOffer(vector<Offer> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            Offer oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " to " << oneData.getDescription() << " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }


    // display names of the Screen vector
    void displaySnack(vector<Snack> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            Snack oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " for " << oneData.getName() << " for INR " << oneData.getPrice() << " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }


    // display names of the Screen vector
    void displayDrink(vector<Drink> allList)
    {
        int dataSize = allList.size();

        int dataCounter = 0;
        while (dataCounter < dataSize)
        {
            Drink oneData = allList.at(dataCounter);
            std::cout << "\nSelect " << (dataCounter+1) << " for " << oneData.getName() << " for INR " << oneData.getPrice() << " \n";
            dataCounter++;
        } // while (dataCounter <= dataSize) {

    }



    vector<Booking> readCustomerBookingDataFromFile (string fileName)
    {

        ifstream  inFile;

        vector<Booking> customerBookingList;

        inFile.open(fileName, ios::in);

        // check if file exists
        if (!inFile.is_open())
        {
            setTextColor(4);
            cout << "\n" << fileName << " not found\n";
            setTextColor(7);
        }
        else
        {
            string fileDataRow;
            int rowCounter = 0;

            // read one line at a time, from file
            while (getline (inFile, fileDataRow))//infile from where is read, file data row where data is stored
            {

                // show one line of the text from the file
                //cout << "\n Row " << rowCounter << " Data # " << fileDataRow << " #";
                rowCounter++;

                unsigned long bookingNumber;
                string theatreDetails;
                string movieDetails;
                string screenName;
                string showDetails;
                string seatDetails;
                string offerDetails;
                string snackDetails;
                string drinkDetails;
                int totalOrderCost ;


                istringstream lineData(fileDataRow);
                int colCounter = 1;
                string colData;
                char delimitor = *DELIMITER ; // ','

                // read one delimited word at a time, from the one row data
                while (std::getline(lineData, colData, delimitor))
                {

                    // show one word of the line
                    //cout << "\n Column " << colCounter << " Data # " << colData << " #";

                    switch (colCounter)
                    {
                    case 1:
                    {
                        // convert from string to unsigned long
                        bookingNumber = stoul(colData);
                        break;
                    }

                    case 2:
                    {
                        theatreDetails = colData;
                        break;
                    }

                    case 3:
                    {
                        movieDetails = colData;
                        break;
                    }

                    case 4:
                    {
                        screenName = colData;
                        break;
                    }


                    case 5:
                    {
                        showDetails = colData;
                        break;
                    }


                    case 6:
                    {
                        seatDetails = colData;
                        break;
                    }


                    case 7:
                    {
                        offerDetails = colData;
                        break;
                    }


                    case 8:
                    {
                        snackDetails = colData;
                        break;
                    }


                    case 9:
                    {
                        drinkDetails = colData;
                        break;
                    }


                    case 10:
                    {
                        totalOrderCost = stoi(colData);;
                        break;
                    }


                    } // switch (colCounter) {


                    colCounter++;

                } //  while (std::getline(lineData, colData, DELIMITER)) {

                // create one booking and add / push to the customer vector
                Booking oneBooking (bookingNumber, theatreDetails,movieDetails,screenName,showDetails,seatDetails,offerDetails,snackDetails,drinkDetails,totalOrderCost);
                //oneBooking.printMyDetails();

                // add one customer booking record to the vector.
                customerBookingList.push_back(oneBooking);


            } // while (getline (inFile, fileDataRow)) {


            inFile.close();
        }


        //displayCustomerBookingData(customerBookingList);

        return customerBookingList;


    } // vector<Booking> readCustomerBookingDataFromFile (string fileName) {


    // display content of the customerList vector
    void displayCustomerBookingData(vector<Booking> allBookingList)
    {

        int BookingListSize = allBookingList.size();
        setTextColor(1);
        cout << "\n Total Number of Bookings # " << BookingListSize << " #\n";
        setTextColor(7);

        int bookingCounter = 0;
        while (bookingCounter < BookingListSize)
        {
            Booking customerBooking = allBookingList.at(bookingCounter);
            //customerBooking.printMyDetails();

            std::cout << "\n\tYour Booking Number: " << customerBooking.getBookingNumber()
                      << "\n\tTheatre: " << customerBooking.getTheatreDetails()
                      << "\n\tMovie: "<< customerBooking.getMovieDetails()
                      << "\n\tShow: "<< customerBooking.getShowDetails()
                      << "\n\tSeat: "<< customerBooking.getSeatDetails()
                      << "\n\tOffer: "<< customerBooking.getOfferDetails()
                      << "\n\tSnack: "<< customerBooking.getSnackDetails()
                      << "\n\tDrink: "<< customerBooking.getDrinkDetails()
                      << "\n\tTotal Booking Cost: "<< customerBooking.getTotalOrderCost() << "\n ";


            bookingCounter++;
        } // while (bookingCounter <= BookingListSize) {


    } // void displayCustomerData(vector<Booking> allCustomerList){



};
