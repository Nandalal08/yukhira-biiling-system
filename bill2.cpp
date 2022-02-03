#include<iostream>
#include<fstream>
using namespace std;


//creating a class then declaring the private and public elements

class shopping
{
 //note1
  private:

  int prdcode;
  float price;
  float dis;
  string prdname;
 
 public:
  void menu();
  void ad();
  void customer();
  void add();
  void edit();
  void rem();
  void list();
  void receipt();

};
//note2
void shopping :: menu()
{
    kk:
    int choice;
    string username;
    string password;
    string email;

    cout<<"\t\t\t\t________________________________________________________\n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t* * * * * * * * YUKIHIRA SUPERMARKET * * * *  * * * * * \n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t________________________________________________________\n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t        ___________________________________________     \n";
    cout<<"\t\t\t\t      |   1. ADMINISTRATOR                        |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   2. CUSTOMER                             |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   3. EXIT                                 |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |___________________________________________|     \n";

    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t       your choice:                                     \n"; 
    cout<<"\t\t\t\t     --> ";cin>>choice;


    switch (choice)
    {
    case 1:
    {
    cout<<"\t\t\t\t       Login to your account                            \n";
    cout<<"\t\t\t\t       ---------------------                            \n";
    cout<<"\t\t\t\t       Enter email:                                     \n";
    cout<<"\t\t\t\t     --> ";cin>>email;             
    cout<<"\t\t\t\t       Enter password:                                  \n";
    cout<<"\t\t\t\t     --> ";cin>>password;

    if(email=="user@gmail.com"&&password=="user123")
    {
        ad();
      //administrator();
    }
    else
    {
    cout<<"\t\t\t\t       Invalid username , password                       \n";
    }
    break;
    }
    case 2:
    {
        customer();
    }
    case 3:
    {
        exit(0);
    }
    
    default:
    {

    cout<<"\t\t\t\t        Wrong input!!!                                   \n";

    }
    //note3 -- kk is the labelname
    goto kk;

}
}

void shopping :: ad()
{
    m:
    int choice;

    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t|              ADMINISTRATIVE MENU                      |\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t       ___________________________________________      \n";
    cout<<"\t\t\t\t      |   1.ADD PRODUCT                           |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   2.MODIFY PRODUCT                        |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   3.DELETE PRODUCT                        |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   4.RETURN TO MAIN                        |     \n";
    cout<<"\t\t\t\t      |___________________________________________|     \n";


    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t       Your Choice:                                     \n"; 
    cout<<"\t\t\t\t     --> ";cin>>choice;
    switch(choice)
    {
        case 1:
                add();
                break;
        case 2:
                edit();
                break;
        case 3: 
                rem();
                break;
        case 4:
                menu();
                break;
        default:
    cout<<"\t\t\t\t      INVALID CHOICE!!!                                 \n"; 

    }

 goto m;

}


void shopping:: add()
{
    m:
    fstream ob;
    int c;
    float p;
    float d;
    string n;
    int token =0;



    cout<<"\t\t\t\t          PRODUCT DETAILS                               \n";
    cout<<"\t\t\t\t       ---------------------                            \n";
    cout<<"\t\t\t\t       PRODUCT CODE:                                    \n";
    cout<<"\t\t\t\t     --> ";cin>>prdcode;             
    cout<<"\t\t\t\t       PRODUCT NAME  :                                  \n";
    cout<<"\t\t\t\t     --> ";cin>>prdname;
    cout<<"\t\t\t\t       PRODUCT PRICE:                                  \n";
    cout<<"\t\t\t\t     --> ";cin>>price;             
    cout<<"\t\t\t\t       PRODUCT DISCOUNT  :                              \n";
    cout<<"\t\t\t\t     --> ";cin>>dis;
    //note5
    ob.open("database.txt",ios::in);
    if(!ob)
    {
        ob.open("database.txt",ios::app|ios::out);
        //inorder to write in a file.
        ob<<" "<<prdcode<<" "<<prdname<<" "<<price<<" "<<dis<<"\n";
        ob.close();
    }
    else
    { 
       
        ob>>c>>n>>p>>d;
        while(!ob.eof())
        {
            if( c== prdcode)
            {
                token= token+1;
            }
            ob>>c>>n>>p>>d;
        }
        ob.close();

    if(token == 1)
    
        goto m;
    
    else{
        ob.open("database.txt",ios::app|ios::out);
        ob<<" "<<prdcode<<" "<<prdname<<" "<<price<<" "<<dis<<"\n";
        ob.close();

        }
    }
    
    cout<<"\t\t\t\t      RECORD INSERTED                          \n";
      
}



