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
  - `print`
  - `cls` (clears terminal)
  - `help` (shows command list)
  - `exit`

---

## 🛠️ Build Instructions

Make sure you have a C compiler and makefile tools from gnu.

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
./stack-cli
```

Once inside, try commands like:

```bash
prompt@> push 5
prompt@> push 10
prompt@> peek
prompt@> find 10
prompt@> sort
prompt@> print
prompt@> pop
prompt@> help
prompt@> exit
```

---

## 📁 Project Structure

```
📂 stack-cli
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

- The stack is fixed-size (`max_nums = 100`)
- Sorting uses quicksort
- The `swap` command swaps the top 2 elements (if available)
- Trying to `pop` or `peek` from an empty stack exits the program ( as a warning ⚠️  )

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

