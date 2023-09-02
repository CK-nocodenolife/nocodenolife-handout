#!/bin/bash

# Function to display usage information
show_usage() {
  echo "Usage: $0 <input_document_path> <output_document_path> <cpc_path>"
  echo "  main_path: Path to the folder nocodenolife_handout."
  echo "  input_document: Name of the input document (ex. DataStructure/Basic)."
  echo "  output_document_path: Path that is written in the output document."
  echo "  cpc_path: Path to the NTUCPC directory."
}

# Check if the number of arguments is less than 3
if [ $# -lt 4 ]; then
  show_usage
  exit 1
fi

# Parse command-line arguments
main_path="$1"
input_path="$2"
output_path="$3"
cpc_path="$4"

# Check if the help option is provided
if [ "$1" = "--help" ] || [ "$1" = "-h" ]; then
  show_usage
  exit 0
fi

python3 prep.py input_path main_path cpc_path

pandoc -s -f latex+latex_macros -F ./filter.py -t markdown -o ".md" main.tex
