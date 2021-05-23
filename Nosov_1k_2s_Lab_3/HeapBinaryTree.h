#include "BinaryTree.h"

template <typename T>
class HeapBinaryTree : BinaryTree<T>
{
private:
    long Size = 1;
public:
    void push(int x) {
        Size++; // Увеличиваем размер кучи на единицу
        tree.push_back(x);
        sift_up(Size - 1);
    }

    int max() {
        if (Size > 1) {
            return tree[1];
        }
        else {
            //Ошибка: попытка найти максимум в пустой куче
        }
    }

    void pop() {
        if (Size > 1) {
            Size--; // Уменьшаем размер кучи на единицу
            tree[1] = tree.back();
            tree.pop_back();
            sift_down(1);
        }
        else {
            //Ошибка: попытка извлечь максимум из пустой кучи
        }
    }

    //Проталкивание вверх.
    void sift_up(int v) {
        if (v == 1) {
            return;     //Больше некуда подниматься.
        }

        if (tree[v / 2] < tree[v]) {
            swap(tree[v], tree[v / 2]);
            sift_up(v / 2);
        }
    }

    //Проталкивание вниз
    void sift_down(int v) {
        if (v * 2 >= Size) {
            return;     //Больше некуда спускаться.
        }

        //Индекс большего дочернего элемента
        int max_idx;
        if (v * 2 + 1 == Size) {     //Если можно спуститься только влево
            max_idx = v * 2;
        }
        else if (tree[v * 2] >= tree[v * 2 + 1]) {
            max_idx = v * 2;
        }
        else {
            max_idx = v * 2 + 1;
        }

        if (tree[v] < tree[max_idx]) {
            swap(tree[v], tree[max_idx]);
            sift_down(max_idx);
        }
    }

    bool empty() {
        return tree.size() == 1;
    }
};