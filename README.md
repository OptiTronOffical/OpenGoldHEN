# Complete Compilation Guide: OpenGoldHEN Payload

This guide covers compiling **only the C/C++ payload** (the GoldHEN binary) from the OpenGoldHEN repository. It ignores all web host files (HTML, JavaScript, CSS, manifests, etc.). The payload is built using the **OpenOrbis PS4 Toolchain**.

---

## 1. Prerequisites

### 1.1 System Requirements

- **OS:** Linux (Ubuntu/Debian recommended) or Windows with WSL2.
- **Internet:** Required to clone the repository and toolchain.

### 1.2 Install System Packages

Open a terminal and run:

```bash
sudo apt update
sudo apt install -y build-essential git clang lld
```

The OpenOrbis toolchain requires `clang` and `lld`. On Arch-based systems, use `sudo pacman -S clang lld`.

---

## 2. Set Up the OpenOrbis PS4 Toolchain

### 2.1 Clone the Toolchain

```bash
git clone https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain.git ~/OpenOrbis-PS4-Toolchain
```

### 2.2 Set the Environment Variable

Add the following to your shell profile (`~/.bashrc` or `~/.zshrc`):

```bash
export OO_PS4_TOOLCHAIN="$HOME/OpenOrbis-PS4-Toolchain"
export PATH="$OO_PS4_TOOLCHAIN/bin:$PATH"
```

Reload your profile:

```bash
source ~/.bashrc   # or source ~/.zshrc
```

### 2.3 Verify the Toolchain

```bash
ps4-elf-clang --version
```

If the command is not found, ensure `$OO_PS4_TOOLCHAIN/bin` is in your `PATH`.

---

## 3. Clone the OpenGoldHEN Repository

```bash
git clone https://github.com/OptiTronOffical/OpenGoldHEN.git
cd OpenGoldHEN
```

The payload source is located in the `src/` directory, with headers in `include/`. The build is controlled by a `Makefile` in the repository root.

---

## 4. Compile the Payload

### 4.1 Clean Previous Builds

```bash
make clean
```

### 4.2 Build the Payload

```bash
make
```

This invokes the OpenOrbis toolchain to compile all `.c` files in `src/` and link them into a PS4 payload binary. The output is typically placed in a `build/` directory or directly in the repository root.

### 4.3 Locate the Output

Check the following locations:

```bash
ls -la build/
ls -la .
```

The expected output is a `.bin` file (e.g., `goldhen.bin`). Note its exact name—you will need it when deploying the payload.

### 4.4 (Optional) Copy the Payload

If your workflow requires the payload in a specific location (e.g., `assets/` for the web host), copy it manually. However, for payload-only builds, you can use the binary directly from the build output.

```bash
cp build/*.bin .
```

---

## 5. Troubleshooting

| Problem | Solution |
|---------|----------|
| `ps4-elf-clang: command not found` | Toolchain not in `PATH`. Re-check Section 2.2. |
| Build fails with missing headers | `OO_PS4_TOOLCHAIN` not set correctly. Verify it points to the toolchain root. |
| `make: *** No targets specified` | Check for a custom build script or different Makefile target. |
| Linker errors | Ensure `clang` and `lld` are installed and in `PATH`. |

---

## 6. Summary of Commands

```bash
# Install packages
sudo apt update && sudo apt install -y build-essential git clang lld

# Clone toolchain
git clone https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain.git ~/OpenOrbis-PS4-Toolchain

# Set environment
export OO_PS4_TOOLCHAIN="$HOME/OpenOrbis-PS4-Toolchain"
export PATH="$OO_PS4_TOOLCHAIN/bin:$PATH"

# Clone OpenGoldHEN
git clone https://github.com/OptiTronOffical/OpenGoldHEN.git
cd OpenGoldHEN

# Build payload
make clean
make
```

---

## 7. Credits

- **SiSTRo** and the GoldHEN team for the original payload.
- **OpenOrbis** for the PS4 toolchain.
- All contributors to the **OpenGoldHEN** project.

---

