#include <iostream>
#include "conio.h"
#include <fstream>
#include <string>

#include "Utility.cpp"
// #include "Customer.cpp" --- included in Utility.cpp

#include "drink.cpp"
#include "snack.cpp"
#include "seat.cpp"
#include "offer.cpp"
#include "movie.cpp"
#include "ShowTiming.cpp"
#include "screen.cpp"
#include "booking.cpp"

#define CUSTOMER_DATA_FILE ".\\dataFiles\\customerData.txt"
#define CUSTOMER_BOOKING_DATA_FILE ".\\dataFiles\\customerBookingData_"

// NOTE ----- using namespace std; is bad practice, and that one should use std::cout and std::cin directly instead

vector<Customer> allCustomerList;
vector<Theatre> allTheatreList;

Utility myUtility;
//string adminPassword = "BTITerm5";

string adminPassword = "22";
Customer LoggedInCustomer ;


void loadApplicationData () {
    //std::cout << "\nStarting to load Application data ...";

    //::cout << "\nLoading Customer data ...";
    allCustomerList = myUtility.readCustomerDataFromFile(CUSTOMER_DATA_FILE);

    //std::cout << "\nLoading Theatre data ...";
    allTheatreList = myUtility.SetupAllTheatres();

    //std::cout << "\nApplication data load has been completed ...\n";
    //system("pause");

} // void loadApplicationData (){


bool isAdminOK () {
    bool retValue = false;

    std::cout << "\n\t\tEnter ADMIN password\t";
    std::cin.ignore();
    string userInputText = "";

    myUtility.hideUserInput();
    std::getline (std::cin, userInputText,'\n');
    //std::cout << "\nYou have entered \t" << userInputText ;
    myUtility.showUserInput();

    if (userInputText.compare(adminPassword) != 0) {
        std::cout << "\n\t\tIncorrect Password .. \n";
    } else {
        // password is all OK
        retValue = true;
    }

    return retValue;

} // bool isAdminOK () {



bool isUserLoginOK () {
    bool retValue = false; //default value is intailised to false
    string userInputName = "";
    string userInputPassword = "";
    LoggedInCustomer.setLoggedIn(false);

    std::cout << "\n\t\tEnter your name \t";
    // first character gets dropped by getline, so to avoid this used cin.ignore();
    std::cin.ignore();
    std::getline (std::cin, userInputName,'\n');

    std::cout << "\n\t\tEnter your password \t";
    myUtility.hideUserInput();
    std::getline (std::cin, userInputPassword,'\n');
    myUtility.showUserInput();


    if ((userInputName.length() > 0 ) &&  (userInputPassword.length() > 0 )) {
        LoggedInCustomer = myUtility.validateUserLogin(allCustomerList, userInputName, userInputPassword);
            if ( LoggedInCustomer.getLoggedIn()) {
            retValue = true;
    }
    }

    return retValue;

} // bool isUserLoginOK () {



bool registerNewUser () {
    bool retValue = false;


        string userInputText;

        Customer customer1;

        std::cout << "\n\n\n\t=========================================================== Welcome to new user registration ===========================================================";


        // int userInputNumber;
        // std::cin >> userInputText;
        // NOTE -- cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being extracted,
        // and thus extracting a string means to always extract a single word, not a phrase or an entire sentence.
        // To get an entire line from cin, use function, called getline
        // A common problem while using getline with cin is getline does not ignore leading whitespace characters.
        // If getline is used after cin >>, the getline() sees this newline character as leading whitespace, and it just stops reading any further.

        //myUtility.showUserInput();
        // NOTE - no need t ask the ID, as this will be auto generated
        std::cout << "\n\n\tEnter user name\t";
        //std::cin.ignore();
        std::getline (std::cin, userInputText,'\n');
        //                    std::cout << "\nYou have entered \t" << userInputText ;
        //                    system("pause");
        customer1.setCustomerName(userInputText);

        bool passwordOk = false;
        string tempPassword = "";

        myUtility.hideUserInput();
        while (!passwordOk) {
            std::cout << "\n\n\tEnter user password\t";
            userInputText = "";
            tempPassword = "";
            //std::cin.ignore();
            std::getline (std::cin, userInputText,'\n');

            if (userInputText.length() < 9) {
                myUtility.setTextColor(4);
                //std::cout << "\nYou have entered \t" << userInputText ;
                std::cout << "\n\n\tPassword length should be more than 8 characters\t";
                myUtility.setTextColor(7);
            } else {
                tempPassword = userInputText;

                std::cout << "\n\n\tRe-enter user password\t";
                userInputText = "";

                std::getline (std::cin, userInputText,'\n');
                if (tempPassword.compare(userInputText) != 0) {
                    //std::cout << "\nYou have re-entered \t" << userInputText ;
                    myUtility.setTextColor(4);
                    std::cout << "\n\tBoth Passwords are not matching. Retry \n";
                    myUtility.setTextColor(7);
                } else { // if (tempPassword.compare(userInputText) != 0){
                    // password is all OK
                    passwordOk = true;
                }
            } // if (userInputText.length() < 9) {

        } // while (!passwordOk) {

        myUtility.showUserInput();
        customer1.setPassword(userInputText);

        std::cout << "\n\tEnter user e-mail\t";
        userInputText = "";
        std::getline (std::cin, userInputText,'\n');
        customer1.setEmailAddress(userInputText);


        customer1.printMyDetails();
        userInputText = customer1.toCSV();

        myUtility.writeToFile(CUSTOMER_DATA_FILE, userInputText);
        myUtility.setTextColor(2);
        std::cout << "\n\n\n\t=========================================================== You have successfully registered ===========================================================\n\n";
        myUtility.setTextColor(7);

        // add this customer record to the vector.
        allCustomerList.push_back(customer1);
        system("pause");




    return retValue;

} // bool registerNewUser ()




