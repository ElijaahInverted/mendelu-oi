# Exercise 3: Iteration & Numeric Comparison

> "I have what I call an internal scoreboard. I pride myself on not being stupid." — Charlie Munger

## The Goal
Create a script `compare.sh` that:
1. Asks for a number **5 times** in a row.
2. Compares that number to **100**.
3. Tells you if it's **greater, smaller, or equal**.

---

## 1. Inversion: How to fail this exercise?
- **The Infinite Loop**: Using a `while` loop but forgetting to increment the counter. You’ll be stuck forever.
- **String vs Integer**: Comparing numbers like they are words. In Bash, `[[ $a > $b ]]` can behave like an alphabetical check if you aren't careful. We want math.
- **Messy Logic**: Nesting `if` statements instead of using `elif`. It makes the code look like a plate of spaghetti.

---

## 2. The Mental Model: Determinism
In a chaotic world, we prefer the "Fixed Loop." If we know we need 5 cycles, we use a `for` loop. It’s hard to break.

### Step A: The Loop (`for`)
- **Simplest Path**: `for i in {1..5}`
- **Why?**: It’s explicit. Everyone can see it runs 5 times. No math required for the counter.

### Step B: The Prompt (`read`)
- **Simplest Path**: `read -p "Enter number: " a`
- **Why?**: It combines the "print" and "input" into one line. Efficient.

### Step C: The Comparison (`if`)
- **Simplest Path**: `if [ $a -lt 100 ]`
- **Why?**: The `[ ... ]` (test) command is the gold standard for portable scripts. 
- **The Codes**: 
    - `-lt`: **L**ess **T**han.
    - `-gt`: **G**reater **T**han.
    - `-eq`: **Eq**ual.

---

## 3. The "High-Reliability" Solution

```bash
#!/bin/bash

# Simple loop using the brace expansion for 5 turns
for i in {1..5}
do
    read -p "Zadejte cislo: " a
    
    if [ "$a" -lt 100 ]; then
        echo "Cislo je mensi nez 100"
    elif [ "$a" -gt 100 ]; then
        echo "Cislo je vetsi nez 100"
    else
        echo "Cislo je rovno 100"
    fi
done
```

### Parameter-by-Parameter Proof:
- `for i in {1..5}`: **Start** the loop. `i` is the variable, `{1..5}` is the range.
- `do ... done`: The **boundary** of the loop's actions.
- `read -p`: **Read** input. `-p` stands for **p**rompt (the text shown to user).
- `if [ "$a" -lt 100 ]`: 
    - `if`: Start the logic.
    - `[`: The **test** command.
    - `"$a"`: Use quotes! It prevents the script from crashing if the user enters nothing.
    - `-lt`: The **math** operator for "less than."
- `elif`: **Else if**. Handles the second condition without nesting.

---

## 4. Simpler Examples (Building Competence)

**Example 1: A loop that just counts 1 to 3**
```bash
for i in 1 2 3
do
    echo "Count: $i"
done
```

**Example 2: A simple comparison (no loop)**
```bash
read -p "Num: " x
if [ "$x" -eq 100 ]; then echo "Exactly 100"; fi
```
