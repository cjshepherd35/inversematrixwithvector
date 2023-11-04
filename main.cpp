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
    try
    {
        result = matmult(mat1, mat2, 2,4,4,2);
        throw("error");
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
        cout << "there was  problem \n";
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
        
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
    
    
    return 0;
}



