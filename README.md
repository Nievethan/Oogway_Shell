# 🐢 The Oogway Shell (oogway_shell)

> "Yesterday is history, tomorrow is a mystery, but today is a gift. That is why it is called the present... working directory."
> — Master Oogway (in his coding era)

## 📜 The Legend
The **Oogway Shell** is a lightweight, C-based command-line interpreter that brings inner peace to your Operating System. It harmonizes with the Linux kernel to execute commands, manage processes, and flow like water through the filesystem.

It was forged in the fires of `gcc` and tempered by the holy `Makefile`.

## 🥋 The Techniques (Features)

### 1. The Art of Navigation (`cd`)
* **Technique:** Moves the user's spirit (process) to a new realm (directory).
* **Wisdom:** "One often meets his destiny on the road he takes to avoid it."
* **Usage:** `cd <path>`

### 2. The Empty Mind (`clear`)
* **Technique:** Instantly clears the chaos from the terminal screen, leaving only a blank slate for new ideas.
* **Wisdom:** "Your mind is like this water, my friend. When it is agitated, it becomes difficult to see. But if you allow it to settle, the answer becomes clear."
* **Usage:** `clear`

### 3. The Shadow Clones (Fork & Exec)
* **Technique:** The shell summons external warriors (programs like `ls`, `grep`, `python`) to fight battles on its behalf.
* **Mechanism:** Uses the ancient `fork()` and `execvp()` distinct styles.
* **Usage:** Just type the command! (e.g., `ls -l`)

### 4. Flowing Like Water (I/O Redirection)
* **Technique:** Redirects the flow of data energy.
* **Input (`<`):** Draws energy from a scroll (file).
* **Output (`>`):** Channels energy into a scroll (file).
* **Append (`>>`):** Adds to the legacy without destroying the past.
* **Usage:** `ls -l > scroll_of_files.txt`

### 5. The Scroll of Destiny (Batch Mode)
* **Technique:** The shell reads a list of prophecies (commands) from a file and executes them in perfect order without human intervention.
* **Usage:** `./oogway_shell destiny.txt`

---

## 🏯 How to Train (Compile)

To awaken the dragon, open your terminal and recite the summoning chant:

    make

This will create the executable artifact known as `oogway_shell`.

To banish the spirits of the past (clean build files):

    make clean

---

## 🐉 How to Fight (Run)

### Interactive Combat
Enter the dojo to face your commands one by one:

    ./oogway_shell

### Batch Combat
Execute a pre-written sequence of moves:

    ./oogway_shell <filename>

---

**"There are no accidents."** *(Except for segmentation faults. Those are definitely accidents.)*
