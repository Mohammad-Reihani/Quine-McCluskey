# Quine-McCluskey Algorithm Implementation

## Overview

This project provides an implementation of the Quine-McCluskey algorithm, a method used in digital logic design for simplifying Boolean functions. The implementation allows for input of main terms and don't cares, and processes the input to produce a simplified Boolean expression.

## Features

- **Input Handling**: Accepts main terms and don't cares from the user.
- **Simplification**: Uses the Quine-McCluskey algorithm to simplify Boolean functions.
- **Output**: Displays grouped terms, prime implicants, and the final simplified Boolean expression.

## Dependencies

- C++11 or later

## Files

- `QuineMcCluskey.h` - Header file for the Quine-McCluskey class definition.
- `QuineMcCluskey.cpp` - Implementation file for the Quine-McCluskey class.
- `main.cpp` - Main file demonstrating how to use the Quine-McCluskey class.

## Usage


There are two main ways to use this tool:

1. **As a Library**: The `QuineMcCluskey` class can be integrated as a library or additional component into your own project. Refer to `main.cpp` for an example of how to integrate and use it within your own codebase. This approach provides greater control and customization for applying the Quine-McCluskey algorithm to your specific needs.

2. **As a Standalone Application**: You can also use the tool directly as a standalone executable. Here’s how:

   1. **Compile the Code**: To compile the project, use the following command:

      ```sh
      g++ -std=c++11 -o quine_mccluskey main.cpp QuineMcCluskey.cpp
      ```
   
   2. **Run the Executable**: Execute the compiled binary:

      ```sh
      ./quine_mccluskey
      ```

   3. **Input Data**:
      - **Main Terms**: Enter the main terms of the Boolean function separated by spaces.
      - **Don't Cares**: Enter don't care terms separated by spaces (press Enter to skip if there are none).
      - **Max Terms**: Indicate whether you have entered max terms by typing `yes` or `y`. Any other input will be considered as skipping this option.

   4. **View Results**:
      - The program will display:
        - **Grouped Terms**: Details of the grouped terms.
        - **Prime Implicants**: Details of the prime implicants, including whether they are essential or required.
        - **Main Terms Status**: Coverage status of each main term.
        - **Simplified Expression**: The final simplified Boolean expression.

## Example

Here's a sample run of the program:

```
Enter the mainTerms in a line separated by spaces:
1 2 4 5 7
Enter don't cares of the function if any separated by spaces (press Enter to skip):
10 11 
Did you enter MaxTerms? (yes/y or any):
no
Proceeding...
-------------------------------------------------------------------
The function is now simplified, getting ready to display results :
-------------------------------------------------------------------
Grouped Terms:
MainTerms Included: [1 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [2 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [4 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [5 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [10 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [7 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [11 ] Deleted Args: [] stage: 0 isPI: 0
MainTerms Included: [1 5 ] Deleted Args: [4 ] stage: 1 isPI: 1
MainTerms Included: [2 10 ] Deleted Args: [8 ] stage: 1 isPI: 1
MainTerms Included: [4 5 ] Deleted Args: [1 ] stage: 1 isPI: 1
MainTerms Included: [5 7 ] Deleted Args: [2 ] stage: 1 isPI: 1
MainTerms Included: [10 11 ] Deleted Args: [1 ] stage: 1 isPI: 1
-------------------------------------------------------------------
Prime Implicants:
MainTerms Included: [1 5 ] Deleted Args: [4 ] isEssential: 1 isRequired: 1
MainTerms Included: [2 10 ] Deleted Args: [8 ] isEssential: 1 isRequired: 1
MainTerms Included: [4 5 ] Deleted Args: [1 ] isEssential: 1 isRequired: 1
MainTerms Included: [5 7 ] Deleted Args: [2 ] isEssential: 1 isRequired: 1
MainTerms Included: [10 11 ] Deleted Args: [1 ] isEssential: 0 isRequired: -1
-------------------------------------------------------------------
MainTerms status:
term : 1 | is covered : 1
term : 2 | is covered : 1
term : 4 | is covered : 1
term : 5 | is covered : 1
term : 7 | is covered : 1
-------------------------------------------------------------------
Simplified Expression :
F(A,B,C,D)=A'C'D+B'CD'+A'BC'+A'BD

```

## Notes

- Ensure that the `QuineMcCluskey.h` and `QuineMcCluskey.cpp` files are in the same directory as `main.cpp` for the compilation to work correctly.
- The program assumes valid integer inputs. Invalid or non-integer inputs may lead to unexpected behavior.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
