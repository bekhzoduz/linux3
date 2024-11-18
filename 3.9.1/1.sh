#!/bin/bash

# File formats and count
formats=("txt" "doc" "csv")
total_files=100
target_word="HD{Linux_ko'nikmalarimizni_sinab_ko'rish_vaqti_keldi}"
katy_word="k\aty:hellowworld"

# Generate 100 random files with the extensions .txt, .doc, and .csv in the current directory
for ((i=1; i<=total_files; i++)); do
    # Select a random format
    format=${formats[$RANDOM % ${#formats[@]}]}
    # Generate a random file name
    file="file_$i.$format"
    # Create the file and add random content
    echo "This is file number $i." > "$file"
done

# Pick a random file to insert the target_word
random_file=$((RANDOM % total_files + 1))
file_path="file_$random_file.txt"
echo "$target_word" > "$file_path"

# Pick another random file for the Katy:hellowworld word
random_file2=$((RANDOM % total_files + 1))
file_path2="file_$random_file2.txt"
echo "$katy_word" > "$file_path2"

# Echo where the words were placed for your reference
echo "Inserted '$target_word' into file: file_$random_file.txt"
echo "Inserted '$katy_word' into file: file_$random_file2.txt"