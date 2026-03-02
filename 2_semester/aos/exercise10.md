# Exercise 10: Identity & Active Users

> "A lot of people with high IQs are terrible investors because they’ve got terrible temperaments. You need to keep raw irrational emotion under control." — Charlie Munger

## The Goal
1. Print **your own** user information.
2. Print information about the user **xnovak**.
3. List all **currently logged-in** users.

---

## 1. Inversion: How to fail this exercise?
- **Mixing Identities**: Confusing who you are with who the target is.
- **The Ghost User**: Trying to check `xnovak` if the user doesn't exist on the system (always check existence first).
- **The "Static" Error**: Checking a file (like `/etc/passwd`) instead of using the live identity tools.

---

## 2. The Mental Model: The ID Card (`id`)

### Step A: Self-Identification
- **Command**: `id`
- **Why?**: Without arguments, `id` shows your UID, GID, and groups. It's your digital mirror.

### Step B: Target-Identification
- **Command**: `id xnovak`
- **Why?**: Providing a username as an argument looks up *their* card.

### Step C: The Presence Check (`who`)
- **Command**: `who`
- **Why?**: It shows who is currently "in the building" (active sessions).

---

## 3. The "High-Reliability" Solution

```bash
# 1. My info
id

# 2. Target info
id xnovak

# 3. Active users
who
```

---

## 4. Simpler Examples (Building Competence)

**Example 1: Just your username**
```bash
whoami
```

**Example 2: Detailed user status (if finger is installed)**
```bash
finger xnovak
```

**Example 3: Short version of who**
```bash
users
```
