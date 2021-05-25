#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
// My includes
#include "BinaryTreeValue.h"

void SpeedTestBinaryTreeGetRoot(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeAdd(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);

 // For BinaryTree
void SpeedTestBinaryTree(int count, int numberDots)
{
    SpeedTestBinaryTreeGetRoot("text1.txt", "SpeedTestBinaryTreeGetRoot.txt", count, numberDots);
    SpeedTestBinaryTreeAdd("text1.txt", "SpeedTestBinaryTreeAdd.txt", count, numberDots);
}
 // GetRoot
void SpeedTestBinaryTreeGetRoot(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
{
    
    ifstream file_for_analysis(file_name_for_analysis, ios_base::in);
    ofstream file_for_answer(file_name_for_answer, ios_base::trunc);
    int currentCount = 0;
    for (int i = count / numberDots; i < count; i = i + count / numberDots) {
        BinaryTreeVal<int>* bt = new BinaryTreeVal<int>;
        int tmp = 0;
        file_for_analysis.close();
        file_for_analysis.open(file_name_for_analysis, ios_base::in);
        for (int j = 0; j < i; j++)
        {
            file_for_analysis >> tmp;
            bt->Add(tmp);
        }
        unsigned int start_time = clock();
        bt->GetRoot();
        file_for_answer << i << ' ';
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// Add
void SpeedTestBinaryTreeAdd(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
{

    ifstream file_for_analysis(file_name_for_analysis, ios_base::in);
    ofstream file_for_answer(file_name_for_answer, ios_base::trunc);
    int currentCount = 0;
    for (int i = count / numberDots; i < count; i = i + count / numberDots) {
        BinaryTreeVal<int>* bt = new BinaryTreeVal<int>;
        int tmp = 0;
        file_for_analysis.close();
        file_for_analysis.open(file_name_for_analysis, ios_base::in);
        unsigned int start_time = clock();
        for (int j = 0; j < i; j++)
        {
            file_for_analysis >> tmp;
            bt->Add(tmp);
        }
        file_for_answer << i << ' ';
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
