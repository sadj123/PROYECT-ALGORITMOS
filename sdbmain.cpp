#include<iostream>
#include<string>
#include<fstream>
#include "Database.hpp"
#include "Student.hpp"

int start_up_menu(){
  int choice;
  std::cout<<"1. Display all students"<<std::endl;
  std::cout<<"2. Add student"<<std::endl;
  std::cout<<"3. Delete student"<<std::endl;
  std::cout<<"4. Delete the whole database"<<std::endl;
  std::cout<<"5. Enter students grade"<<std::endl;
  std::cout<<"6. Display specific student information"<<std::endl;
  std::cout<<"7. EXIT "<<std::endl;
  std::cout<<"You can choose any of the options above"<<std::endl;
  std::cin>>choice;
  return choice;
}


int main(){
  Database_map db;
  int choice = 0;
  while(choice != 7){
    choice = start_up_menu();
    switch(choice){
      case 1:{
        system("cls");
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_all();
        std::cout<<"There are a total of "<<db.size()<<" students within our database"<<std::endl;
        std::cout<<std::endl;
        break;
      }
      case 2:{
        system("cls");
        std::string name;
        std::cout<<"Please enter the students name: ";
        std::cin.get();
        getline(std::cin,name);
        db.insert_student(name);
        std::cout<<"The student has successfully been entered to the database!"<<std::endl;
        std::cout<<std::endl;
        break;
      }
      case 3:{
        system("cls");
        std::string name;
        std::cout<<"Please enter the students name which you want to delete: ";
        std::cin.get();
        getline(std::cin,name);
        db.delete_student(name);
        break;
      }
      case 4:{
        std::string answer;
        std::cout<<"Are you sure you wish to delete all the students from the database? ";
        std::cin>>answer;
        if(answer == "yes")
          db.clear();
        else
          start_up_menu();
        break;
      }
      case 5:{
        std::cout<<"THIS IS MISSING"<<std::endl;
      }
      case 6:{
        system("cls");
        std::string name;
        std::cout<<"Please enter the students name: ";
        std::cin.get();
        getline(std::cin,name);
        db.display_student(name);
        std::cout<<std::endl;
        break;
      }
      case 7:{
        std::cout<<"Thank you for using our database!"<<std::endl;
        break;
      }
    }
  }
  return  0;
}
