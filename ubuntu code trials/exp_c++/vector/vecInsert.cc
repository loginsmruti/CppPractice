// inserting into a vector
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

//    for (it=myvector.begin(); it<myvector.end(); it++)
//        std::cout << ' ' << *it;
//    std::cout << '\n';
//200 100 100 100

    myvector.insert (it,2,300);

    //for (it=myvector.begin(); it<myvector.end(); it++)
    //    std::cout << ' ' << *it;
    //std::cout << '\n';
   
    //300 300 200 100 100 100
    // "it" no longer valid, get a new one:
    it = myvector.begin();


    int myarray [] = { 501,502,503 };
    myvector.insert (it , myarray, myarray+3);

    //501 502 503 300 300 200 100 100 100
    // "it" no longer valid, get a new one:
    it = myvector.begin();
    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    //501 502 400 400 503 300 300 200 100 100 100

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
