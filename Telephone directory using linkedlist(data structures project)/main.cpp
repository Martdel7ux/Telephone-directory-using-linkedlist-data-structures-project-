//
//  main.cpp
//  Telephone directory using linkedlist(data structures project)
//  This program focuses on using linked list to implement a telephone directory system
//  Created by MARTIN AHOTO on 1/05/2022.
//

#include <iostream>
#include<cstring>
#include<fstream>

using namespace std;

fstream MyFile;

//creating structure called user to store data in a linked list
struct User
{
 
string Firstname;
string Lastname;
string number;
 
    User*link;
    User()
    {
        link=NULL;
        
    }
    
};

class PhoneDirectory
{
    
    //implementing pointers for linklist
    User *start,*current,*temp;
public:
    PhoneDirectory()
    {
        start=NULL;
        
    }
    //function to create nodes
    void create_file (string FN, string LN, string num)
    {
        //creates first node
        if(start==NULL)
        {
            start=new User;
            start->link=NULL;
            start->Firstname=FN;
            start->Lastname=LN;
            start->number=num;
            
            MyFile.open ("teldir.txt",ios::out | ios::app);
            MyFile<<"First Name__: "<<start->Firstname<<"__|__Last Name__: "<<start->Lastname<<"__|__Phone Number : "<<start->number<<endl;
            MyFile.close();
            
        }
        //creates new node..
        else
        {
            current=start;
            while(current->link!=NULL)
            {
                current=current->link;
                
            }
            temp=new User;
            temp->Firstname=FN;
            temp->Lastname=LN;
            temp->number=num;
            temp->link=NULL;
            current->link=temp;
            MyFile.open ("teldir.txt",ios::out | ios::app);
            MyFile<<"First Name : "<<temp->Firstname<<"___|__Last Name: "<<temp->Lastname<<"__|__Phone Number :  "<<temp->number<<endl;
            MyFile.close();
            
        }
        
    }
    
    //function to terminate a file
    void terminate_file(string FN, string LN)
    {
        current=start;
        if(start->Firstname==FN && start->Lastname==LN)
        {
            temp=start;
            start=start->link;
            delete temp;
            
        }
        else
        {
            while(current->Firstname!=FN && current->Lastname !=LN)
            {
                if(current->link==NULL)
                {
                    cout<<"We don't have"<<FN<<LN<<"in our directory try again!"<<endl;
                    return ;
                    
                }
                temp=current;
                current=current->link;
                
            }
            temp->link=current->link;
            delete current;
            
        }
        
    }
   
    //print data of the subscriber.
    void display_subscribers()
    {
        current=start;
        int count;
       
        cout<<"User  "<<" ---- User First Name \tUser Last Name \tUser Number"<<endl;
        for(count=1;current->link!=NULL;count++)
        {
            cout<<"Person "<<count<<" --- "<<current->Firstname<<"\t"<<current->Lastname<<"\t"<<current->number<<endl;
            current=current->link;
            
        }
        cout<<"Person "<<count<<" --- "<<current->Firstname<<"\t"<<current->Lastname<<"\t"<<current->number<<endl;
        
    }
    
    //function to search for a subscriber
    void search(string FN, string LN)
    {
        current=start;
        while(current!=NULL)
        {
            if(current->Lastname==LN)
            {
            
                cout<<"\n\t_________DATA FOUND__________\n\n";
                cout<<"Last Name : "<<current->Lastname<<endl;
                cout<<"First Name : "<<current->Firstname<<endl;
                cout<<"Phone Number : "<<current->number<<endl;
                 
                
            }
            current=current->link;
            
        }
        if(current==NULL)
            cout<<"\n\t_______DATA DOES NOT EXIST IN OUR SYSTEM_________\n\n";
        
        
    }
   
    //function to add new subscriber
    void AddNewSubscriber()
    {
        char key;
        
        cout<<"\nDo You want to Add a New Subscriber (y/n) : ";
        cin>>key;
        
        if(key=='y' || key=='Y')
        {
            cout<<"Enter Subscribers First Name: "<<current->Firstname;
            cout<<"Enter Subscribers Last Name: "<<current->Lastname;
            cout<<"Enter New Phone Number "<<current->number;
            cout<<"\n\t_________NEW SUBSCRIBER HAVE BEEN ADDED TO THE SYSTEM________"<<endl;
            
        }

    }
    
