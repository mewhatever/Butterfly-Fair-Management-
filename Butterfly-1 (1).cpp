#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<iomanip>
#include<ctime>
using namespace std;
void admin_menu()
{
    cout<<"\nPress 1 to add new Butterfly species\n";
    cout<<"Press 2 to remove existing Butterfly species\n";
    cout<<"Press 3 to display Butterfly information\n";
    cout<<"Press 4 to search Butterfly Species\n";
    cout<<"Press 5 to add Volunteer\n";
    cout<<"Press 6 to delete Volunteer\n";
    cout<<"Press 7 to display Volunteer information\n";
    cout<<"Press 8 to search Volunteer\n";
    cout<<"Press 9 for main menu\n";
    cout<<"Press 10 for exit\n";
    cout<<"Enter choice : ";
}

void butterfly_menu()
{
    cout<<"Press 1 for Register\n";
    cout<<"Press 2 for login\n";
    cout<<"Press 3 for main menu\n";
    cout<< "Press 0 for exit\n";
}
void butterfly_menu2 ()
{
    cout << "Press 1 to Explore the Location of different butterfly species\n";
    cout << "Press 2 to Explore Characteristics of different butterfly species present in the fair\n";
    cout << "Press 3 to Explore your Contribution in butterfly conservation\n";
    cout << "Press 4 to Go Back\n";
}
void location()
{
    cout << "Choose Location to see Butterflies available in these places\n";
    cout << "1. Jahir Rayhan Auditorium\n";
    cout << "2. Department of Zoology\n";
    cout << "3. Butterfly Park\n";
}
/// @brief /////////////////////// REGISTER CLASS ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
class  Register
{
private:
    string regname;
    string regpass;
    string logname;
    string logpass;
public:
    void reg()
    {
        cout<<"Registration\nEnter user name : ";
        cin>>regname;
        this->regname = regname;
        cout<<"Enter password : ";
        cin>>regpass;
        this->regpass = regpass;
        ofstream reg("database.txt", ios:: app);
        reg << regname << ' ' << regpass << endl;
        cout<<"Registration successfull\n";


    }

    int login()
    {
        int exist;
        string u,p;
        cout<<"Login\nEnter user name : ";
        cin>>logname;
        cout<<"Enter password : ";
        cin>>logpass;
        ifstream input("database.txt");
        while(input >> u >> p)
        {
            if(u == logname && p == logpass)
            {
                exist = 1;
                break;
            }
        }
        input.close();
        if(exist == 1)
        {
            cout<<"Hello "<< logname << " Welcome to Attendee Panel\n";
            return 1;
        }
        else
        {
            cout<<"Login error!!\nTry again\n";
            return 0;
        }
    }

};
/////////////////////////////////// PERSON CLASS //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Person :  public Register
{
public:
    long double salary;
public:
    string name;
    string age;
    string nationality;
public:                         //////// VIRTUAL FUNCTIONS
    virtual void getdata(int=0)=0;
    virtual void showdata()=0;
    virtual void Delete()=0;
    virtual void search()=0;
    virtual void conservation()=0;
    virtual void characteristics()=0;
    virtual int show_species()=0;
};

