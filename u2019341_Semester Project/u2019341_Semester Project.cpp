// u2019341_Semester Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

void Table();

using namespace std;
class linkedlist {

public:
    struct Node {

    public:

        int sr=0;
        string name="";
        string pri="";
        string sec="";
        string add="";

        Node* next=NULL;

   


    };

    Node* Head=NULL;

    void create(int serial, string Name, string primary, string secondary, string address)
    {
        
        Node* ptrnew = new Node;

        ptrnew->sr = serial;
        ptrnew->name = Name;
        ptrnew->pri = primary;
        ptrnew->sec = secondary;
        ptrnew->add = address;
        ptrnew->next = Head;
        Head = ptrnew;


        

    }



};
class hashtablelist:public linkedlist{

public:

    void initialize() {

        for (int i = 0; i < 20; i++)
        {
            hashtable[i] = NULL;
        }



    }
    void mapping(int asci)
    {
        index = asci % 20;
        
  
        
    }
    
    void search(string choice)
    
    {

        

        for (int i=0;i<20;i++)
        {

            
            if (hashtable[i]!=NULL&&hashtable[i]->name == choice)
            {

                cout << hashtable[i]->pri << endl;

                cout << hashtable[i]->sec << endl;

                cout << hashtable[i]->add << endl;

                cout << "Match Found" << endl;



                break;
            }

          

            if (i == 19)
            {


                cout<<"Name not Found" << endl;
            }
            
        }

        Table();
      
    }
    void insert()
    {
        if (hashtable[index] == NULL)

        {

            hashtable[index] = Head;



        }
        else
            hashtable[index]->next = Head;

        
    }
       
    void Delete(string del)
        {

            for (int i = 0; i < 20; i++)
            {

                if (hashtable[i]!=NULL&&hashtable[i]->name == del)
                {
                    hashtable[i]->name = "";
                    hashtable[i]->pri = "";
                    hashtable[i]->sec = "";
                    hashtable[i]->add = "";
                    hashtable[i] = NULL;

                    cout << "Record deleted" << endl;

                    break;
                }

                if (i == 19)
                {


                    cout<<"Record not Found"<<endl;
                }

            }

            Table();

        }
 
 
private:

    int index=0;
    Node* hashtable[20];
}T1;

int main()
{




    T1.initialize();
     Table();






    


    

    

        
    
}

void insert()
{


    int Sr;

    string name;

    string primary;

    string secondary;

    string address;


    ifstream file;



    file.open("Table.txt", ios::in);

    while (!file.eof())
    {
        cout << "Do you wish to insert a record,y/n" << endl;
        char choice=' ';

        cin >> choice;

        if (choice == 'n')
        {

            Table();


        }

        else

        file >> Sr >> name >> primary >> secondary >> address;


        int asci = 0;

        int i = 0;


        T1.create(Sr, name, primary, secondary, address);


        while (name[i] != '\0')
        {

            asci = asci + int(name[i]);

            i++;


        }

        T1.mapping(asci);
        T1.insert();

    }




}

void Table()
{
    cout << "1:Do you wish to insert a record" << endl;
    cout << "2:Do you wish to search for a record" << endl;
    cout << "3:Do you wish to delete a record" << endl;

    char choice;
    string name;
    cin >> choice;

    switch (choice) {

    case '1':

        insert();

    case '2':
        
      

        cout << "Enter the name of the person you wish to search for" << endl;
        cin >> name;

        T1.search(name);

    case '3':

       

        cout << "Enter the name of the person you wish to delete" << endl;
        cin >> name;

        T1.Delete(name);



    }
}