void delimitorTest () {
    constexpr const char* DELIMITER = ",";
    char delimitor = *DELIMITER ; // ','
    std::cout << "\n\n\n\ DELIMITER " << *DELIMITER;

}






int main() {

    bool mainLoop = true;

    // load all application data ...
    loadApplicationData();


    while (mainLoop == true) {
        int userMode;

        myUtility.console_clear_screen();
        std::cout<<"\n\n\t\t=========================";
        std::cout<<"   Movie Ticket Booking  ";
        std::cout<<"=========================\n\n";

        std::cout << "\n\t\tMake Your Choice\n\t\t 1 - Login\n\t\t 2 - Registration\n\t\t 3 - Show Registered Customers\n\t\t 0 - Exit Application\n\n\t\t ";
        std::cin >> userMode;

        if (!std::cin.good()) {
            userMode = 1000;
            // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// searched on net for the solution
        }


        switch (userMode) {

        case 1: { // Login
            if (!isUserLoginOK()) {
                myUtility.setTextColor(4);
                std::cout << "\n\n\t\tUser login failed \n";
                myUtility.setTextColor(7);
                system("pause");

            } else {
                myUtility.setTextColor(2);
                std::cout << "\n\n\t\tUser login successful \n";
                myUtility.setTextColor(7);
system("pause");
                bool LoggedInLoop = true;
                int userActionMode;

                while (LoggedInLoop == true) {
                    myUtility.console_clear_screen();
                    myUtility.setTextColor(1);
                    std::cout << "\n\t\t\t\t\t\tLogged in User --> " << LoggedInCustomer.getCustomerName();
                    myUtility.setTextColor(7);
                    std::cout << "\n\n\t\tSelect User Operation \n\t\t 1 - Make Booking\n\t\t 2 - View Bookings\n\t\t 0 - Logout \n\t\t ";
                    std::cin >> userActionMode;
                    if (!std::cin.good()) {
                        userActionMode = 1000;//to break from loop
                        // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } // if (!std::cin.good()) {

                    switch (userActionMode) {

                    case 1: { // Make Booking
                        bool makeBookingLoop = true;
                        int bookingActionMode;
                        Booking customerBooking;


                        while (makeBookingLoop) {
                            bookingActionMode = 0;
                            myUtility.console_clear_screen();
                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                            /*std::cout << "\n\t\tUnder Make Booking ...";*/
                            myUtility.setTextColor(7);

                            std::cout << "\n\nSelect a Theatre from the below list \t OR \t select 0 for Return to Booking\n";
                            myUtility.displayTheatreNames(allTheatreList);
                            std::cin >> bookingActionMode;

                            if (!std::cin.good()) {
                                bookingActionMode = 1000;
                                // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            } // if (!std::cin.good()) {

                            if (bookingActionMode == 0) {
                                makeBookingLoop = false;
                                std::cout << "\n\nReturn to Make Booking\n";
                                customerBooking.clearMyDetails();
                                system("pause");
                            } else if ( (bookingActionMode < 0) || (bookingActionMode > allTheatreList.size()) ) {
                                myUtility.setTextColor(4);
                                std::cout << "\n\n\t\tYou have selected incorrect option.\n";
                                myUtility.setTextColor(7);
                                system("pause");
                            } else {
                                int selectedTheatreIndex = bookingActionMode-1;
                                customerBooking.setTheatreDetails(allTheatreList.at(selectedTheatreIndex).getTheatreName()
                                                                  + " at " + allTheatreList.at(selectedTheatreIndex).getAddress());

                                vector<Screen> screenList = allTheatreList.at(selectedTheatreIndex).getScreenList();

                                bool selectMovieLoop = true;

                                while (selectMovieLoop) {
                                    myUtility.console_clear_screen();
                                    myUtility.setTextColor(1);
                                    std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                    /*std::cout << "\nUnder Make Booking ";*/
                                    myUtility.setTextColor(2);
                                    std::cout << "\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails() << " \n ";
                                    myUtility.setTextColor(7);
                                    std::cout << "\n\nSelect a Movie from the below list \t OR \t select 0 for Return to Booking\n";
                                    bookingActionMode = 0;
                                    myUtility.displayMovieNames(screenList);
                                    std::cin >> bookingActionMode;
                                    if (!std::cin.good()) {
                                        bookingActionMode = 1000;
                                        // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    } // if (!std::cin.good()) {

                                    if (bookingActionMode == 0) {
                                        makeBookingLoop = false;
                                        selectMovieLoop = false;
                                        std::cout << "\n\nReturn to Make Booking \n";
                                        customerBooking.clearMyDetails();
                                        //std::cin.ignore();
                                        system("pause");
                                    } else if ( (bookingActionMode < 0) || (bookingActionMode > screenList.size()) ) {
                                        myUtility.setTextColor(4);
                                        std::cout << "\n\nYou have selected incorrect option.\n";
                                        myUtility.setTextColor(7);
                                        //std::cin.ignore();
                                        system("pause");
                                    } else {
                                        int selectedScreenIndex = bookingActionMode-1;
                                        customerBooking.setMovieDetails(screenList.at(selectedScreenIndex).getMovie().getName()
                                                                        + " in " + screenList.at(selectedScreenIndex).getMovie().getLanguage());
                                        customerBooking.setScreenName(screenList.at(selectedScreenIndex).getScreenName());


                                        vector<ShowTiming> ShowTimingList = screenList.at(selectedScreenIndex).getShowTimingList();

                                        bool showTimingLoop = true;
                                        while (showTimingLoop) {
                                            myUtility.console_clear_screen();
                                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                            /*std::cout << "\nUnder Make Booking ...";*/
                                            myUtility.setTextColor(2);
                                            std::cout << "\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                      << "\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails() << " \n ";
                                            myUtility.setTextColor(7);
                                            std::cout << "\n\nSelect a Show Timing from the below list \t OR \t select 0 for Return to Booking\n";
                                            bookingActionMode = 0;
                                            myUtility.displayShowTiming(ShowTimingList);
                                            std::cin >> bookingActionMode;
                                            if (!std::cin.good()) {
                                                bookingActionMode = 1000;
                                                // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            } // if (!std::cin.good()) {

                                            if (bookingActionMode == 0) {
                                                makeBookingLoop = false;
                                                selectMovieLoop = false;
                                                showTimingLoop = false;
                                                std::cout << "\nReturn to Make Booking \n";
                                                customerBooking.clearMyDetails();
                                                system("pause");
                                            } else if ( (bookingActionMode < 0) || (bookingActionMode > ShowTimingList.size()) ) {
                                                myUtility.setTextColor(4);
                                                std::cout << "\n\nYou have selected incorrect option.\n";
                                                myUtility.setTextColor(7);
                                                system("pause");
                                            } else {
                                                int ShowTimingIndex = bookingActionMode-1;
                                                customerBooking.setShowDetails(" Start Time: " + ShowTimingList.at(ShowTimingIndex).getStartTime()
                                                                               + " End Time: " + ShowTimingList.at(ShowTimingIndex).getEndTime());


                                                vector<Seat> seatList = screenList.at(selectedScreenIndex).getSeatList();

                                                bool seatLoop = true;
                                                while (seatLoop) {
                                                    myUtility.console_clear_screen();
                                                    myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                                    /*std::cout << "\nUnder Make Booking ...";*/
                                                    myUtility.setTextColor(2);
                                                    std::cout << "\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                              << "\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails()
                                                              << "\n\n\t\t\tShow: "<< customerBooking.getShowDetails() << " \n ";
                                                    myUtility.setTextColor(7);


                                                    // ask # of seats ...
                                                    bool seatOK = false;
                                                    int selectedSeatCount = 0;

                                                    while (! seatOK) {
                                                        std::cout << "\n\nEnter number of seats \t OR \t enter 0 for Return to Booking\n";
                                                        std::cin >> selectedSeatCount;

                                                        if (!std::cin.good()) {
                                                            myUtility.setTextColor(4);
                                                            std::cout << "\nYou have entered incorrect option.\n";
                                                            myUtility.setTextColor(7);

                                                            // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                            cin.clear();
                                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        } else { // if (!std::cin.good()) {
                                                            if (selectedSeatCount < 0) {
                                                                myUtility.setTextColor(4);
                                                                std::cout << "\nYou have entered incorrect option.\n";
                                                                myUtility.setTextColor(7);
                                                            }else if (selectedSeatCount > seatList.size ()){
                                                                myUtility.setTextColor(4);
                                                                std::cout << "\nYour requirement is more than theatre capacity which is "<<seatList.size()<<" seats.\n";
                                                                myUtility.setTextColor(7);
                                                            }
                                                            else {
                                                                seatOK = true;
                                                            }

                                                        } // else


                                                    } // while (! seatOK) {


                                                    if (selectedSeatCount == 0) {
                                                        bookingActionMode = 0;

                                                    } else {
                                                        std::cout << "\nYou are booking " << selectedSeatCount << " seats\n ";
                                                        std::cout << "\nSelect starting seat from the below list \t OR \t select 0 for Return to Booking\n";
                                                        bookingActionMode = 0;
                                                        myUtility.displaySeat(seatList);
                                                        std::cin >> bookingActionMode;
                                                        if (!std::cin.good()) {
                                                            bookingActionMode = 1000;
                                                            // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                            cin.clear();
                                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        } // if (!std::cin.good()) {

                                                    } // else


                                                    // check if enough seat from the starting seat if not then follow incorrect option flow
                                                    // bookingActionMode = 1000;
                                                    int seatTempIndex = bookingActionMode-1;

                                                    if ( (seatTempIndex + selectedSeatCount)  > seatList.size()) {
                                                        bookingActionMode = 1000;
                                                        myUtility.setTextColor(4);
                                                        std::cout << "\n" << selectedSeatCount << " seats not available " << " after " << seatList.at(seatTempIndex).getSeatNumber();
                                                        myUtility.setTextColor(7);
                                                    } // if (( (seatTempIndex + selectedSeatCount)  > seatList.size()) {


                                                    if (bookingActionMode == 0) {
                                                        makeBookingLoop = false;
                                                        selectMovieLoop = false;
                                                        showTimingLoop = false;
                                                        seatLoop = false;
                                                        std::cout << "\nReturn to Make Booking \n";
                                                        customerBooking.clearMyDetails();
                                                        system("pause");
                                                    } else if ( (bookingActionMode < 0) || (bookingActionMode > seatList.size()) ) {
                                                        myUtility.setTextColor(4);
                                                        std::cout << "\n\nYou have selected incorrect option.\n";
                                                        myUtility.setTextColor(7);
                                                        system("pause");
                                                    } else {
                                                        int seatIndex = bookingActionMode-1;
                                                        string seatDetails ;

                                                        int counter = 0;
                                                        int totalCost = 0;

                                                        //get user specified seats from the starting sear.
                                                        while ( counter < selectedSeatCount) {
                                                            seatDetails += " Seat Type: " + seatList.at(seatIndex).getType()
                                                                           + " Seat Number: " + seatList.at(seatIndex).getSeatNumber()+ ".";
                                                            totalCost += seatList.at(seatIndex).getPrice();

                                                            //std::cout << "\nseatDetails --> " << seatDetails;

                                                            // also calculate the totalSeatCost ***********************************************************

                                                            counter++;
                                                            seatIndex++;

                                                        } // while ( counter < selectedSeatCount) {


                                                        customerBooking.setSeatDetails(seatDetails);


                                                        customerBooking.setTotalOrderCost(customerBooking.getTotalOrderCost() + totalCost);



                                                        vector<Offer> offerList = screenList.at(selectedScreenIndex).getOfferList();

                                                        bool offerLoop = true;
                                                        while (offerLoop) {
                                                            myUtility.console_clear_screen();
                                                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                                            /*std::cout << "\nUnder Make Booking ...";*/
                                                            myUtility.setTextColor(2);
                                                            std::cout << "\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                                      << "\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails()
                                                                      << "\n\n\t\t\tShow: "<< customerBooking.getShowDetails()
                                                                      << "\n\n\t\t\tSeat: "<< customerBooking.getSeatDetails()
                                                                      << "\n\n\t\t\tTotal Booking Cost: "<< customerBooking.getTotalOrderCost() << " \n ";
                                                            myUtility.setTextColor(7);

                                                            std::cout << "\nSelect offer from the below list \t OR \t select 0 for Not Interested\n";
                                                            bookingActionMode = 0;
                                                            myUtility.displayOffer(offerList);
                                                            std::cin >> bookingActionMode;
                                                            if (!std::cin.good()) {
                                                                bookingActionMode = 1000;
                                                                // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                cin.clear();
                                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                            } // if (!std::cin.good()) {


                                                            if (bookingActionMode == 0) {
                                                                offerLoop = false;
                                                                // only offer is skipped, proceed to next step
                                                            } else if ( (bookingActionMode < 0) || (bookingActionMode > offerList.size()) ) {
                                                                myUtility.setTextColor(4);
                                                                std::cout << "\n\nYou have selected incorrect option.\n";
                                                                myUtility.setTextColor(7);
                                                                system("pause");
                                                            } else {
                                                                int offerIndex = bookingActionMode-1;
                                                                customerBooking.setOfferDetails( offerList.at(offerIndex).getDescription());

                                                                std::cout << "\n\nYou have selected --> \t" + customerBooking.getOfferDetails();

                                                                offerLoop = false;

                                                            } // else


                                                        } // while (offerLoop)




                                                        vector<Snack> snackList = allTheatreList.at(selectedTheatreIndex).getSnackList();

                                                        bool snackLoop = true;
                                                        while (snackLoop) {
                                                            myUtility.console_clear_screen();
                                                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                                            /*std::cout << "\nUnder Make Booking ...";*/
                                                            myUtility.setTextColor(2);
                                                            std::cout << "\n\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                                      << "\n\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails()
                                                                      << "\n\n\n\t\t\tShow: "<< customerBooking.getShowDetails()
                                                                      << "\n\n\n\t\t\tSeat: "<< customerBooking.getSeatDetails()
                                                                      << "\n\n\n\t\t\tOffer: "<< customerBooking.getOfferDetails()
                                                                      << "\n\n\n\t\t\tTotal Booking Cost: "<< customerBooking.getTotalOrderCost() << " \n ";
                                                            myUtility.setTextColor(7);


                                                            // ask # of Snack ...
                                                            bool snackOK = false;
                                                            int selectedSnackCount = 0;

                                                            while (! snackOK) {
                                                                std::cout << "\nEnter number of Snack \t OR \t enter 0 for Not Interested\n";
                                                                std::cin >> selectedSnackCount;

                                                                if (!std::cin.good()) {
                                                                    myUtility.setTextColor(4);
                                                                    std::cout << "\nYou have entered incorrect option.\n";
                                                                    myUtility.setTextColor(7);

                                                                    // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                } else { // if (!std::cin.good()) {
                                                                    if (selectedSnackCount < 0) {
                                                                        myUtility.setTextColor(4);
                                                                        std::cout << "\nYou have entered incorrect option.\n";
                                                                        myUtility.setTextColor(7);
                                                                    } else {
                                                                        snackOK = true;
                                                                    }

                                                                } // else

                                                            } // while (! snackOK) {



                                                            if (selectedSnackCount == 0) {

                                                                bookingActionMode = 0;

                                                            } else {
                                                                std::cout << "\nYou are ordering " << selectedSnackCount << " Snacks\n ";

                                                                std::cout << "\nSelect from the below list \t OR \t select 0 for Return to Booking\n";
                                                                bookingActionMode = 0;
                                                                myUtility.displaySnack(snackList);
                                                                std::cin >> bookingActionMode;
                                                                if (!std::cin.good()) {
                                                                    bookingActionMode = 1000;
                                                                    // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                } // if (!std::cin.good()) {


                                                            } // else



                                                            if (bookingActionMode == 0) {
                                                                snackLoop = false;
                                                                // only snack is skipped, proceed to next step
                                                            } else if ( (bookingActionMode < 0) || (bookingActionMode > snackList.size()) ) {
                                                                myUtility.setTextColor(4);
                                                                std::cout << "\nYou have selected incorrect option.\n";
                                                                myUtility.setTextColor(7);
                                                                system("pause");
                                                            } else {
                                                                snackLoop = false;
                                                                int snackIndex = bookingActionMode-1;
                                                                customerBooking.getSnackDetails("" + to_string(selectedSnackCount) + " "
                                                                                                +  snackList.at(snackIndex).getName());

                                                                //std::cout << "\nYou have selected --> \t" << customerBooking.GetsnackDetails() ;

                                                                int totalCost = 0;
                                                                totalCost = selectedSnackCount * snackList.at(snackIndex).getPrice();
                                                                customerBooking.setTotalOrderCost(customerBooking.getTotalOrderCost() + totalCost);


                                                            } // else



                                                        } // while (snackLoop)


                                                        vector<Drink> drinkList = allTheatreList.at(selectedTheatreIndex).getDrinkist();

                                                        bool drinkLoop = true;
                                                        while (drinkLoop) {
                                                            myUtility.console_clear_screen();
                                                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                                            /*std::cout << "\nUnder Make Booking ...";*/
                                                            myUtility.setTextColor(2);
                                                            std::cout << "\n\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                                      << "\n\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails()
                                                                      << "\n\n\n\t\t\tShow: "<< customerBooking.getShowDetails()
                                                                      << "\n\n\n\t\t\tSeat: "<< customerBooking.getSeatDetails()
                                                                      << "\n\n\n\t\t\tOffer: "<< customerBooking.getOfferDetails()
                                                                      << "\n\n\n\t\t\tSnack: "<< customerBooking.getSnackDetails()
                                                                      << "\n\n\n\t\t\tTotal Booking Cost: "<< customerBooking.getTotalOrderCost() << " \n ";
                                                            myUtility.setTextColor(7);


                                                            // ask # of Snack ...
                                                            bool drinkOK = false;
                                                            int selectedDrinkCount = 0;

                                                            while (! drinkOK) {
                                                                std::cout << "\nEnter number of Drink \t OR \t enter 0 for Not Interested\n";
                                                                std::cin >> selectedDrinkCount;

                                                                if (!std::cin.good()) {
                                                                    myUtility.setTextColor(4);
                                                                    std::cout << "\nYou have entered incorrect option.\n";
                                                                    myUtility.setTextColor(7);

                                                                    // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                } else { // if (!std::cin.good()) {
                                                                    if (selectedDrinkCount < 0) {
                                                                        myUtility.setTextColor(4);
                                                                        std::cout << "\nYou have entered incorrect option.\n";
                                                                        myUtility.setTextColor(7);
                                                                    } else {
                                                                        drinkOK = true;
                                                                    }

                                                                } // else

                                                            } // while (! drinkOK) {



                                                            if (selectedDrinkCount == 0) {

                                                                bookingActionMode = 0;

                                                            } else {
                                                                std::cout << "\nYou are ordering " << selectedDrinkCount << " Drink\n ";

                                                                std::cout << "\nSelect from the below list \t OR \t select 0 for Return to Booking\n";
                                                                bookingActionMode = 0;
                                                                myUtility.displayDrink(drinkList);
                                                                std::cin >> bookingActionMode;
                                                                if (!std::cin.good()) {
                                                                    bookingActionMode = 1000;
                                                                    // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                } // if (!std::cin.good()) {


                                                            } // else



                                                            if (bookingActionMode == 0) {
                                                                drinkLoop = false;
                                                                // only snack is skipped, proceed to next step
                                                            } else if ( (bookingActionMode < 0) || (bookingActionMode > drinkList.size()) ) {
                                                                myUtility.setTextColor(4);
                                                                std::cout << "\nYou have selected incorrect option.\n";
                                                                myUtility.setTextColor(7);
                                                                system("pause");
                                                            } else {
                                                                drinkLoop = false;
                                                                int drinkIndex = bookingActionMode-1;
                                                                customerBooking.setDrinkDetails("" + to_string(selectedDrinkCount) + " "
                                                                                                +  drinkList.at(drinkIndex).getName());

                                                                //std::cout << "\nYou have selected --> \t" << customerBooking.getDrinkDetails() ;
                                                                int totalCost = 0;
                                                                totalCost = selectedDrinkCount * drinkList.at(drinkIndex).getPrice();
                                                                customerBooking.setTotalOrderCost(customerBooking.getTotalOrderCost() + totalCost);


                                                            } // else


                                                        } // while (drinkLoop)


                                                        bool paymentLoop = true;
                                                        while (paymentLoop) {
                                                            myUtility.console_clear_screen();
                                                            myUtility.setTextColor(1);
                            std::cout << "\n\n\t\t===================\tLogged in User --> " << LoggedInCustomer.getCustomerName()<<"\t===================";
                                                            /*std::cout << "\nUnder Make Booking ...";*/
                                                            myUtility.setTextColor(2);
                                                            std::cout<<"\n\n\n============================================================================================================================================================================";
                                                            std::cout << "\n\n\n\t\t\tYour Selection - Theatre: " << customerBooking.getTheatreDetails()
                                                                      << "\n\n\t\t\tMovie: "<< customerBooking.getMovieDetails()
                                                                      << "\n\n\t\t\tShow: "<< customerBooking.getShowDetails()
                                                                      << "\n\n\t\t\tSeat: "<< customerBooking.getSeatDetails()
                                                                      << "\n\n\t\t\tOffer: "<< customerBooking.getOfferDetails()
                                                                      << "\n\n\t\t\tSnack: "<< customerBooking.getSnackDetails()
                                                                      << "\n\n\t\t\tDrink: "<< customerBooking.getDrinkDetails()
                                                                      << "\n\n\t\t\tTotal Booking Cost: "<< customerBooking.getTotalOrderCost()<< " \n \n";
                                                            std::cout<<"============================================================================================================================================================================";

                                                            myUtility.setTextColor(7);


                                                            std::cout << "\n\nSelect 1 to Confirm \t OR \t select 0 for Cancel & Return to Booking\n";
                                                            bookingActionMode = 0;

                                                            std::cin >> bookingActionMode;
                                                            if (!std::cin.good()) {
                                                                bookingActionMode = 1000;
                                                                // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                                                cin.clear();
                                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                            } // if (!std::cin.good()) {

                                                            if (bookingActionMode == 0) {
                                                                makeBookingLoop = false;
                                                                selectMovieLoop = false;
                                                                showTimingLoop = false;
                                                                seatLoop = false;
                                                                snackLoop = false;
                                                                drinkLoop = false;
                                                                paymentLoop = false;
                                                                std::cout << "\nReturning to Booking ...\n";
                                                                customerBooking.clearMyDetails();
                                                                system("pause");
                                                            } else if ( (bookingActionMode < 0) || (bookingActionMode > 1) ) {

                                                                myUtility.setTextColor(4);
                                                                std::cout << "\nYou have selected incorrect option.\n";
                                                                myUtility.setTextColor(7);
                                                                system("pause");
                                                            } else {


                                                                string bookingtDetailsText = customerBooking.toCSV();
                                                                string bookingFileName = CUSTOMER_BOOKING_DATA_FILE + to_string(LoggedInCustomer.getCustomerId()) + ".txt";

                                                                myUtility.writeToFile( bookingFileName , bookingtDetailsText);
                                                                std::cout << "\nYou have successfully booked a movie ticket";
                                                                std::cout << "\nYour booking is confirmed !!!";
                                                                std::cout << "\nYour Ticket is attached below, See you on movie day!!!";

                                                                myUtility.setTextColor(1);
                                                                std::cout<<"\n\n\n============================================================================================================================================================================";
                                                            std::cout << "\n\n\t\t\t===================\t MTB Tickets  \t===================";
                                                                std::cout << "\n\n\t\t\t===================\tUser Name --> " << LoggedInCustomer.getCustomerName()<<"\t===================";

                                                            std::cout << "\n\n\n\tTheatre: " << customerBooking.getTheatreDetails()
                                                                      << "\n\n\tMovie: "<< customerBooking.getMovieDetails()
                                                                      << "\n\n\tTimings: "<< customerBooking.getShowDetails()
                                                                      << "\n\n\tSeat: "<< customerBooking.getSeatDetails()
                                                                      << "\n\n\tOffers Availed: "<< customerBooking.getOfferDetails()
                                                                      << "\n\n\tSnacks: "<< customerBooking.getSnackDetails()
                                                                      << "\n\n\tDrinks: "<< customerBooking.getDrinkDetails()
                                                                      << "\n\n\tTotal Booking Cost without GST: "<< customerBooking.getTotalOrderCost()<< " \n"
                                                                    << "\n\n\tTotal Booking Cost with GST: "<< customerBooking.getTotalOrderCost() << " + 25 \n \n";

                                                            std::cout<<"============================================================================================================================================================================\n\n";

                                                                 ;
                                                                /*std::cout << "\nReturning to Booking ...\n";*/
                                                                myUtility.setTextColor(7);


                                                                makeBookingLoop = false;
                                                                selectMovieLoop = false;
                                                                showTimingLoop = false;
                                                                seatLoop = false;
                                                                snackLoop = false;
                                                                drinkLoop = false;
                                                                paymentLoop = false;
                                                                customerBooking.clearMyDetails();

                                                                system("pause");

                                                            } // else


                                                        } // while (paymentLoop)


                                                    } //  else


                                                } // while (seatLoop)


                                            } // else


                                        } // while (showTimingLoop)


                                    } // else

                                } // while (selectMovieLoop) {


                            } // else

                        } // while (makeBookingLoop)

                    }
                    break;


                    case 2: { // View Booking
                        bool viewBookingLoop = true;
                        int bookingActionMode;

                        while (viewBookingLoop == true) {
                            myUtility.console_clear_screen();
                            myUtility.setTextColor(1);
                            std::cout << "\nLogged in User --> " << LoggedInCustomer.getCustomerName();
                            std::cout << "\nUnder View Booking ...";
                            myUtility.setTextColor(7);

                            string bookingFileName = CUSTOMER_BOOKING_DATA_FILE + to_string(LoggedInCustomer.getCustomerId()) + ".txt";

                            //std::cout << "\n bookingFileName ---> " << bookingFileName;

                            vector<Booking> customerBookingList;
                            customerBookingList = myUtility.readCustomerBookingDataFromFile(bookingFileName);
                            myUtility.displayCustomerBookingData(customerBookingList);


                            std::cout << "\nSelect 0 for Return to Booking\n";
                            std::cin >> bookingActionMode;

                            if (!std::cin.good()) {
                                bookingActionMode = 1000;
                                // error occurs if you input a char where an int is expected. to solve the issue, below 2 lines
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            } // if (!std::cin.good()) {

                            if (bookingActionMode == 0) {
                                viewBookingLoop = false;

                            } else {
                                 myUtility.setTextColor(4);
                                std::cout << "\nYou have selected incorrect option.\n";
                                myUtility.setTextColor(7);
                                system("pause");
                            } // else


                        } // while (viewBookingLoop == true)//


                    }
                    break;

                    case 0: { // logout
                        LoggedInLoop = false;
                        std::cout << "\nLogging out ...\n";
                        LoggedInCustomer.clearMyDetails();

                        //system("pause");
                    }
                    break;

                    default: {
                        myUtility.setTextColor(4);
                        std::cout << "\nYou have selected incorrect option.\n";
                        myUtility.setTextColor(7);
                        system("pause");
                    }
                    break;

                    } // switch (userActionMode){

                } // while (LoggedInLoop == true){


            }

            break;
        }


        case 2: { // Registration

            if (!isAdminOK()) {
                myUtility.setTextColor(4);
                std::cout << "\nOnly ADMIN can perform user registration ...\n";
                myUtility.setTextColor(7);
                system("pause");

            } else {
                registerNewUser();
            }

            break;
        }



        case 3: { // Show Registered Customers
            if (!isAdminOK()) {
                myUtility.setTextColor(4);
                std::cout << "\nOnly ADMIN can view user detail...\n";
                myUtility.setTextColor(7);
            } else {
                myUtility.displayCustomerData(allCustomerList);
            }

            system("pause");
            break;
        }

        case 0: { // Exit Application
            mainLoop = false;
            std::cout << "\nThanks for using the Application ...\n";
            system("pause");
            break;
        }

        default: {
            myUtility.setTextColor(2);
            std::cout << "\n\n\t\tYou have selected incorrect option.\n";
            myUtility.setTextColor(7);
            system("pause");
            break;
        }

        } // switch (userMode){




    } // while (mainLoop == true){


    return 0;
}


