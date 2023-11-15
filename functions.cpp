#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

using namespace std;

std::mutex m;
std::condition_variable cv;

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
        
    if (det == 0) {
        cout << "determinant zero so won't have an inverse" << endl;
        exit(1);
    }
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


vector<vector<int>> matmult(vector<vector<int>> array1, vector<vector<int>> array2, int rows1, int cols1, int rows2, int cols2) 
{
    if (cols1 != rows2)
    {
        cout << "the dimensions don't match \n";
        exit(1);
    }
    //output vector
    vector<vector<int>> multarray;
    //inner summation tool, sums all columns at once. 
    vector<int> sumprodo(cols2);
    
    //outmost loop for number of  vectors, middle loop for each value in a vector, and 
    //innermost loop is for  multiplying and summing each value in input matrices.
    for (int j = 0; j < rows1; j++) {
        for (int k = 0; k < cols2; k++)
        {
            sumprodo[k] = 0;
        }
        for (int i = 0; i < cols1; i++)
        {
            for (int ind = 0; ind < cols2; ind++)
            {
                sumprodo[ind] += (array1[j][i] * array2[i][ind]);
            }
        }
        multarray.push_back(sumprodo);
        
    }
    return multarray;
}

// thread function inside threadmatmultiply function. 

void threadLoop( int arr1row, int cols2, int array1RsubI, 
    vector<int> array2SubI, int i, vector<int>& tsumprod)
{
   
    for (int ind = 0; ind < cols2; ind++)
    {
       
        tsumprod[ind] = (array1RsubI * array2SubI[ind]);
    }
}

//needs to figure out how to distribute among threads.
////////////
vector<vector<int>> threadMatMult(vector<vector<int>> array1, vector<vector<int>> array2, int rows1, int cols1, int rows2, int cols2) 
{

    
    if (cols1 != rows2)
    {
        std::cout << "the dimensions don't match \n";
        exit(1);
    }

    //output vector
    vector<vector<int>> tmultarray(rows1, vector<int> (cols2, 0));
    
    //const auto threadCount = thread::hardware_concurrency();

    for (int arr1row = 0; arr1row < rows1; arr1row++)
    {
        vector<int> sumprod(cols2);
        vector<int> threadsumprod(cols2);
        for (int i = 0; i < cols1; i++)
            {
               
                //thread t;
                future<void> fut;
                if (i%2)
                {
                    
                    //t = std::thread(threadLoop, arr1row, cols2, array1[arr1row][i], array2[i], i, std::ref(threadsumprod));
                    fut = async(&threadLoop, arr1row, cols2, array1[arr1row][i], array2[i], i, std::ref(threadsumprod));
                    
                } 
                else
                {
                    for (int ind = 0; ind < cols2; ind++)
                    {
                        sumprod[ind] += (array1[arr1row][i] * array2[i][ind]);
                    }
                }
                if (fut.valid())
                {
                    fut.get();
                }
                
                
                // if (t.joinable())
                // {
                //     t.join();
                // };
                
                for (int k = 0; k < cols2; k++)
                {
                    tmultarray[arr1row][k] += (sumprod[k] + threadsumprod[k]);
                    threadsumprod[k] = 0;
                    sumprod[k] = 0;
                }   
            }  
    }

    return tmultarray;
}