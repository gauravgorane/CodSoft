#include <iostream>

using namespace std;

int main()
{

    char choice;

    do
    {
        int operation, ch;
        double x, y;

        cout << "_____Operation_____" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Substraction" << endl;
        cout << "3. Multipication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter your choice (1-4): ";
        
        cin >> ch;

        cout << endl;

        switch (ch)
        {
        case 1:
            cout << "_____Addition_____" << endl;
            cout << "Enter 1st number: ";
            cin >> x;
            cout << "Enter 2nd number: ";
            cin >> y;
            cout << "Result: " << x + y << endl;
            break;

        case 2:
            cout << "_____Substraction_____" << endl;
            cout << "Enter 1st number: ";
            cin >> x;
            cout << "Enter 2nd number: ";
            cin >> y;
            cout << "Result: " << x - y << endl;
            break;

        case 3:
            cout << "_____Multipication_____" << endl;
            cout << "Enter 1st number: ";
            cin >> x;
            cout << "Enter 2nd number: ";
            cin >> y;
            cout << "Result: " << x * y << endl;
            break;

        case 4:
            cout << "_____Division_____" << endl;
            cout << "Enter 1st number: ";
            cin >> x;
            cout << "Enter 2nd number: ";
            cin >> y;

            try
            {
                if (y == 0)
                {
                    throw runtime_error("Error: Division by zero is undefined.");
                }
                cout << "Result: " << x / y << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;

        default:
            cerr << "_____Invalid choice._____ Please enter a number between 1 and 4." << endl;
            break;
        }

        cout << endl;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using." << endl;

    return 0;
}