void shopping:: edit()
{
    fstream ob,ob1;
    int newprdcode;
    int pkey;
    int token = 0;
    float newprdprice;
    float newprddis;
    string newprdname;
    cout<<"\t\t\t\t       MODIFY RECORD                            \n";
    cout<<"\t\t\t\t      ________________                          \n";

    cout<<"\t\t\t\t       PRODUCT CODE :                            \n";
    cout<<"\t\t\t\t     --> ";
    cin>>pkey;

    ob.open("database.txt",ios::in);
    if(!ob)
    {
    cout<<"\t\t\t\t       FILE DOESN'T EXIST                        \n";
    }
    else
    {
        //database1.txt here the edited file is stored.then rename it as database.txt.
        ob1.open("database1.txt",ios::app|ios::out);

        ob>>prdcode>>prdname>>price>>dis;
        while(!ob.eof())
        {
            if(pkey == prdcode)
            {
                
            cout<<"\t\t\t\t       PRODUCT NEW CODE :                         \n";
            cout<<"\t\t\t\t     --> ";
            cin>>newprdcode;
            cout<<"\t\t\t\t       PRODUCT NAME :                             \n";
            cout<<"\t\t\t\t     --> ";
            cin>>newprdname;
            cout<<"\t\t\t\t       PRODUCT PRICE :                             \n";
            cout<<"\t\t\t\t     --> ";
            cin>>newprdprice;
            cout<<"\t\t\t\t       PRODUCT DISCOUNT :                          \n";
            cout<<"\t\t\t\t     --> ";
            cin>>newprddis;

            ob1<<" "<<newprdcode<<" "<<newprdname<<" "<<newprdprice<<" "<<newprddis<<"\n";
            cout<<"\t\t\t\t      RECORD EDITED                               \n";
            token = token+1;
             }
            else{
             ob1<<" "<<prdcode<<" "<<prdname<<" "<<price<<" "<<dis<<"\n";

             }
            ob>>prdcode>>prdname>>price>>dis;
        }
        ob.close();
        ob1.close();

        //renaming new database to old database;
        //remove() and rename()
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
    cout<<"\t\t\t\t      RECORD NOT FOUND                            \n";
        
        }
    }



}


void shopping::rem()
{
    fstream ob,ob1;
    int pkey;
    int token =0;
    cout<<"\t\t\t\t       DELETE RECORD                            \n";
    cout<<"\t\t\t\t      ________________                          \n";
    cout<<"\t\t\t\t       ENTER THE PRODUCT CODE:                  \n";
    cout<<"\t\t\t\t     --> ";cin>>pkey;
    ob.open("database.txt",ios::in);
    {
        if(!ob)
        {
         cout<<"\t\t\t\t       FILE DOESN'T EXIST                        \n";

        }
        else
        {
            ob1.open("database1.txt",ios::app|ios::out);
            ob>>prdcode>>prdname>>price>>dis;
        while(!ob.eof())
            {
            if(prdcode == pkey)
            {
                cout<<"\t\t\t\t      PRODUCT DELETED SUCCESSFULLY               \n";
                token++;

            }
            else
            {
                ob1<<" "<<prdcode<<" "<<prdname<<" "<<price<<" "<<dis<<"\n";

            }
                ob>>prdcode>>prdname>>price>>dis;

        }
        ob.close();
        ob1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\t\t\t\t       RECORD NOT FOUND                       \n";
            
        }


            
        }
        
    }
    
    
}



