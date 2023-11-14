#include "implements.cpp"
#include <algorithm>

int main(int argc, const char * argv[]) {

    vector<vector<int>> mat1 {
        {3,2,3,4},
        {1,3,2,4}
    };

    vector<vector<int>> mat2 {
        {1,2},
        {1,3},
        {6,-1},
        {0,9}
    };
    int rows1 = 2;
    int cols1 = 4;
    int rows2 = 4;
    int cols2 = 2;

    // int rows1 = 5;
    // int cols1 = 3;
    // int rows2 = 3;
    // int cols2 = 30;
    //srand(time(0));

    // vector<vector<int>> mat1(rows1, vector<int> (cols1, 0));
    // for (int i = 0; i < rows1; i++)
    // {
    //     //generate(mat2[i].begin(), mat2[i].end(), rand);
    //     for (int j = 0; j < cols1; j++)
    //     {
    //         mat1[i][j] = rand() % 5;
    //     }
        
    // }
    
    // vector<vector<int>> mat2(rows2, vector<int> (cols2, 0));
    // for (int i = 0; i < rows2; i++)
    // {
    //     //generate(mat2[i].begin(), mat2[i].end(), rand);
    //     for (int j = 0; j < cols2; j++)
    //     {
    //         mat2[i][j] = rand() % 5;
    //     }
        
    // }



    vector<vector<int>> result;
    vector<vector<int>> result2;

    auto start = chrono::high_resolution_clock::now();
    result = matmult(mat1, mat2, rows1,  cols1,rows2,cols2);
    auto stop = chrono::high_resolution_clock::now();

    auto timediff = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << timediff.count() << " for one thread \n";

    try
    {
        // auto start = chrono::high_resolution_clock::now();
        // result = matmult(mat1, mat2, rows1,  cols1,rows2,cols2);
        // auto stop = chrono::high_resolution_clock::now();

        // auto timediff = chrono::duration_cast<chrono::microseconds>(stop - start);
        // cout << timediff.count() << " for one thread \n";


        start = chrono::high_resolution_clock::now();
        result2 = threadMatMult(mat1, mat2, 2, 4, 4, 2);
        stop = chrono::high_resolution_clock::now();
        timediff = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << timediff.count() << " for two threads \n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j]  << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < result2.size(); i++)
    {
        for (int j = 0; j < result2[i].size(); j++)
        {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



// int choice;
    // cout << "do  you want an inverse or to multiply?  \n";
    // cout << " choose 0 for inverse or 1 for multiply. \n";
    // cin >> choice;

    // if (choice == 0)
    // {
    //     inverseImplement();
    // }
    // else if(choice == 1)
    // {
    //     matMultImplement();
    // }
    // else 
    // {
    //     cout << "you're dumb. That is not an acceptable choice. \n";

    // }