#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
// My includes
#include "Function.h"
#include "BinaryTreeValue.h"

void SpeedTestBinaryTreeGetRoot(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeAdd(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeAddAndGetPointer(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeAddNode(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeMap(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeWhere(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeSearchItem(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeSearchTree(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeCut(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeToString(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);
void SpeedTestBinaryTreeheapifyAll(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots);

 // For BinaryTreeVal
void SpeedTestBinaryTree(int count, int numberDots)
{
    SpeedTestBinaryTreeGetRoot("text1.txt", "SpeedTestBinaryTreeGetRoot.txt", count, numberDots);
    SpeedTestBinaryTreeAdd("text1.txt", "SpeedTestBinaryTreeAdd.txt", count, numberDots);
    SpeedTestBinaryTreeAddAndGetPointer("text1.txt", "SpeedTestBinaryTreeAddAndGetPointer.txt", count, numberDots);
    SpeedTestBinaryTreeAddNode("text1.txt", "SpeedTestBinaryTreeAddNode.txt", count, numberDots);
    SpeedTestBinaryTreeMap("text1.txt", "SpeedTestBinaryTreeMap.txt", count, numberDots);
    SpeedTestBinaryTreeWhere("text1.txt", "SpeedTestBinaryTreeWhere.txt", count, numberDots);
    SpeedTestBinaryTreeSearchItem("text1.txt", "SpeedTestBinaryTreeSearchItem.txt", count, numberDots);
    SpeedTestBinaryTreeSearchTree("text1.txt", "SpeedTestBinaryTreeSearchTree.txt", count, numberDots);
    SpeedTestBinaryTreeCut("text1.txt", "SpeedTestBinaryTreeCut.txt", count, numberDots);
    SpeedTestBinaryTreeToString("text1.txt", "SpeedTestBinaryTreeToString.txt", count, numberDots);
    SpeedTestBinaryTreeheapifyAll("text1.txt", "SpeedTestBinaryTreeheapifyAll.txt", count, numberDots);
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
// Map
void SpeedTestBinaryTreeMap(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        bt->Map(plusOne);
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// AddAndGetPointer
void SpeedTestBinaryTreeAddAndGetPointer(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
            bt->AddAndGetPointer(tmp);
        }
        file_for_answer << i << ' ';
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// AddNode
void SpeedTestBinaryTreeAddNode(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
            bt->AddAndGetPointer(tmp);
        }
        unsigned int start_time = clock();
        bt->AddNode(tmp, nullptr, bt->GetRoot());
        file_for_answer << i << ' ';
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// Where
void SpeedTestBinaryTreeWhere(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        delete( bt->Where(BigZero) );
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// SearchItem
void SpeedTestBinaryTreeSearchItem(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        bt->SearchItem(bt->GetRoot(), tmp);
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// SearchTree
void SpeedTestBinaryTreeSearchTree(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        bt->SearchTree(bt, bt);
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// Cut
void SpeedTestBinaryTreeCut(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        delete( bt->Cut(bt, tmp) );
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// ToString
void SpeedTestBinaryTreeToString(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
{

    ifstream file_for_analysis(file_name_for_analysis, ios_base::in);
    ofstream file_for_answer(file_name_for_answer, ios_base::trunc);
    int currentCount = 0;
    string str;
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        str = bt->ToString();
        file_for_answer << "String is: " << str << endl;
        str.clear();
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}
// heapifyAll
void SpeedTestBinaryTreeheapifyAll(const char* file_name_for_analysis, const char* file_name_for_answer, int count, int numberDots)
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
        file_for_answer << i << ' ';
        unsigned int start_time = clock();
        bt->heapifyAll();
        file_for_answer << clock() - start_time << endl;
        delete bt;
    }
    file_for_analysis.close();
    file_for_answer.close();
}