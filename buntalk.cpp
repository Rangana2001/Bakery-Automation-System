#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void display() // Heading of the first screen in the program
{
    cout << " _________________________________________________________________________________________________________________\n";
    cout << "                                                                                                                  \n";
    cout << " 8888888888888888888888888888888888~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~88888888888888888888888888888888888888888888\n";
    cout << " 8888888888888888888888888888888888~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~88888888888888888888888888888888888888888888\n";
    cout << "                                                                                                                  \n";
    cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<          BUN TALK BAKERY          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "                                                                                                                  \n";
    cout << " 8888888888888888888888888888888888~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~88888888888888888888888888888888888888888888\n";
    cout << " 8888888888888888888888888888888888~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~88888888888888888888888888888888888888888888\n";
    cout << "                                                                                                                  \n";
    cout << " _________________________________________________________________________________________________________________\n";
}

int main()
{
    string password, pw;
    string username, un;
    string name;
    char key;
    int E, F, S, C, B;
    int option, num;
    int cash;
    bool exitProgram = false;

    do
    {
        display(); // Call display function

        cout << "\n\n Please select an option: \n\n 1. Register \n 2. Login \n 3. Help";
        cout << "\n\n Option: ";
        cin >> option;

        if (option == 1)
        {
            cout << "Give a username: ";
            cin >> username;
            cout << "Give a password (Please include both characters & numbers): ";
            cin >> password;

            ofstream file; // create a file and store data
            file.open("userD\\" + username + ".txt");
            file << username << endl
                 << password;

            file.close();
        }
        else if (option == 2)
        {
            do
            {
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;

                ifstream read("userD\\" + username + ".txt"); // open file and get data
                getline(read, un);
                getline(read, pw);

                if (un != username || pw != password)
                {
                    cout << "Invalid username or password. Please try again." << endl;
                }

            } while (un != username || pw != password);

            cout << "\n\n Welcome to Bun Talk Bakery !";
            cout << "\n\n\t\t########################## Here is the Menu ########################## \n\n";
            cout << "\t\tItem No\t\tMenu Item\t\tPrice\n\n";
            cout << "\t\t======================================================================\n\n";

            cout << "\t\t111\t\tEgg Roll\t\tRs.150.00\n\n";

            cout << "\t\t112\t\tFish Roll\t\tRs.130.00\n\n";

            cout << "\t\t116\t\tSandwich\t\tRs.200.00\n\n";

            cout << "\t\t114\t\tChocolate Cookie\tRs.120.00\n\n";

            cout << "\t\t115\t\tBurger\t\t\tRs.500.00\n\n";

            cout << "\n\n\t\t########################## Place Your Order ########################## \n\n";
            cout << "\n\n Enter your name: ";
            cin >> name;

            cout << "\n How many Egg Rolls do you want: ";
            cin >> E;

            cout << "\n How many Fish Rolls do you want: ";
            cin >> F;

            cout << "\n How many Sandwiches do you want: ";
            cin >> S;

            cout << "\n How many Chocolate Cookies do you want: ";
            cin >> C;

            cout << "\n How many Burgers do you want: ";
            cin >> B;

            int bill = (E * 150.00 + F * 130.00 + S * 200.00 + C * 120.00 + B * 500.00); // Calculate Total

            cout << "\n\n Your Total Bill is: Rs. " << bill;
            cout << "\n\n Please Enter your cash amount: ";
            cin >> cash;

            int bal = (cash - bill); // Calculate the Balance

            cout << "\n\n\t\t####################### Here is your Receipt, ####################### \n\n";
            cout << "\n\n \t\t Customer Name: \t (" << name << ")";
            cout << "\n \t\t Egg Rolls \t\t\t" << E;
            cout << "\n \t\t Fish Rolls \t\t\t" << F;
            cout << "\n \t\t Sandwiches \t\t\t" << S;
            cout << "\n \t\t Chocolate Cookies \t\t" << C;
            cout << "\n \t\t Burgers \t\t\t" << B;

            cout << "\n \t\t...................................................";

            cout << "\n \t\t Paid Amount:\t Rs. " << cash;
            cout << "\n \t\t Total Amount:\t Rs. " << bill;
            cout << "\n \t\t Your Balance:\t Rs. " << bal;

            cout << "\n\n \t\t Thanks For Visiting Bun Talk Bakery, Come Again !!!";
            cout << "\n\n \t\t Press 'E' to exit or any other key to return to the main menu...";

            cin >> key;

            if (key == 'E' || key == 'e')
            { // Exit from the application
                exitProgram = true;
            }
        }
        else if (option == 3) // Check if the option is for Help
        {
            cout << "\n\n Help: \n";
            cout << "1. To register, select option 1 and provide a username and password.\n";
            cout << "2. To log in, select option 2 and enter your username and password.\n";
            cout << "3. Enter your name and the quantity of items you want to order.\n";
            cout << "4. Enter the cash amount to pay, and the program will calculate your bill and balance.\n";
            cout << "5. Press 'E' to exit the application.\n";
            cout << "\n Press Enter to return to the main menu...";
            cin.ignore();
            cin.get(); // Wait for Enter key

        }

    } while (!exitProgram);

    return 0;
}