/////////////////////////////////// USER CLASS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class user : public Person
{
public:
    void getdata(int t)     /////////   WRITE TO FILE
    {
        cin.ignore(1, '\n');
        cout<<"Enter name : ";
        getline(cin,name);
        cout<<"Enter age : ";
        cin>>age;
        cout<<"Enter nationality : ";
        cin>>nationality;
        cin.ignore(1, '\n');
        fstream user_information("user_information.txt", ios::app);

    }
    void showdata()
    {
        cout<<"Name : " << name << endl;
        cout<<"Age : " << age << endl;
        cin>>age;
        cout<<"Nationality : " << nationality << endl;
    }
    void search()
    {

        int x=0;
        fstream d;
        d.open("user_information.txt", ios::in);
        string uname;
        cout<<"Enter User Name to search : ";
        cin>>uname;
        while (!d.eof())        ///////// READ FILE
        {
            d >> name >> age >> nationality;
            if(uname == name)
            {
                cout << "Name" << setw(24) << "Age" << setw(20) << "Nationality" << endl;
                cout << name << setw(25-name.size()) << ' ' << age << setw(10) << ' ' << nationality << endl;
                x=1;
                break;
            }
        }
        d.close();
        if (x==0)
            cout << "Not found!!" <<endl;
    }

    void Delete()
    {
        cout<<"Enter User Name to delete : ";
        string deleteuser;
        cin>> deleteuser;
        ifstream d;
        d.open("user_information.txt");
        ofstream e;
        e.open("new.txt");
        d >> name >> age >> nationality;
        while (!d.eof())
        {
            if (name != deleteuser)
            {
                e << name << setw(25-name.size()) << ' ' << age << setw(10) << ' ' << nationality << endl;
            }
            else cout << "User deleted\n";
            d >> name >> age >> nationality;
        }
        e.close();
        d.close();
        remove("user_information.txt");
        rename("new.txt","user_information.txt");
    }
    void conservation() { }
    void characteristics() {   }
    int show_species()
    {
        return 0 ;
    }
};

/////////////////////////////////// Volunteer CLASS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
class employee : public Person
{
public:
    string ID;
    string Job;
public:
    void getdata(int t)     /////////   WRITE TO FILE
    {
        cout<<"Enter ID : "; cin>>ID;
        cin.ignore(1, '\n');
        cout<<"Enter name : ";
        getline(cin,name);
        cout<<"Enter age : ";
        cin>>age;
        cout<<"Enter nationality : ";
        cin>>nationality;
        cin.ignore(1, '\n');
        cout<<"Enter Job title : "; getline(cin,Job);
        cout<<"Set salary : "; cin>>salary;

        fstream employee_information("employee_information.txt", ios::app);
        employee_information << ID << setw(10-ID.size()) << ' ' << name << setw(25-name.size()) << ' ' << age << setw(10) << ' ' << nationality << setw(17-nationality.size()) << ' ' << Job << setw(18-Job.size()) << ' '<< salary << endl;
    }
    void showdata()
    {
        cout<<"ID : " << ID << endl;
        cout<<"Name : " << name << endl;
        cout<<"Age : " << age << endl;
        cin>>age;
        cout<<"Nationality : " << nationality << endl;
        cout<<"Job title : " << Job << endl;
    }
    void search()
    {

        int x=0;
        fstream d;
        d.open("employee_information.txt", ios::in);
        string empID;
        cout<<"Enter ID number to search : ";
        cin>>empID;
        while (!d.eof())        ///////// READ FILE
        {
            d >> ID >> name >> age >> nationality >> Job >> salary;
            if(empID == ID)
            {
                cout << "ID" << setw(12) << "Name" << setw(24) << "Age" << setw(20) << "Nationality" << setw(15) << "Job Title" << setw(15) << "Salary" << endl;
                cout << ID << setw(10-ID.size()) << ' ' << name << setw(25-name.size()) << ' ' << age << setw(10) << ' ' << nationality << setw(17-nationality.size()) << ' ' << Job << setw(18-Job.size()) << ' '<< salary << endl;
                x=1;
                break;
            }
        }
        d.close();
        if (x==0)
            cout << "Not found!!" <<endl;
    }

