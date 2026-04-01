# Exercise 7: Advanced Find & Detailed Listing

> "Invert, always invert." — Charlie Munger

## The Goal
Find all files in `/usr/bin` larger than **2MB** and print their **detailed information** (long listing) using a single command.

---

## 1. Inversion: How to fail this exercise?
- **The Manual Sisyphus**: Finding the files, then manually typing `ls -l` for each one.
- **The Path Error**: Searching in `/bin` or `/usr/local/bin` instead of `/usr/bin`.
- **The Size Mistake**: Using `2M` (exactly 2MB) instead of `+2M` (larger than 2MB).
- **The Type Oversight**: Forgetting `-type f`, which might lead you to include directories if any were massive.

---

## 2. The Mental Model: The Search Engine (`find`)
`find` is a recursive search engine. We specify the **Location**, the **Filter**, and the **Action**.

### Step A: The Location & Filter
- **Filter**: `-size +2M` 
- **Filter**: `-type f` (ensures we only get files).

### Step B: The Action (`-ls` or `-exec`)
- **Action**: `-ls`
- **Why?**: In the student environment, `-ls` is the most reliable way to get long-format output within one `find` command.

---

## 3. The "High-Reliability" Solution

```bash
find /usr/bin -type f -size +2M -ls
```

### Parameter-by-Parameter Proof:
- `/usr/bin`: The starting **path**.
- `-type f`: Look for regular **f**iles only.
- `-size +2M`: Only files **greater than** (+) 2 Megabytes.
- `-ls`: **Action** that prints the result in `ls -dils` format.

---

## 4. Simpler Examples (Building Competence)

**Example 1: Find files by name**
```bash
find /usr/bin -name "bash"
```

**Example 2: Find all directories in home**
```bash
find $HOME -type d
```

**Example 3: Find small files less than 10KB**
```bash
find . -size -10k
```
