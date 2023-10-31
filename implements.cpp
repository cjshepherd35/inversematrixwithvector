#include "functions.cpp"




void inverseImplement()
{
    int rows, cols, x=0;
    cout << "what is the dimension nxn dimension, only input rows. \n";
    cin >> rows;
    cols = rows;
    vector<int> arr;
    vector<double> inversevec;
    
//    input the entries of the desired matrix.
    cout << " now input entries of the matrix. \n ";
    for (int first=0; first < rows; first++) {
        cout << " input row " << first+1 << endl;
        for (int second = 0; second < cols; second++) {
            cout << "input your value. \n";
            cin >> x;
            arr.push_back(x);
            
            
        }
    }
    
    cout << "input matrix \n";
//    reads out the input matrix.
    for (int s = 0; s < arr.size(); s++) {
        if (!(s%rows)) {
            cout << endl;
        }
        cout << arr[s] << "  ";
    }
    
    
    cout << endl;
    cout << "testing.. \n";
//    reads out the determinant of the input matrix.
    int det = determinant(arr, rows, cols);
    
    if (!det) {
        cout << "determinant zero so won't have an inverse" << endl;
        return;
    }

    inversevec = inverse(arr, rows, cols);
    cout << " did we make it past inv? \n";
    cout << inversevec.size() << " is size of inv \n";
    cout << "the inverse is \n";
    for (int i = 0; i < inversevec.size(); i++)
    {
        cout << inversevec[i] << " ";
    }
}



void matMultImplement()
{
    cout << "there is nothing here yet. \n";
}