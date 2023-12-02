#!/bin/bash

# Check arguments
if [ $# -ne 2 ]; then
  echo "Usage: $0 <module_name> <problem_num>"
  exit 1
fi

module_name=$1
problem_num=$2

# Create module directory
mkdir -p "$module_name"
cd "$module_name" || exit

# Create problem directories
for ((i = 0; i < problem_num; i++)); do
  dir=$(printf "ex%02d" "$i")
  mkdir -p "$dir"
  # Copy template files
  cp -r ../template/* "$dir/"
done
