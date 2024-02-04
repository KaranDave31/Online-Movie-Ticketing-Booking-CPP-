#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Customer
{

private:
    unsigned long customerId;
    string customerName;
    string emailAddress;
    string password;
    bool loggedIn;

public:
    static constexpr const char* DELIMITER = ",";

    Customer ()
    {
        milliseconds ms = duration_cast< milliseconds >(
                              system_clock::now().time_since_epoch()
                          );

       // to get unique booking number everytime
        //std::cout << "\n ms.count: " << ms.count();
        customerId = ms.count();
        //std::cout << "\n Customer Id: " << customerId;

        loggedIn = false;
    }

    Customer (unsigned long customerIdVal, string customerNameVal, string passwordVal, string emailAddressVal, bool loggedInVal )
    {
        customerId = customerIdVal;
        customerName = customerNameVal;
        password = passwordVal;
        emailAddress = emailAddressVal;
        loggedIn = loggedInVal;
    }

    unsigned long getCustomerId()
    {
        return customerId;
    }

    string getCustomerName()
    {
        return customerName;
    }

    void setCustomerName(string value)
    {
        customerName = value;
    }

    string getEmailAddress()
    {
        return emailAddress;
    }

    void setEmailAddress(string value)
    {
        emailAddress = value;
    }

    string getPassword()
    {
        return password;
    }

    void setPassword(string value)
    {
        password = value;
    }


    bool getLoggedIn()
    {
        return loggedIn;
    }

    void setLoggedIn(bool value)
    {
        loggedIn = value;
    }


    void printMyDetails()
    {
        //std::cout << "\n" << typeid(this).name() << "\t Customer Id: " << customerId << "\tCustomer Name: " << customerName << "\tPassword: " << password << "\tEmail Address: " << emailAddress << "\tLogged In: " << loggedIn << "\t" ;
        std::cout << "\n\n\tCustomer Id --> " << customerId << "\n\n\tCustomer Name --> " << customerName << "\n\n\tPassword --> " << password << "\n\n\tEmail Address --> " << emailAddress << "\n\n\tLogged In --> " << loggedIn << "\n\n\n" ;
    } // void printMyDetails(){



    void clearMyDetails()
    {
        customerId = -1;
        customerName = "";
        password = "";
        emailAddress = "";
        loggedIn = false;

    } // void clearMyDetails(){


    string toCSV()
    {
        string retValue = "";

        retValue = to_string(customerId) + DELIMITER + customerName + DELIMITER + password + DELIMITER + emailAddress + DELIMITER + to_string(loggedIn) ;
        // std::cout << "\n### retValue: " << retValue << "\t ###\n";

        return retValue;
    } // string toCSV(){


};

