#pragma once
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

typedef int ULL;

void test_generator(const char* DatasetName, ULL max_number, ULL count)
{
    random_device my_random;
    ofstream file_random_mashroom_forest;
    file_random_mashroom_forest.open(DatasetName, ios_base::trunc);
    unsigned char* tmp = new unsigned char[max_number + 1];
    ULL generate = 0;
    for (ULL i = 0; i < max_number + 1; i++) {
        tmp[i] = 0;
    }
    if (count > max_number) count = max_number;
    for (int i = 0; i < count; i++)
    {
        do {
            tmp[generate] = 1;
            generate = my_random.operator()() % max_number + 1;
        } while (tmp[generate] != 0);
        file_random_mashroom_forest << generate << '\n';
    }
    file_random_mashroom_forest.close();
    if (tmp != NULL) delete[] tmp;
}