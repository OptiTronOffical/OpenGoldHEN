# Complete Compilation Guide: OpenGoldHEN (FW 7.00–13.52)

This guide provides the exact steps to compile the **OpenGoldHEN** project from source. The repository contains a C/C++ payload (the GoldHEN binary) and a set of static web assets (the browser-based exploit host). You will need a Linux environment (native or WSL on Windows) to build the payload using the OpenOrbis PS4 Toolchain.

---

## 1. Prerequisites

Before you begin, ensure your system meets the following requirements.

### 1.1 System Requirements

- **OS:** Linux (Ubuntu/Debian recommended) or Windows with WSL2.
- **Internet:** Required to clone repositories and download toolchain components.

### 1.2 Install System Packages

Open a terminal and run:

```bash
sudo apt update
sudo apt install -y build-essential git python3 python3-pip clang lld
```

The OpenOrbis toolchain requires `clang` and `lld` (the LLVM linker). On Arch-based systems, use `sudo pacman -S clang lld` instead.

---

## 2. Set Up the OpenOrbis PS4 Toolchain

OpenGoldHEN is built using the **OpenOrbis PS4 Toolchain**, which provides the headers, library stubs, and build tools needed to compile homebrew for the PS4 without Sony's official SDK.

### 2.1 Clone the Toolchain

```bash
git clone https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain.git ~/OpenOrbis-PS4-Toolchain
```

### 2.2 Set the Environment Variable

The build system expects the `OO_PS4_TOOLCHAIN` environment variable to point to the toolchain root.

Add the following to your shell profile (`~/.bashrc` for Bash, `~/.zshrc` for Zsh):

```bash
export OO_PS4_TOOLCHAIN="$HOME/OpenOrbis-PS4-Toolchain"
export PATH="$OO_PS4_TOOLCHAIN/bin:$PATH"
```

Then reload your profile:

```bash
source ~/.bashrc   # or source ~/.zshrc
```

### 2.3 Verify the Toolchain

Run the following to confirm the cross-compiler is available:

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

The repository structure is organized as follows:

```
OpenGoldHEN/
├── assets/          # Payload binaries, manifests, and web resources
│   ├── kpayload/
│   ├── loader/
│   ├── tables/
│   └── manifest.json
├── include/         # C/C++ header files
├── src/             # C/C++ source files
├── Makefile         # Build script
└── README.md
```

---

## 4. Compile the Payload

### 4.1 Clean Previous Builds (Optional)

If you have previously built the project, clean the build directory first:

```bash
make clean
```

### 4.2 Build the Payload

Run the default build target:

```bash
make
```

The build system will use the `OO_PS4_TOOLCHAIN` to compile all source files from `src/` and link them into a PS4 payload binary. Depending on the repository's Makefile, the output may be placed in a `build/` directory or directly into `assets/`.

### 4.3 Locate the Output

Check the following locations for the compiled payload:

```bash
ls -la build/
ls -la assets/
```

The expected output is a `.bin` file (e.g., `goldhen.bin`). If the Makefile produces a differently named file, note its exact name—you will need it for the web host configuration.

### 4.4 Copy the Payload to Assets (If Needed)

If the build output is not automatically placed in `assets/`, copy it manually:

```bash
cp build/*.bin assets/
```

---

## 5. Build the Web Host (No Compilation Required)

The web host portion of OpenGoldHEN consists entirely of static HTML, JavaScript, and CSS files. **No compilation step is required.**

### 5.1 Verify the Assets Directory

Ensure the `assets/` directory contains the following:

- The compiled payload binary (e.g., `goldhen.bin`).
- `manifest.json` (the Application Cache manifest for offline use).
- Any firmware-specific subdirectories (`kpayload/`, `loader/`, `tables/`).

### 5.2 Serve the Files Locally

To test the host on your local network, start a simple HTTP server from the repository root:

```bash
python3 -m http.server 8000
```

### 5.3 Access from the PS4

1.  On your PS4, open the **Internet Browser**.
2.  Navigate to `http://<your-pc-ip>:8000` (replace `<your-pc-ip>` with the local IP address of the machine running the server).
3.  Follow the on-screen instructions to install the offline cache and trigger the exploit.

---

## 6. Firmware 13.52 Specific Notes

- **Payload Compatibility:** OpenGoldHEN supports firmware **7.00 through 13.52**. The 13.52 support is provided by the **GoldHEN 2.4b18.11** (or later) payload included in the `assets/` directory.
- **Manifest Configuration:** Ensure that `manifest.json` correctly references the payload binary and all associated resource files. If you rebuilt the payload with a different filename, update the manifest accordingly.
- **Offline Caching:** The web host uses an Application Cache manifest to enable offline use. After the initial page load, the exploit can be triggered without an internet connection.

---

## 7. Troubleshooting

| Problem | Solution |
|---------|----------|
| `ps4-elf-clang: command not found` | The toolchain is not in your `PATH`. Re-check the `export` commands in Section 2.2. |
| Build fails with "missing headers" | `OO_PS4_TOOLCHAIN` is not set correctly. Verify it points to the toolchain root. |
| `make: *** No targets specified` | The repository may use a custom build script (e.g., `./build.sh`). Check the repository root for executable scripts. |
| "Not enough free system memory" on console | Restart the PS4 and try the exploit again. Early attempts often require a second try. |
| Offline cache not working | Clear the PS4 browser cache, then reload the host page to reinstall the AppCache manifest. |
| Payload not loading on 13.52 | Verify that the payload binary in `assets/` is the GoldHEN 2.4b18.11+ build. Earlier payloads do not support 13.52. |

---

## 8. Summary of Commands

```bash
# 1. Install packages
sudo apt update && sudo apt install -y build-essential git python3 clang lld

# 2. Clone toolchain
git clone https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain.git ~/OpenOrbis-PS4-Toolchain

# 3. Set environment
export OO_PS4_TOOLCHAIN="$HOME/OpenOrbis-PS4-Toolchain"
export PATH="$OO_PS4_TOOLCHAIN/bin:$PATH"

# 4. Clone OpenGoldHEN
git clone https://github.com/OptiTronOffical/OpenGoldHEN.git
cd OpenGoldHEN

# 5. Build
make clean
make

# 6. Serve locally (for testing)
python3 -m http.server 8000
```

---

## 9. Credits

- **SiSTRo** and the GoldHEN team for the original payload.
- **OpenOrbis** for the PS4 toolchain.
- All contributors to the **OpenGoldHEN** project.

This guide reflects the standard build process for OpenOrbis-based PS4 payloads. If the repository includes a custom `build.sh` or deviates from the `Makefile` convention, always check the repository root for the authoritative build instructions.
