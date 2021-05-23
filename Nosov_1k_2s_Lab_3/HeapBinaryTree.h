#include "BinaryTree.h"

template <typename T>
class HeapBinaryTree : BinaryTree<T>
{
private:
    long Size = 1;
public:
    void push(int x) {
        Size++; // ����������� ������ ���� �� �������
        tree.push_back(x);
        sift_up(Size - 1);
    }

    int max() {
        if (Size > 1) {
            return tree[1];
        }
        else {
            //������: ������� ����� �������� � ������ ����
        }
    }

    void pop() {
        if (Size > 1) {
            Size--; // ��������� ������ ���� �� �������
            tree[1] = tree.back();
            tree.pop_back();
            sift_down(1);
        }
        else {
            //������: ������� ������� �������� �� ������ ����
        }
    }

    //������������� �����.
    void sift_up(int v) {
        if (v == 1) {
            return;     //������ ������ �����������.
        }

        if (tree[v / 2] < tree[v]) {
            swap(tree[v], tree[v / 2]);
            sift_up(v / 2);
        }
    }

    //������������� ����
    void sift_down(int v) {
        if (v * 2 >= Size) {
            return;     //������ ������ ����������.
        }

        //������ �������� ��������� ��������
        int max_idx;
        if (v * 2 + 1 == Size) {     //���� ����� ���������� ������ �����
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