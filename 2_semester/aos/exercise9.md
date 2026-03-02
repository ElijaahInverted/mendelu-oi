# Exercise 9: Filesystem Mounting Info

> "Knowing what you don’t know is more useful than being brilliant." — Charlie Munger

## The Goal
List information about all currently **mounted volumes** that use the **ext4** filesystem.

---

## 1. Inversion: How to fail this exercise?
- **The Information Overload**: Running `mount` without filters. You will be buried under dozens of `tmpfs`, `devpts`, and `proc` virtual volumes.
- **The "df" Trap**: Use `df` without `-t`. It shows disk space but might miss mounting details required by the prompt.

---

## 2. The Mental Model: The Map (`mount`)
The system is a collection of disks attached to a single tree. **`mount`** is the command that shows which branch belongs to which disk.

### Step A: The Type Filter (`-t`)
- **Command**: `mount -t ext4`
- **Why?**: The `-t` flag filters by **t**ype. It removes all the noise from other filesystems.

### Step B: The Backup Model (`df`)
- **Command**: `df -t ext4`
- **Why?**: If `mount` is too complex, `df` (disk free) with `-t` gives a clean table of the physical drives.

---

## 3. The "High-Reliability" Solution

```bash
mount -t ext4
```

### Parameter-by-Parameter Proof:
- `mount`: The utility to manage and **view** connected volumes.
- `-t`: Filter by **t**ype.
- `ext4`: The specific Linux filesystem standard requested.

---

## 4. Simpler Examples (Building Competence)

**Example 1: See EVERYTHING mounted**
```bash
mount
```

**Example 2: Clean disk space summary (Human readable)**
```bash
df -h
```

**Example 3: Just the kernel filesystem labels**
```bash
cat /proc/mounts | grep ext4
```
