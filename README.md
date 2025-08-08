# 🌀 Stack CLI Manager (C)

Welcome to the **Stack CLI**, a fun and interactive command-line stack implementation written entirely in C. This project supports a bunch of operations like `push`, `pop`, `find`, `sort`, and more — all from your terminal. Perfect for C learners who wanna sharpen their data structure skills with a lil' spice 🌶️.

---

## 💾 Features

- Stack implemented using a fixed-size array
- Easy command-line interaction
- Support for:
  - `push <value>`
  - `pop`
  - `peek`
  - `delete <value>`
  - `find <value>`
  - `count`
  - `swap`
  - `sort`
  - `reverse`
  - `print`
  - `cls` (clears terminal)
  - `help` (shows command list)
  - `exit`

---

## 🛠️ Build Instructions

Make sure you have a C compiler and makefile tools from gnu.

1. clone the reposetory
```bash
git clone git@github.com:skinwalker3654/stack-cli.git  #ssh key required
cd stack-cli
```
2. compile the program
```bash
make
make run
```

When you want to delete the executable file run:
```bash 
make clean
```

> ✅ You must have all three files: `main.c`, `stack.c`, and `stack.h`

---

## 🚀 Usage

Run it in your terminal:

```bash
./bin/main
```
![My Pic][.github/image.png]

---

## 📁 Project Structure

```
📂 stack-cli
├── .github/
|    ├── image.png
|    └── CONTRIBUTING.md
|
├── explanation/
|    └── explain.txt
|
├── src/
|    ├── main.c
|    ├── stack.c
|    └── stack.h
|
├── README.md
├── Makefile
└── LICENSE
```

---

## 📣 Notes

- The stack is fixed-size (`max_nums = 100`) you can change the size by changing the #define MAX_STACK_SIZE from the src/stack.h
- Sorting uses quicksort
- The `swap` command swaps the top 2 elements (if available)

---

## 💡 Why?

This project is great for:

- Practicing C structs and arrays
- Learning CLI parsing with `sscanf` and `fgets`
- Getting comfy with stack operations in a low-level language

---

## 🧠 Inspired By

Just the vibes of coding raw C like a boss 😎
Ideal for beginners, students, or anyone trying to flex with terminal tools.

---

## 📜 License

MIT License. Feel free to fork and remix ✨

---

Made with caffeine ☕ and C
By **skinwalker**

