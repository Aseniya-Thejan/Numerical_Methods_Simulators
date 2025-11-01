# Bisection Method — Root Finder (C)

A small, interactive C program that finds a root of a continuous function on an interval `[lower, upper]` using the **bisection method**.  
This build uses the function:

\[
f(x) = 32 e^{0.09x} - 39
\]

The program requests interval bounds and a required number of **significant digits**, then iteratively halves the interval until the **relative approximate error** is below the target threshold.

---

## Features

- Bracketing check `f(lower) * f(upper) < 0` to ensure a sign change
- Iteration table printing `lower`, `upper`, `approximation`, and `% error`
- Stops when `% error ≤ 0.5 × 10^{(2 − s)} ` where `s` = significant digits
- Immediate exit if an endpoint is already a root

---

## Build

Requires a C compiler and libm.

```bash
# GCC (Linux/macOS/WSL/MinGW)
gcc -O2 -Wall -Wextra -o bisection Bisection.c -lm
```

---

## Run

```bash
./bisection
```

You will be prompted for:

1. **Upper bracket** (a number)
2. **Lower bracket** (a number)
3. **Required number of significant digits** (integer ≥ 1)

If the initial interval does **not** bracket a root, the program asks you to re-enter bounds until a valid sign change is provided.

> **Tip:** For the built-in function `32·e^{0.09x} − 39`, a valid starting interval is, for example, `lower = 0`, `upper = 5` (root ≈ 2.19).

---

## Algorithm

**Bisection** repeatedly halves the interval containing a sign change:

1. Compute midpoint `m = (lower + upper) / 2`.
2. If `f(m) == 0`, return `m` as the root.
3. Else, pick the subinterval `[lower, m]` or `[m, upper]` that still has a sign change.
4. Estimate the **relative approximate error** (from the code):  
   \[
   \varepsilon_a(\%) = \left|\frac{m - m_\text{prev}}{m}\right| \times 100
   \]
5. Continue until `ε_a ≤ 0.5 × 10^{(2 − s)}`.

---

## I/O Format

- **Input (via prompts):**
  - `Upper bracket` (double)
  - `Lower bracket` (double)
  - `Significant digits` (int)

- **Output:**
  - A header, followed by an iteration table and the final root approximation.
  - On the first line of the table, error is printed as `N/A` by design.

---

## Example Session

```
Enter the upper bracket :-5
Enter the lover bracket :-0
Enter the required no of significant digits required :-5
X-lower = 0.000000
 X-upper = 5.000000
You have chosen two guesses correctly.
	   |   Lower   |   Upper   |   Approximation   |   Error   |
	   ---------------------------------------------------------
	    0.000000   5.000000 	2.500000 	  N/A  
	    0.000000   2.500000 	1.250000 	100.000000%
	    1.250000   2.500000 	1.875000 	33.333333%
	    ... (continues) ...
Root is 2.1889
```

*(Numbers are illustrative; your output will reflect actual iterations and termination based on your chosen significant digits.)*

---

## Notes & Limitations

- Works for **continuous** functions with a **single sign change** in the chosen interval.
- For multiple roots or discontinuities within the interval, bisection may not converge to what you expect.
- The code currently calculates **relative approximate error** using successive midpoints. If you prefer the theoretical bisection bound `(|upper-lower|)/2^k`, you can modify the stopping criterion.
- Minor prompt typo in the current build (“lover” instead of “lower”).

---

## File

- `Bisection.c` — main program (function definition, bracketing, loop, printing, error computation).

---

## License

MIT (recommended). You may replace with your preferred license.
