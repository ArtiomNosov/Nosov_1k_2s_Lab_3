/*
*	BinaryHeap.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#include <list>
using namespace std;

 // TODO: Сделать задаеин нулевого элемента для любого typename while (i > 0 && list[parent] < getListItem(i))
template <typename T>
class BinaryHeap
{
private:
    list<T> List;

    T getListItem(long index)
    {
        assert(index < heapSize());
        auto iterator = List.begin();
        for (int i = 0; i < index; i++)
            iterator++;
        return *iterator;
    }

    const list<int>::iterator getListIterator(long index)
    {
        auto iterator = List.begin();
        for (int i = 0; i < index; i++)
            iterator++;
        return iterator;
    }

    void heapify(long i)
    {
        long leftChild;
        long rightChild;
        long largestChild;

        for (; ; )
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heapSize() && getListItem(leftChild) > getListItem(largestChild))
            {
                largestChild = leftChild;
            }

            if (rightChild < heapSize() && getListItem(rightChild) > getListItem(largestChild))
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            T temp = getListItem(i);
            *(getListIterator(i)) = getListItem(largestChild);
            *(getListIterator(largestChild)) = temp;
            i = largestChild;
        }
    }

public:
    // Конструктор для построения из list
    BinaryHeap<T>(list<T> list)
    {
        List = list;
        for (int i = heapSize() / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    BinaryHeap<T>(T array[], long sizeArray)
    {
        for (int i = 0; i < sizeArray; i++)
        {
            List.push_back(array[i]);
        }
        for (int i = heapSize() / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    long heapSize()
    {
        return List.size();
    }

    void add(T value)
    {
        List.push_back(value);
        int i = heapSize() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && getListItem(parent) < getListItem(i))
        {
            T temp = getListItem(i);
            *(getListIterator(i)) = getListItem(parent);
            *(getListIterator(parent)) = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    T getMax()
    {
        T result = *( List.begin() ) ;
        List.erase(List.begin());
        List.emplace_front(*(--List.end()));
        List.erase(--List.end());
        heapify(0);
        return result;
    }

    T findMax()
    {
        return List.front();
    }

    void reBuildHeap(T sourceArray[], long sourceArraySize)
    {
        List.clear();
        for (long i = 0; i < sourceArraySize; i++)
        {
            List.push_back(sourceArray[i]);
        }
        for (int i = heapSize() / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapSort(T array[], long sizeArray)
    {
        reBuildHeap(array, sizeArray);
        for (int i = sizeArray - 1; i >= 0; i--)
        {
            array[i] = getMax();
            heapify(0);
        }
    }
};