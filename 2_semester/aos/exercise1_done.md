# Exercise 1: Line Range Extraction & Numbering

> "It is remarkable how much long-term advantage people like us have gotten by trying to be consistently not stupid, instead of trying to be very intelligent." — Charlie Munger

## The Goal
Extract lines **10 to 19** from `uzivatele.txt`, ensure they have their **original line numbers**, and save them to `users1.txt`.

---

## 1. Inversion: How to fail this exercise?
To ensure success, we first look at how a student might create a catastrophe:
- **Manual Copying**: Trying to copy-paste lines. It’s slow, error-prone, and doesn't scale.
- **Complex Regex**: Using `grep` with a range that you don't fully understand. If you don't know the pattern, you'll grab the wrong data.
- **Forgetting Numbers**: Filtering the data *before* numbering it. If you filter first, line 10 becomes line 1 in the output. Misery follows.

---

## 2. The Mental Model: Component Assembly
We need two simple tools that do one thing well. We combine them like LEGO bricks.

### Step A: The "numberer" (`cat -n` or `nl`)
We need to attach the original line numbers *first*.
- **Command**: `cat -n uzivatele.txt`
- **Why?**: It prepends each line with its index. Simple. Reliable.

### Step B: The "filter" (`sed`)
We need to pick exactly lines 10 through 19.
- **Command**: `sed -n '10,19p'`
- **Why?**: `sed` is a stream editor. The `-n` tells it "don't print everything," and `10,19p` says "only print lines 10 to 19."

---

## 3. The "High-Reliability" Solution
Combine them with a pipe (`|`) and redirect to a file (`>`).

```bash
cat -n uzivatele.txt | sed -n '10,19p' > users1.txt
```

### Parameter-by-Parameter Proof:
- `cat -n`: **cat**enate with **n**umbers. Creates the sequence.
- `|`: The **pipe**. Transfers the output of the first command to the second.
- `sed`: The **s**tream **ed**itor.
- `-n`: **Silent** mode. Prevents `sed` from printing every line it reads.
- `'10,19p'`: The instruction. **10,19** is the range; **p** stands for **p**rint.
- `>`: **Redirect**. Sends the final result into `users1.txt` (overwriting it if it exists).

---

## 4. Simpler Examples (Building Competence)
Before tackling the final one, ensure you can do these:

**Example 1: Just the first 10 lines with numbers**
```bash
cat -n uzivatele.txt | head -n 10
```

**Example 2: Just line 15 (no numbers)**
```bash
sed -n '15p' uzivatele.txt
```

**Example 3: Lines 5 to 7 (with original numbers)**
```bash
cat -n uzivatele.txt | sed -n '5,7p'
```
