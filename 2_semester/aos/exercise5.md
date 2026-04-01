# Exercise 5: Arithmetics & Decision Trees

> "It is remarkable how much long-term advantage people like us have gotten by trying to be consistently not stupid, instead of trying to be very intelligent." — Charlie Munger

## The Goal
Create a script `vypocet.sh` that:
1. Takes an operation (**s** for sum, **n** for multiply) as a **parameter** (`$1`).
2. Asks for two numbers (**A** and **B**) via **prompt** (`read`).
3. If no parameter is given, prints "Operace nezadana".

---

## 1. Inversion: How to fail this exercise?
- **Empty Variable Catastrophe**: Forgetting to check if `$1` exists. The script will fail silently.
- **Math Confusion**: Trying to calculate without `$(( ... ))`.
- **Input Error**: Forgetting that "na výzvu" means `read`, not more arguments.

---

## 2. The Mental Model: The Switchboard (`case`)
When a single value determines which path to take, use the **`case`** model. It's cleaner than `if/else`.

### Step A: Guarding the Entry (`if -z`)
- **Command**: `if [ -z "$1" ]`
- **Why?**: `-z` checks if the string is empty.

### Step B: The Multi-Choice Switch (`case`)
- **Structure**: `case "$1" in s) ... ;; n) ... ;; esac`
- **Why?**: It maps parameters directly to actions.

---

## 3. The "High-Reliability" Solution

```bash
#!/bin/bash

if [ -z "$1" ]; then
    echo "Operace nezadana"
    exit 1
fi

read -p "Zadej A: " a
read -p "Zadej B: " b

case "$1" in
    s) echo "Vysledek: $((a + b))" ;;
    n) echo "Vysledek: $((a * b))" ;;
    *) echo "Neznama operace" ;;
esac
```

### Parameter-by-Parameter Proof:
- `-z "$1"`: Checks if the **first** argument is **z**ero-length.
- `read -p`: **P**rompts and saves the value.
- `$(( ... ))`: Performs integer **arithmetic**.
- `s) ... ;;`: Defines the block for 's', ended by **double semicolons**.
- `*)`: The **universal** catch-all for anything else.

---

## 4. Simpler Examples (Building Competence)

**Example 1: Simple Addition**
```bash
echo $((10 + 20))
```

**Example 2: Check if parameter exists**
```bash
if [ -z "$1" ]; then echo "Empty"; fi
```

**Example 3: Minimalist case check**
```bash
case "$1" in
    a) echo "Alpha" ;;
    *) echo "Default" ;;
esac
```
