#!/bin/bash

# File formats and count
formats=("txt" "doc" "csv")
total_files=1000
target_word="HD{tez_orada_bu_quti_sizniki_bo'ladi}"

# Generate 1000 random files with the extensions .txt, .doc, and .csv in the current directory
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

# Echo where the word was placed for your reference
echo "Inserted '$target_word' into file: $file_path"