void shopping:: customer()
{
    kk:
    int choice;
    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t|              CUSTOMER MENU                           |\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t       ___________________________________________      \n";
    cout<<"\t\t\t\t      |   1.BUY PRODUCT                           |     \n";
    cout<<"\t\t\t\t      |                                           |     \n";
    cout<<"\t\t\t\t      |   2.RETURN                                |     \n";
    cout<<"\t\t\t\t      |___________________________________________|     \n";



    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t       Your Choice:                                     \n"; 
    cout<<"\t\t\t\t     --> ";cin>>choice;
    switch(choice)
    {
        case 1:
                receipt();
                break;
        case 2:
                menu();
        default: 
    cout<<"\t\t\t\t      INVALID CHOICE!!!                                 \n"; 

    }
    goto kk;

}



void shopping:: list()
{
    fstream ob;
    ob.open("database.txt",ios::in);
    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t         pro no\t\tname\t\tprice            \n";
    cout<<"\t\t\t\t____________________________________________\n";
    ob>>prdcode>>prdname>>price>>dis;
    while(!ob.eof())
    {
    cout<<"\t\t\t\t      "<<prdcode<<"\t\t"<<prdname<<"\t\t"<<price<<"\n";
    ob>>prdcode>>prdname>>price>>dis;
    cout<<"\n\n";

    }
    ob.close();
    

}

void shopping:: receipt()
{
    kk:
   fstream ob;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float dis =0;
    float amount =0;
    float total =0 ;
     cout<<"\t\t\t\t            RECEIPT                                    \n";
    cout<<"\t\t\t\t       ---------------------                            \n";
    ob.open("database.txt",ios::in);
    if(!ob)
    {
    cout<<"\t\t\t\t       -EMPTY DATABASE                                   \n";
    }
    else
    {
        ob.close();
        list();

        //here we are displaying the list of items available.
        int choice;
        cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t|              PLACE YOUR ORDER                         |\n";
        cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        do
        {
        cout<<"\t\t\t\t                                                         \n";
        
        cout<<"\t\t\t\t       PRODUCT CODE :                                  \n";
        cout<<"\t\t\t\t     --> ";cin>>arrc[c];
        cout<<"\t\t\t\t       PRODUCT QUANTITY :                              \n";
        cout<<"\t\t\t\t     --> ";cin>>arrq[c];
        for(int i =0;i<c;i++)
        {
            if(arrc[c]==arrc[i])
            {
        cout<<"\t\t\t\t     -->DUPLICATE VALUE.TRY AGAIN!!!                   \n";
        goto kk;
            }

        }
        c++;
        cout<<"\n\n";
        cout<<"\t\t\t\t     -->CONTINUE YOUR PURCHASAE ! IF YES PRESS 1 ELSE 0 \n";
        cout<<"\t\t\t\t     --> ";cin>>choice;
        }
        while (choice == 1);
        
        cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t|               RECEIPT                                 |\n";
        cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t                                                         \n";
        cout<<"\nProdcut no\tProduct name\tProduct quantity\tMRP\tAmount\tMRP with dis \n";
        for(int i =0;i<c;i++)
        {
            ob.open("database.txt",ios::in);
            ob>>prdcode>>prdname>>price>>dis;
            while (!ob.eof())
            {
                if(prdcode==arrc[i])
                {
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
        cout<<"\n"<<prdcode<<"\t\t"<<prdname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;


                }
                ob>>prdcode>>prdname>>price>>dis;
            }
            
        }
        ob.close();
    }
        cout<<"\t\t\t\t                                   \n";

        cout<<"\t\t\t\n      total amount: "<<total;
        cout<<"\t\t\t\t                                   \n";
        cout<<"\t\t\t\t***********************************\n";

}




















int main()
{
    shopping s;
    s.menu();
}