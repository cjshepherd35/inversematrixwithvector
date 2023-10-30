//
//  main.cpp
//  inversec
//
//  Created by Colton Shepherd on 10/3/20.
//  Copyright © 2020 Colton Shepherd. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int determinant(vector<int>&, int, int);
vector<int> cofactors(vector<int>&, int, int);
void negative(vector<int>&, int, int);
void flip(vector<int>&, int, int);
vector<double> inverse(vector<int>&, int, int);
vector<int> matmult(vector<int>&, vector<int>&, int, int, int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //vector<int>* ptr = nullptr;
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
        return 0;
    }

    inversevec = inverse(arr, rows, cols);
    cout << " did we make it past inv? \n";
    cout << inversevec.size() << " is size of inv \n";
    cout << "the inverse is \n";
    for (int i = 0; i < inversevec.size(); i++)
    {
        cout << inversevec[i] << " ";
    }
    
    return 0;
}

// start of determinant function *****************
//############################################################
int determinant(vector<int>& array, int rows, int cols) {
    
    int nums = 0, rev, sum_minors = 0;
    vector<int> newarr((rows-1)*(cols-1));
    
    if (rows == 1) {
        return array[0];
    }
    else if (rows == 2) {
        sum_minors = array[0]*array[3] - array[1]*array[2];
        return sum_minors;
    }
    
    else {
        for (int index = 0; index < rows; index++) {
            int addup = 0;
            for (int value = 0; value < rows; value++) {
                for (int val = 0; val < cols; val++) {
                    if (value != index && val != 0) {

                        newarr[addup] = array[(value*rows)+val];
                        addup++;
                    }
                    
                }
            }
            if (index % 2) {
                               rev = -1;
                           }
                           else {
                               rev = 1;
                           }
            int current_value = array[index*cols];
            nums = determinant(newarr, rows-1, cols-1);
            sum_minors += (nums*current_value*rev);
        }
    }

    return sum_minors;
    
}

//creates the minors matrix
vector<int> cofactors(vector<int>& array, int rows, int cols) {
    
    //int *newarrptr = new int[(rows-1)*(cols-1)], *cofarray = new int[(rows)*(cols)] ;
    vector<int> *newarrptr = new vector<int>((rows-1)*(cols-1));
    vector<int> cofarray(rows*cols);
    
    for (int index = 0; index < rows; index++) {
        for (int columns = 0; columns < cols; columns++) {
            int addup = 0;
            for (int value = 0; value < rows; value++) {
                for (int val = 0; val < cols; val++) {
                    if (value != index && val != columns) {
                        newarrptr->at(addup) = array[(value * rows)+val];
                        addup++;
                    }
                }
            }
            cofarray[(index*rows)+columns] = determinant(*newarrptr, rows-1, cols-1);
        }
    }
    return cofarray;
}
//makes checkerboard of negatives for creating cofactors matrix.
void negative(vector<int>& arr, int rows, int cols) {
    
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            if (!(j%2) ) {
                
                if (i%2) {
                    arr[j*rows+i] *= -1;
                }
                
            }
            else if (j%2 ){
                if (!(i%2)) {
                    arr[j*rows+i] *= -1;
                }
                
            }
        }
    }
    
}


//reflects the numbers across the diagonal.
void flip(vector<int>& arr, int rows, int cols) {
    vector<int> poitr(rows*cols);
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            poitr[i*rows+j] = arr[j*rows+i];
        }
    }
    for (int k = 0; k < rows*cols; k++) {
        arr[k] = poitr[k];
    }
    
    
}

//puts together the other functions and divides by the determinant to get the
//inverse matrix.
vector<double> inverse(vector<int>& arr, int rows, int cols) {
    
    
    //double *doubleptr = nullptr;
    int det = determinant(arr, rows, cols);
        
    // if (det == 0) {
    //     cout << "determinant zero so won't have an inverse" << endl;
        
    // }
    vector<int> cofs = cofactors(arr, rows, cols);
    negative(cofs, rows, cols);
    flip(cofs, rows, cols);

    cout << "did we make it in inverse? \n";
    //doubleptr = new double(rows*cols);
    vector<double> doubvect;
    for (int deter = 0; deter < rows*cols; deter++) {
        doubvect.push_back(double(cofs[deter]) / det);
    }

    return doubvect;
}


int *matmult(int *array1, int *array2, int rows1, int cols1, int rows2, int cols2) {
    int *multarray = nullptr;
    
    for (int j = 0; j < rows1; j++) {
        //<#statements#>
    }
    
    return multarray;
}
