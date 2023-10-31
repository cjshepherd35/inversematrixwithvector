#include "implements.cpp"


int main(int argc, const char * argv[]) {

    int choice;
    cout << "do  you want an inverse or to multiply?  \n";
    cout << " choose 0 for inverse or 1 for multiply. \n";
    cin >> choice;

    if (choice == 0)
    {
        inverseImplement();
    }
    else if(choice == 1)
    {
        matMultImplement();
    }
    else 
    {
        cout << "you're dumb. That is not an acceptable choice. \n";

    }
    
    
    return 0;
}



