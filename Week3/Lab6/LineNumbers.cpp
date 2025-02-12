/*

Your task
    Your program should perform the following steps:
        0. Rename this file to LineNumbers.cpp
        
        1. Prompt the user to enter the name of an input file that
        contains the text to which line numbers will be added. Open the named file
        for reading.

        2. Prompt the user to enter the name of an
        output file that will contain the numbered text. Open this file for writing.

        3. Once both the input and output files have been opened, read each line from
        the input file and write it to the output file with a line number inserted into
        the front of the line. For example, if the input file reads:

            Mary had a little lamb,
            whose fleece was white as snow.

            And everywhere that Mary went,
            the lamb was sure to go.

            *** then the modified lines written to the output file will be: ***

            1. Mary had a little lamb,
            2. whose fleece was white as snow.
            3.
            4. And everywhere that Mary went,
            5. the lamb was sure to go.

        The line numbers must be formatted such that they are right justified
        in a field 5 characters wide, followed by a period, then a space, then
        the line of text.
        Note that blank lines in the file must be handled appropriately.

        4. You may use the file maryLamb.txt for testing, or any other text
        file that you choose. (We will test your code using a longer file,
        such as WarAndPeace.txt.) For your information,
        maryLamb.txt has exactly 23 lines and Tolstoy’s War and Peace has
        approximately 65,000 lines

        5. Be sure to close all open files at the end of your main() method.
        
Specifications
    For full credit, your program must meet the following specifications:
    - Complete file prolog comments included.
    - Naming conventions for variable, method, and class names are followed.
    - Meaningful variable names, prompts, and output messages are used.
    - Runs without error; does not crash on proper input.
    - Performs all actions described above and generates correct results.
    - All lines of text from the input file must be successfully copied into the output file
    with correctly formatted line numbers as described above.
    - The program must run correctly for input files of arbitrary length.
    - Blank lines present in the input file must be included in the output file, with line
    numbers. Extra blank lines must not be introduced into the output file.
    - All open file(s) must be closed before the program finishes.

*/