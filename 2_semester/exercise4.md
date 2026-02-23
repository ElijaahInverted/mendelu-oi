# Exercise 4: Parameters & File Verification

> "The first rule is that you can't really know anything if you just remember isolated facts and try and bang 'em back. You've got to have models in your head." — Charlie Munger

## The Goal
Create a script `files.sh` that:
1. Takes any number of file paths as **parameters**.
2. Checks if each file **exists**.
3. If it exists, prints its **file type** (using the `file` utility).
4. If it doesn't, says it's missing.

---

## 1. Inversion: How to fail this exercise?
- **Hardcoded Limits**: Writing a script that only checks `$1` and `$2`. The instructions say "unlimited." You’ll fail on the "Lollapalooza" of missing flexibility.
- **Space-Bar Catastrophe**: Forgetting to quote your variables. If a user enters `/root/My Documents/file.txt`, and you don't use quotes, the script treats it as two separate files. Misery follows.
- **Silence**: Not giving feedback for missing files. If the file isn't there, the user needs to know *why* nothing happened.

---

## 2. The Mental Model: The Iterator
When dealing with an "unlimited" number of items, we use the "Generic Iterator."

### Step A: The "All Parameters" Variable (`$@`)
- **Simplest Path**: `for f in "$@"`
- **Why?**: `$@` is a special variable that represents every argument you typed after the script name. The quotes around `"$@"` are mandatory to handle spaces correctly.

### Step B: The Existence Check (`if [ -f ]`)
- **Simplest Path**: `if [ -e "$f" ]`
- **Why?**:
    - `-e`: Check if **E**xists.
    - `-f`: Check if it’s a regular **F**ile.
    - Reference: For this exam, `-e` or `-f` are usually acceptable.

### Step C: The Type Utility (`file`)
- **Simplest Path**: `file "$f"`
- **Why?**: It’s the standard tool to look inside a file and guess what it is (text, image, executable).

---

## 3. The "High-Reliability" Solution

```bash
#!/bin/bash

# Check if the user provided ANY arguments
if [ $# -eq 0 ]; then
    echo "Stupid error: Please provide at least one file path."
    exit 1
fi

# Iterate over every argument provided
for item in "$@"
do
    if [ -e "$item" ]; then
        echo "Soubor $item existuje."
        # Use the 'file' utility to show the type
        file "$item"
    else
        echo "Soubor $item neexistuje!"
    fi
    echo "-------------------"
done
```

### Parameter-by-Parameter Proof:
- `$#`: **Number** of arguments. We check if it's 0 to prevent "silent stupidity."
- `"$@"`: The **list** of all parameters. Quoted to prevent space-splitting.
- `if [ -e "$item" ]`:
    - `[`: Test command.
    - `-e`: Test for **e**xistence.
    - `"$item"`: The current file being checked.
- `file "$item"`: Runs the `file` command on the item to find its magic type.

---

## 4. Simpler Examples (Building Competence)

**Example 1: Just printing all arguments**
```bash
for x in "$@"; do echo "Arg: $x"; done
```

**Example 2: Just checking one file**
```bash
if [ -e "/bin/bash" ]; then echo "Bash exists"; fi
```

**Example 3: Checking if a file is a directory**
```bash
if [ -d "/etc" ]; then echo "It is a directory"; fi
```
