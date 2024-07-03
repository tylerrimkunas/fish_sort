# fish_sort

## How it Works
1. Reads from file_names.txt for directories of the csv and the folder containing the vsi files
2. Reads every row in the CSV
3. For each row, the file name will be generated to find the file and the rename will be generated to use as the name for the copy
4. Make the destination directory and put all copied files in there with new name that is sortable.

## file_names.txt format
line 1: csv file   
line 2: source directory   
line 3: destination directory  

## How to Use
1. format file_names.txt file correctly
2. Run Executable file