# Exercise 8: Symbolic vs. Hard Links

> "I have what I call an internal scoreboard. I pride myself on not being stupid." — Charlie Munger

## The Goal
In your **home directory**, create two links for the file `uzivatele.txt`:
1. A **hard link** named `hard`.
2. A **symbolic link** named `symbolic`.

---

## 1. Inversion: How to fail this exercise?
- **Ordering Catastrophe**: Swapping the "Source" and "Target" names. You'll accidentally delete your data or link to nothing.
- **The Ghost Link**: Creating a symbolic link but misspelling the source. It will look like a broken link (red text).
- **Flag Amnesia**: Forgetting the `-s` for symbolic links. If you forget it, you get a hard link instead.

---

## 2. The Mental Model: Address vs. Shortcut

### Biology: The Hard Link
Think of a Hard Link as a **twin**. Both names point to the exact same "body" (the data on the disk). If you delete one twin, the other survives perfectly.
- **Command**: `ln [source] [target]`

### Psychology: The Symbolic Link
Think of a Symbolic Link as a **Post-it note** that says "Go look at that file." If the original file is moved or deleted, the note becomes useless.
- **Command**: `ln -s [source] [target]`

---

## 3. The "High-Reliability" Solution

```bash
# Hard link
ln uzivatele.txt hard

# Symbolic link
ln -s uzivatele.txt symbolic
```

### Parameter-by-Parameter Proof:
- `ln`: The **l**i**n**k command.
- `-s`: Specifies a **s**oft (symbolic) link.
- `uzivatele.txt`: The **source** (original file).
- `hard` / `symbolic`: The **target** names.

---

## 4. Simpler Examples (Building Competence)

**Example 1: Verification (How to tell them apart)**
```bash
ls -l
```
*Look for `l` at the start of the line for symbolic.*

**Example 2: Linking a directory (Symbolic ONLY)**
```bash
ln -s /etc ./etc_link
```

**Example 3: Checking inode numbers (For Hard Links)**
```bash
ls -i
```
*Hard links will share the exact same number.*
