# Exercise 6: Process Listing

> "The first rule is that you can't really know anything if you just remember isolated facts... You've got to have models in your head." — Charlie Munger

## The Goal
List **all processes** owned by the user **root**, including their attributes (PID, TTY, TIME, CMD).

---

## 1. Inversion: How to fail this exercise?
- **The Global Flood**: Running `ps aux` and handing in 500 lines of data. It shows everything, but doesn't answer the specific question.
- **The Empty Snapshot**: Running `ps` without arguments. It only shows your current terminal session.
- **Wrong User**: Filtering for your own username instead of `root`.

---

## 2. The Mental Model: The Process Snapshot (`ps`)
To see what the "brain" (CPU) is doing, we take a snapshot of the process table using **`ps`**.

### Step A: Selection by User (`-u` or `-U`)
- **Command**: `ps -u root`
- **Why?**: The `-u` (user) flag limits the snapshot to one specific owner.

### Step B: Detail vs. Summary
- **Note**: Standard `ps -u root` already provides PID, TTY, TIME, and CMD. No extra complexity is needed.

---

## 3. The "High-Reliability" Solution

```bash
ps -u root
```

### Parameter-by-Parameter Proof:
- `ps`: **P**rocess **S**tatus utility.
- `-u root`: Filters the output to show only processes owned by the **u**ser **root**.

---

## 4. Simpler Examples (Building Competence)

**Example 1: See your own processes**
```bash
ps
```

**Example 2: See every process on the system (The "Lollapalooza")**
```bash
ps -e
```

**Example 3: See process details for a different user**
```bash
ps -u xnovak
```
