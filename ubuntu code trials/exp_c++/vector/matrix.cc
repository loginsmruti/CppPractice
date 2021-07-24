#include <iostream>
#include <vector>

int main()
{
    // 3 x 2 matrix
    
    std::vector<std::vector<int> > myVecA(3,std::vector<int>(2) ) ;
    myVecA[0][0] = 0;
    myVecA[0][1] = 1;
    myVecA[1][0] = 10;
    myVecA[1][1] = 11;
    myVecA[2][0] = 20;
    myVecA[2][1] = 21;

    for(int i = 0;i < 3 ; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << myVecA[i][j] << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int> > myVecB;
    for (int i = 0; i < 3; i++) {
        std::vector<int> row; // Create an empty row
        for(int j = 0; j < 2; j++) {
            row.push_back(i+j); // Add an element (column) to the row
        }
        myVecB.push_back(row); // Add the row to the main vector
    }
    for(int i = 0;i < 3 ; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << myVecB[i][j] << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int> > myVecC;
    for (int i = 0; i < 3; i++) {
        myVecC.push_back(std::vector<int>()); // Add an empty row
    }
    int dummy = 0;
    for (int i = 0; i < 3; i++) {
        for (std::vector<std::vector<int> >::iterator it = myVecC.begin(); it != myVecC.end(); ++it) {
            it->push_back(i*100 + dummy++); // Add column to all rows
        }
    }
    for(int i = 0;i < 3 ; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << myVecC[i][j] << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
