function swap(nums, inx1, inx2)
{
    var aux = nums[inx1];
    nums[inx1] = nums[inx2];
    nums[inx2] = aux;

    return nums;
}

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var start = 0;
    var end = nums.length - 1;
    var index = 0;
    var base = [0, 1, 2];

    while(index <= end)
    {
        switch(nums[index])
        {
            case base[0]:
                if(start == index)
                    index++;
                else if(nums[start] > nums[index])
                    nums = swap(nums, index, start);

                start++;
            break;

            case base[1]:
                index++;
            break;

            case base[2]:
                if(nums[index] > nums[end])
                    nums = swap(nums, index, end);

                end--;
            break;
        }
    }
};