    void Delete()
    {
        cout<<"Enter ID to delete : ";
        string deleteID;
        cin>> deleteID;
        ifstream d;
        d.open("employee_information.txt");
        ofstream e;
        e.open("new.txt");
        d >> ID >> name >> age >> nationality >> Job >> salary;
        while (!d.eof())
        {
            if (ID != deleteID)
            {
                e << ID << setw(10-ID.size()) << ' ' << name << setw(25-name.size()) << ' ' << age << setw(10) << ' ' << nationality << setw(17-nationality.size()) << ' ' << Job << setw(18-Job.size()) << ' '<< salary << endl;
            }
            else cout << "Employee deleted\n";
            d >> ID >> name >> age >> nationality >> Job >> salary;
        }
        e.close();
        d.close();
        remove("employee_information.txt");
        rename("new.txt","employee_information.txt");
    }
    void conservation() { }
    void characteristics() {   }
    int show_species()
    {
        return 0 ;
    }
};
/////////////////////////////////// butterfly CLASS //////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class butterfly : public Person
{
public:
    string species;
    string color;
    string sz;
    string dfeature;
public:        ///////// CONSTRUCTOR .///////////
    butterfly(string species, string color, string sz, string dfeature)
    {
        this->species = species;              //////// THIS POINTER //////////
        this->color = color;
        this->sz = sz;
        this->dfeature = dfeature;
        fstream butterfly_information("butterfly_Information.txt", ios::app);
        butterfly_information << species << ' ' << color << ' ' << sz << dfeature << '\n' << endl;
    }
    butterfly() {}

    void getdata(int t)
    {
        cin.ignore(1, '\n');
        cout<<"Enter Species : ";
        getline(cin,species);
        cout<<"Enter Color : ";
        cin>>color;
        cout<<"Enter Size : ";
        cin>>sz;
        cout<<"Enter Distinctive Features : ";
        cin>>dfeature;
        fstream butterfly_information("butterfly_Information.txt", ios::app);
        butterfly_information << species << ' ' << color << ' ' << sz << dfeature << '\n' << endl;
    }
    void showdata()
    {
        cout<<"Species : " << species << endl;
        cout<<"Color : " << color << endl;
        cout<<"Size : " << sz << endl;
        cout<<"Distinctive Features : " << dfeature << endl;
    }
    void Delete()
    {
        cout<<"Enter Species to delete : ";
        string deletename;
        cin>> deletename;
        ifstream d;
        d.open("butterfly_information.txt");
        ofstream e;
        e.open("new.txt");
        d >> species >> color >> sz >> dfeature;
        while (!d.eof())
        {
            if (species != deletename)
            {
                //     e << name << ' ' << age << ' ' << nationality << ' ' << position << ' ' << jerseynumber << ' ' << salary << endl;
                e << species << ' ' << color << ' ' << sz << dfeature << '\n' << endl;
            }
            else cout << "Species deleted\n";
            d >> species >> color >> sz >> dfeature;
        }
        e.close();
        d.close();
        remove("butterfly_information.txt");
        rename("new.txt","butterfly_information.txt");
    }
    void search()
    {

        int x=0;
        fstream d;
        d.open("butterfly_information.txt", ios::in);
        string sname;
        cout<<"Species Species to search : ";
        cin>>sname;
        while (!d.eof())
        {
            d >> species >> color >> sz >> dfeature;
            if(sname == species)
            {
                cout<<"Species"<<setw(10)<<"Color"<<setw(5)<<"Size"<<setw(5)<<"Distinctive Features"<<endl;
                cout << species << ' ' << color << ' ' << sz << dfeature << '\n' << endl;
                x=1;
                break;
            }
        }
        d.close();
        if (x==0)
            cout<<"Not found!!";
    }
    void conservation()
    {
        cout << "1. Butterfly-Friendly Gardens:" << endl;
        cout << "   - Design and maintain a garden with plants that serve as host plants for butterfly larvae (caterpillars) and nectar-rich flowers for adult butterflies. Choose native plants to support local butterfly species." << endl;

        cout << "\n2. Butterfly Houses or Boxes:" << endl;
        cout << "   - Install butterfly houses or boxes in your garden or local green spaces. These structures provide shelter and breeding opportunities for butterflies." << endl;

        cout << "\n3. Host Educational Workshops:" << endl;
        cout << "   - Organize workshops in schools, community centers, or local events to educate people about the importance of butterflies, their life cycle, and the role they play in ecosystems." << endl;

        cout << "\n4. Citizen Science Initiatives:" << endl;
        cout << "   - Participate in citizen science programs that monitor butterfly populations. Collecting data on species and their numbers helps scientists understand trends and make informed conservation decisions." << endl;

        cout << "\n5. Adopt a Butterfly Habitat:" << endl;
        cout << "   - Work with local authorities or conservation organizations to adopt and care for a butterfly habitat. Regular cleanups and habitat maintenance activities can help sustain the ecosystem." << endl;

        cout << "\n6. Create Butterfly Corridors:" << endl;
        cout << "   - Advocate for and participate in the creation of butterfly corridors by planting butterfly-friendly plants along pathways and connecting green spaces. These corridors help butterflies move between habitats." << endl;

        cout << "\n7. Monarch Waystations:" << endl;
        cout << "   - Create a Monarch Waystation by planting milkweed and nectar plants. Monarchs rely on milkweed as a host plant, and these waystations help support their migration." << endl;

        cout << "\n8. Butterfly-Friendly Policies:" << endl;
        cout << "   - Advocate for butterfly-friendly policies in your community. This may include restrictions on the use of pesticides harmful to butterflies and the preservation of natural habitats." << endl;

        cout << "\n9. Butterfly Monitoring Apps:" << endl;
        cout << "   - Use smartphone apps designed for butterfly identification and monitoring. By contributing data to these apps, you can help scientists track butterfly populations and distribution." << endl;

        cout << "\n10. Art and Awareness Campaigns:" << endl;
        cout << "    - Use art and creative projects to raise awareness about butterfly conservation. Murals, sculptures, or public installations can draw attention to the beauty and importance of butterflies." << endl;

        cout << "\n11. Butterfly Citizen Gardener Certification:" << endl;
        cout << "    - Get certified as a Butterfly Citizen Gardener through programs offered by conservation organizations. This certification signifies your commitment to butterfly-friendly practices." << endl;

        cout << "\n12. Support Conservation Organizations:" << endl;
        cout << "    - Contribute financially or volunteer your time to organizations dedicated to butterfly conservation. These organizations often engage in research, habitat restoration, and educational initiatives." << endl;

        cout << "\nRemember, every small effort counts, and collective actions can make a significant impact on butterfly conservation.\n" << endl;

    }
    ~butterfly()      //////////////  POLYMORPHISM
    {
        string deletename;
        deletename = species;
        ifstream d;
        d.open("butterfly_information.txt");
        ofstream e;
        e.open("new.txt");
        d >> species >> color >> sz >> dfeature;
        while (!d.eof())
        {
            if (species != deletename)
            {
                e << species << setw(10-species.size()) << ' ' << color << setw(5) << ' ' << sz << setw(5)<<dfeature<<endl;
            }
            d >> species >> color >> sz >> dfeature;
        }
        e.close();
        d.close();
        remove("butterfly_information.txt");
        rename("new.txt","butterfly_information.txt");
    }
    void characteristics() {   }
    int show_species()
    {
        return 1;
    }
};