    //function to print subscribers from the file
    void print()
    {
        //function to read data from the file
        string s;
        MyFile.open("teldir.txt",ios::in);
        while(!MyFile.eof())
        {
            MyFile>>s;
            cout<<s<<endl;
            
        }
        MyFile.close();
        
    }
    
};

//main program
int main()
{
    PhoneDirectory Tel;
    int num_of_files,i,ch;
    string FN,LN,num;
    cout<<"\n\t===================================================================\n\n";
    cout<<"\t\t\t TELEPHONE DIRECTORY SYSTEM\n";
    cout<<"\n\t===================================================================\n\n";
     
    
    //ask user how many numbers to save
    cout<<"\thow many numbers you want to save : ";
    cin>>num_of_files;
   
    //create and save data in a file
    for(i=1;i<=num_of_files;i++)
    {
        cout<<"\n\tEnter First Name: \t";
        getline(cin,FN);
        
        cin.ignore();
    
        cout<<"\n\tEnter Last Name: \t";
        getline(cin,LN);
        
        cin.ignore();
       
        cout<<"\n\tEnter Phone number \t";
        cin>>num;
        Tel.create_file(FN,LN,num);
        
        cin.ignore();
        cin.ignore();
        
    }
    system("CLS");
    do
    {
        //display options to the user
        cout<<"\n\nChoose your desired option"<<endl;
        cout<<"\n1- Add new phone number\n";
        cout<<"2-Delete any number"<<endl;
        cout<<"3-Add New subscriber"<<endl;
        cout<<"4-Search user"<<endl;
        cout<<"5-Display Subscriber details\n"<<endl;
        cout<<"6-Display Telephone directory data \n"<<endl;
        cout<<"7-Exit\n"<<endl;
        cin>>ch;
        system("CLS");
        switch(ch)
        {
                //program to ask user to add a new phone number
            case 1:
                cout<<"\n\t============================ADD NEW PHONE NUMBER============================\n\n";
                cout<<"Enter Data to insert new person's data'"<<endl;
                cout<<"\nEnter First Name \t";
                getline(cin,FN);
                
                cout<<"\nEnter Last Name \t";
                getline(cin,LN);
                
                cout<<"Enter Phone Number \t";
                cin>>num;
                Tel.create_file(FN,LN,num);
                
                cout<<"Number of "<<FN<<" "<<LN<<" has been Saved "<<endl;
                break;
           
                //Program to remove phone number
            case 2:
                cout<<"\n\t=========================REMOVE PHONE NUMBER============================\n\n";
                cout<<"\nEnter First name of person whose number you want to delete\n"<<endl;
                getline(cin,FN);
                
                cout<<"\nEnter Last Name of person here\n:";
                getline(cin,LN);
                Tel.terminate_file(FN,LN);
                
                cout<<"\nNumber of "<<FN<<" "<<LN<<" Has been deleted"<<endl;
                break;
           
                //program to add a new subscriber to the system
            case 3:
                cout<<"\n\t========================ADD NEW SUBSCRIBER===================\n\n";
                cout<<"\nEnter First Name Here\n:";
                getline(cin,FN);
                cout<<"\nEnter Last Name Here\n:";
                getline(cin,LN);
                cout<<"Enter Phone NUmber Here\n:";
                cin>>num;
                Tel.AddNewSubscriber();
            
                //program to search for the number of a subscriber
            case 4:
                cout<<"\n\t=====================SEARCH NUMBER=====================\n\n";
                cout<<"Enter First Name here:\t";
                getline(cin,FN);
                
                cout<<"Enter Last Name of person here:\t";
                getline(cin,LN);
                Tel.search(FN,LN);
                break;
           
                //program to display subscriber data
            case 5:
                cout<<"\n\t=====================DISPLAY SUBSCRIBER DATA============================\n\n";
                Tel.print();
                break;
            
            //display list of subscribers in the system
            case 6:
                cout<<"\n\t====================LIST OF SUBSCRIBERS======================\n\n";
                Tel.display_subscribers();
                break;
            default:
                cout<<"\t----------Invalid----------"<<endl;
                
        }
        
    }
    //exits program
    while(ch!=6);
    cout<<"\nTHANK YOU"<<endl;
    getchar();
    
}//end of main program
