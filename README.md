
# Ingredient Check Program

## Overview

This program checks if you can prepare multiple dishes given a list of available ingredients. Each dish requires a specific set of ingredients, and the program verifies if it's possible to select disjoint subarrays from the available ingredients list to match each dish's requirements.

## Problem Statement

You are given:
- `groups`: A list of sets, where each set contains the ingredients required for a particular dish.
- `nums`: An array of available ingredients.

The goal is to determine if you can find `n` disjoint subarrays from the `nums` array such that each subarray matches the ingredients required for one of the dishes in `groups`.

## Solution Approach

1. **Reading Input**: The input consists of a text file that provides the required ingredients for each dish (`groups`) and the available ingredients (`nums`).
2. **Hash Matching**: Each dish's ingredients are hashed, and the same is done for potential subarrays in `nums`. This helps in efficiently checking for matches.
3. **Finding Disjoint Subarrays**: The algorithm searches for `n` disjoint subarrays in `nums` that match the ingredients of each dish in `groups`.
4. **Checking and Returning Result**: If such disjoint subarrays are found, the function returns true; otherwise, it returns false.

## Input File Format

The input file `p1_input.txt` should have the following structure:

```cpp
groups = [
    {ingredient1, ingredient2, ...},
    {ingredient1, ingredient2, ...},
    ...
]

nums = {ingredient1, ingredient2, ingredient3, ...}
```

- `groups` is a list of sets, where each inner set contains the ingredients required for one dish.
- `nums` is a list of ingredients available.

## How to Run

1. Ensure you have a C++ compiler installed on your system.
2. Place the input file `p1_input.txt` in the same directory as the source code.
3. Compile the program using a command like:
   ```sh
   g++ -o ingredient_check ingredient_check.cpp
   ```
4. Run the compiled program using the command:
   ```sh
   ./ingredient_check
   ```
5. The result will be printed on the console, indicating whether it is possible to prepare all dishes with disjoint subarrays from `nums`.


## Time Complexity

The time complexity of the solution is O(N * m^2), where:
- `N` is the number of elements in the `nums` array.
- `m` is the maximum length of any dish's ingredient list.

## Space Complexity

The space complexity of the solution is O(len), where `len` is the number of dishes (`groups`).

## Notes

- Ensure the input file format is strictly followed to avoid parsing errors.
- The solution assumes that ingredients are integers or comparable objects.

---
