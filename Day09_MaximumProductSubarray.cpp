#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class code
{
public:
    int maxProductSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int MaxEndingHere = nums[0];
        int MinEndingHere = nums[0];
        int GlobalMax = nums[0];

        for (int i = 1; i < n; i++)
        {
            int prevMax = MaxEndingHere;
            int prevMin = MinEndingHere;

            MaxEndingHere = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            MinEndingHere = min({nums[i], prevMax * nums[i], prevMin * nums[i]});

            GlobalMax = max(GlobalMax, MaxEndingHere);
        }
        return GlobalMax;
    }
};

int main()
{
    code cc;
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max Product Subarray Is: " << cc.maxProductSubarray(nums1) << endl;
    return 0;
}

--- 
```🔢 Problem: Maximum Product Subarray (LeetCode 152)
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest product, and return that product.

Example:
nums = [2, 3, -2, 4] → max product = 6 (subarray [2, 3])

🧩 What is a Subarray?
A subarray is a contiguous block of elements from the array.
For [1, 2, 3], valid subarrays are:
[1], [2], [3], [1,2], [2,3], [1,2,3]
❌ Not allowed: [1,3] (non-contiguous) → that’s a subsequence.

🤔 Why Product ≠ Sum?
With sum, a negative number always reduces the total.
With product, a negative × negative = positive, so a very negative product can become the maximum when multiplied by a negative number.

So, we can’t just track the max — we must also track the min product ending at each position.

✅ Core Idea: Track Max & Min
At each index i, maintain:

max_ending_here: max product of subarray ending at i
min_ending_here: min product of subarray ending at i

Because:

min_ending_here * nums[i] can become the new maximum if nums[i] is negative.
max_ending_here * nums[i] can become the new maximum if nums[i] is positive.
We can always start fresh: nums[i] itself.

Update:
cpp
new_max = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
new_min = min({nums[i], prev_max * nums[i], prev_min * nums[i]});
Then update the global answer:
cpp
global_max = max(global_max, new_max);

⏱️ Complexity
Time: O(n) — single pass
Space: O(1) - only a few variables

📌 Key Takeaway
When dealing with product of subarrays, always consider that a very negative product can become the maximum when multiplied by a negative number.
So, track both max and min ending at each position.```
    
---
> 🔢 **Problem: Maximum Product Subarray (LeetCode 152)**  
> Given an integer array `nums`, find the contiguous **subarray** (containing at least one number) which has the largest product, and return that product.
>
> **Example:**  
> `nums = [2, 3, -2, 4]` → max product = `6` (subarray `[2, 3]`)

---

> 🧩 **What is a Subarray?**  
> A **subarray** is a **contiguous** block of elements from the array.  
> For `[1, 2, 3]`, valid subarrays are:  
> `[1]`, `[2]`, `[3]`, `[1,2]`, `[2,3]`, `[1,2,3]`  
> ❌ Not allowed: `[1,3]` (non‑contiguous) → that’s a subsequence.

---

> 🤔 **Why Product ≠ Sum?**  
> - With **sum**, a negative number always reduces the total.  
> - With **product**, a negative × negative = positive, so a very negative product can become the maximum when multiplied by a negative number.  
>
> So, we can’t just track the max — we must also track the **min** product ending at each position.

---

> ✅ **Core Idea: Track Max & Min**  
> At each index `i`, maintain:
> - `max_ending_here`: max product of subarray ending at `i`  
> - `min_ending_here`: min product of subarray ending at `i`
>
> Because:
> - `min_ending_here * nums[i]` can become the new maximum if `nums[i]` is negative.  
> - `max_ending_here * nums[i]` can become the new maximum if `nums[i]` is positive.  
> - We can always start fresh: `nums[i]` itself.
>
> **Update:**
> ```cpp
> new_max = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
> new_min = min({nums[i], prev_max * nums[i], prev_min * nums[i]});
> ```
>
> Then update the global answer:
> ```cpp
> global_max = max(global_max, new_max);
> ```

---

> ⏱️ **Complexity**  
> - **Time:** `O(n)` — single pass  
> - **Space:** `O(1)` — only a few variables

---

> 📌 **Key Takeaway**  
> When dealing with **product** of subarrays, always consider that a very negative product can become the maximum when multiplied by a negative number.  
> So, track **both max and min** ending at each position.
