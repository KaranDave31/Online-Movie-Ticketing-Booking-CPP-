#pragma once

#include<iostream>
using namespace std;

class Movie
{
protected:
    string name;
    string language;

public:
    string getName(){
        return name;
    }

    void setName(string nameVal){
        name = nameVal;
    }


    string getLanguage(){
        return language;
    }

    void setLanguage(string languageVal){
        language = languageVal;
    }


    void printMyDetails()
    {
        std::cout << "\n Movie Name: " << name << "\t Language : " << language << "\t" ;
    } // void printMyDetails(){

};


class MovieEnglish : public Movie
{
public:
    MovieEnglish(){
        language = "English";
    }

};


class MovieHindi : public Movie
{

public:
    MovieHindi(){
        language = "Hindi";
    }

};

class MovieMarathi : public Movie
{
public:
    MovieMarathi(){
        language = "Marathi";
    }

};

class MovieGujrati : public Movie
{
public:
    MovieGujrati(){
        language = "Gujrati";
    }
};