/////////////////////////////////// butterflyS AS OBJECT //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

butterfly Menelaus("Menelaus Blue Morpho", "Bright iridescent blue on the upper side of wings.", "Large wingspan.", "The wings have a shimmering quality due to microscopic scales that reflect light.");
butterfly Monarch("Monarch Butterfly", "Orange and black with white spots.", "Medium-sized.", "Known for long-distance migration and a unique pattern of black veins on its wings.");
butterfly Glasswing("Glasswing Butterfly", "Mostly transparent wings with dark borders.", "Medium-sized.", "Transparent wings make it look like it has glass wings.");
butterfly ZebraLongwing("Zebra Longwing Butterfly", "Black with long, narrow yellow stripes.", "Medium-sized.", "Striking zebra-like stripes on its wings.");
butterfly EasternTigerSwallowtail("Eastern Tiger Swallowtail", "Yellow with black stripes.", "Large wingspan.", "Mimics the appearance of a tiger with its black stripes.");
butterfly OrnithopteraGoliath("Ornithoptera Goliath", "Black with green markings.", "Very large wingspan.", "One of the largest butterflies in the world.");
butterfly PapilioPalinurus("Papilio Palinurus", "Green with black markings.", "Medium to large.", "Long-tailed butterfly with beautiful green coloration and black markings on the wings.");
butterfly PeacockPansy("Peacock Pansy", "Brown with iridescent eyespots on wings.", "Small to medium-sized.", "Resembles the eyespots on a peacock's tail.");
butterfly ChorineaSylphina("Chorinea Sylphina", "Metallic blue-green.", "Small.", "Shiny, metallic appearance.");
butterfly CramersEightyEight("Cramer's Eighty-Eight", "Black and white.", "Medium-sized.", "Has the number '88' pattern on its wings.");
butterfly QueenAlexandrasBirdwing("Queen Alexandra's Birdwing", "Brown with yellow and green markings.", "One of the largest butterflies.", "Named after Queen Alexandra.");
butterfly OrangeOakleaf("Orange Oakleaf", "Mimics a dead leaf with shades of orange and brown.", "Medium-sized.", "Camouflages as a leaf when resting.");
butterfly AppiasZarinda("Appias Zarinda", "White with black markings.", "Small to medium-sized.", "Simple and elegant black and white coloration.");
butterfly LampropteraMeges("Lamproptera Meges", "Iridescent blue and black.", "Medium-sized.", "Brilliant iridescent blue coloration.");
butterfly CaligoEurilochus("Caligo Eurilochus", "Brown with owl-like eye markings.", "Large.", "Resembles owl eyes on its wings, giving it a distinctive appearance.");
butterfly AdonisBlue("Adonis Blue", "Vibrant blue with black and white markings.", "Small.", "Bright blue coloration on the upper side of wings.");
butterfly MourningCloak("Mourning Cloak", "Dark brown with blue and yellow spots.", "Medium to large.", "Irregular wing shape and dark coloration.");


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////// butterflysquad CLASS //////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class butterflysquad : public butterfly
{


public:
    void showdata()
    {

        location();
        int x;
        cin >> x;
        int choice;
        while (x!=0)
        {
            if (x == 1)
            {
                cout << "Jahir Rayhan Auditorium\n\n";
                cout <<"Menelaus blue morpho\n"<< endl;
                cout <<"Monarch butterfly\n"<< endl;
                cout <<"Glasswing butterfly\n"<< endl;
                cout <<"Zebra Longwing Butterfly\n"<< endl;
                cout <<"Eastern tiger swallowtail\n"<< endl;
                cout <<"Ornithoptera goliath\n";

                cout << "Press 1 to change Location \nPress 2 to select this formation\n";
                cin >> choice;
                if(choice == 1)
                    location();
                else
                {
                    cout << "Location selected\n";
                    admin_menu();
                    return;
                }
            }
            if (x==2)
            {
                cout << "Department of Zoology\n\n";
                cout << "Papilio palinurus\n"<<endl;
                cout << "Peacock Pansy\n"<<endl;
                cout << "Chorinea sylphina\n"<<endl;
                cout << "Cramer's eighty-eight\n"<<endl;
                cout << "Queen Alexandra's birdwing\n"<<endl;
                cout << "Press 1 to change Location \nPress 2 to select this formation\n";
                cin >> choice;
                if(choice == 1)
                    location();
                else
                {
                    cout << "Location selected\n";
                    admin_menu();
                    return;
                }
            }


            if (x==3)
            {
                cout << "Butterfly Park\n\n";
                cout << "Orange oakleaf\n"<<endl;
                cout << "Appias zarinda\n"<<endl;
                cout << "Lamproptera meges\n"<<endl;
                cout << "Caligo eurilochus\n"<<endl;
                cout << "Adonis blue\n"<<endl;
                cout << "Mourning cloak";
                cout << "Press 1 to change Location \nPress 2 to select this formation\n";
                cin >> choice;
                if(choice == 1)
                    location();
                else
                {
                    cout << "Formation selected\n";
                    admin_menu();
                    return;
                }
            }
            cin >> x;
        }

    }
    int show_species()
    {
        location();
        int x;
        cin >> x;
        int choice;

        if (x == 1)
        {
            cout << "Jahir Rayhan Auditorium\n\n";
            cout <<"Menelaus blue morpho\n"<< endl;
            cout <<"Monarch butterfly\n"<< endl;
            cout <<"Glasswing butterfly\n"<< endl;
            cout <<"Zebra Longwing Butterfly\n"<< endl;
            cout <<"Eastern tiger swallowtail\n"<< endl;
            cout <<"Ornithoptera goliath\n"<< endl;
            cout << "Press 1 to change Location \nPress 2 to go back\n";
            cin >> choice;
            if(choice == 1)
                show_species();
            else
            {
                return 1;

            }
        }
        else if (x==2)
        {
            cout << "Department of Zoology\n\n";
            cout << "Papilio palinurus\n"<<endl;
            cout << "Peacock Pansy\n"<<endl;
            cout << "Chorinea sylphina\n"<<endl;
            cout << "Cramer's eighty-eight\n"<<endl;
            cout << "Queen Alexandra's birdwing\n"<<endl;

            cout << "Press 1 to change Location \nPress 2 to go back\n";
            cin >> choice;
            if(choice == 1)
                show_species();
            else
            {
                return 1;
            }
        }


        else if (x==3)
        {
            cout << "Butterfly Park\n\n";
            cout << "Orange oakleaf\n"<<endl;
            cout << "Appias zarinda\n"<<endl;
            cout << "Lamproptera meges\n"<<endl;
            cout << "Caligo eurilochus\n"<<endl;
            cout << "Adonis blue\n"<<endl;
            cout << "Mourning cloak\n"<<endl;

            cout << "Press 1 to change Location \nPress 2 to go back\n";
            cin >> choice;
            if(choice == 1)
                show_species();
            else
            {
                return 1;
            }
        }
        return 1;

    }

    ///////////////////////////////////////////////////////////
    void characteristics()
    {

        cout << "Menelaus Blue Morpho:" << endl;
        cout << "Color: Bright iridescent blue on the upper side of wings." << endl;
        cout << "Size: Large wingspan." << endl;
        cout << "Distinctive Features: The wings have a shimmering quality due to microscopic scales that reflect light." << endl;

        cout << "\nMonarch Butterfly:" << endl;
        cout << "Color: Orange and black with white spots." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Known for long-distance migration and a unique pattern of black veins on its wings." << endl;

        cout << "\nGlasswing Butterfly:" << endl;
        cout << "Color: Mostly transparent wings with dark borders." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Transparent wings make it look like it has glass wings." << endl;

        cout << "\nZebra Longwing Butterfly:" << endl;
        cout << "Color: Black with long, narrow yellow stripes." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Striking zebra-like stripes on its wings." << endl;

        cout << "\nEastern Tiger Swallowtail:" << endl;
        cout << "Color: Yellow with black stripes." << endl;
        cout << "Size: Large wingspan." << endl;
        cout << "Distinctive Features: Mimics the appearance of a tiger with its black stripes." << endl;

        cout << "\nOrnithoptera Goliath:" << endl;
        cout << "Color: Black with green markings." << endl;
        cout << "Size: Very large wingspan." << endl;
        cout << "Distinctive Features: One of the largest butterflies in the world." << endl;

        cout << "\nPapilio Palinurus:" << endl;
        cout << "Color: Green with black markings." << endl;
        cout << "Size: Medium to large." << endl;
        cout << "Distinctive Features: Long-tailed butterfly with beautiful green coloration and black markings on the wings." << endl;

        cout << "\nPeacock Pansy:" << endl;
        cout << "Color: Brown with iridescent eyespots on wings." << endl;
        cout << "Size: Small to medium-sized." << endl;
        cout << "Distinctive Features: Resembles the eyespots on a peacock's tail." << endl;

        cout << "\nChorinea Sylphina:" << endl;
        cout << "Color: Metallic blue-green." << endl;
        cout << "Size: Small." << endl;
        cout << "Distinctive Features: Shiny, metallic appearance." << endl;

        cout << "\nCramer's Eighty-Eight:" << endl;
        cout << "Color: Black and white." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Has the number '88' pattern on its wings." << endl;

        cout << "\nQueen Alexandra's Birdwing:" << endl;
        cout << "Color: Brown with yellow and green markings." << endl;
        cout << "Size: One of the largest butterflies." << endl;
        cout << "Distinctive Features: One of the largest butterflies in the world, named after Queen Alexandra." << endl;

        cout << "\nOrange Oakleaf:" << endl;
        cout << "Color: Mimics a dead leaf with shades of orange and brown." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Camouflages as a leaf when resting." << endl;

        cout << "\nAppias Zarinda:" << endl;
        cout << "Color: White with black markings." << endl;
        cout << "Size: Small to medium-sized." << endl;
        cout << "Distinctive Features: Simple and elegant black and white coloration." << endl;

        cout << "\nLamproptera Meges:" << endl;
        cout << "Color: Iridescent blue and black." << endl;
        cout << "Size: Medium-sized." << endl;
        cout << "Distinctive Features: Brilliant iridescent blue coloration." << endl;

        cout << "\nCaligo Eurilochus:" << endl;
        cout << "Color: Brown with owl-like eye markings." << endl;
        cout << "Size: Large." << endl;
        cout << "Distinctive Features: Resembles owl eyes on its wings, giving it a distinctive appearance." << endl;

        cout << "\nAdonis Blue:" << endl;
        cout << "Color: Vibrant blue with black and white markings." << endl;
        cout << "Size: Small." << endl;
        cout << "Distinctive Features: Bright blue coloration on the upper side of wings." << endl;

        cout << "\nMourning Cloak:" << endl;
        cout << "Color: Dark brown with blue and yellow spots." << endl;
        cout << "Size: Medium to large." << endl;
        cout << "Distinctive Features: Irregular wing shape and dark coloration.\n" << endl;

    }
};

