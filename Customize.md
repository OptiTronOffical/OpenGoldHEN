# Customization Guide: OpenGoldHEN Payload Source

This guide covers modifications to the **payload source code** (C/C++ files in `src/` and `include/`). It ignores all web host files. The payload is the binary that runs on the PS4 after the browser exploit succeeds.

> **Note:** The payload icon is **not** defined in the source code. It is a separate PNG file placed next to the payload binary, named `<payload_name>.bin.png`. To change the icon, simply replace that PNG file—no recompilation is needed. This guide focuses on code-level customizations.

---

## 1. Prerequisites

- A working build environment (see the Compilation Guide above).
- A text editor or IDE.
- Basic knowledge of C and the PS4 APIs used by GoldHEN.

---

## 2. Locating Customizable Strings

Most user-visible text (notifications, log messages) is stored as string literals in the source files. Search for them:

```bash
grep -R "GoldHEN" src/ include/
grep -R "notify" src/ include/
grep -R "sceNotification" src/ include/
```

Common files include:
- `src/main.c`
- `src/notify.c`
- `src/goldhen.c`
- Any file with `payload` or `hen` in the name.

---

## 3. Changing Notification Messages

If the payload sends a notification on success or failure, you will find a call similar to:

```c
sceNotificationSend("GoldHEN loaded successfully!");
```

or a custom wrapper:

```c
notify("GoldHEN loaded successfully!");
```

Edit the string literal to your desired message. Keep it concise; very long strings may be truncated in the PS4 notification area.

After editing, rebuild the payload:

```bash
make clean
make
```

---

## 4. Changing the Payload Version String

GoldHEN often prints a version string in logs or notifications. Search for a version definition:

```bash
grep -R "VERSION" src/ include/
grep -R "2.4" src/ include/
```

You may find something like:

```c
#define GOLDHEN_VERSION "2.4b18.11"
```

Change it to your custom version. Rebuild the payload.

---

## 5. Changing the Payload Binary Name

The name of the output binary is controlled by the `Makefile`. Open the `Makefile` and look for variables such as:

```make
TARGET := goldhen
```

or

```make
OUTPUT := goldhen.bin
```

Change the target name to your preference. After rebuilding, the new binary will have the new name. Remember to rename the icon PNG accordingly if you use one.

---

## 6. Adding or Modifying Functionality

If you want to change the payload's behavior (e.g., enable/disable a feature, add a new patch), you will need to modify the C source. The GoldHEN source is complex, but common areas include:

- **Kernel patches:** Look for functions that apply patches to the PS4 kernel.
- **Plugin loading:** Search for `plugin` or `load_plugin`.
- **Debug menu:** Look for `debug` or `menu`.

Always test changes on a console you can afford to lose, and keep backups of the original source.

---

## 7. Rebuilding After Changes

After any source modification:

```bash
make clean
make
```

The new payload binary will be generated. Deploy it using your preferred method (e.g., via the web host, but that is outside the scope of this guide).

---

## 8. Quick Reference: Where to Change What

| Customization | Location | Rebuild Required? |
|---------------|----------|-------------------|
| Notification text | String literals in `src/` | Yes |
| Version string | `#define` in `include/` or `src/` | Yes |
| Payload binary name | `Makefile` | Yes |
| Payload icon | Separate PNG file next to binary | No (just replace PNG) |
| Behavior / features | C source in `src/` | Yes |

---

## 9. Troubleshooting

| Problem | Likely Cause | Solution |
|---------|--------------|----------|
| Notification not changing | String is in a different file | Search all source files with `grep -R` |
| Build fails after edits | Syntax error | Check compiler output, fix the error |
| Payload crashes on console | Incompatible change | Revert to original source and rebuild |
| Icon not showing | PNG filename mismatch | Ensure PNG is named `<payload_name>.bin.png` |

---

## 10. Credits

- **SiSTRo** and the GoldHEN team for the original payload.
- **OpenOrbis** for the toolchain.
- All contributors to **OpenGoldHEN**.

This guide assumes the repository structure follows common conventions for OpenOrbis-based PS4 payloads. Always search the source tree for the exact strings and definitions you wish to change.
