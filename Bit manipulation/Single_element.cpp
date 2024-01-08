int singleNumber(int* nums, int numsSize){
    int result = nums[0];
    for (int index = 1; index < numsSize; index++) {
        result = result ^ nums[index];
    }
    return result;
}