/////////////////////////////////// MAIN FUNCTION //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main()
{

    cout << "***************** WELCOME TO Butterfly Fair JU *****************\n";
    Person *personptr[200];
    int n=0;
    cout<<"Login as\n(1) Admin\n(2) Attendee\n(3) Exit\n";
    int x;
    cin >> x;
    ////////////////////////// LOG IN AS ADMIN //////////////
    /////////////////////////////////////////////////////////
    if(x==1)
    {
        char  name[10],password[10];
        cout<<"Enter user name : ";
        cin >> name;
        cout<<"Enter password : ";
        cin >> password;
        if(  !(strcmp(name,"Boss") && strcmp(password,"admin"))  )
        {
            admin_menu();
            int choice;
            cin >> choice;
            while(x!=0)
            {
                if (choice==1)     //////   ADD NEW butterfly
                {

                    char ans;
                    do
                    {
                        personptr[n] = new butterfly;
                        personptr[n]->getdata(1);
                        n++;
                        cout<<"Want to add another butterfly? (y/n) : ";
                        cin>>ans;
                    }
                    while(ans!='n');
                    admin_menu();
                }

                if (choice==2)      //////  DELETE butterfly
                {
                    personptr[n] = new butterfly;
                    personptr[n]->Delete();
                    admin_menu();
                }
                if (choice==3)      /////// DISPLAY butterfly INFORMATION
                {
                    ifstream butterfly_information("butterfly_information.txt");
                    char ch;
                    while (butterfly_information)
                    {
                        butterfly_information.get(ch);
                        cout<<ch;
                    }
                    cout<<endl;
                    admin_menu();
                }
                if (choice==4)  ///////     SEARCH butterfly
                {
                    personptr[n] = new butterfly;
                    personptr[n]->search();
                    admin_menu();
                }
                if (choice==5)  //////      ADD NEW EMPLOYEE
                {
                    char ans;
                    do
                    {
                        personptr[n] = new employee;
                        personptr[n]->getdata();
                        n++;
                        cout<<"Want to add another employee? (y/n) : ";
                        cin>>ans;
                    }
                    while(ans!='n');
                    admin_menu();
                }
                if (choice==6)     //////////  DELETE EMPLOYEE
                {
                    personptr[n] = new employee;
                    personptr[n]->Delete();
                    admin_menu();
                }
                if (choice==7)     /////   DISPLAY EMPLOYEE INFORMATION
                {
                    ifstream employee_information("employee_information.txt");
                    char ch;

                    cout << "ID" << setw(12) << "Name" << setw(24) << "Age" << setw(20) << "Nationality" << setw(15) << "Job Title" << setw(15) << "Salary" << endl;
                    while (employee_information)
                    {
                        employee_information.get(ch);
                        cout<<ch;
                    }
                    cout<<endl;
                    admin_menu();
                }
                if (choice==8)  //////////      SEARCH EMPLOYEE
                {
                    personptr[n] = new employee;
                    personptr[n]->search();
                    admin_menu();
                }

                if (choice==9)     /////// MAIN MENU
                {
                    main();
                }
                if (choice == 0)    /////   EXIT
                {

                    //  remove("butterflysquad_report.txt");
                    //remove("conservation.txt");
                    fstream ofs;
                    ofs.open("Top_scorer.txt", ios::out | ios::trunc);
                    ofs.close();
                    ofs.open("squad_report1.txt", ios::out | ios::trunc);
                    ofs.close();
                    exit(0);
                }

                cin>>choice;
            }

        }
        else
        {
            cout<<"Error!!\nTry again\n";
            main();
        }

    }
    /////////////////////// LOG IN AS Attendee ///////////////////
    ///////////////////////////////////////////////////////////
    if (x==2)
    {

b:
        butterfly_menu();
        int choise;
        cin >> choise;
        while(choise != 50)
        {
            if(choise==1)           //////////  REGISTER
            {

                personptr[n] = new user;
                personptr[n]->reg();
                cout<<"Please fill up the form\n";
                personptr[n]->getdata(0);
                n++;
                cout << "Now login to see features\n";
                butterfly_menu();
            }
            if(choise==2)       //////      LOG IN
            {

                int log = 0;
                while ( 1 )
                {
                    personptr[n] = new butterfly;
                    int log = personptr[n]->login();
                    n++;
                    if ( log == 1)  break;
                }
a:
                butterfly_menu2();
                int y;
                cin >> y;
                if ( y == 1 )           ////////    VIEW Location
                {
                    personptr[n] = new butterflysquad;
                    int z = personptr[n] ->show_species();
                    n++;
                    if ( z == 1 )   goto a;

                }
                if ( y == 2 )       ////////////    Butterfly Characteristics
                {
                    personptr[n] = new butterflysquad;
                    personptr[n] ->characteristics();
                    n++;
                    goto a;
                }
                if ( y == 3 )
                {

                    personptr[n] = new butterfly;
                    personptr[n] ->conservation();
                    n++;
                    goto a;
                }
                if ( y == 4)
                {
                    goto b;
                }


            }
            if ( choise == 3)
            {
                main();
            }


            if ( choise == 0)   /////// EXIT
            {
                exit(0);
            }



            cin>>choise;
        }

    }  //// END OF LOG IN AS butterfly
    else
        exit(0);
}

