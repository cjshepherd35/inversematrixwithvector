#include "implements.cpp"


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

    vector<vector<int>> result;
    vector<vector<int>> result2;
    try
    {
        auto start = chrono::high_resolution_clock::now();
        result = matmult(mat1, mat2, 2,4,4,2);
        auto stop = chrono::high_resolution_clock::now();

        auto timediff = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << timediff.count() << " for one thread \n";

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
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

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