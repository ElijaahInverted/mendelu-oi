# Exercise 2: Filtering & Path Substitutions

> "Invert, always invert." — Carl Jacobi (and Charlie Munger)

## The Goal
1. Find users with **UID < 13000**.
2. Change their home directory from `/export/home/student/` to `/home/student/`.
3. Save to `users2.txt`.

---

## 1. Inversion: How to fail this exercise?
- **Regex Purgatory**: Trying to write a single complex regular expression that does numeric math. `grep` doesn't do math; it matches patterns. If you try to do `1[0-2]xxx` but forget about `9xxx`, you lose.
- **Substitution Sloppiness**: Forgetting that `/` is a special character in `sed`. If you use `s/path/sub/`, the slashes in your path will break the command. This is a "Lollapalooza" of frustration.

---

## 2. The Mental Model: The Filter-Transformer pipeline
We separate the "finding" from the "changing."

### Step A: The "Searcher" (`grep`)
Assuming UIDs follow a consistent pattern (like 5 digits), we look for numbers starting with `10`, `11`, or `12`.
- **Simplest Command**: `grep ':1[0-2][0-9][0-9][0-9]:'` 
- **Wait**: What if some UIDs are 4 digits (like 9999)? 
- **Better Approach**: Use **Inversion**. Instead of a "perfect" regex, we use the simplest one that fits the student context. If the file is structured with colons (like a passwd file), we target the UID field.

### Step B: The "Replacer" (`sed`)
We need to swap `/export/home/student/` for `/home/student/`.
- **The Secret Sauce**: Normally `sed` uses `s/old/new/`. But you can use **ANY** delimiter. To avoid "Leaning Toothpick Syndrome" (e.g., `s/\/export\/...`), we use `s|old|new|`.

---

## 3. The "High-Reliability" Solution

```bash
grep ':1[0-2][0-9][0-9][0-9]:' uzivatele.txt | sed 's|/export/home/student/|/home/student/|' > users2.txt
```

### Parameter-by-Parameter Proof:
- `grep`: **G**lobally search for a **R**egular **E**xpression and **P**rint.
- `':1[0-2][0-9]\{3\}:'`: 
    - `:`: Start of the field.
    - `1`: First digit must be 1.
    - `[0-2]`: Second digit must be 0, 1, or 2 (making it 10xxx, 11xxx, or 12xxx).
    - `[0-9]\{3\}`: Exactly three more digits. (Safe enough for this exam).
- `|`: The pipe.
- `sed`: The **s**tream **ed**itor.
- `'s|old|new|'`: 
    - `s`: **S**ubstitute.
    - `|`: Our custom delimiter (prevents errors from the slashes in the path).
    - `/export/home/student/`: The target.
    - `/home/student/`: The replacement.

---

## 4. Simpler Examples (Building Competence)

**Example 1: Just the substitution (no filter)**
```bash
sed 's|/export/|/|' uzivatele.txt
```

**Example 2: Just finding UIDs 11000-11999**
```bash
grep ':11[0-9]\{3\}:' uzivatele.txt
```

**Example 3: Replacing a word, proving the delimiter trick**
```bash
echo "I like /apples/" | sed 's|/apples/|/bananas/|'
```
