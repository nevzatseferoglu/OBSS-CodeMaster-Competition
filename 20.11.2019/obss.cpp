#include <iostream>
#include <vector>


using namespace std;

int solution(vector<int> &A);
bool checkCurrentMin(vector<int>& A , int min_index , int  max_index );

int main()
{
    vector<int> sequence1 = {2,5,1,3,9,7};
    vector<int> sequence2 = {2,4,1,6,5,9,7};
    vector<int> sequence3 = {4,3,2,6,1};
    vector<int> sequence4 = {2,1,6,4,3,7};
    vector<int> sequence5 = {2,5,1,3,7,9};
    vector<int> sequence6 = {1,2,3,4,5};
    vector<int> sequence7 = {84,12,54,87,24,45,9,23,53,76};
    vector<int> sequence8 = {15,3,8,7,6,16,4,5,20,11,21};
    vector<int> sequence9 = {1,2,3,4,5};
    vector<int> sequence10 = {1,3,5,4,2};
    vector<int> sequence11 = {1,2,3,6,8,7,5,4};
    


    cout << "Sequence1 -> " << solution(sequence1) << endl;
    cout << "Sequence2 -> " << solution(sequence2) << endl;
    cout << "Sequence3 -> " << solution(sequence3) << endl;
    cout << "Sequence4 -> " << solution(sequence4) << endl;
    cout << "Sequence5 -> " << solution(sequence5) << endl;
    cout << "Sequence6 -> " << solution(sequence6) << endl;
    cout << "Sequence7 -> " << solution(sequence7) << endl;
    cout << "Sequence8 -> " << solution(sequence8) << endl;
    cout << "Sequence9 -> " << solution(sequence9) << endl;
    cout << "Sequence10 -> " << solution(sequence10) << endl;
    cout << "Sequence11 -> " << solution(sequence11) << endl;

    return 0;
}
int solution(vector<int> &A)
{
    int sliceAmount = 0 , index = 0;
    bool sliceBool = false , flag = true;

    for( int i = 0 ; i < A.size() ; ++i )
    {
        for( int j = i ; j < A.size() && flag ; ++j )
        {
            if( A[j] <= A[i] )
            {
                sliceBool = checkCurrentMin(A , i ,j);
                index = j;

                if( sliceBool )
                    flag = false;
            }
        }

        if( sliceBool )
        {
            ++sliceAmount;
            i = index;
        }

        sliceBool = false , flag = true;

    }

    return sliceAmount;
}
bool checkCurrentMin(vector<int>& A , int min_index , int  max_index )
{
    for( int i = max_index + 1 ; i < A.size() ; ++i )
    {
        for(int  j = min_index ; j <=  max_index ; ++ j)
            if(A[i] < A[j])
                return false;
    }
    
    return true;
}
