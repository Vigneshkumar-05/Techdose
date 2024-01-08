#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> segment_tree;

void Built_Segment_Tree(vector<int> &nums, int start_index, int end_index, int segment_index)
{
    // Base condition
    if (start_index > end_index)
    {
        return;
    }
    // Leafnode
    if (start_index == end_index)
    {
        segment_tree[segment_index] = nums[start_index];
        return;
    }

    int middle_index = start_index + (end_index - start_index) / 2;
    Built_Segment_Tree(nums, start_index, middle_index, (2 * segment_index + 1));
    Built_Segment_Tree(nums, middle_index + 1, end_index, (2 * segment_index + 2));
    segment_tree[segment_index] = segment_tree[2 * segment_index + 1] + segment_tree[2 * segment_index + 2];
}

int Range_Sum(int start_range, int end_range, int start_index, int end_index, int segment_index)
{
    // No overlapping condition
    if (start_range > end_index or end_range < start_index)
    {
        return 0;
    }

    // Total overlapping condition
    if (start_range <= start_index and end_range >= end_index)
    {
        return segment_tree[segment_index];
    }

    // Partial overlapping conditon
    int middle_index = start_index + (end_index - start_index) / 2;
    int left_sum = Range_Sum(start_range, end_range, start_index, middle_index, (2 * segment_index + 1));
    int right_sum = Range_Sum(start_range, end_range, middle_index + 1, end_index, (2 * segment_index + 2));

    return left_sum + right_sum;
}

void Update(int start_index, int end_index, int segment_index, int update_index, int update_element)
{
    // Base condition
    if (start_index > update_index or end_index < update_index)
    {
        return;
    }
    // Leafnode
    if (start_index == end_index)
    {
        segment_tree[segment_index] = update_element;
        return;
    }

    int middle_index = start_index + (end_index - start_index) / 2;
    Update(start_index, middle_index, (2 * segment_index + 1), update_index, update_element);
    Update(middle_index + 1, end_index, (2 * segment_index + 2), update_index, update_element);
    segment_tree[segment_index] = segment_tree[2 * segment_index + 1] + segment_tree[2 * segment_index + 2];
}

int main()
{
    int nums_size;
    cin >> nums_size;

    vector<int> nums(nums_size);
    for (int index = 0; index < nums_size; index++)
    {
        cin >> nums[index];
    }

    // Size of the segment tree array
    segment_tree.resize(pow(2, (ceil(log2(nums_size)) + 1)) - 1);
    cout << "The size of the segment tree will be: " << segment_tree.size() << endl;

    int start_index = 0;
    int end_index = nums_size - 1;
    int segment_index = 0;
    int segement_tree_size = segment_tree.size();

    Built_Segment_Tree(nums, start_index, end_index, segment_index);

    cout << "Segement tree:" << endl;
    for (int index = 0; index < segement_tree_size; index++)
    {
        cout << segment_tree[index] << " ";
    }
    cout << endl;

    // Range sum
    int start_range;
    int end_range;
    cout << "Enter the start range and end range of the query:" << endl;
    cin >> start_range >> end_range;

    cout << "The range sum of " << start_range << " to " << end_range << ":" << endl;
    cout << Range_Sum(start_range, end_range, start_index, end_index, segment_index) << endl;

    // Update
    int update_index;
    int update_element;
    cout << "Enter the update index from 0 to " << nums_size << ":" << endl;
    cin >> update_index;
    cout << "Enter the element to be updated:" << endl;
    cin >> update_element;

    nums[update_index] = update_element;
    Update(start_index, end_index, segment_index, update_index, update_element);

    cout << "Segement tree after updation:" << endl;
    for (int index = 0; index < segement_tree_size; index++)
    {
        cout << segment_tree[index] << " ";
    }
    cout << endl;
    return 0;
}