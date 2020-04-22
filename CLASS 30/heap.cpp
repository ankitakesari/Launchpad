#include <iostream>
#include <vector>
using namespace std;

void upheapify(vector<int> &heap, int index)
{
    if (index == 0)
    {
        return;
    }

    int parent_index = (index - 1) / 2;

    if (heap[index] > heap[parent_index])
    {
        swap(heap[index], heap[parent_index]);
        upheapify(heap, parent_index);
    }

    else
    {
        return;
    }
}

void downheapify(vector<int> &heap, int index)
{
    int left_child_index = (2 * index) + 1;
    int right_child_index = (2 * index) + 2;

    if (left_child_index >= heap.size() && right_child_index >= heap.size())
    {
        return;
    }

    int largest_child_index = index;

    if (left_child_index < heap.size() && heap[left_child_index] > heap[index])
    {
        largest_child_index = left_child_index;
    }

    if (right_child_index < heap.size() && heap[right_child_index] > heap[largest_child_index])
    {
        largest_child_index = right_child_index;
    }

    if (largest_child_index == index)
    {
        return;
    }

    swap(heap[index], heap[largest_child_index]);
    downheapify(heap, largest_child_index);
}

void insert(vector<int> &heap, int val)
{
    heap.push_back(val);
    upheapify(heap, heap.size() - 1);
}

void display_heap(vector<int> &heap)
{

    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void build_heap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        upheapify(heap, i);
    }
}

void build_heap_opt(vector<int> &heap)
{
    for (int i = heap.size() - 1; i >= 0; i--)
    {
        downheapify(heap, i);
    }
}

void delete_root(vector<int> &heap)
{
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    downheapify(heap, 0);
}

void delete_node(vector<int> &heap, int index)
{
    heap[index] = INT_MAX;
    upheapify(heap, index);
    delete_root(heap);
}
int main()
{

    vector<int> heap;

    // insert(heap, 10);
    // insert(heap, 5);
    // insert(heap, 1);
    // insert(heap, 12);
    // insert(heap, 190);
    // insert(heap, 18);

    // display_heap(heap);

    //delete_root(heap);
    // delete_node(heap, 3);
    // display_heap(heap);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        heap.push_back(ele);
    }

    build_heap(heap);
    display_heap(heap);
}